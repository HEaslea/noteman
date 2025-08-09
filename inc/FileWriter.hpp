#pragma once

#include <fstream>

class FileWriter{

    std::ofstream _targetFile; 
    std::string _targetName; // _targetFile path

    bool writeToFile(const std::string&);

    bool clearFile();

    bool addEmptyLines(int); // perhaps not bool 

public:

    // Must be opened with targetFilePath
    FileWriter() = delete; 

    FileWriter(const std::string&);

    ~FileWriter();

    void clear();
};