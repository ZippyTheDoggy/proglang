#pragma once
#include "../includes.h"

class StringCrawler { 
    private:
        std::string _str;
        size_t pos = 0;
    public:
        StringCrawler(std::string str, size_t start_pos = 0) : _str(str), pos(start_pos) {};

        // current
        bool eof() {
            return pos >= _str.length() || _str[pos] == '\0';
        }
        char current() {
            if(pos >= 0 && pos < _str.length()) return _str[pos];
            return '\0';
        }
        int cpos() {
            return pos;
        }

        // forward
        char next() {
            if((pos + 1) <= _str.length()) return _str[pos++];
            return '\0';
        }
        char peek() {
            if((pos + 1) <= _str.length()) return _str[pos + 1];
            return '\0';
        }

        // backward
        char back() {
            if(pos > 0) return _str[pos--];
            return '\0';
        }
        char last() {
            if(pos > 0) return _str[pos - 1];
            return '\0';
        }

        // omni-directional
        char seek(int relPos) {
            int res = pos + relPos;
            if(res > 0 && res < _str.length()) return _str[res];
            return '\0';
        }
        char jump(int relPos) {
            int res = pos + relPos;
            if(res > 0 && res < _str.length()) return _str[pos = res];
            return '\0';
        }
};