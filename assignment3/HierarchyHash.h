#ifndef HIERARCHYHASH_H
#define HIERARCHYHASH_H

#include <iostream>
#include "FlatHash.h"

class HierarchyHash
{
private:
  unsigned int** hashtable;
  // Variable for overflow handling
  enum overflow_handle flag;
  // Loading factor
  float alpha;
  // Size(range) of full hash table. Initially 1000
  unsigned int table_size;
  // Size of subhash table. Fixed by 100
  unsigned int sub_table_size;
  // Nums of keys
  unsigned int num_of_keys;


public:
  HierarchyHash(enum overflow_handle _flag, float _alpha);

  ~HierarchyHash();

  unsigned int hashFunction(const unsigned int key) { return key % table_size; }

  unsigned int getTableSize() { return table_size; }

  unsigned int getNumofKeys() { return num_of_keys; }

  // Return the size of allocated sub hash table
  unsigned int getAllocatedSize();

  // Return time cost
  int insert(const unsigned int key);

  // Return time cost
  int remove(const unsigned int key);

  // Return time cost
  int search(const unsigned int key);

  // Delete tombstones
  void clearTombstones();

  void print();
};

HierarchyHash::HierarchyHash(enum overflow_handle _flag, float _alpha)
{
  // Initial map size is 1000
  table_size = 1000;
  // Table size is fixed to 100
  sub_table_size = 100;
  flag = _flag;
  alpha = _alpha;

  // Write your code

}

HierarchyHash::~HierarchyHash()
{
  // Write your code

}

unsigned int HierarchyHash::getAllocatedSize()
{
  // Write your code

}

int HierarchyHash::insert(const unsigned int key)
{
  // Write your code

}

int HierarchyHash::remove(const unsigned int key)
{
  // Write your code

}

int HierarchyHash::search(const unsigned int key)
{
  // Write your code

}

void HierarchyHash::clearTombstones()
{
  // Write your code
  
}

void HierarchyHash::print()
{
  // Print valid key pair for each sub hash table - subtable_id:(index1:key1,index2:key2)
  // Seperate each sub table by endl
  // Give **NO** space between each character
  // e.g., 0:(1:3,3:7,5:1)
  //       1:(101:2,192:10)
  //       9:(902:90,938:82)

  // Exceptionally, keep this code only for the case there is no key in the table
  if( getNumofKeys() == 0){
    std::cout << "[]" << std::endl;
    return;
  }

  // Write your code

}

#endif
