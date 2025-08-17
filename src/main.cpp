#include "../inc/Manager.hpp"
#include "../inc/Log.hpp"
#include "../inc/LogEnums.hpp"
#include "../inc/PathFinder.hpp"
#include "../inc/temputil.hpp"
#include "../inc/verbose.hpp"
#include "../inc/ObsPath.hpp"

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

int main(int argc, char* argv[])
{ 
    std::vector<std::string> args;
    for(int i = 1; i < argc; ++i)
    { 
        std::string cur(argv[i]);
        args.push_back(cur);
    }

    Manager man(args);
    man.addCurDir();
}