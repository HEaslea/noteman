#include <iostream> 
#include <filesystem>
#include <optional>
#include <fstream>
#include <vector> 
#include <set> 
#include <map> 
#include <unordered_map>
#include <unordered_set>
#include <windows.h>

#include "../inc/Log.hpp"
#include "../inc/LogEnums.hpp"
#include "../inc/PathFinder.hpp"
#include "../inc/temputil.hpp"
#include "../inc/verbose.hpp"



std::filesystem::path getExePath()
{ 
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return std::filesystem::path(buffer);
}


int main()
{ 
    PathFinder::getAllPaths();


}