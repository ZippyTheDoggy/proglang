#pragma once
#include "../includes.h"

#include "../Structs/Token.h"
#include "../utility/Crawler.h"
#include "./Consumer.h"

std::vector<Token> tokenize(std::string code) {
    const std::map<char, TokenType> static_types {
        {'{', TokenType::LBRACE},
        {'}', TokenType::RBRACE},
        {'(', TokenType::LPAREN},
        {')', TokenType::RPAREN},
        {'[', TokenType::LBRACKET},
        {']', TokenType::RBRACKET},

        {'+', TokenType::PLUS},
        {'-', TokenType::MINUS},  
        {'/', TokenType::DIVIDE},
        {'=', TokenType::EQUALS},
        {'>', TokenType::GREATER},
        {'<', TokenType::LESS},

        {';', TokenType::SEMICOLON},
        {':', TokenType::COLON},
        {',', TokenType::COMMA},
        {'!', TokenType::NOT},
        {'*', TokenType::ASTERISK},
        {'&', TokenType::AMPERSAND},
    };

    StringCrawler sc(code);
    std::vector<Token> out = {};

    while(!sc.eof()) {
        char c = sc.next();
        if(c == ' ' || c == '\n') continue;
        for(const auto& [k, v] : static_types)
            if(k == c)
                out.push_back(Token {v, std::string(1, c)});

        if(c == '"')
            out.push_back(Token {
                TokenType::STRING, consume_until<TokenType::STRING>(&sc)
            });
        else if(char_is<TokenType::DIRECTIVE>(c)) 
            out.push_back(Token {
                TokenType::DIRECTIVE, consume_until<TokenType::DIRECTIVE>(&sc)
            });
        else if(char_is<TokenType::IDENTIFIER>(c))
            out.push_back(Token {
                TokenType::IDENTIFIER, consume_until<TokenType::IDENTIFIER>(&sc)
            });
        else if(char_is<TokenType::NUMBER>(c))
            out.push_back(Token {
                TokenType::NUMBER, consume_until<TokenType::NUMBER>(&sc)
            });
    }

    return out;
}