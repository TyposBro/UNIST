#ifndef FLATHASH_H
#define FLATHASH_H

#include <iostream>
using namespace std;
// Flag(hint) for overflow handling
enum overflow_handle
{
  LINEAR_PROBING = 0,
  QUADRATIC_PROBING
};

class FlatHash

{
private:
  unsigned int *hashtable;
  // Variable for overflow handling
  enum overflow_handle flag;
  // Loading factor
  float alpha;
  // Size of hash table
  unsigned int table_size;
  // Nums of keys
  unsigned int num_of_keys;
  unsigned int thumbstone = 1000001;

public:
  FlatHash(enum overflow_handle _flag, float _alpha);

  ~FlatHash();

  unsigned int hashFunction(const unsigned int key) { return key % table_size; }

  unsigned int getTableSize() { return table_size; }

  unsigned int getNumofKeys() { return num_of_keys; }

  // Return time cost
  int insert(const unsigned int key);

  // Remove function in lecture. Return time cost
  int remove(const unsigned int key);

  // Return time cost
  int search(const unsigned int key);

  // Delete tombstones
  void clearTombstones();

  void print();

  // CUSTOM
  unsigned int *create_table(const unsigned int size)
  {
    unsigned int *table = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++)
    {
      table[i] = 0;
    }

    return table;
  }
  int linear_probing(const unsigned int key)
  {
    for (unsigned int i = 0; i < table_size; i++)
    {
      unsigned int index = hashFunction(key + i);
      if (hashtable[index] == 0 || hashtable[index] == thumbstone)
      {
        hashtable[index] = key;
        num_of_keys++;
        return i + 1;
      }
      if (hashtable[index] == key)
      {
        i += 1;
        i = -i;
        return i;
      }
    }
    return 0;
  };

  int quadratic_probing(const unsigned int key)
  {
    for (unsigned int i = 0; i < table_size; i++)
    {
      unsigned int index = hashFunction(key + i * i);
      if (hashtable[index] == 0 || hashtable[index] == thumbstone)
      {
        hashtable[index] = key;
        num_of_keys++;
        return i + 1;
      }
      if (hashtable[index] == key)
      {
        i += 1;
        i = -i;
        return i;
      }
    }
    return 0;
  };

  void check_load_factor()
  {
    float load_factor = (float)getNumofKeys() / (float)getTableSize();
    if (load_factor >= alpha)
    {
      unsigned int *oldTable = hashtable;
      unsigned int oldSize = table_size;
      table_size *= 2;
      hashtable = create_table(table_size);
      for (unsigned int i = 0; i < oldSize; i++)
      {
        if (flag == QUADRATIC_PROBING)
          quadratic_probing(oldTable[i]);

        else
          linear_probing(oldTable[i]);
      }
    }
  };
};

FlatHash::FlatHash(enum overflow_handle _flag, float _alpha)
{
  // Initial table size is 1000
  table_size = 1000;
  num_of_keys = 0;
  flag = _flag;
  alpha = _alpha;

  hashtable = create_table(table_size);
}

FlatHash::~FlatHash()
{
  // Write your code
}

int FlatHash::insert(const unsigned int key)
{
  // You have to implement two overflow handling by using flag
  // Write your code
  int q;
  int l;

  // FLAG = QADRATIC
  if (flag == QUADRATIC_PROBING)
  {
    q = quadratic_probing(key);
    // NOT FOUND in QUADRATIC
    if (q == 0)
    {
      l = linear_probing(key);
      // DUPLICATE
      if (l < 0)
        return l - table_size;
      // LINEAR INSERT
      check_load_factor();
      return l + table_size;
    }
    else
    {
      check_load_factor();
      return q;
    }
  }
  else
  { // FLAG = LINEAR
    l = linear_probing(key);
    check_load_factor();
    return l;
  }
}
int FlatHash::remove(const unsigned int key)
{
  // Write your code
}

int FlatHash::search(const unsigned int key)
{
  // Write your code
}

void FlatHash::clearTombstones()
{
  // Write your code
}

void FlatHash::print()
{
  // Print valid key pair - (index1:key1,index2:key2)
  // Give **NO** space between each character
  // e.g., (1:3,3:7,5:1)
  std::cout << "(";

  // Write your code
  string s = "";
  for (int i = 0; i < table_size; i++)
  {
    if (hashtable[i] != 0)
    {
      s += to_string(i) + ":" + to_string(hashtable[i]) + ",";
    }
  }
  string out = s.substr(0, s.size() - 1);
  cout << out;

  std::cout << ")" << std::endl;
}

#endif
