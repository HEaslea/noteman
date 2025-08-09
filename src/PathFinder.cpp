#include "../inc/PathFinder.hpp"
#include "../inc/Log.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>


namespace PathFinder{ 

    std::filesystem::path getExePath()
    {
        char buf[MAX_PATH]; // TODO
        DWORD len = GetModuleFileNameA(NULL, buf, MAX_PATH); // Not W for wide
        if(len == 0)
        { 
            Log::vLog("Error In getExeDir()", LogLevel::LOG, LogOrigin::PATHFINDER);
        }
        return std::filesystem::path(buf).parent_path(); // stripping the exe part
    }

    std::filesystem::path getConfigPath()
    { 
        auto p = getExePath();

        return p / "paths"; 
    }

    std::vector<std::string> getAllPaths()
    { 
        // CONFIGPATH
        auto p = getConfigPath() / "paths.conf";

        std::string v = p.string();

        std::ifstream iFile(p);

        if(!iFile)
        { 
            Log::vLog("Failed to open paths.conf", LogLevel::LOGERROR, LogOrigin::PATHFINDER);
        }

        std::vector<std::string> ret;

        std::string temp;
        while(std::getline(iFile, temp))
        { 
            ret.push_back(temp);
        }

        return ret;
    }
}