#include "NRKFlat.h"

#include <iostream>

int main()
{

    // #######################
    // # NRKFlat test example
    // #######################
    std::cout << "NRKFlat test" << std::endl;
    NRKFlat nf(LINEAR_PROBING, 0.8, 1000);
    std::cout << nf.insert(2019) << std::endl; // 1
    std::cout << nf.search(3019) << std::endl; // 0
    for (int i = 1; i < 500; i++)
    { // UPDATED 191111
        nf.insert(i);
    }
    std::cout << nf.insert(365) << std::endl; // -2
    std::cout << nf.search(222) << std::endl; // 2
    std::cout << nf.search(501) << std::endl; // 0
    //nf.~NRKFlat();
    std::cout << std::endl;

    std::cout << "done" << std::endl;

    return 0;
}
