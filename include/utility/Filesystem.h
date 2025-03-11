#pragma once
#include "../includes.h"

#define CPP17
#include <filesystem>

namespace fs {
    bool exists(std::string path) {
        #ifdef CPP17
        return std::filesystem::exists(path);
        #endif

        std::fstream file(path);
        bool i_o = file.is_open();
        file.close();
        return i_o;
    }
    std::string read_file(std::string path) {
        if(!exists(path)) return "";
        std::fstream file(path);
        std::string content = "";
        std::string line;
        while(std::getline(file, line))
            content += line + "\n";
        file.close();
        return content;
    }
    bool write_file(std::string path, std::string content, bool append = false, bool createIfNotExists = false) {
        if(!exists(path) && !createIfNotExists) return false;
        std::fstream file(path, 
            std::ios::out | (append ? std::ios::app : std::ios::trunc)
        );
        file.write(content.c_str(), content.size());
        file.close();
        return true;
    }
    bool create(std::string path, bool is_directory = false) {
        #ifndef CPP17
        return false;
        #endif

        if(is_directory && !exists(path)) std::filesystem::create_directory(path);
        if(!is_directory && !exists(path)) {
            write_file(path, "", false, true);
        }
        return exists(path);
    }
}