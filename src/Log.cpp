#include "../inc/Log.hpp"

/* 
    SEE OBSIDIAN NOTES [[CPP Logger]] - how we can improve on all of this
*/

namespace Log{

    std::string getLogLevelString(LogLevel l)
    { 
        static std::unordered_map<LogLevel, std::string> m
        { 
            {LogLevel::NONE, ""}, 
            {LogLevel::LOGERROR, "ERROR"},
            {LogLevel::LOG, "LOG"},
            {LogLevel::SUCCESS, "SUCCESS"}
        };
        return m[l] + " ::: ";
    }

    std::string getLogOriginString(LogOrigin o)
    { 
        static std::unordered_map<LogOrigin, std::string> m 
        { 
            {LogOrigin::NONE, ""}, 
            {LogOrigin::FILEREADER, "FileReader"}, 
            {LogOrigin::FILEWRITER, "FileWriter"},
            {LogOrigin::OBSPATH, "ObsPath"}, 
            {LogOrigin::PATHFINDER, "PathFinder"}
        };

        return m[o] + " ::: ";
    }

    /*
    template<typename ... Strings> 
    void vLog(const Strings& ... s, LogLevel l, LogOrigin o)
    {
        if(Verbose::ifVerbose() || l == LogLevel::LOGERROR)        
        { 
            std::cout << getLogLevelString(l) << getLogOriginString(o);
            ((std::cout << s), ...) << std::endl;
        }
    }
    */

    void vLog(const std::string& s, LogLevel l, LogOrigin o) 
    { 
        if(Verbose::ifVerbose() || l == LogLevel::LOGERROR)
        { 
            std::cout << getLogLevelString(l) << getLogOriginString(o) << s << std::endl;
        }
    }


}