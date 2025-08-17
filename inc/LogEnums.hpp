#pragma once

#include <string>

enum class LogLevel
{
    NONE     = 0, 
    LOGERROR    = 1, 
    LOG      = 2,
    SUCCESS  = 10
};

enum class LogOrigin 
{ 
    NONE        = 0,
    FILEWRITER  = 1, 
    FILEREADER  = 2, 
    OBSPATH     = 3, 
    PATHFINDER  = 4, 
    MANAGER     = 5
};