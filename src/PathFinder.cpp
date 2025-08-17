#include "../inc/PathFinder.hpp"
#include "../inc/Log.hpp"
#include "../inc/LogEnums.hpp"

#include <filesystem>
#include <fstream>
#include <utility>
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

    //TODO : fix relativity
    // Get path to the paths.cfg file
    std::filesystem::path getConfigPath()
    { 
        auto exePath = getExePath(); // cfgPaths should be in the same folder

        // if not in the same folder, then add to this
        // CFGPATH
        std::string buildDirToPaths = "";

        return (buildDirToPaths.empty()) ? exePath : exePath / buildDirToPaths;
    }

    // Get All Paths in paths.cfg
    // This is being moved to getAllPaths in ObsVault
    std::pair<bool, std::vector<std::string>> getAllPaths()
    { 
        // CONFIGPATH
        auto p = getConfigPath() / "paths.cfg";

        std::cout << "PATH TO CONFIG : " << p << std::endl;

        std::ifstream iFile(p);

        if(!iFile)
        { 
            Log::vLog("Failed to open paths.conf", LogLevel::LOGERROR, LogOrigin::PATHFINDER);
            return {false, {}};
        }

        std::vector<std::string> ret;

        std::string temp;
        while(std::getline(iFile, temp))
        { 
            ret.push_back(temp);
        }

        return {true, ret};
    }
}