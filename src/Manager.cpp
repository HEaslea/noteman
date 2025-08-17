#include "../inc/Manager.hpp"
#include "../inc/Log.hpp"
#include "../inc/ObsPath.hpp"
#include "../inc/LogEnums.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <filesystem>
#include <format>

Manager::Manager(std::vector<std::string> args) : _args(std::move(args))
{ 
    run();
}

void Manager::run() const
{ 
    std::cout << "Manager Run" << std::endl;
}

void Manager::addDirToPathCfg(const std::string& pathToAdd) const
{ 
    std::filesystem::path pathToCurDir;
    if(pathToAdd == ".")
    { 
        pathToCurDir = std::filesystem::current_path(); // 
    } else 
    { 
        // if the path does exist 
        if(std::filesystem::exists(pathToAdd))
        { 
            std::filesystem::path pathToCurDir(pathToAdd);

            // check if reg file and then fix to get parent dir
            if(std::filesystem::is_regular_file(pathToAdd))
                pathToCurDir = pathToCurDir.parent_path();

            std::cout << "Adding cur dir" << std::endl;
            ObsVaultPathManager obs;
            obs.addPathCurrentDir(pathToCurDir.string());
        } else { // path does not exist 
            Log::vLog("Path does not exist", LogLevel::LOGERROR, LogOrigin::MANAGER);
        }
    }
    ObsVaultPathManager obs;
    obs.addPathCurrentDir(pathToCurDir.string());
}

void Manager::addCurDir()
{ 
    addDirToPathCfg(".");
}