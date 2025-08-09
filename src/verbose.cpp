#include "../inc/verbose.hpp"

namespace Verbose { 
    bool verbose = false;
    bool test = true;

    bool ifVerbose() 
    { 
        return verbose || test;
    }
}