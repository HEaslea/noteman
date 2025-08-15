#include "../inc/ObsPath.hpp"
#include "../inc/PathFinder.hpp"
#include "../inc/Log.hpp"
#include "../inc/temputil.hpp"

#include <vector> 
#include <utility>
#include <string> 

ObsVaultPathManager::ObsVaultPathManager()
{ 
    if(getAllPaths())
    { 
        Log::vLog("Paths retrieved succesfully", LogLevel::SUCCESS, LogOrigin::OBSPATH);
    }  else { 
        Log::vLog("Paths could not be retrived", LogLevel::LOGERROR, LogOrigin::OBSPATH);
    }
}


bool ObsVaultPathManager::getAllPaths()
{
    if(_paths.empty()){
        auto pathPair = PathFinder::getAllPaths();
        // can move if true
        if(pathPair.first) // true if successfully gotten all the paths
        { 
            _paths = std::move(pathPair.second);
            return true;
        } else { 
            Log::vLog("Error Getting Paths in GetAllPaths", LogLevel::LOGERROR, LogOrigin::OBSPATH);
            return false;
        }
    }
    // TODO: This doesn't really work to return true if paths are already in there
    return true;
}

void ObsVaultPathManager::printOutPaths() const 
{ 
    tempUtil::printCont(_paths);
}

