
#define LANG_NAME_LOWER zig
#define LANG_NAME_CAMEL Zig

#include "lexer_generator/4coder_lex_gen_main.cpp"

internal void build_language_model(void)
{
  u8 utf8[129];
  smh_utf8_fill(utf8);
  
  smh_set_base_character_names();
  smh_typical_tokens();
  
  sm_char_name('!', "Not");
  sm_char_name('&', "And");
  sm_char_name('|', "Or");
  sm_char_name('%', "Mod");
  sm_char_name('/', "Div");
  
  sm_select_base_kind(TokenBaseKind_Comment);
  sm_direct_token_kind("BlockComment");
  sm_direct_token_kind("LineComment");
  
  sm_select_base_kind(TokenBaseKind_Whitespace);
  sm_direct_token_kind("Backslash");
  
  sm_select_base_kind(TokenBaseKind_LiteralInteger);
  sm_direct_token_kind("LiteralInteger");
  sm_direct_token_kind("LiteralIntegerHex");
  sm_direct_token_kind("LiteralIntegerOct");
  sm_direct_token_kind("LiteralIntegerDoz");
  sm_direct_token_kind("LiteralIntegerBin");
  
  sm_select_base_kind(TokenBaseKind_LiteralFloat);
  sm_direct_token_kind("LiteralFloat");
  
  sm_select_base_kind(TokenBaseKind_LiteralString);
  sm_direct_token_kind("LiteralString");
  sm_direct_token_kind("LiteralStringWide");
  sm_direct_token_kind("LiteralStringUTF8");
  sm_direct_token_kind("LiteralStringUTF16");
  sm_direct_token_kind("LiteralStringUTF32");
  sm_direct_token_kind("LiteralStringRaw");
  sm_direct_token_kind("LiteralStringWideRaw");
  sm_direct_token_kind("LiteralStringUTF8Raw");
  sm_direct_token_kind("LiteralStringUTF16Raw");
  sm_direct_token_kind("LiteralStringUTF32Raw");
  sm_direct_token_kind("LiteralCharacter");
  sm_direct_token_kind("LiteralCharacterWide");
  sm_direct_token_kind("LiteralCharacterUTF8");
  sm_direct_token_kind("LiteralCharacterUTF16");
  sm_direct_token_kind("LiteralCharacterUTF32");
  
  sm_select_base_kind(TokenBaseKind_Keyword);
  sm_direct_token_kind("KeywordGeneric");
  
  sm_select_base_kind(TokenBaseKind_BuiltinFunction);
  sm_direct_token_kind("BuiltinFunctions");
  
  sm_select_base_kind(TokenBaseKind_Identifier);
  sm_direct_token_kind("IdentifierMacro");
  
  
  // Zig Operators
  Operator_Set *main_ops = sm_begin_op_set();
  sm_select_base_kind(TokenBaseKind_ScopeOpen);
  sm_op("{");
  sm_select_base_kind(TokenBaseKind_ScopeClose);
  sm_op("}");
  sm_select_base_kind(TokenBaseKind_ParentheticalOpen);
  sm_op("(");
  sm_op("[");
  sm_select_base_kind(TokenBaseKind_ParentheticalClose);
  sm_op(")");
  sm_op("]");
  sm_select_base_kind(TokenBaseKind_StatementClose);
  sm_op(";");
  sm_select_base_kind(TokenBaseKind_Operator);
  
  sm_op(".");
  sm_op(":");
  sm_op("=");
  sm_op("?");
  
  sm_op("+");
  sm_op("+=");
  sm_op("+%");
  sm_op("+%=");
  sm_op("+|");
  sm_op("+|=");
  
  sm_op("-");
  sm_op("-=");
  sm_op("-%");
  sm_op("-%=");
  sm_op("-|");
  sm_op("-|=");
  
  sm_op("*");
  sm_op("*=");
  sm_op("*%");
  sm_op("*%=");
  sm_op("*|");
  sm_op("*|=");
  
  sm_op("/");
  sm_op("/=");
  sm_op("%");
  sm_op("%=");
  sm_op("<<");
  sm_op("<<=");
  sm_op("<<|");
  sm_op("<<|=");
  sm_op(">>");
  sm_op(">>=");
  sm_op("&");
  sm_op("&=");
  sm_op("|");
  sm_op("|=");
  sm_op("^");
  sm_op("^=");
  sm_op("~");
  sm_op(".?");
  sm_op("!");
  sm_op("==");
  sm_op("!=");
  
  sm_op("<");
  sm_op(">");
  sm_op("<=");
  sm_op(">=");
  sm_op("++");
  sm_op("**");
  sm_op(".*");
  sm_op("||");
  
  sm_select_base_kind(TokenBaseKind_StatementClose);
  sm_op(",");
  
  // Rust Keywords
  Keyword_Set *main_keys = sm_begin_key_set("main_keys");
  
  sm_select_base_kind(TokenBaseKind_Keyword);
  
  sm_key("align");
  sm_key("allowzero");
  sm_key("and");
  sm_key("anyframe");
  sm_key("anytype");
  sm_key("asm");
  sm_key("async");
  sm_key("await");
  sm_key("break");
  sm_key("catch");
  sm_key("comptime");
  sm_key("const");
  sm_key("continue");
  sm_key("defer");
  sm_key("else");
  sm_key("enum");
  sm_key("errdefer");
  sm_key("error");
  sm_key("export");
  sm_key("extern");
  sm_key("fn");
  sm_key("for");
  sm_key("if");
  sm_key("inline");
  sm_key("noalias");
  sm_key("nosuspend");
  sm_key("or");
  sm_key("orelse");
  sm_key("opaque");
  sm_key("packed");
  sm_key("pub");
  sm_key("resume");
  sm_key("return");
  sm_key("linksection");
  sm_key("struct");
  sm_key("suspend");
  sm_key("switch");
  sm_key("test");
  sm_key("threadlocal");
  sm_key("try");
  sm_key("union");
  sm_key("unreachable");
  sm_key("usingnamespace");
  sm_key("var");
  sm_key("volatile");
  sm_key("while");
  
  sm_select_base_kind(TokenBaseKind_LiteralInteger);
  sm_key("LiteralTrue",  "true");
  sm_key("LiteralFalse", "false");
  
  sm_select_base_kind(TokenBaseKind_Keyword);
  
  // Builtin Types
  sm_key("i8");
  sm_key("u8");
  sm_key("i16");
  sm_key("u16");
  sm_key("i32");
  sm_key("u32");
  sm_key("i64");
  sm_key("u64");
  sm_key("i128");
  sm_key("u128");
  sm_key("isize");
  sm_key("usize");
  sm_key("c_short");
  sm_key("c_ushort");
  sm_key("c_int");
  sm_key("c_uint");
  sm_key("c_long");
  sm_key("c_ulong");
  sm_key("c_longlong");
  sm_key("c_ulonglong");
  sm_key("c_longdouble");
  sm_key("f16");
  sm_key("f32");
  sm_key("f64");
  sm_key("f80");
  sm_key("f128");
  sm_key("bool");
  sm_key("anyopaque");
  sm_key("void");
  sm_key("noreturn");
  sm_key("type");
  sm_key("anyerror");
  sm_key("comptime_int");
  
  sm_select_base_kind(TokenBaseKind_Identifier);
  sm_key_fallback("Identifier");
  
  // State Machine
  State *root = sm_begin_state_machine();
  
  Flag *is_hex = sm_add_flag(FlagResetRule_AutoZero);
  Flag *is_oct = sm_add_flag(FlagResetRule_AutoZero);
  Flag *is_doz = sm_add_flag(FlagResetRule_AutoZero);
  
  Flag *is_wide  = sm_add_flag(FlagResetRule_AutoZero);
  Flag *is_utf8  = sm_add_flag(FlagResetRule_AutoZero);
  Flag *is_utf16 = sm_add_flag(FlagResetRule_AutoZero);
  Flag *is_utf32 = sm_add_flag(FlagResetRule_AutoZero);
  Flag *is_bin = sm_add_flag(FlagResetRule_AutoZero);
  
  Flag *is_char = sm_add_flag(FlagResetRule_AutoZero);
  
#define AddState(N) State *N = sm_add_state(#N)
  
  AddState(identifier);
  AddState(whitespace);
  AddState(backslash);
  
  AddState(operator_or_fnumber_dot);
  AddState(operator_or_comment_slash);
  
  AddState(number);
  AddState(znumber);
  
  AddState(fnumber_decimal);
  AddState(fnumber_exponent);
  AddState(fnumber_exponent_sign);
  AddState(fnumber_exponent_digits);
  
  AddState(number_hex_first);
  AddState(number_doz_first);
  AddState(number_bin_first);
  
  AddState(number_hex);
  AddState(number_oct);
  AddState(number_doz);
  AddState(number_bin);
  
#if 1
  AddState(pre_L);
  AddState(pre_u);
  AddState(pre_U);
  AddState(pre_u8);
  AddState(pre_R);
  
  AddState(character);
  AddState(string);
  AddState(string_esc);
  AddState(string_esc_oct2);
  AddState(string_esc_oct1);
  AddState(string_esc_hex);
  AddState(string_esc_universal_8);
  AddState(string_esc_universal_7);
  AddState(string_esc_universal_6);
  AddState(string_esc_universal_5);
  AddState(string_esc_universal_4);
  AddState(string_esc_universal_3);
  AddState(string_esc_universal_2);
  AddState(string_esc_universal_1);
  
  AddState(raw_string);
  AddState(raw_string_get_delim);
  AddState(raw_string_finish_delim);
  AddState(raw_string_find_close);
  AddState(raw_string_try_delim);
  AddState(raw_string_try_quote);
  
#else
  AddState(character);
  
  AddState(string);
  AddState(string_esc);
  AddState(raw_string);
#endif
  
  AddState(builtin_function);
  
  AddState(comment_block);
  AddState(comment_block_try_close);
  AddState(comment_line);
  
  Operator_Set *main_ops_without_dot_or_slash = smo_copy_op_set(main_ops);
  smo_remove_ops_with_prefix(main_ops_without_dot_or_slash, ".");
  smo_remove_ops_with_prefix(main_ops_without_dot_or_slash, "/");
  
  Operator_Set *main_ops_with_dot = smo_copy_op_set(main_ops);
  smo_remove_ops_without_prefix(main_ops_with_dot, ".");
  smo_ops_string_skip(main_ops_with_dot, 1);
  
  ////
  
  sm_select_state(root);
  
  //sm_set_flag(TRUE, true);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("EOF");
    sm_case_eof(emit);
  }
  
  sm_case("abcdefghijklmnopqrstuvwxyz"
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
          "_$",
          identifier);
  sm_case(utf8, identifier);
  
  
  sm_case("L", pre_L);
  sm_case("u", pre_u);
  sm_case("U", pre_U);
  sm_case("R", pre_R);
  
  sm_case(" \r\n\t\f\v", whitespace);
  sm_case("\\", backslash);
  
  sm_case("@", builtin_function);
  
  sm_case(".", operator_or_fnumber_dot);
  sm_case("/", operator_or_comment_slash);
  {
    Character_Set *char_set = smo_new_char_set();
    smo_char_set_union_ops_firsts(char_set, main_ops_without_dot_or_slash);
    smo_char_set_remove(char_set, "./");
    char *char_set_array = smo_char_set_get_array(char_set);
    State *operator_state = smo_op_set_lexer_root(main_ops_without_dot_or_slash, root, "LexError");
    sm_case_peek(char_set_array, operator_state);
  }
  
  sm_case("123456789", number);
  sm_case("0", znumber);
  
  sm_case("\"", string);
  sm_case("\'", character);
  
  
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_fallback(emit);
  }
  
  ////
  
  sm_select_state(identifier);
  sm_case("abcdefghijklmnopqrstuvwxyz"
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
          "_$"
          "0123456789",
          identifier);
  sm_case(utf8, identifier);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_keys(main_keys);
    sm_fallback_peek(emit);
  }
  
  ////
  
  ////
  
  sm_select_state(whitespace);
  sm_case(" \t\r\n\f\v", whitespace);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("Whitespace");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(backslash);
  sm_case("\r", backslash);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("Backslash");
    sm_case("\n", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("Backslash");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(operator_or_comment_slash);
  sm_case("*", comment_block);
  sm_case("/", comment_line);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("DivEq");
    sm_case("=", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("Div");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(operator_or_fnumber_dot);
  sm_case("0123456789", fnumber_decimal);
  {
    Character_Set *char_set = smo_new_char_set();
    smo_char_set_union_ops_firsts(char_set, main_ops_with_dot);
    char *char_set_array = smo_char_set_get_array(char_set);
    State *operator_state = smo_op_set_lexer_root(main_ops_with_dot, root, "LexError");
    sm_case_peek(char_set_array, operator_state);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("Dot");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number);
  sm_case("_0123456789", number);
  sm_case(".", fnumber_decimal);
  sm_case("Ee", fnumber_exponent);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralInteger");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(znumber);
  sm_case(".", fnumber_decimal);
  sm_case("Ee", fnumber_exponent);
  sm_case("Xx", number_hex_first);
  sm_case("Zz", number_doz_first);
  sm_case("Bb", number_bin_first);
  sm_case("Oo", number_oct);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralInteger");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(fnumber_decimal);
  sm_case("_0123456789", fnumber_decimal);
  sm_case("Ee", fnumber_exponent);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralFloat");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(fnumber_exponent);
  sm_case("+-", fnumber_exponent_sign);
  sm_case("0123456789", fnumber_exponent_digits);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralFloat");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(fnumber_exponent_sign);
  sm_case("0123456789", fnumber_exponent_digits);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralFloat");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(fnumber_exponent_digits);
  sm_case("_0123456789", fnumber_exponent_digits);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralFloat");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_hex_first);
  sm_set_flag(is_hex, true);
  sm_case("0123456789abcdefABCDEF", number_hex);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_hex);
  sm_case("_0123456789abcdefABCDEF", number_hex);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralIntegerHex");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_oct);
  sm_set_flag(is_oct, true);
  sm_case("_01234567", number_oct);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralIntegerOct");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_doz_first);
  sm_set_flag(is_doz, true);
  sm_case("0123456789abAB", number_doz);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_doz);
  sm_case("_0123456789abcdefABCDEF", number_doz);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralIntegerDoz");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_bin_first);
  sm_set_flag(is_bin, true);
  sm_case("_", number_bin_first);
  sm_case("01", number_bin);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_fallback_peek(emit);
  }
  
  ////
  
  sm_select_state(number_bin);
  sm_case("01_", number_bin);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LiteralIntegerBin");
    sm_fallback_peek(emit);
  }
  
  
  ////
  
  sm_select_state(pre_L);
  sm_set_flag(is_wide, true);
  sm_case("\"", string);
  sm_case("R", pre_R);
  sm_fallback_peek(identifier);
  
  ////
  
  sm_select_state(pre_u);
  sm_set_flag(is_utf16, true);
  sm_case("\"", string);
  sm_case("8", pre_u8);
  sm_case("R", pre_R);
  sm_fallback_peek(identifier);
  
  ////
  
  sm_select_state(pre_U);
  sm_set_flag(is_utf32, true);
  sm_case("\"", string);
  sm_case("R", pre_R);
  sm_fallback_peek(identifier);
  
  ////
  
  sm_select_state(pre_u8);
  sm_set_flag(is_utf8, true);
  sm_case("\"", string);
  sm_case("R", pre_R);
  sm_fallback_peek(identifier);
  
  ////
  
  sm_select_state(pre_R);
  sm_case("\"", raw_string);
  sm_fallback_peek(identifier);
  
  ////
  
  sm_select_state(character);
  sm_set_flag(is_char, true);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct(is_wide, "LiteralStringWide");
    sm_emit_handler_direct(is_utf8 , "LiteralStringUTF8");
    sm_emit_handler_direct(is_utf16, "LiteralStringUTF16");
    sm_emit_handler_direct(is_utf32, "LiteralStringUTF32");
    sm_emit_handler_direct("LiteralString");
    sm_case_flagged(is_char, false, "\"", emit);
  }
  
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct(is_wide, "LiteralCharacterWide");
    sm_emit_handler_direct(is_utf8 , "LiteralCharacterUTF8");
    sm_emit_handler_direct(is_utf16, "LiteralCharacterUTF16");
    sm_emit_handler_direct(is_utf32, "LiteralCharacterUTF32");
    sm_emit_handler_direct("LiteralCharacter");
    sm_case_flagged(is_char, true, "\'", emit);
  }
  sm_case("\\", string_esc);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case_peek("\n", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case_eof_peek(emit);
  }
  sm_case_flagged(is_char, true, "\"", string);
  sm_case_flagged(is_char, false, "\'", string);
  sm_fallback(string);
  
  ////
  
  sm_select_state(string_esc);
  sm_case("\n'\"?\\abfnrtv", string);
  sm_case("01234567", string_esc_oct2);
  sm_case("x", string_esc_hex);
  sm_case("u", string_esc_universal_4);
  sm_case("U", string_esc_universal_8);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case_peek("\n", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case_eof_peek(emit);
  }
  sm_fallback(string);
  
  ////
  
  sm_select_state(string_esc_oct2);
  sm_case("01234567", string_esc_oct1);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_oct1);
  sm_case("01234567", string);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_hex);
  sm_case("0123456789abcdefABCDEF", string_esc_hex);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_8);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_7);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_7);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_6);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_6);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_5);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_5);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_4);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_4);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_3);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_3);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_2);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_2);
  sm_case("0123456789abcdefABCDEF", string_esc_universal_1);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(string_esc_universal_1);
  sm_case("0123456789abcdefABCDEF", string);
  sm_fallback_peek(string);
  
  ////
  
  sm_select_state(raw_string);
  sm_delim_mark_first();
  sm_fallback_peek(raw_string_get_delim);
  
  ////
  
  sm_select_state(raw_string_get_delim);
  sm_case_peek("(", raw_string_finish_delim);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case(" \\)", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case_eof_peek(emit);
  }
  sm_fallback(raw_string_get_delim);
  
  ////
  
  sm_select_state(raw_string_finish_delim);
  sm_delim_mark_one_past_last();
  sm_fallback_peek(raw_string_find_close);
  
  ////
  
  sm_select_state(raw_string_find_close);
  sm_case(")", raw_string_try_delim);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LexError");
    sm_case_eof_peek(emit);
  }
  sm_fallback(raw_string_find_close);
  
  ////
  
  sm_select_state(raw_string_try_delim);
  sm_match_delim(raw_string_try_quote, raw_string_find_close);
  
  ////
  
  sm_select_state(raw_string_try_quote);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct(is_wide, "LiteralStringWideRaw");
    sm_emit_handler_direct(is_utf8 , "LiteralStringUTF8Raw");
    sm_emit_handler_direct(is_utf16, "LiteralStringUTF16Raw");
    sm_emit_handler_direct(is_utf32, "LiteralStringUTF32Raw");
    sm_emit_handler_direct("LiteralStringRaw");
    sm_case("\"", emit);
  }
  sm_fallback_peek(raw_string_find_close);
  
  sm_select_state(builtin_function);
  sm_case("abcdefghijklmnopqrstuvwxyz"
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
          "_$"
          "0123456789",
          builtin_function);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("BuiltinFunctions");
    sm_fallback_peek(emit);
  }
  ////
  
  sm_select_state(comment_block);
  sm_case("*", comment_block_try_close);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("BlockComment");
    sm_case_eof_peek(emit);
  }
  sm_fallback(comment_block);
  
  ////
  
  sm_select_state(comment_block_try_close);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("BlockComment");
    sm_case("/", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("BlockComment");
    sm_case_eof_peek(emit);
  }
  sm_case("*", comment_block_try_close);
  sm_fallback(comment_block);
  
  ////
  
  sm_select_state(comment_line);
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LineComment");
    sm_case_peek("\n", emit);
  }
  {
    Emit_Rule *emit = sm_emit_rule();
    sm_emit_handler_direct("LineComment");
    sm_case_eof_peek(emit);
  }
  sm_fallback(comment_line);
}