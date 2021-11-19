#ifndef HIERARCHYHASH_H
#define HIERARCHYHASH_H

#include <iostream>
#include "FlatHash.h"

class HierarchyHash
{
private:
  unsigned int **hashtable;
  unsigned int thumbstone = 1000001;

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

  // CUSTOM
  unsigned int *create_sub_table();
  unsigned int **prepare_table(unsigned int tableIndex);
  int _insert(unsigned int key, bool isLinear);
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
  hashtable = new unsigned int *[10];
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
  int q;
  int l;

  // FLAG = QADRATIC
  if (flag == QUADRATIC_PROBING)
  {
    q = _insert(key, false);
    // NOT FOUND in QUADRATIC
    if (q == 0)
    {
      l = _insert(key, true);
      // DUPLICATE
      if (l < 0)
        return l - table_size;
      // LINEAR INSERT
      // check_load_factor();
      return l + table_size;
    }
    else
    {
      // check_load_factor();
      return q;
    }
  }
  else
  { // FLAG = LINEAR
    l = _insert(key, true);

    // check_load_factor();
    return l;
  }
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
  if (getNumofKeys() == 0)
  {
    std::cout << "()" << std::endl;
    return;
  }

  // Write your code
}
unsigned int *HierarchyHash::create_sub_table()
{
  unsigned int *temp = new unsigned int[sub_table_size];
  for (unsigned int i = 0; i < sub_table_size; i++)
  {
    temp[i] = 0;
  }
  return temp;
};

unsigned int **HierarchyHash::prepare_table(unsigned int tableIndex)
{

  if (hashtable[tableIndex])
    return hashtable;

  hashtable[tableIndex] = create_sub_table();
  return hashtable;
};

int HierarchyHash::_insert(unsigned int key, bool isLinear)
{
  for (unsigned int i = 0; i < table_size; i++)
  {
    unsigned int index = (isLinear) ? hashFunction(key + i) : hashFunction(key + i * i);
    unsigned int row = index / sub_table_size;
    unsigned int col = index % sub_table_size;

    hashtable = prepare_table(row);
    cout << hashtable[row][col] << endl;
    if (hashtable[row][col] == 0 || hashtable[row][col] == thumbstone)
    {
      hashtable[row][col] = key;
      return i + 1;
    }
    if (hashtable[row][col] == key)
    {
      int res = -i - 1;
      return res;
    }

    cout << hashtable[row][col] << endl;
  }
  return 0;
};
#endif
