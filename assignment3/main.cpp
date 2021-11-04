#include "FlatHash.h"
#include "HierarchyHash.h"
#include "NRKFlat.h"

#include <iostream>

int main()
{
	// ########################################
	// # FlatHash test example: Linear probing
	// ########################################
	std::cout << "FlatHash test: Linear" << std::endl;
	FlatHash fh(LINEAR_PROBING, 0.8);
	std::cout << fh.insert(3)    << std::endl;    // 1
	std::cout << fh.insert(7)    << std::endl;    // 1
	std::cout << fh.insert(7)    << std::endl;    // -1
	std::cout << fh.insert(1003) << std::endl;    // 2
	std::cout << fh.insert(2006) << std::endl;    // 1
	std::cout << fh.insert(3006) << std::endl;    // 3
	fh.print();   // [3:3,4:1003,6:2006,7:7,8:3006] 
	std::cout << fh.insert(6)    << std::endl;    // 4
	std::cout << fh.remove(4003) << std::endl;    // -3
	std::cout << fh.insert(5003) << std::endl;    // 3
	fh.print();   // [3:3,4:1003,5:5003,6:2006,7:7,8:3006,9:6]
	//fh.~FlatHash();
	std::cout << std::endl;


	// ###########################################
	// # FlatHash test example: Quadratic probing
	// ###########################################
	std::cout << "FlatHash test: Quadratic" << std::endl;
	FlatHash fh1(QUADRATIC_PROBING, 0.8);
	std::cout << fh1.insert(1008) << std::endl;    // 1
	std::cout << fh1.insert(8009) << std::endl;    // 1
	std::cout << fh1.insert(5008) << std::endl;    // 3
	std::cout << fh1.insert(6008) << std::endl;    // 4
	std::cout << fh1.search(9008) << std::endl;    // -5
	std::cout << fh1.insert(4009) << std::endl;    // 2
	std::cout << fh1.insert(9)    << std::endl;    // 3
	fh1.print();    // [8:1008,9:8009,10:4009,12:5008,13:9,17:6008]

	FlatHash fh2(QUADRATIC_PROBING, 0.8);
	int a = 1;
	for(int i = 0; i < 157; i++){
		fh2.insert(a);
		a+=1000;
	}
	std::cout << fh2.insert(a+=1000) << std::endl;  // 247
	std::cout << fh2.insert(a+=1000) << std::endl;  // 249
	std::cout << fh2.insert(a+=1000) << std::endl;  // 1003
	std::cout << fh2.insert(a+=1000) << std::endl;  // 1004
	//fh1.~FlatHash();
	//fh2.~FlatHash();
	std::cout << std::endl;


	// #############################
	// # HierarchyHash test example
	// #############################
	std::cout << "HierarchyHash test" << std::endl;
	HierarchyHash hh(LINEAR_PROBING, 0.8);
	std::cout << hh.insert(3)    << std::endl;    // 1
	std::cout << hh.insert(7)    << std::endl;    // 1
	std::cout << hh.insert(103)  << std::endl;    // 1
	std::cout << hh.insert(903)  << std::endl;    // 1
	std::cout << hh.insert(99)   << std::endl;    // 1
	std::cout << hh.insert(1099) << std::endl;    // 2
	std::cout << hh.insert(98)   << std::endl;    // 1
	std::cout << hh.insert(1098) << std::endl;    // 4
	std::cout << hh.search(100)  << std::endl;    // -3
	hh.print();   // 0:[3:3,7:7,98:98,99:99]
	              // 1:[100:1099,101:1098,103:103]
	              // 9:[903:903]

	std::cout << hh.remove(1099) << std::endl;    // 2
	std::cout << hh.remove(2098) << std::endl;    // -4
	hh.print();   // 0:[3:3,7:7,98:98,99:99]
	              // 1:[100:1098,103:103]
	              // 9:[903:903]

	std::cout << hh.insert(1903) << std::endl;    // 2
	std::cout << hh.remove(903)  << std::endl;    // 1
	for (int i = 500; i < 1300; i++){
		hh.insert(i);
	}
	std::cout << hh.getTableSize() << std::endl;      // 2000
	std::cout << hh.getNumofKeys() << std::endl;      // 806
	std::cout << hh.getAllocatedSize() << std::endl;  // 1100
	//hh.~HierarchyHash();
	std::cout << std::endl;


	// #######################
	// # NRKFlat test example
	// #######################
	std::cout << "NRKFlat test" << std::endl;
	NRKFlat nf(LINEAR_PROBING, 0.8, 1000);
	std::cout << nf.insert(2019) << std::endl;    // 1
	std::cout << nf.search(3019) << std::endl;    // 0
	for (int i = 1; i < 500; i++){    // UPDATED 191111
		nf.insert(i);
	}
	std::cout << nf.insert(365) << std::endl;     // -2
	std::cout << nf.search(222) << std::endl;     // 2
	std::cout << nf.search(501) << std::endl;     // 0
	//nf.~NRKFlat();
	std::cout << std::endl;

	std::cout << "done" << std::endl;

	return 0;
}
