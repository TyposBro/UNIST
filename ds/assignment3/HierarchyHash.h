#ifndef HIERARCHYHASH_H
#define HIERARCHYHASH_H

#include <iostream>
#include "FlatHash.h"

class HierarchyHash
{
private:
  unsigned int **hashtable;
  unsigned int thumbstone = 1000001;
  unsigned int allocatedSize = 0;
  FlatHash fh;

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
  unsigned int getAllocatedSize() { return allocatedSize; };

  // Return time cost
  int insert(const unsigned int key);

  // Return time cost
  int remove(const unsigned int key);

  // Return time cost
  int search(const unsigned int key);

  // Delete tombstones
  void clearTombstones();

  void print();
  // CUSTOM
  unsigned int _getAllocated();
};

HierarchyHash::HierarchyHash(enum overflow_handle _flag, float _alpha) : fh(_flag, _alpha)
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

int HierarchyHash::insert(const unsigned int key)
{
  // Write your code
  int res = fh.insert(key);
  num_of_keys = fh.getNumofKeys();
  table_size = fh.getTableSize();
  _getAllocated();
  return res;
}

int HierarchyHash::remove(const unsigned int key)
{
  // Write your code
  int res = fh.remove(key);
  num_of_keys = fh.getNumofKeys();
  table_size = fh.getTableSize();
  _getAllocated();
  return res;
}

int HierarchyHash::search(const unsigned int key)
{
  // Write your code
  return fh.search(key);
}

void HierarchyHash::clearTombstones()
{
  // Write your code
  fh.clearTombstones();
  num_of_keys = fh.getNumofKeys();
  table_size = fh.getTableSize();
  _getAllocated();
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
  if (getNumofKeys() == 0)
  {
    std::cout << "()" << std::endl;
    return;
  }

  // Write your code
  table_size = fh.getTableSize();

  string res = "";
  for (unsigned int i = 0; i < table_size / sub_table_size; i++)
  {
    bool isFound = false;
    string temp = to_string(i) + ":(";
    for (unsigned int j = 0; j < sub_table_size; j++)
    {
      if (fh.getFHT()[i * sub_table_size + j] != 0 && fh.getFHT()[i * sub_table_size + j] != thumbstone)
      {
        isFound = true;
        // temp = to_string(fh.getFHT()[i * sub_table_size + j]);
        temp += to_string(i * sub_table_size + j) + ":" + to_string(fh.getFHT()[i * sub_table_size + j]) + ",";
      }
    }
    if (isFound)
    {
      temp.pop_back();
      temp.push_back(')');
      res += temp;
      res += "\n";
    }
    else
    {
      temp = "";
    }
  }
  cout << res;
}

unsigned int HierarchyHash::_getAllocated()
{
  allocatedSize = 0;
  table_size = fh.getTableSize();
  num_of_keys = fh.getNumofKeys();
  for (unsigned int i = 0; i < table_size / sub_table_size; i++)
  {
    for (unsigned int j = 0; j < sub_table_size; j++)
    {
      if (fh.getFHT()[i * sub_table_size + j] && fh.getFHT()[i * sub_table_size + j] != 0 && fh.getFHT()[i * sub_table_size + j] != thumbstone)
      {
        allocatedSize += 100;
        break;
      }
    }
  }
  return allocatedSize;
};

#endif
