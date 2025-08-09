#pragma once

#include "LogEnums.hpp"
#include "verbose.hpp"

#include <string>
#include <unordered_map>
#include <iostream>

namespace Log { 

    std::string getLogLevelString(LogLevel l);
    
    std::string getLogOriginString(LogOrigin o);

    void vLog(const std::string& s, LogLevel l = LogLevel::NONE, LogOrigin o = LogOrigin::NONE);
}