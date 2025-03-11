#pragma once
#include "./includes.h"

namespace KW {
    enum class Keyword {
        // Types
        INT = 0,
        BOOL, CHAR, FLOAT, STRING, VOID,
    
        // Modifiers
        CONST = 100, FINAL, STATIC,
    
        // Flow Control
        IF = 200, ELSE, WHILE, FOR, SWITCH, CASE, DEFAULT,
        RETURN, BREAK, CONTINUE,

        UNKNOWN = 900
    };
    enum class KeywordType {
        Type, Modifier, FlowControl,

        UNKNOWN = 900,
    };

    KeywordType get_kw_type(Keyword kw) {
        int c = static_cast<int>(kw);
        bool is_type    = c >= 0   && c < 100;
        bool is_mod     = c >= 100 && c < 200;
        bool is_fc      = c >= 200 && c < 300;

        if(is_type) return KeywordType::Type;
        if(is_mod)  return KeywordType::Modifier;
        if(is_fc)   return KeywordType::FlowControl;
    }
    bool is_kw_type(Keyword kw, KeywordType kwt) {
        return get_kw_type(kw) == kwt;
    }
    std::string stringify(Keyword kw) {
        return std::string(magic_enum::enum_name<Keyword>(kw));
    }
    bool is_str_keyword(std::string str) {
        return magic_enum::enum_contains<Keyword>(str);
    }
    Keyword get_str_keyword(std::string str) {
        if(!is_str_keyword) return Keyword::UNKNOWN;
        return magic_enum::enum_cast<Keyword>(str).value();
    }
}