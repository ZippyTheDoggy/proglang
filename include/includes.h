#pragma once

#define MAGIC_ENUM_RANGE_MIN 0
#define MAGIC_ENUM_RANGE_MAX 1024
#include "../libs/magic_enum/magic_enum.hpp"

#if (__cplusplus >= 201703L)
    #define CPP17
    #include <filesystem>
#endif

// General
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

// Data Structures
#include <vector>
#include <map>
#include <vector>