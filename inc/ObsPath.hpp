#pragma once

#include "PathFinder.hpp"
#include "Log.hpp"

#include <string> 
#include <vector>
#include <fstream>
#include <filesystem>

class ObsVaultPathManager { 

    std::vector<std::string> _paths;

    // not sure how necessary this one is
    std::filesystem::path _pathToCfg;

    bool getAllPaths();

    bool addPathToCfg(const std::string&);

    void setPathToCfg();

public: 

    ObsVaultPathManager();

    void printOutPaths() const;
    
    // either we add in an argued Path, the string is the path
    void addPathArgued(const std::string&);

    // or we add in a path of the dir that we are currently in
    void addPathCurrentDir(const std::string&);
};