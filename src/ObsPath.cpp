#include "../inc/ObsPath.hpp"
#include "../inc/PathFinder.hpp"
#include "../inc/Log.hpp"
#include "../inc/temputil.hpp"

#include <vector> 
#include <fstream>
#include <utility>
#include <string> 
#include <filesystem>

ObsVaultPathManager::ObsVaultPathManager()
{ 
    setPathToCfg();
    std::cout << "ObsVPM : " <<  _pathToCfg << std::endl;

    if(getAllPaths())
    { 
        Log::vLog("Paths retrieved succesfully", LogLevel::SUCCESS, LogOrigin::OBSPATH);
    }  else { 
        Log::vLog("Paths could not be retrived", LogLevel::LOGERROR, LogOrigin::OBSPATH);
    }
}
 
bool ObsVaultPathManager::addPathToCfg(const std::string& pathToAdd)
{ 
    _paths.push_back(pathToAdd);
    std::ofstream pathsFile(_pathToCfg, std::ios::app | std::ios::out);
    if(!pathsFile.is_open()) // if the file is not open
    { 
        Log::vLog("Could not open _pathToCfg", LogLevel::LOGERROR, LogOrigin::OBSPATH);
        return false; 
    }
    pathsFile.seekp(0, std::ios::end);

    pathsFile << "\n" << pathToAdd;
    
    pathsFile.flush();
    if(!pathsFile.good())
    { 
        Log::vLog("Could not write path to _pathToCfg", LogLevel::LOGERROR, LogOrigin::OBSPATH);
        return false; 
    }
    return true;
}

void ObsVaultPathManager::setPathToCfg()
{ 
    _pathToCfg = PathFinder::getConfigPath() / "paths.cfg";
}

bool ObsVaultPathManager::getAllPaths()
{
    // this is a strange thing to have in here
    if(_paths.empty()){
        auto pathPair = PathFinder::getAllPaths();

        // then we need to get the paths using _pathToCfg that we have already gotten

        std::ifstream iFile(_pathToCfg);

        if(!iFile)
        { 
            Log::vLog("Failed to open paths.cfg", LogLevel::LOGERROR, LogOrigin::OBSPATH);
            return false;
        }

        // file is open
        std::string tempPath; 
        while(std::getline(iFile, tempPath))
        { 
            _paths.push_back(tempPath);
        }
    }
    return true;
}

void ObsVaultPathManager::printOutPaths() const 
{ 
    tempUtil::printCont(_paths);
}

void ObsVaultPathManager::addPathArgued(const std::string& s)
{ 
    addPathToCfg(s);
}

void ObsVaultPathManager::addPathCurrentDir(const std::string& s)
{
    if(addPathToCfg(s))
    { 
        Log::vLog("Added path of cur dir to file", LogLevel::SUCCESS, LogOrigin::OBSPATH);
    } else { 
        Log::vLog("Coudn't add path of cur dir to file", LogLevel::LOGERROR, LogOrigin::OBSPATH);
    }
}

