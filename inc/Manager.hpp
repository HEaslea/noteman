#pragma once

#include "Log.hpp"

#include <string>
#include <vector>
#include <unordered_map>

/* 
Thinking about the commands: 


When we are in a dir that we want to add as a path, therefore it's vault that we are in
noteman add . 
*/




class Manager{ 
    std::vector<std::string> _args;

    void run() const;

    void addDirToPathCfg(const std::string&) const;

public: 

    Manager() = delete;

    // default set up at the beginning
    Manager(std::vector<std::string>);

    //REMOVE
    void addCurDir();
};