#pragma once

#include <filesystem>
#include <windows.h>
#include <string>
#include <vector>
#include <utility>

namespace PathFinder{ 

    std::filesystem::path getExePath();

    std::filesystem::path getConfigPath();

    std::pair<bool, std::vector<std::string>> getAllPaths();

}
// F:\noteman\build\paths.cfg