
#include "HierarchyHash.h"

#include <iostream>

int main()
{

    // #############################
    // # HierarchyHash test example
    // #############################
    std::cout << "HierarchyHash test" << std::endl;
    HierarchyHash hh(LINEAR_PROBING, 0.8);
    std::cout << hh.insert(3) << std::endl;    // 1
    std::cout << hh.insert(7) << std::endl;    // 1
    std::cout << hh.insert(103) << std::endl;  // 1
    std::cout << hh.insert(903) << std::endl;  // 1
    std::cout << hh.insert(99) << std::endl;   // 1
    std::cout << hh.insert(1099) << std::endl; // 2
    std::cout << hh.insert(98) << std::endl;   // 1
    std::cout << hh.insert(1098) << std::endl; // 4
    std::cout << hh.search(100) << std::endl;  // -3
    hh.print();                                // 0:[3:3,7:7,98:98,99:99]
                                               // 1:[100:1099,101:1098,103:103]
                                               // 9:[903:903]

    std::cout << hh.remove(1099) << std::endl; // 2
    std::cout << hh.remove(2098) << std::endl; // -4
    hh.print();                                // 0:[3:3,7:7,98:98,99:99]
                                               // 1:[100:1098,103:103]
                                               // 9:[903:903]

    std::cout << hh.insert(1903) << std::endl; // 2
    std::cout << hh.remove(903) << std::endl;  // 1
    for (int i = 500; i < 1300; i++)
    {
        hh.insert(i);
    }
    std::cout << hh.getTableSize() << std::endl;     // 2000
    std::cout << hh.getNumofKeys() << std::endl;     // 806
    std::cout << hh.getAllocatedSize() << std::endl; // 1100
    //hh.~HierarchyHash();
    std::cout << std::endl;

    return 0;
}
