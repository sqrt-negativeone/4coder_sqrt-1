/* date = January 29th 2021 9:37 pm */

#ifndef FCODER_FLEURY_LANG_LIST_H
#define FCODER_FLEURY_LANG_LIST_H

// NOTE(rjf): Include language files here.
#include "generated/4coder_fleury_lexer_jai.h"
#include "generated/4coder_fleury_lexer_jai.cpp"

#include "generated/4coder_fleury_lexer_rust.h"
#include "generated/4coder_fleury_lexer_rust.cpp"

#include "generated/4coder_fleury_lexer_odin.h"
#include "generated/4coder_fleury_lexer_odin.cpp"

#include "generated/4coder_fleury_lexer_zig.h"
#include "generated/4coder_fleury_lexer_zig.cpp"

#include "4coder_fleury_lang_cpp.cpp"
#include "4coder_fleury_lang_jai.cpp"
#include "4coder_fleury_lang_odin.cpp"
#include "4coder_fleury_lang_zig.cpp"
#include "4coder_fleury_lang_metadesk.cpp"
#include "4coder_fleury_lang_rust.cpp"

// NOTE(rjf): @f4_register_languages Register languages.
function void
F4_RegisterLanguages(void)
{
  // NOTE(rjf): C/C++
  {
    String_Const_u8 extensions[] =
    {
      S8Lit("cpp"), S8Lit("cc"), S8Lit("c"), S8Lit("cxx"),
      S8Lit("C"), S8Lit("h"), S8Lit("hpp"), S8Lit("glsl")
    };
    for(int i = 0; i < ArrayCount(extensions); i += 1)
    {
      F4_RegisterLanguage(extensions[i],
                          F4_CPP_IndexFile,
                          lex_full_input_cpp_init,
                          lex_full_input_cpp_breaks,
                          F4_CPP_PosContext,
                          F4_CPP_Highlight,
                          Lex_State_Cpp);
    }
  }
  
  // NOTE(rjf): Jai
  {
    F4_RegisterLanguage(S8Lit("jai"),
                        F4_Jai_IndexFile,
                        lex_full_input_jai_init,
                        lex_full_input_jai_breaks,
                        F4_Jai_PosContext,
                        F4_Jai_Highlight,
                        Lex_State_Jai);
  }
  
  // NOTE(fakhri): Odin
  {
    F4_RegisterLanguage(S8Lit("odin"),
                        F4_Odin_IndexFile,
                        lex_full_input_odin_init,
                        lex_full_input_odin_breaks,
                        F4_Odin_PosContext,
                        F4_Odin_Highlight,
                        Lex_State_Odin);
  }
  
  // NOTE(fakhri): Zig
  {
    F4_RegisterLanguage(S8Lit("zig"),
                        F4_Zig_IndexFile,
                        lex_full_input_zig_init,
                        lex_full_input_zig_breaks,
                        F4_Zig_PosContext,
                        F4_Zig_Highlight,
                        Lex_State_Zig);
  }
  
  // NOTE(fakhri): Rust
  {
    String_Const_u8 extensions[] =
    {
      S8Lit("rs"), S8Lit("rlib")
    };
    
    for(int i = 0; i < ArrayCount(extensions); i += 1)
    {
      
      F4_RegisterLanguage(extensions[i],
                          F4_Rust_IndexFile,
                          lex_full_input_rust_init,
                          lex_full_input_rust_breaks,
                          F4_Rust_PosContext,
                          F4_Rust_Highlight,
                          Lex_State_Rust);
      
    }
  }
  
  // NOTE(rjf): Metadesk
  {
    String_Const_u8 extensions[] =
    {
      // TODO(rjf): Maybe find a config-driven way to specify these? "mc" was sort of
      // introduced ad-hoc...
      S8Lit("md"), S8Lit("mc"), S8Lit("metacode"), S8Lit("meta"), S8Lit("metadesk"),
    };
    for(int i = 0; i < ArrayCount(extensions); i += 1)
    {
      F4_RegisterLanguage(extensions[i],
                          F4_MD_IndexFile,
                          lex_full_input_cpp_init,
                          lex_full_input_cpp_breaks,
                          F4_MD_PosContext,
                          F4_MD_Highlight,
                          Lex_State_Cpp);
    }
  }
}

#endif //FCODER_FLEURY_LANG_LIST_H
