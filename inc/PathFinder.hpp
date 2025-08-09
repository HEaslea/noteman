#pragma once

#include <filesystem>
#include <windows.h>
#include <string>
#include <vector>

namespace PathFinder{ 

    std::filesystem::path getExePath();

    std::filesystem::path getConfigPath();

    std::vector<std::string> getAllPaths();

}