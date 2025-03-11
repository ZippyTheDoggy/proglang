#pragma once
#include "../includes.h"

#include "../Structs/Token.h"
#include "../utility/Crawler.h"

namespace is {
    bool character(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool number(char c) {
        return (c >= '0' && c <= '9') || c == '.';
    }
}

template <TokenType T>
constexpr bool char_is(char c, int pos = 0) {
    if constexpr (T == TokenType::NUMBER) return is::number(c);
    if constexpr (T == TokenType::STRING) {
        if(pos == 0) return c == '"';
        return c != '"';
    }
    if constexpr (T == TokenType::IDENTIFIER) {
        if(pos == 0) return c == '_' || is::character(c);
        return c == '_' || is::character(c) || (is::number(c) && c != '.');
    }
    if constexpr (T == TokenType::DIRECTIVE) {
        if(pos == 0) return c == '#';
        return true;
    }
    return false;
}

template <TokenType T>
std::string consume_until(StringCrawler* sc) {
    std::string buffer = std::string(1, sc->last());

    while(!sc->eof()) {
        char c = sc->next();
        if(char_is<T>(c, buffer.length())) buffer += c;
        else {
            // special end of string conditional
            if(c != '"') sc->back();
            else buffer += '"';
            break;
        }
    }
    return buffer;
}