#pragma once

#include "PathFinder.hpp"
#include "Log.hpp"

#include <string> 
#include <vector>
#include <fstream>

namespace { 

}


class ObsVaultPathManager { 

    std::vector<std::string> _paths;

    bool getAllPaths();

public: 

    ObsVaultPathManager();

    void printOutPaths() const;


};