#pragma once
#include "../includes.h"

enum TokenType {
    // Char Types
    KEYWORD, IDENTIFIER, STRING, NUMBER,

    // Scope Symbols
    LBRACE, RBRACE,
    LPAREN, RPAREN,
    LBRACKET, RBRACKET,

    // Operator Symbols
    PLUS, MINUS, DIVIDE,
    EQUALS, GREATER, LESS,
    
    // Symbols
    SEMICOLON, COLON, COMMA,
    NOT,
    ASTERISK, AMPERSAND,

    // Combined Tokens
    PIPE_LEFT, PIPE_RIGHT,
    ACCESSOR_MEMBER, ACCESSOR_INDEX,

    DIRECTIVE,
};
struct Token {
    TokenType type;
    std::string value;
};