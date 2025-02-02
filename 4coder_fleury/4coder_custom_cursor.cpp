
enum Cursor_Type
{
    cursor_none,
    cursor_insert,
    cursor_open_range,
    cursor_close_range,
};


function void
draw_cursor_thingy(Application_Links *app, Rect_f32 rect,
                   f32 roundness, f32 thickness,
                   ARGB_Color color, Cursor_Type type)
{
    f32 line_height = rect.y1 - rect.y0;
    f32 bracket_width = 0.5f*line_height;
    
    if(type == cursor_open_range)
    {
        Rect_f32 start_top, start_side, start_bottom;
        
        Vec2_f32 start_p = {rect.x0, rect.y0};
        
        start_top.x0 = start_p.x + thickness;
        start_top.x1 = start_p.x + bracket_width;
        start_top.y0 = start_p.y;
        start_top.y1 = start_p.y + thickness;
        
        start_bottom.x0 = start_top.x0;
        start_bottom.x1 = start_top.x1;
        start_bottom.y1 = start_p.y + line_height;
        start_bottom.y0 = start_bottom.y1 - thickness;
        
        start_side.x0 = start_p.x;
        start_side.x1 = start_p.x + thickness;
        start_side.y0 = start_top.y0;
        start_side.y1 = start_bottom.y1;
        
        draw_rectangle(app, start_top, roundness, color);
        draw_rectangle(app, start_side, roundness, color);
        
        // draw_rectangle(app, start_bottom, start_color);
    }
    else if(type == cursor_close_range)
    {
        Rect_f32 end_top, end_side, end_bottom;
        
        Vec2_f32 end_p = {rect.x0, rect.y0};
        
        end_top.x0 = end_p.x;
        end_top.x1 = end_p.x - bracket_width;
        end_top.y0 = end_p.y;
        end_top.y1 = end_p.y + thickness;
        
        end_side.x1 = end_p.x;
        end_side.x0 = end_p.x + thickness;
        end_side.y0 = end_p.y;
        end_side.y1 = end_p.y + line_height;
        
        end_bottom.x0 = end_top.x0;
        end_bottom.x1 = end_top.x1;
        end_bottom.y1 = end_p.y + line_height;
        end_bottom.y0 = end_bottom.y1 - thickness;
        
        draw_rectangle(app, end_bottom, roundness, color);
        draw_rectangle(app, end_side, roundness, color);
    }
    else if(type == cursor_insert)
    {
        Rect_f32 side;
        side.x0 = rect.x0;
        side.x1 = rect.x0 + thickness;
        side.y0 = rect.y0;
        side.y1 = rect.y1;
        
        draw_rectangle(app, side, roundness, color);
    }
}

function void
highlight_cursor_mark_range(Application_Links *app, Text_Layout_ID text_layout_id, View_ID view_id)
{
    Rect_f32 view_rect = view_get_screen_rect(app, view_id);
    Rect_f32 clip = draw_set_clip(app, view_rect);
    
    f32 lower_bound_y;
    f32 upper_bound_y;
    
    i64 cursor_pos = view_get_cursor_pos(app, view_id);
    i64 mark_pos   = view_get_mark_pos(app, view_id);
    
    Rect_f32 cursor_rect = text_layout_character_on_screen(app, text_layout_id, cursor_pos);
    Rect_f32 mark_rect   = text_layout_character_on_screen(app, text_layout_id, mark_pos);
    
    if(cursor_rect.y0 < mark_rect.y0)
    {
        lower_bound_y = cursor_rect.y0;
        upper_bound_y = mark_rect.y1;
    }
    else
    {
        lower_bound_y = mark_rect.y0;
        upper_bound_y = cursor_rect.y1;
    }
    
    draw_rectangle(app, Rf32(view_rect.x0, lower_bound_y, view_rect.x0 + 4, upper_bound_y), 3.f,
                   fcolor_resolve(fcolor_change_alpha(fcolor_id(defcolor_comment), 0.5f)));
    draw_set_clip(app, clip);
}


function void
custom_draw_cursor_mark(Application_Links *app, View_ID view_id, b32 is_active_view,
                        Buffer_ID buffer, Text_Layout_ID text_layout_id,
                        f32 roundness, f32 outline_thickness, Frame_Info frame_info){
    b32 has_highlight_range = draw_highlight_range(app, view_id, buffer, text_layout_id, roundness);
    
    i64 cursor_pos = view_get_cursor_pos(app, view_id);
    i64 mark_pos = view_get_mark_pos(app, view_id);
    Rect_f32 nxt_cursor_rect = text_layout_character_on_screen(app, text_layout_id, cursor_pos);
    Rect_f32 cur_cursor_rect = Rf32_xy_wh(qol_cur_cursor_pos, rect_dim(nxt_cursor_rect));
    
    Rect_f32 nxt_mark_rect = text_layout_character_on_screen(app, text_layout_id, mark_pos);
    
    if (is_active_view && nxt_cursor_rect.x1 > 0.f){
        qol_nxt_cursor_pos = nxt_cursor_rect.p0;
    }
    
    if (!has_highlight_range){
        
        ColorFlags flags = 0;
        flags |= !!global_keyboard_macro_is_recording * ColorFlag_Macro;
        flags |= !!power_mode.enabled * ColorFlag_PowerMode;
        ARGB_Color cursor_color = F4_GetColor(app, ColorCtx_Cursor(flags, GlobalKeybindingMode));
        ARGB_Color mark_color = cursor_color;
        if (vim_state.mode == VIM_Insert)
        {
            Cursor_Type cursor_type = cursor_none;
            Cursor_Type mark_type = cursor_none;
            if(cursor_pos <= mark_pos)
            {
                cursor_type = cursor_open_range;
                mark_type = cursor_close_range;
            }
            else
            {
                cursor_type = cursor_close_range;
                mark_type   = cursor_open_range;
            }
            
            // NOTE(rjf): Draw main cursor.
            {
                draw_cursor_thingy(app, cur_cursor_rect, 0, 3.f, cursor_color, cursor_type);
                draw_cursor_thingy(app, nxt_cursor_rect, 0, 3.f, cursor_color, cursor_type);
            }
            
            // NOTE(rjf): Draw main cursor.
            {
                draw_cursor_thingy(app, nxt_mark_rect, 0, 1.f, mark_color, mark_type);
            }
        }
        else
        {
            if (is_active_view && rect_overlap(nxt_cursor_rect, cur_cursor_rect)){
                // NOTE: Only paint once cursor is overlapping (from Jack Punter)
                paint_text_color_pos(app, text_layout_id, cursor_pos, fcolor_id(defcolor_at_cursor));
            }
            else if (!is_active_view){
                draw_rectangle_outline(app, nxt_cursor_rect, roundness, outline_thickness, cursor_color);
            }
            draw_character_wire_frame(app, text_layout_id, mark_pos, roundness, outline_thickness, mark_color);
            draw_rectangle(app, cur_cursor_rect, roundness, cursor_color);
        }
    }
    
}

