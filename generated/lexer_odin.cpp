#if !defined(FCODER_LEX_GEN_HAND_WRITTEN)
#define FCODER_LEX_GEN_HAND_WRITTEN

internal u64
lexeme_hash(u64 seed, u8 *ptr, u64 size){
    u64 result = 0;
    for (u64 i = 0; i < size; i += 1, ptr += 1){
        result ^= ((*ptr) ^ result*59) + seed;
    }
    return(result);
}

internal Lexeme_Table_Lookup
lexeme_table_lookup(u64 *hash_array, String_Const_u8 *key_array, 
                    Lexeme_Table_Value *value_array, i32 slot_count, u64 seed,
                    u8 *ptr, u64 size){
    Lexeme_Table_Lookup result = {};
    u64 hash = lexeme_hash(seed, ptr, size);
    u64 comparison_hash = hash | 1;
    i32 first_index = (hash % slot_count);
    i32 index = first_index;
    for (;;){
        if (hash_array[index] == comparison_hash){
            if (string_match(SCu8(ptr, size), key_array[index])){
                result.found_match = true;
                result.base_kind = value_array[index].base_kind;
                result.sub_kind = value_array[index].sub_kind;
                break;
            }
        }
        else if (hash_array[index] == 0){
            break;
        }
        index += 1;
        if (index == slot_count){
            index = 0;
        }
        if (index == first_index){
            break;
        }
    }
    return(result);
}

#endif
u64 odin_main_keys_hash_array[287] = {
0x1dd89d38cc79d2af,0x0000000000000000,0xbcc345dca7988aab,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x148c8aef7e7683af,0xb6e688937ee31867,
0x0000000000000000,0x827d19e0dfa5a6a3,0x78d0e720125da5ff,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x1dd89d5ad70dc867,
0x148c8aef7df4bf79,0xb6e688870d03524d,0x0000000000000000,0x78d060dd62195cbd,
0x148c8aef7d90d5bb,0x24f9f810575b0373,0x0000000000000000,0x0000000000000000,
0x540c2b81420d14cd,0x540c2b81636659ad,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x1dd89dba15c28b63,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x540c2b816015f8b9,0xb6e6888dc7b2aafb,
0x0000000000000000,0xb6e6889217a9815f,0x0000000000000000,0x827d19e0dfa6f29d,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x540c2b816d6c7c75,0x0000000000000000,0x0000000000000000,
0x540c2b81421f6319,0x1dd89dee259cdb53,0x24be31b79ded0f79,0x0000000000000000,
0x0000000000000000,0x148c8aef7e6a6feb,0x24ba01d6e8c1b0cd,0x0000000000000000,
0x0000000000000000,0x78d1a6543a40413d,0x540c2b8173d2cd87,0xb6e6888dd2794ecb,
0xb6e6888fa7476d61,0x0000000000000000,0x0000000000000000,0xb6e68891abe4aad9,
0x1c41dc7052021f47,0x0000000000000000,0x78d03ba90858752f,0x0000000000000000,
0x540c2b81600aa5b9,0x0000000000000000,0x827d19e0dfa417cb,0x72a80229735b0f0f,
0x148c8aef7dcf0f97,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x148c8aef7db9d5a9,0xb9def3ca10b1360f,0xb9def3ca10b121e1,0x72a80229735b1393,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x827d19e0dfa6f62b,0x540c2b81717dd57f,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x1dd89ec412b9cc0d,0x0000000000000000,0x148c8aef7db7fedf,0x0000000000000000,
0xbb67d79854a6069b,0x0000000000000000,0x7960659604533fc7,0x540c2b816f75deb9,
0x540c2b81606ca36f,0x540c2b81685482ad,0x0000000000000000,0x827d19e0dfa69ecb,
0x0000000000000000,0x0000000000000000,0xb6e6888fb9a202bd,0x148c8aef7da89a47,
0x0000000000000000,0x78d0456faae4eb75,0x0000000000000000,0x0000000000000000,
0xa4c4118b0a2016cb,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x78d1bb9ea27ac683,0x72a80229735b0d01,
0x148c8aef7da89a55,0x2ca98c6d5a3d5f47,0x1dd89c64a3372311,0x0000000000000000,
0x0000000000000000,0x78d19ff0e4aa0ff1,0x827d19e0dfa41921,0x24be016f6164ed61,
0x0000000000000000,0x0000000000000000,0xb6e68893708e15ff,0x827d19e0dfa64ad1,
0x1dd89e8bc889721d,0x1dd89eab41f06379,0x0000000000000000,0x0000000000000000,
0x148c8aef7dfccc8b,0x0000000000000000,0x148c8aef7df4a2d5,0x0000000000000000,
0x540c2b81605207d5,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xdf5eb454c00158c7,0x0000000000000000,0xde4109155364c54f,0x0000000000000000,
0xb6e688870d0352d9,0x1dd89ec2938bd9d5,0x827d19e0dfa6442b,0x827d19e0dfa6f66d,
0x0000000000000000,0x540c2b816f8e686d,0x78d011558d71a6b1,0x540c2b8163665919,
0xbf8ca5781a9058c7,0x0000000000000000,0x0000000000000000,0xb6e688937ef08d07,
0x540c2b81420d18b9,0x148c8aef7db5d8ad,0x24ba01d6e8c1bfcb,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x827d19e0dfa6f67d,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x148c8aef7dc1cb0f,
0x1dd89be7f8ea9da1,0x827d19e0dfa65bcd,0x0000000000000000,0x72a80229735b0d39,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x827d19e0dfa6b6a3,0x0000000000000000,0xb6e6888dd3d7d161,0x540c2b816f8e57b9,
0x540c2b8142f51fb9,0x78d06bd96e19d299,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x827d19e0dfa6f8d1,0x0000000000000000,0x1dd89dbb39807c59,
0x1dd89be7f8e13479,0x540c2b8147108111,0x72a80229735b0d4b,0x540c2b8165614e6d,
0x0000000000000000,0x0000000000000000,0x827d19e0dfa69bcd,0x1dd89d753a81b975,
0x540c2b8142f51c6d,0x148c8aef7daf42b5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x24f90a6836571b47,0xb6e6888e1f01c6cb,
0x540c2b8168548319,0x24a19e4a032d3615,0xb6e68891abe4aa4d,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xb6e688937effb1ff,0x540c2b8147b04727,0x0000000000000000,0x0000000000000000,
0x78d011bfda226385,0xb6e68892e513f3b9,0x0000000000000000,0x0000000000000000,
0x827d19e0dfa4108d,0x148c8aef7e7541b1,0x78d063096664e9ff,0x540c2b81421f62ad,
0x0000000000000000,0x0000000000000000,0x540c2b81716ce6cb,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x1dd89d146a2fde67,
0x0000000000000000,0x0000000000000000,0xb6e6888f1006cf35,0x827d19e0dfa5a78f,
0xb6e68893c10da921,0x0000000000000000,0x540c2b816f75dacd,0x24a33c2754dcaaf9,
0x540c2b81600aa0cd,0x0000000000000000,0x540c2b8174fc46cb,0xb6e6889113e882f9,
0x827d19e0dfa698a1,0x0000000000000000,0x78d06b9251b152ad,0x0000000000000000,
0x0000000000000000,0xb6e688901bcfd4cd,0xb6e688937c731563,0x24f97a999964dea7,
0x1dd89d3ccc6e0b8f,0xb6e6888721aa6507,0x0000000000000000,0x0000000000000000,
0x1dd89dbb398010ff,0x0000000000000000,0x24c0df3216f71185,0x0000000000000000,
0x827d19e0dfa4188d,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x148c8aef7ddcea5f,0x827d19e0dfa64a3d,0x827d19e0dfa6836b,0x148c8aef7e774a0f,
0x0000000000000000,0x0000000000000000,0x72a80229735b0fdb,0x0000000000000000,
0x540c2b816015fbed,0x0000000000000000,0x540c2b817170c963,
};
u8 odin_main_keys_key_array_0[] = {0x76,0x69,0x72,0x74,0x75,0x61,0x6c,};
u8 odin_main_keys_key_array_2[] = {0x71,0x75,0x61,0x74,0x65,0x72,0x6e,0x69,0x6f,0x6e,0x36,0x34,};
u8 odin_main_keys_key_array_6[] = {0x74,0x68,0x69,0x73,};
u8 odin_main_keys_key_array_7[] = {0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_9[] = {0x6e,0x65,0x77,};
u8 odin_main_keys_key_array_10[] = {0x75,0x6e,0x73,0x69,0x67,0x6e,0x65,0x64,};
u8 odin_main_keys_key_array_15[] = {0x62,0x69,0x74,0x5f,0x73,0x65,0x74,};
u8 odin_main_keys_key_array_16[] = {0x65,0x6e,0x75,0x6d,};
u8 odin_main_keys_key_array_17[] = {0x75,0x31,0x32,0x38,0x6c,0x65,};
u8 odin_main_keys_key_array_19[] = {0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,};
u8 odin_main_keys_key_array_20[] = {0x70,0x72,0x6f,0x63,};
u8 odin_main_keys_key_array_21[] = {0x62,0x69,0x74,0x5f,0x66,0x69,0x65,0x6c,0x64,};
u8 odin_main_keys_key_array_24[] = {0x75,0x33,0x32,0x6c,0x65,};
u8 odin_main_keys_key_array_25[] = {0x66,0x36,0x34,0x6c,0x65,};
u8 odin_main_keys_key_array_32[] = {0x64,0x65,0x66,0x61,0x75,0x6c,0x74,};
u8 odin_main_keys_key_array_38[] = {0x66,0x31,0x36,0x62,0x65,};
u8 odin_main_keys_key_array_39[] = {0x66,0x72,0x69,0x65,0x6e,0x64,};
u8 odin_main_keys_key_array_41[] = {0x70,0x75,0x62,0x6c,0x69,0x63,};
u8 odin_main_keys_key_array_43[] = {0x61,0x73,0x6d,};
u8 odin_main_keys_key_array_53[] = {0x77,0x68,0x69,0x6c,0x65,};
u8 odin_main_keys_key_array_56[] = {0x75,0x36,0x34,0x62,0x65,};
u8 odin_main_keys_key_array_57[] = {0x63,0x6f,0x6e,0x74,0x65,0x78,0x74,};
u8 odin_main_keys_key_array_58[] = {0x6f,0x66,0x66,0x73,0x65,0x74,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_61[] = {0x75,0x69,0x6e,0x74,};
u8 odin_main_keys_key_array_62[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,0x33,0x32,};
u8 odin_main_keys_key_array_65[] = {0x6f,0x70,0x65,0x72,0x61,0x74,0x6f,0x72,};
u8 odin_main_keys_key_array_66[] = {0x62,0x72,0x65,0x61,0x6b,};
u8 odin_main_keys_key_array_67[] = {0x65,0x78,0x70,0x6f,0x72,0x74,};
u8 odin_main_keys_key_array_68[] = {0x72,0x65,0x74,0x75,0x72,0x6e,};
u8 odin_main_keys_key_array_71[] = {0x69,0x31,0x32,0x38,0x62,0x65,};
u8 odin_main_keys_key_array_72[] = {0x73,0x74,0x61,0x74,0x69,0x63,0x5f,0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_74[] = {0x65,0x78,0x70,0x6c,0x69,0x63,0x69,0x74,};
u8 odin_main_keys_key_array_76[] = {0x66,0x33,0x32,0x62,0x65,};
u8 odin_main_keys_key_array_78[] = {0x75,0x36,0x34,};
u8 odin_main_keys_key_array_79[] = {0x62,0x38,};
u8 odin_main_keys_key_array_80[] = {0x6c,0x6f,0x6e,0x67,};
u8 odin_main_keys_key_array_84[] = {0x77,0x68,0x65,0x6e,};
u8 odin_main_keys_key_array_85[] = {0x71,0x75,0x61,0x74,0x65,0x72,0x6e,0x69,0x6f,0x6e,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_86[] = {0x71,0x75,0x61,0x74,0x65,0x72,0x6e,0x69,0x6f,0x6e,0x32,0x35,0x36,};
u8 odin_main_keys_key_array_87[] = {0x75,0x38,};
u8 odin_main_keys_key_array_93[] = {0x62,0x36,0x34,};
u8 odin_main_keys_key_array_94[] = {0x63,0x6f,0x6e,0x73,0x74,};
u8 odin_main_keys_key_array_100[] = {0x70,0x61,0x63,0x6b,0x61,0x67,0x65,};
u8 odin_main_keys_key_array_102[] = {0x76,0x6f,0x69,0x64,};
u8 odin_main_keys_key_array_104[] = {0x66,0x61,0x6c,0x6c,0x74,0x68,0x72,0x6f,0x75,0x67,0x68,};
u8 odin_main_keys_key_array_106[] = {0x74,0x68,0x72,0x65,0x61,0x64,0x5f,0x6c,0x6f,0x63,0x61,0x6c,};
u8 odin_main_keys_key_array_107[] = {0x69,0x33,0x32,0x62,0x65,};
u8 odin_main_keys_key_array_108[] = {0x66,0x6c,0x6f,0x61,0x74,};
u8 odin_main_keys_key_array_109[] = {0x69,0x36,0x34,0x6c,0x65,};
u8 odin_main_keys_key_array_111[] = {0x69,0x36,0x34,};
u8 odin_main_keys_key_array_114[] = {0x72,0x61,0x77,0x70,0x74,0x72,};
u8 odin_main_keys_key_array_115[] = {0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_117[] = {0x76,0x6f,0x6c,0x61,0x74,0x69,0x6c,0x65,};
u8 odin_main_keys_key_array_120[] = {0x73,0x74,0x61,0x74,0x69,0x63,0x5f,0x61,0x73,0x73,0x65,0x72,0x74,};
u8 odin_main_keys_key_array_126[] = {0x6e,0x6f,0x65,0x78,0x63,0x65,0x70,0x74,};
u8 odin_main_keys_key_array_127[] = {0x69,0x66,};
u8 odin_main_keys_key_array_128[] = {0x63,0x61,0x73,0x65,};
u8 odin_main_keys_key_array_129[] = {0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_130[] = {0x66,0x6f,0x72,0x65,0x69,0x67,0x6e,};
u8 odin_main_keys_key_array_133[] = {0x63,0x6f,0x6e,0x74,0x69,0x6e,0x75,0x65,};
u8 odin_main_keys_key_array_134[] = {0x75,0x31,0x36,};
u8 odin_main_keys_key_array_135[] = {0x6f,0x72,0x5f,0x72,0x65,0x74,0x75,0x72,0x6e,};
u8 odin_main_keys_key_array_138[] = {0x73,0x69,0x67,0x6e,0x65,0x64,};
u8 odin_main_keys_key_array_139[] = {0x66,0x31,0x36,};
u8 odin_main_keys_key_array_140[] = {0x6e,0x75,0x6c,0x6c,0x70,0x74,0x72,};
u8 odin_main_keys_key_array_141[] = {0x73,0x69,0x7a,0x65,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_144[] = {0x67,0x6f,0x74,0x6f,};
u8 odin_main_keys_key_array_146[] = {0x65,0x6c,0x73,0x65,};
u8 odin_main_keys_key_array_148[] = {0x66,0x61,0x6c,0x73,0x65,};
u8 odin_main_keys_key_array_152[] = {0x63,0x6f,0x6e,0x73,0x74,0x5f,0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_154[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_156[] = {0x75,0x31,0x32,0x38,0x62,0x65,};
u8 odin_main_keys_key_array_157[] = {0x6f,0x72,0x5f,0x65,0x6c,0x73,0x65,};
u8 odin_main_keys_key_array_158[] = {0x66,0x36,0x34,};
u8 odin_main_keys_key_array_159[] = {0x61,0x6e,0x79,};
u8 odin_main_keys_key_array_161[] = {0x69,0x31,0x36,0x6c,0x65,};
u8 odin_main_keys_key_array_162[] = {0x74,0x79,0x70,0x65,0x6e,0x61,0x6d,0x65,};
u8 odin_main_keys_key_array_163[] = {0x66,0x36,0x34,0x62,0x65,};
u8 odin_main_keys_key_array_164[] = {0x72,0x65,0x69,0x6e,0x74,0x65,0x72,0x70,0x72,0x65,0x74,0x5f,0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_167[] = {0x73,0x74,0x72,0x75,0x63,0x74,};
u8 odin_main_keys_key_array_168[] = {0x75,0x33,0x32,0x62,0x65,};
u8 odin_main_keys_key_array_169[] = {0x63,0x68,0x61,0x72,};
u8 odin_main_keys_key_array_170[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,0x36,0x34,};
u8 odin_main_keys_key_array_175[] = {0x62,0x33,0x32,};
u8 odin_main_keys_key_array_179[] = {0x69,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_180[] = {0x74,0x79,0x70,0x65,0x64,0x65,0x66,};
u8 odin_main_keys_key_array_181[] = {0x66,0x6f,0x72,};
u8 odin_main_keys_key_array_183[] = {0x69,0x6e,};
u8 odin_main_keys_key_array_188[] = {0x6d,0x61,0x70,};
u8 odin_main_keys_key_array_190[] = {0x65,0x78,0x74,0x65,0x72,0x6e,};
u8 odin_main_keys_key_array_191[] = {0x69,0x31,0x36,0x62,0x65,};
u8 odin_main_keys_key_array_192[] = {0x75,0x31,0x36,0x62,0x65,};
u8 odin_main_keys_key_array_193[] = {0x61,0x6c,0x69,0x67,0x6e,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_197[] = {0x62,0x31,0x36,};
u8 odin_main_keys_key_array_199[] = {0x61,0x6c,0x69,0x67,0x6e,0x6f,0x66,};
u8 odin_main_keys_key_array_200[] = {0x74,0x79,0x70,0x65,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_201[] = {0x75,0x6e,0x69,0x6f,0x6e,};
u8 odin_main_keys_key_array_202[] = {0x69,0x38,};
u8 odin_main_keys_key_array_203[] = {0x64,0x65,0x66,0x65,0x72,};
u8 odin_main_keys_key_array_206[] = {0x69,0x33,0x32,};
u8 odin_main_keys_key_array_207[] = {0x70,0x72,0x69,0x76,0x61,0x74,0x65,};
u8 odin_main_keys_key_array_208[] = {0x75,0x31,0x36,0x6c,0x65,};
u8 odin_main_keys_key_array_209[] = {0x62,0x79,0x74,0x65,};
u8 odin_main_keys_key_array_214[] = {0x61,0x75,0x74,0x6f,0x5f,0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_215[] = {0x69,0x6d,0x70,0x6f,0x72,0x74,};
u8 odin_main_keys_key_array_216[] = {0x69,0x36,0x34,0x62,0x65,};
u8 odin_main_keys_key_array_217[] = {0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,};
u8 odin_main_keys_key_array_218[] = {0x69,0x31,0x32,0x38,0x6c,0x65,};
u8 odin_main_keys_key_array_224[] = {0x73,0x74,0x61,0x74,0x69,0x63,};
u8 odin_main_keys_key_array_225[] = {0x75,0x73,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_228[] = {0x74,0x65,0x6d,0x70,0x6c,0x61,0x74,0x65,};
u8 odin_main_keys_key_array_229[] = {0x6e,0x6f,0x74,0x5f,0x69,0x6e,};
u8 odin_main_keys_key_array_232[] = {0x74,0x72,0x79,};
u8 odin_main_keys_key_array_233[] = {0x74,0x72,0x75,0x65,};
u8 odin_main_keys_key_array_234[] = {0x64,0x69,0x73,0x74,0x69,0x6e,0x63,0x74,};
u8 odin_main_keys_key_array_235[] = {0x75,0x36,0x34,0x6c,0x65,};
u8 odin_main_keys_key_array_238[] = {0x63,0x6c,0x61,0x73,0x73,};
u8 odin_main_keys_key_array_243[] = {0x63,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_246[] = {0x64,0x65,0x6c,0x65,0x74,0x65,};
u8 odin_main_keys_key_array_247[] = {0x6e,0x69,0x6c,};
u8 odin_main_keys_key_array_248[] = {0x6f,0x70,0x61,0x71,0x75,0x65,};
u8 odin_main_keys_key_array_250[] = {0x69,0x33,0x32,0x6c,0x65,};
u8 odin_main_keys_key_array_251[] = {0x6e,0x6f,0x5f,0x69,0x6e,0x6c,0x69,0x6e,0x65,};
u8 odin_main_keys_key_array_252[] = {0x66,0x33,0x32,0x6c,0x65,};
u8 odin_main_keys_key_array_254[] = {0x73,0x68,0x6f,0x72,0x74,};
u8 odin_main_keys_key_array_255[] = {0x69,0x6e,0x6c,0x69,0x6e,0x65,};
u8 odin_main_keys_key_array_256[] = {0x69,0x31,0x36,};
u8 odin_main_keys_key_array_258[] = {0x64,0x65,0x63,0x6c,0x74,0x79,0x70,0x65,};
u8 odin_main_keys_key_array_261[] = {0x64,0x6f,0x75,0x62,0x6c,0x65,};
u8 odin_main_keys_key_array_262[] = {0x73,0x77,0x69,0x74,0x63,0x68,};
u8 odin_main_keys_key_array_263[] = {0x70,0x72,0x6f,0x74,0x65,0x63,0x74,0x65,0x64,};
u8 odin_main_keys_key_array_264[] = {0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,};
u8 odin_main_keys_key_array_265[] = {0x74,0x79,0x70,0x65,0x69,0x64,};
u8 odin_main_keys_key_array_268[] = {0x61,0x6c,0x69,0x67,0x6e,0x61,0x73,};
u8 odin_main_keys_key_array_270[] = {0x74,0x72,0x61,0x6e,0x73,0x6d,0x75,0x74,0x65,};
u8 odin_main_keys_key_array_272[] = {0x75,0x33,0x32,};
u8 odin_main_keys_key_array_276[] = {0x62,0x6f,0x6f,0x6c,};
u8 odin_main_keys_key_array_277[] = {0x66,0x33,0x32,};
u8 odin_main_keys_key_array_278[] = {0x69,0x6e,0x74,};
u8 odin_main_keys_key_array_279[] = {0x75,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_282[] = {0x64,0x6f,};
u8 odin_main_keys_key_array_284[] = {0x66,0x31,0x36,0x6c,0x65,};
u8 odin_main_keys_key_array_286[] = {0x63,0x61,0x74,0x63,0x68,};
String_Const_u8 odin_main_keys_key_array[287] = {
{odin_main_keys_key_array_0, 7},
{0, 0},
{odin_main_keys_key_array_2, 12},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_6, 4},
{odin_main_keys_key_array_7, 6},
{0, 0},
{odin_main_keys_key_array_9, 3},
{odin_main_keys_key_array_10, 8},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_15, 7},
{odin_main_keys_key_array_16, 4},
{odin_main_keys_key_array_17, 6},
{0, 0},
{odin_main_keys_key_array_19, 8},
{odin_main_keys_key_array_20, 4},
{odin_main_keys_key_array_21, 9},
{0, 0},
{0, 0},
{odin_main_keys_key_array_24, 5},
{odin_main_keys_key_array_25, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_32, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_38, 5},
{odin_main_keys_key_array_39, 6},
{0, 0},
{odin_main_keys_key_array_41, 6},
{0, 0},
{odin_main_keys_key_array_43, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_53, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_56, 5},
{odin_main_keys_key_array_57, 7},
{odin_main_keys_key_array_58, 9},
{0, 0},
{0, 0},
{odin_main_keys_key_array_61, 4},
{odin_main_keys_key_array_62, 9},
{0, 0},
{0, 0},
{odin_main_keys_key_array_65, 8},
{odin_main_keys_key_array_66, 5},
{odin_main_keys_key_array_67, 6},
{odin_main_keys_key_array_68, 6},
{0, 0},
{0, 0},
{odin_main_keys_key_array_71, 6},
{odin_main_keys_key_array_72, 11},
{0, 0},
{odin_main_keys_key_array_74, 8},
{0, 0},
{odin_main_keys_key_array_76, 5},
{0, 0},
{odin_main_keys_key_array_78, 3},
{odin_main_keys_key_array_79, 2},
{odin_main_keys_key_array_80, 4},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_84, 4},
{odin_main_keys_key_array_85, 13},
{odin_main_keys_key_array_86, 13},
{odin_main_keys_key_array_87, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_93, 3},
{odin_main_keys_key_array_94, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_100, 7},
{0, 0},
{odin_main_keys_key_array_102, 4},
{0, 0},
{odin_main_keys_key_array_104, 11},
{0, 0},
{odin_main_keys_key_array_106, 12},
{odin_main_keys_key_array_107, 5},
{odin_main_keys_key_array_108, 5},
{odin_main_keys_key_array_109, 5},
{0, 0},
{odin_main_keys_key_array_111, 3},
{0, 0},
{0, 0},
{odin_main_keys_key_array_114, 6},
{odin_main_keys_key_array_115, 4},
{0, 0},
{odin_main_keys_key_array_117, 8},
{0, 0},
{0, 0},
{odin_main_keys_key_array_120, 13},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_126, 8},
{odin_main_keys_key_array_127, 2},
{odin_main_keys_key_array_128, 4},
{odin_main_keys_key_array_129, 12},
{odin_main_keys_key_array_130, 7},
{0, 0},
{0, 0},
{odin_main_keys_key_array_133, 8},
{odin_main_keys_key_array_134, 3},
{odin_main_keys_key_array_135, 9},
{0, 0},
{0, 0},
{odin_main_keys_key_array_138, 6},
{odin_main_keys_key_array_139, 3},
{odin_main_keys_key_array_140, 7},
{odin_main_keys_key_array_141, 7},
{0, 0},
{0, 0},
{odin_main_keys_key_array_144, 4},
{0, 0},
{odin_main_keys_key_array_146, 4},
{0, 0},
{odin_main_keys_key_array_148, 5},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_152, 10},
{0, 0},
{odin_main_keys_key_array_154, 10},
{0, 0},
{odin_main_keys_key_array_156, 6},
{odin_main_keys_key_array_157, 7},
{odin_main_keys_key_array_158, 3},
{odin_main_keys_key_array_159, 3},
{0, 0},
{odin_main_keys_key_array_161, 5},
{odin_main_keys_key_array_162, 8},
{odin_main_keys_key_array_163, 5},
{odin_main_keys_key_array_164, 16},
{0, 0},
{0, 0},
{odin_main_keys_key_array_167, 6},
{odin_main_keys_key_array_168, 5},
{odin_main_keys_key_array_169, 4},
{odin_main_keys_key_array_170, 9},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_175, 3},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_179, 4},
{odin_main_keys_key_array_180, 7},
{odin_main_keys_key_array_181, 3},
{0, 0},
{odin_main_keys_key_array_183, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_188, 3},
{0, 0},
{odin_main_keys_key_array_190, 6},
{odin_main_keys_key_array_191, 5},
{odin_main_keys_key_array_192, 5},
{odin_main_keys_key_array_193, 8},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_197, 3},
{0, 0},
{odin_main_keys_key_array_199, 7},
{odin_main_keys_key_array_200, 7},
{odin_main_keys_key_array_201, 5},
{odin_main_keys_key_array_202, 2},
{odin_main_keys_key_array_203, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_206, 3},
{odin_main_keys_key_array_207, 7},
{odin_main_keys_key_array_208, 5},
{odin_main_keys_key_array_209, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_214, 9},
{odin_main_keys_key_array_215, 6},
{odin_main_keys_key_array_216, 5},
{odin_main_keys_key_array_217, 9},
{odin_main_keys_key_array_218, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_224, 6},
{odin_main_keys_key_array_225, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_228, 8},
{odin_main_keys_key_array_229, 6},
{0, 0},
{0, 0},
{odin_main_keys_key_array_232, 3},
{odin_main_keys_key_array_233, 4},
{odin_main_keys_key_array_234, 8},
{odin_main_keys_key_array_235, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_238, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_243, 7},
{0, 0},
{0, 0},
{odin_main_keys_key_array_246, 6},
{odin_main_keys_key_array_247, 3},
{odin_main_keys_key_array_248, 6},
{0, 0},
{odin_main_keys_key_array_250, 5},
{odin_main_keys_key_array_251, 9},
{odin_main_keys_key_array_252, 5},
{0, 0},
{odin_main_keys_key_array_254, 5},
{odin_main_keys_key_array_255, 6},
{odin_main_keys_key_array_256, 3},
{0, 0},
{odin_main_keys_key_array_258, 8},
{0, 0},
{0, 0},
{odin_main_keys_key_array_261, 6},
{odin_main_keys_key_array_262, 6},
{odin_main_keys_key_array_263, 9},
{odin_main_keys_key_array_264, 7},
{odin_main_keys_key_array_265, 6},
{0, 0},
{0, 0},
{odin_main_keys_key_array_268, 7},
{0, 0},
{odin_main_keys_key_array_270, 9},
{0, 0},
{odin_main_keys_key_array_272, 3},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_276, 4},
{odin_main_keys_key_array_277, 3},
{odin_main_keys_key_array_278, 3},
{odin_main_keys_key_array_279, 4},
{0, 0},
{0, 0},
{odin_main_keys_key_array_282, 2},
{0, 0},
{odin_main_keys_key_array_284, 5},
{0, 0},
{odin_main_keys_key_array_286, 5},
};
Lexeme_Table_Value odin_main_keys_value_array[287] = {
{4, TokenOdinKind_Virtual},
{0, 0},
{4, TokenOdinKind_quaternion64},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_This},
{4, TokenOdinKind_string},
{0, 0},
{4, TokenOdinKind_New},
{4, TokenOdinKind_Unsigned},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_bit_set},
{4, TokenOdinKind_Enum},
{4, TokenOdinKind_u128le},
{0, 0},
{4, TokenOdinKind_Register},
{4, TokenOdinKind_proc},
{4, TokenOdinKind_bit_field},
{0, 0},
{0, 0},
{4, TokenOdinKind_u32le},
{4, TokenOdinKind_f64le},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_Default},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_f16be},
{4, TokenOdinKind_Friend},
{0, 0},
{4, TokenOdinKind_Public},
{0, 0},
{4, TokenOdinKind_Asm},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_While},
{0, 0},
{0, 0},
{4, TokenOdinKind_u64be},
{4, TokenOdinKind_context},
{4, TokenOdinKind_offset_of},
{0, 0},
{0, 0},
{4, TokenOdinKind_uint},
{4, TokenOdinKind_complex32},
{0, 0},
{0, 0},
{4, TokenOdinKind_Operator},
{4, TokenOdinKind_Break},
{4, TokenOdinKind_Export},
{4, TokenOdinKind_Return},
{0, 0},
{0, 0},
{4, TokenOdinKind_i128be},
{4, TokenOdinKind_StaticCast},
{0, 0},
{4, TokenOdinKind_Explicit},
{0, 0},
{4, TokenOdinKind_f32be},
{0, 0},
{4, TokenOdinKind_u64},
{4, TokenOdinKind_b8},
{4, TokenOdinKind_Long},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_when},
{4, TokenOdinKind_quaternion128},
{4, TokenOdinKind_quaternion256},
{4, TokenOdinKind_u8},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_b64},
{4, TokenOdinKind_Const},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_package},
{0, 0},
{4, TokenOdinKind_Void},
{0, 0},
{4, TokenOdinKind_fallthrough},
{0, 0},
{4, TokenOdinKind_ThreadLocal},
{4, TokenOdinKind_i32be},
{4, TokenOdinKind_Float},
{4, TokenOdinKind_i64le},
{0, 0},
{4, TokenOdinKind_i64},
{0, 0},
{0, 0},
{4, TokenOdinKind_rawptr},
{4, TokenOdinKind_cast},
{0, 0},
{4, TokenOdinKind_Volatile},
{0, 0},
{0, 0},
{4, TokenOdinKind_StaticAssert},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_NoExcept},
{4, TokenOdinKind_If},
{4, TokenOdinKind_Case},
{4, TokenOdinKind_DynamicCast},
{4, TokenOdinKind_foreign},
{0, 0},
{0, 0},
{4, TokenOdinKind_Continue},
{4, TokenOdinKind_u16},
{4, TokenOdinKind_or_return},
{0, 0},
{0, 0},
{4, TokenOdinKind_Signed},
{4, TokenOdinKind_f16},
{4, TokenOdinKind_NullPtr},
{4, TokenOdinKind_size_of},
{0, 0},
{0, 0},
{4, TokenOdinKind_Goto},
{0, 0},
{4, TokenOdinKind_Else},
{0, 0},
{8, TokenOdinKind_LiteralFalse},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_ConstCast},
{0, 0},
{4, TokenOdinKind_complex128},
{0, 0},
{4, TokenOdinKind_u128be},
{4, TokenOdinKind_or_else},
{4, TokenOdinKind_f64},
{4, TokenOdinKind_any},
{0, 0},
{4, TokenOdinKind_i16le},
{4, TokenOdinKind_Typename},
{4, TokenOdinKind_f64be},
{4, TokenOdinKind_ReinterpretCast},
{0, 0},
{0, 0},
{4, TokenOdinKind_Struct},
{4, TokenOdinKind_u32be},
{4, TokenOdinKind_Char},
{4, TokenOdinKind_complex64},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_b32},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_i128},
{4, TokenOdinKind_Typedef},
{4, TokenOdinKind_For},
{0, 0},
{4, TokenOdinKind_in},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_map},
{0, 0},
{4, TokenOdinKind_Extern},
{4, TokenOdinKind_i16be},
{4, TokenOdinKind_u16be},
{4, TokenOdinKind_align_of},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_b16},
{0, 0},
{4, TokenOdinKind_AlignOf},
{4, TokenOdinKind_type_of},
{4, TokenOdinKind_Union},
{4, TokenOdinKind_i8},
{4, TokenOdinKind_defer},
{0, 0},
{0, 0},
{4, TokenOdinKind_i32},
{4, TokenOdinKind_Private},
{4, TokenOdinKind_u16le},
{4, TokenOdinKind_byte},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_auto_cast},
{4, TokenOdinKind_import},
{4, TokenOdinKind_i64be},
{4, TokenOdinKind_Namespace},
{4, TokenOdinKind_i128le},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_Static},
{4, TokenOdinKind_Using},
{0, 0},
{0, 0},
{4, TokenOdinKind_Template},
{4, TokenOdinKind_not_in},
{0, 0},
{0, 0},
{4, TokenOdinKind_Try},
{8, TokenOdinKind_LiteralTrue},
{4, TokenOdinKind_distinct},
{4, TokenOdinKind_u64le},
{0, 0},
{0, 0},
{4, TokenOdinKind_Class},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_cstring},
{0, 0},
{0, 0},
{4, TokenOdinKind_Delete},
{4, TokenOdinKind_nil},
{4, TokenOdinKind_opaque},
{0, 0},
{4, TokenOdinKind_i32le},
{4, TokenOdinKind_no_inline},
{4, TokenOdinKind_f32le},
{0, 0},
{4, TokenOdinKind_Short},
{4, TokenOdinKind_Inline},
{4, TokenOdinKind_i16},
{0, 0},
{4, TokenOdinKind_DeclType},
{0, 0},
{0, 0},
{4, TokenOdinKind_Double},
{4, TokenOdinKind_Switch},
{4, TokenOdinKind_Protected},
{4, TokenOdinKind_dynamic},
{4, TokenOdinKind_TypeID},
{0, 0},
{0, 0},
{4, TokenOdinKind_AlignAs},
{0, 0},
{4, TokenOdinKind_transmute},
{0, 0},
{4, TokenOdinKind_u32},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_Bool},
{4, TokenOdinKind_f32},
{4, TokenOdinKind_Int},
{4, TokenOdinKind_u128},
{0, 0},
{0, 0},
{4, TokenOdinKind_Do},
{0, 0},
{4, TokenOdinKind_f16le},
{0, 0},
{4, TokenOdinKind_Catch},
};
i32 odin_main_keys_slot_count = 287;
u64 odin_main_keys_seed = 0x841c9c3c170181fb;
u64 odin_pp_directives_hash_array[25] = {
0x0000000000000000,0x1a32255f1c165b61,0xdc4750b447b1535b,0x11a65c15d39d1e9b,
0x0000000000000000,0x0000000000000000,0x7b5a7a709e97c2bb,0x1a32255f6eb462bb,
0x0000000000000000,0x0000000000000000,0x02fb492f4e500893,0x11a65c021e3b5e97,
0x11a65c15c7cffb37,0x0000000000000000,0x11a65c16795657ad,0x1a32255f1cfc859b,
0x0000000000000000,0xdc4750b4480d4e17,0xdc4750b4480d4d51,0x0000000000000000,
0x02fb4973ffa7f98f,0x1a32255f6ea0fbcb,0x0000000000000000,0x1a32255f1f13e51b,
0xdc4750b447b152c1,
};
u8 odin_pp_directives_key_array_1[] = {0x75,0x73,0x69,0x6e,0x67,};
u8 odin_pp_directives_key_array_2[] = {0x65,0x6c,0x69,0x66,};
u8 odin_pp_directives_key_array_3[] = {0x69,0x66,0x6e,0x64,0x65,0x66,};
u8 odin_pp_directives_key_array_6[] = {0x69,0x66,};
u8 odin_pp_directives_key_array_7[] = {0x65,0x6e,0x64,0x69,0x66,};
u8 odin_pp_directives_key_array_10[] = {0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,};
u8 odin_pp_directives_key_array_11[] = {0x64,0x65,0x66,0x69,0x6e,0x65,};
u8 odin_pp_directives_key_array_12[] = {0x69,0x6d,0x70,0x6f,0x72,0x74,};
u8 odin_pp_directives_key_array_14[] = {0x70,0x72,0x61,0x67,0x6d,0x61,};
u8 odin_pp_directives_key_array_15[] = {0x75,0x6e,0x64,0x65,0x66,};
u8 odin_pp_directives_key_array_17[] = {0x6c,0x69,0x6e,0x65,};
u8 odin_pp_directives_key_array_18[] = {0x6c,0x6f,0x61,0x64,};
u8 odin_pp_directives_key_array_20[] = {0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,};
u8 odin_pp_directives_key_array_21[] = {0x65,0x72,0x72,0x6f,0x72,};
u8 odin_pp_directives_key_array_23[] = {0x69,0x66,0x64,0x65,0x66,};
u8 odin_pp_directives_key_array_24[] = {0x65,0x6c,0x73,0x65,};
String_Const_u8 odin_pp_directives_key_array[25] = {
{0, 0},
{odin_pp_directives_key_array_1, 5},
{odin_pp_directives_key_array_2, 4},
{odin_pp_directives_key_array_3, 6},
{0, 0},
{0, 0},
{odin_pp_directives_key_array_6, 2},
{odin_pp_directives_key_array_7, 5},
{0, 0},
{0, 0},
{odin_pp_directives_key_array_10, 7},
{odin_pp_directives_key_array_11, 6},
{odin_pp_directives_key_array_12, 6},
{0, 0},
{odin_pp_directives_key_array_14, 6},
{odin_pp_directives_key_array_15, 5},
{0, 0},
{odin_pp_directives_key_array_17, 4},
{odin_pp_directives_key_array_18, 4},
{0, 0},
{odin_pp_directives_key_array_20, 7},
{odin_pp_directives_key_array_21, 5},
{0, 0},
{odin_pp_directives_key_array_23, 5},
{odin_pp_directives_key_array_24, 4},
};
Lexeme_Table_Value odin_pp_directives_value_array[25] = {
{0, 0},
{6, TokenOdinKind_PPUsing},
{6, TokenOdinKind_PPElIf},
{6, TokenOdinKind_PPIfNDef},
{0, 0},
{0, 0},
{6, TokenOdinKind_PPIf},
{6, TokenOdinKind_PPEndIf},
{0, 0},
{0, 0},
{6, TokenOdinKind_PPVersion},
{6, TokenOdinKind_PPDefine},
{6, TokenOdinKind_PPImport},
{0, 0},
{6, TokenOdinKind_PPPragma},
{6, TokenOdinKind_PPUndef},
{0, 0},
{6, TokenOdinKind_PPLine},
{6, TokenOdinKind_PPLoad},
{0, 0},
{6, TokenOdinKind_PPInclude},
{6, TokenOdinKind_PPError},
{0, 0},
{6, TokenOdinKind_PPIfDef},
{6, TokenOdinKind_PPElse},
};
i32 odin_pp_directives_slot_count = 25;
u64 odin_pp_directives_seed = 0x0205dc5ea3299202;
u64 odin_pp_keys_hash_array[2] = {
0x4d6cfacf849ec35b,0x0000000000000000,
};
u8 odin_pp_keys_key_array_0[] = {0x64,0x65,0x66,0x69,0x6e,0x65,0x64,};
String_Const_u8 odin_pp_keys_key_array[2] = {
{odin_pp_keys_key_array_0, 7},
{0, 0},
};
Lexeme_Table_Value odin_pp_keys_value_array[2] = {
{4, TokenOdinKind_PPDefined},
{0, 0},
};
i32 odin_pp_keys_slot_count = 2;
u64 odin_pp_keys_seed = 0x2d336a15f6527ffc;
struct Lex_State_Odin{
u32 flags_ZF0;
u32 flags_KF0;
u16 flags_ZB0;
u8 *base;
u8 *delim_first;
u8 *delim_one_past_last;
u8 *emit_ptr;
u8 *ptr;
u8 *opl_ptr;
};
internal void
lex_full_input_odin_init(Lex_State_Odin *state_ptr, String_Const_u8 input){
state_ptr->flags_ZF0 = 0;
state_ptr->flags_KF0 = 0;
state_ptr->flags_ZB0 = 0;
state_ptr->base = input.str;
state_ptr->delim_first = input.str;
state_ptr->delim_one_past_last = input.str;
state_ptr->emit_ptr = input.str;
state_ptr->ptr = input.str;
state_ptr->opl_ptr = input.str + input.size;
}
internal b32
lex_full_input_odin_breaks(Arena *arena, Token_List *list, Lex_State_Odin *state_ptr, u64 max){
b32 result = false;
u64 emit_counter = 0;
Lex_State_Odin state;
block_copy_struct(&state, state_ptr);
{
state_label_1: // root
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:
case 0x13:case 0x14:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:
case 0x1a:case 0x1b:case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x40:
case 0x60:case 0x7f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0b:case 0x0c:case 0x0d:case 0x20:
{
if ((HasFlag(state.flags_KF0, 0x2))){
state.ptr += 1;
goto state_label_4; // error_body
}
state.ptr += 1;
goto state_label_3; // whitespace
}break;
case 0x0a:
{
state.ptr += 1;
state.flags_ZB0 &= ~(0x1);
state.flags_KF0 &= ~(0x1);
state.flags_KF0 &= ~(0x2);
goto state_label_3; // whitespace
}break;
case 0x21:
{
state.ptr += 1;
goto state_label_59; // op stage
}break;
case 0x22:
{
if ((HasFlag(state.flags_KF0, 0x1))){
state.ptr += 1;
goto state_label_26; // include_quotes
}
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x23:
{
if ((!HasFlag(state.flags_ZB0, 0x1))){
state.ptr += 1;
goto state_label_23; // pp_directive_whitespace
}
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
case 0x25:
{
state.ptr += 1;
goto state_label_64; // op stage
}break;
case 0x26:
{
state.ptr += 1;
goto state_label_60; // op stage
}break;
case 0x27:
{
state.ptr += 1;
state.flags_ZF0 |= 0x40;
goto state_label_32; // string
}break;
case 0x28:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ParenOp;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x29:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ParenCl;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_63; // op stage
}break;
case 0x2b:
{
state.ptr += 1;
goto state_label_62; // op stage
}break;
case 0x2c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Comma;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2d:
{
state.ptr += 1;
goto state_label_54; // op stage
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_6; // operator_or_fnumber_dot
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_7; // operator_or_comment_slash
}break;
case 0x30:
{
state.ptr += 1;
goto state_label_9; // znumber
}break;
case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:
case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_8; // number
}break;
case 0x3a:
{
state.ptr += 1;
goto state_label_53; // op stage
}break;
case 0x3b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Semicolon;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
if ((!HasFlag(state.flags_KF0, 0x1))){
state.ptr += 1;
goto state_label_56; // op stage
}
state.ptr += 1;
goto state_label_25; // include_pointy
}break;
case 0x3d:
{
state.ptr += 1;
goto state_label_58; // op stage
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_57; // op stage
}break;
case 0x3f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Ternary;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:
{
state.ptr += 1;
state.flags_ZF0 |= 0x4;
goto state_label_27; // pre_L
}break;
case 0x52:
{
state.ptr += 1;
goto state_label_31; // pre_R
}break;
case 0x55:
{
state.ptr += 1;
state.flags_ZF0 |= 0x20;
goto state_label_29; // pre_U
}break;
case 0x5b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BrackOp;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x5c:
{
state.ptr += 1;
goto state_label_5; // backslash
}break;
case 0x5d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BrackCl;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x5e:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Xor;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x75:
{
state.ptr += 1;
state.flags_ZF0 |= 0x10;
goto state_label_28; // pre_u
}break;
case 0x7b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BraceOp;
token.kind = 11;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_61; // op stage
}break;
case 0x7d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BraceCl;
token.kind = 12;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x7e:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Tilde;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_2: // identifier
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZB0, 0x1)){
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_pp_keys_hash_array, odin_pp_keys_key_array, odin_pp_keys_value_array, odin_pp_keys_slot_count, odin_pp_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
}
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_main_keys_hash_array, odin_main_keys_key_array, odin_main_keys_value_array, odin_main_keys_slot_count, odin_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenOdinKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:
case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:case 0x13:case 0x14:
case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1a:case 0x1b:
case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x20:case 0x21:case 0x22:
case 0x23:case 0x25:case 0x26:case 0x27:case 0x28:case 0x29:case 0x2a:
case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x3a:case 0x3b:
case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5b:case 0x5c:
case 0x5d:case 0x5e:case 0x60:case 0x7b:case 0x7c:case 0x7d:case 0x7e:
case 0x7f:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZB0, 0x1)){
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_pp_keys_hash_array, odin_pp_keys_key_array, odin_pp_keys_value_array, odin_pp_keys_slot_count, odin_pp_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
}
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_main_keys_hash_array, odin_main_keys_key_array, odin_main_keys_value_array, odin_main_keys_slot_count, odin_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenOdinKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
}
}
{
state_label_3: // whitespace
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0b:case 0x0c:case 0x0d:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
case 0x0a:
{
state.ptr += 1;
state.flags_ZB0 &= ~(0x1);
state.flags_KF0 &= ~(0x1);
state.flags_KF0 &= ~(0x2);
goto state_label_3; // whitespace
}break;
}
}
{
state_label_4: // error_body
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_PPErrorMessage;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_4; // error_body
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_PPErrorMessage;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_5: // backslash
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Backslash;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Backslash;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x0a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Backslash;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x0d:
{
state.ptr += 1;
goto state_label_5; // backslash
}break;
}
}
{
state_label_6: // operator_or_fnumber_dot
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_DotStar;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_67; // op stage
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_10; // fnumber_decimal
}break;
}
}
{
state_label_7: // operator_or_comment_slash
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Div;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Div;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_49; // comment_block
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_51; // comment_line
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_DivEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_8: // number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_10; // fnumber_decimal
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_8; // number
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_11; // fnumber_exponent
}break;
case 0x4c:
{
state.ptr += 1;
goto state_label_18; // L_number
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
goto state_label_17; // U_number
}break;
case 0x6c:
{
state.ptr += 1;
goto state_label_20; // l_number
}break;
}
}
{
state_label_9: // znumber
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_10; // fnumber_decimal
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_16; // number_oct
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_11; // fnumber_exponent
}break;
case 0x4c:
{
state.ptr += 1;
goto state_label_18; // L_number
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
goto state_label_17; // U_number
}break;
case 0x58:case 0x78:
{
state.ptr += 1;
state.flags_ZF0 |= 0x1;
goto state_label_14; // number_hex_first
}break;
case 0x6c:
{
state.ptr += 1;
goto state_label_20; // l_number
}break;
}
}
{
state_label_10: // fnumber_decimal
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_10; // fnumber_decimal
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_11; // fnumber_exponent
}break;
case 0x46:case 0x66:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat32;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:case 0x6c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_11: // fnumber_exponent
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2b:case 0x2d:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_sign
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_13; // fnumber_exponent_digits
}break;
case 0x46:case 0x66:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat32;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:case 0x6c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_12: // fnumber_exponent_sign
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_13; // fnumber_exponent_digits
}break;
case 0x46:case 0x66:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat32;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:case 0x6c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_13: // fnumber_exponent_digits
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_13; // fnumber_exponent_digits
}break;
case 0x46:case 0x66:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat32;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:case 0x6c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat64;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_14: // number_hex_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_15; // number_hex
}break;
}
}
{
state_label_15: // number_hex
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_15; // number_hex
}break;
case 0x4c:
{
state.ptr += 1;
goto state_label_18; // L_number
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
goto state_label_17; // U_number
}break;
case 0x6c:
{
state.ptr += 1;
goto state_label_20; // l_number
}break;
}
}
{
state_label_16: // number_oct
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_16; // number_oct
}break;
case 0x4c:
{
state.ptr += 1;
goto state_label_18; // L_number
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
goto state_label_17; // U_number
}break;
case 0x6c:
{
state.ptr += 1;
goto state_label_20; // l_number
}break;
}
}
{
state_label_17: // U_number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexU;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctU;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerU;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexU;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctU;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerU;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:
{
state.ptr += 1;
goto state_label_19; // UL_number
}break;
case 0x6c:
{
state.ptr += 1;
goto state_label_21; // Ul_number
}break;
}
}
{
state_label_18: // L_number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:
{
state.ptr += 1;
goto state_label_22; // LL_number
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexUL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctUL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerUL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_19: // UL_number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexUL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctUL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerUL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexUL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctUL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerUL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x4c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexULL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctULL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerULL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_20: // l_number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexUL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctUL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerUL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x6c:
{
state.ptr += 1;
goto state_label_22; // LL_number
}break;
}
}
{
state_label_21: // Ul_number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexUL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctUL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerUL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexUL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctUL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerUL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x6c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexULL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctULL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerULL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_22: // LL_number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexLL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctLL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerLL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexLL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctLL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerLL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x55:case 0x75:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x1)){
token.sub_kind = TokenOdinKind_LiteralIntegerHexULL;
token.kind = 8;
break;
}
if (HasFlag(state.flags_ZF0, 0x2)){
token.sub_kind = TokenOdinKind_LiteralIntegerOctULL;
token.kind = 8;
break;
}
token.sub_kind = TokenOdinKind_LiteralIntegerULL;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_23: // pp_directive_whitespace
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0b:case 0x0c:case 0x20:
{
state.ptr += 1;
goto state_label_23; // pp_directive_whitespace
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:
case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:case 0x52:
case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:case 0x59:
case 0x5a:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:case 0x67:case 0x68:case 0x69:case 0x6a:case 0x6b:case 0x6c:
case 0x6d:case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:case 0x73:
case 0x74:case 0x75:case 0x76:case 0x77:case 0x78:case 0x79:case 0x7a:
{
state.delim_first = state.ptr;
state.flags_ZB0 |= 0x1;
state.ptr += 1;
goto state_label_24; // pp_directive
}break;
}
}
{
state_label_24: // pp_directive
if (state.ptr == state.opl_ptr){
if ((true)){
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_pp_directives_hash_array, odin_pp_directives_key_array, odin_pp_directives_value_array, odin_pp_directives_slot_count, odin_pp_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenOdinKind_PPUnknown;
token.kind = 2;
}while(0);
switch (token.sub_kind){
case TokenOdinKind_PPInclude:
{
state.flags_KF0 |= 0x1;
}break;
case TokenOdinKind_PPError:
{
state.flags_KF0 |= 0x2;
}break;
}
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_pp_directives_hash_array, odin_pp_directives_key_array, odin_pp_directives_value_array, odin_pp_directives_slot_count, odin_pp_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenOdinKind_PPUnknown;
token.kind = 2;
}while(0);
switch (token.sub_kind){
case TokenOdinKind_PPInclude:
{
state.flags_KF0 |= 0x1;
}break;
case TokenOdinKind_PPError:
{
state.flags_KF0 |= 0x2;
}break;
}
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:
case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:case 0x52:
case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:case 0x59:
case 0x5a:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:case 0x67:case 0x68:case 0x69:case 0x6a:case 0x6b:case 0x6c:
case 0x6d:case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:case 0x73:
case 0x74:case 0x75:case 0x76:case 0x77:case 0x78:case 0x79:case 0x7a:
{
state.ptr += 1;
goto state_label_24; // pp_directive
}break;
}
}
{
state_label_25: // include_pointy
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x20:case 0x2e:case 0x2f:case 0x30:case 0x31:case 0x32:case 0x33:
case 0x34:case 0x35:case 0x36:case 0x37:case 0x38:case 0x39:case 0x41:
case 0x42:case 0x43:case 0x44:case 0x45:case 0x46:case 0x47:case 0x48:
case 0x49:case 0x4a:case 0x4b:case 0x4c:case 0x4d:case 0x4e:case 0x4f:
case 0x50:case 0x51:case 0x52:case 0x53:case 0x54:case 0x55:case 0x56:
case 0x57:case 0x58:case 0x59:case 0x5a:case 0x5c:case 0x5f:case 0x61:
case 0x62:case 0x63:case 0x64:case 0x65:case 0x66:case 0x67:case 0x68:
case 0x69:case 0x6a:case 0x6b:case 0x6c:case 0x6d:case 0x6e:case 0x6f:
case 0x70:case 0x71:case 0x72:case 0x73:case 0x74:case 0x75:case 0x76:
case 0x77:case 0x78:case 0x79:case 0x7a:
{
state.ptr += 1;
goto state_label_25; // include_pointy
}break;
case 0x3e:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_PPIncludeFile;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_26: // include_quotes
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x20:case 0x2e:case 0x2f:case 0x30:case 0x31:case 0x32:case 0x33:
case 0x34:case 0x35:case 0x36:case 0x37:case 0x38:case 0x39:case 0x41:
case 0x42:case 0x43:case 0x44:case 0x45:case 0x46:case 0x47:case 0x48:
case 0x49:case 0x4a:case 0x4b:case 0x4c:case 0x4d:case 0x4e:case 0x4f:
case 0x50:case 0x51:case 0x52:case 0x53:case 0x54:case 0x55:case 0x56:
case 0x57:case 0x58:case 0x59:case 0x5a:case 0x5c:case 0x5f:case 0x61:
case 0x62:case 0x63:case 0x64:case 0x65:case 0x66:case 0x67:case 0x68:
case 0x69:case 0x6a:case 0x6b:case 0x6c:case 0x6d:case 0x6e:case 0x6f:
case 0x70:case 0x71:case 0x72:case 0x73:case 0x74:case 0x75:case 0x76:
case 0x77:case 0x78:case 0x79:case 0x7a:
{
state.ptr += 1;
goto state_label_26; // include_quotes
}break;
case 0x22:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_PPIncludeFile;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_27: // pre_L
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_2; // identifier
}
}
switch (*state.ptr){
default:
{
goto state_label_2; // identifier
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x52:
{
state.ptr += 1;
goto state_label_31; // pre_R
}break;
}
}
{
state_label_28: // pre_u
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_2; // identifier
}
}
switch (*state.ptr){
default:
{
goto state_label_2; // identifier
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x38:
{
state.ptr += 1;
state.flags_ZF0 |= 0x8;
goto state_label_30; // pre_u8
}break;
case 0x52:
{
state.ptr += 1;
goto state_label_31; // pre_R
}break;
}
}
{
state_label_29: // pre_U
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_2; // identifier
}
}
switch (*state.ptr){
default:
{
goto state_label_2; // identifier
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x52:
{
state.ptr += 1;
goto state_label_31; // pre_R
}break;
}
}
{
state_label_30: // pre_u8
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_2; // identifier
}
}
switch (*state.ptr){
default:
{
goto state_label_2; // identifier
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x52:
{
state.ptr += 1;
goto state_label_31; // pre_R
}break;
}
}
{
state_label_31: // pre_R
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_2; // identifier
}
}
switch (*state.ptr){
default:
{
goto state_label_2; // identifier
}break;
case 0x22:
{
state.ptr += 1;
state.delim_first = state.ptr;
goto state_label_45; // raw_string_get_delim
}break;
}
}
{
state_label_32: // string
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x22:
{
if ((!HasFlag(state.flags_ZF0, 0x40))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x4)){
token.sub_kind = TokenOdinKind_LiteralStringWide;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x8)){
token.sub_kind = TokenOdinKind_LiteralStringUTF8;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x10)){
token.sub_kind = TokenOdinKind_LiteralStringUTF16;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x20)){
token.sub_kind = TokenOdinKind_LiteralStringUTF32;
token.kind = 10;
break;
}
token.sub_kind = TokenOdinKind_LiteralString;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x27:
{
if ((HasFlag(state.flags_ZF0, 0x40))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x4)){
token.sub_kind = TokenOdinKind_LiteralCharacterWide;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x8)){
token.sub_kind = TokenOdinKind_LiteralCharacterUTF8;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x10)){
token.sub_kind = TokenOdinKind_LiteralCharacterUTF16;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x20)){
token.sub_kind = TokenOdinKind_LiteralCharacterUTF32;
token.kind = 10;
break;
}
token.sub_kind = TokenOdinKind_LiteralCharacter;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x5c:
{
state.ptr += 1;
goto state_label_33; // string_esc
}break;
}
}
{
state_label_33: // string_esc
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
goto state_label_34; // string_esc_oct2
}break;
case 0x55:
{
state.ptr += 1;
goto state_label_37; // string_esc_universal_8
}break;
case 0x75:
{
state.ptr += 1;
goto state_label_41; // string_esc_universal_4
}break;
case 0x78:
{
state.ptr += 1;
goto state_label_36; // string_esc_hex
}break;
}
}
{
state_label_34: // string_esc_oct2
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
goto state_label_35; // string_esc_oct1
}break;
}
}
{
state_label_35: // string_esc_oct1
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
goto state_label_32; // string
}break;
}
}
{
state_label_36: // string_esc_hex
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_36; // string_esc_hex
}break;
}
}
{
state_label_37: // string_esc_universal_8
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_38; // string_esc_universal_7
}break;
}
}
{
state_label_38: // string_esc_universal_7
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_39; // string_esc_universal_6
}break;
}
}
{
state_label_39: // string_esc_universal_6
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_40; // string_esc_universal_5
}break;
}
}
{
state_label_40: // string_esc_universal_5
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_41; // string_esc_universal_4
}break;
}
}
{
state_label_41: // string_esc_universal_4
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_42; // string_esc_universal_3
}break;
}
}
{
state_label_42: // string_esc_universal_3
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_43; // string_esc_universal_2
}break;
}
}
{
state_label_43: // string_esc_universal_2
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_44; // string_esc_universal_1
}break;
}
}
{
state_label_44: // string_esc_universal_1
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_32; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_32; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_32; // string
}break;
}
}
{
state_label_45: // raw_string_get_delim
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_45; // raw_string_get_delim
}break;
case 0x20:case 0x29:case 0x5c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x28:
{
state.delim_one_past_last = state.ptr;
state.ptr += 1;
goto state_label_46; // raw_string_find_close
}break;
}
}
{
state_label_46: // raw_string_find_close
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_46; // raw_string_find_close
}break;
case 0x29:
{
state.ptr += 1;
goto state_label_47; // raw_string_try_delim
}break;
}
}
{
state_label_47: // raw_string_try_delim
u64 delim_length = state.delim_one_past_last - state.delim_first;
u64 parse_length = 0;
for (;;){
if (parse_length == delim_length){
goto state_label_48; // raw_string_try_quote
}
if (state.ptr == state.opl_ptr){
goto state_label_48; // raw_string_try_quote
}
if (*state.ptr == state.delim_first[parse_length]){
state.ptr += 1;
parse_length += 1;
}
else{
goto state_label_46; // raw_string_find_close
}
}
}
{
state_label_48: // raw_string_try_quote
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_46; // raw_string_find_close
}
}
switch (*state.ptr){
default:
{
goto state_label_46; // raw_string_find_close
}break;
case 0x22:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
if (HasFlag(state.flags_ZF0, 0x4)){
token.sub_kind = TokenOdinKind_LiteralStringWideRaw;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x8)){
token.sub_kind = TokenOdinKind_LiteralStringUTF8Raw;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x10)){
token.sub_kind = TokenOdinKind_LiteralStringUTF16Raw;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x20)){
token.sub_kind = TokenOdinKind_LiteralStringUTF32Raw;
token.kind = 10;
break;
}
token.sub_kind = TokenOdinKind_LiteralStringRaw;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_49: // comment_block
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_49; // comment_block
}break;
case 0x0a:
{
state.ptr += 1;
state.flags_ZB0 &= ~(0x1);
state.flags_KF0 &= ~(0x1);
goto state_label_49; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_50; // comment_block_try_close
}break;
}
}
{
state_label_50: // comment_block_try_close
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_49; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_50; // comment_block_try_close
}break;
case 0x2f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_51: // comment_line
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_51; // comment_line
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x5c:
{
state.ptr += 1;
goto state_label_52; // comment_line_backslashing
}break;
}
}
{
state_label_52: // comment_line_backslashing
if (state.ptr == state.opl_ptr){
if ((true)){
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_51; // comment_line
}break;
case 0x0d:
{
state.ptr += 1;
goto state_label_52; // comment_line_backslashing
}break;
}
}
{
state_label_53: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Colon;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Colon;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ColonColon;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ColonEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_54: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_MinusEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_55; // op stage
}break;
}
}
{
state_label_55: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_MinusGrtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_MinusGrtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ArrowStar;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_56: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Less;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Less;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
goto state_label_65; // op stage
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LessEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_57: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Grtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Grtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_GrtrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_66; // op stage
}break;
}
}
{
state_label_58: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Eq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Eq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_EqEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_59: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Not;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Not;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_NotEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_60: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_And;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_And;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x26:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_AndAnd;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_61: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Or;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Or;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_OrOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_62: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_PlusEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_63: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Star;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Star;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_StarEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_64: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Mod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Mod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ModEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_65: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LeftLeft;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LeftLeft;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_LeftLeftEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_66: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_RightRight;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_RightRight;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_RightRightEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_67: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Range;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_Range;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_OpenRange;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_ZB0;
do{
token.sub_kind = TokenOdinKind_ClosedRange;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
state.flags_ZB0 = 0;
goto state_label_1; // root
}break;
}
}
end:;
block_copy_struct(state_ptr, &state);
return(result);
}
internal Token_List
lex_full_input_odin(Arena *arena, String_Const_u8 input){
Lex_State_Odin state = {};
lex_full_input_odin_init(&state, input);
Token_List list = {};
lex_full_input_odin_breaks(arena, &list, &state, max_u64);
return(list);
}
