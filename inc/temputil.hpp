#pragma once

#include "verbose.hpp"

namespace tempUtil{
    /* 
        NO CONCEPT USE
    */

    // 
    template <typename Cont> 
    void printCont(const Cont& cont)
    { 
        if(Verbose::ifVerbose())
            std::cout << "PRINT CONTAINER :: A" << std::endl;

        for(auto i : cont)
        { 
            std::cout << i << " : ";

        }
        std::cout << std::endl;
    }

    // ITER
    template <typename Iter>
    void printCont(Iter begin, Iter end)
    { 
        if(Verbose::ifVerbose())
            std::cout << "PRINT CONTAINER :: ITER" << std::endl;

        while(begin != end)
        { 
            std::cout << *begin << " : ";
            begin++;
        }
        std::cout << std::endl;
    }

}