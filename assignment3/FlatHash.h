#ifndef FLATHASH_H
#define FLATHASH_H

#include <iostream>
using namespace std;

// TODO: REHASH
// TODO: LOAD_FACTOR

// TODO: REMOVE LEFT_SHIFT
// TODO: TEST

int _probing(const unsigned int key, unsigned int *local_hashtable, unsigned int size, bool isLinear);
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
  unsigned int *create_table(const unsigned int size);
  int _insert(const unsigned int key, bool isLinear);
  void check_load_factor();
  int _remove(const unsigned int key, bool isLinear);
  unsigned int *rehash(const int factor);
  int _search(const unsigned int key, const bool isLinear);
  unsigned int *shift(const int factor);
};

FlatHash::FlatHash(enum overflow_handle _flag, float _alpha)
{
  // Initial table size is 1000
  // FIXME: 1000
  table_size = 1000;
  num_of_keys = 0;
  flag = _flag;
  alpha = _alpha;

  hashtable = create_table(table_size);
}

FlatHash::~FlatHash()
{
  // Write your code
  if (table_size != 0)
  {
    delete[] hashtable;
    table_size = 0;
  }
}

int FlatHash::insert(const unsigned int key)
{
  // You have to implement two overflow handling by using flag
  // Write your code
  int quadratic;
  int linear;

  // FLAG = QADRATIC
  if (flag == QUADRATIC_PROBING)
  {
    quadratic = _insert(key, false);
    // NOT FOUND in QUADRATIC
    if (quadratic == 0)
    {
      linear = _insert(key, true);
      // DUPLICATE
      if (linear < 0)
        return linear - table_size;

      // LINEAR INSERT
      check_load_factor();
      return linear + table_size;
    }
    else
    {
      check_load_factor();
      return quadratic;
    }
  }
  else
  { // FLAG = LINEAR
    linear = _insert(key, true);

    check_load_factor();
    return linear;
  }
}
int FlatHash::remove(const unsigned int key)
{
  // Write your code

  int quadratic = 0;
  int linear = 0;

  // FLAG QUADRATIC
  if (flag == QUADRATIC_PROBING)
  {
    quadratic = _remove(key, false);
    // QUADRATIC FAILED
    if (quadratic == 0)
    {
      // LINEAR
      linear = _remove(key, true);
      // TODO: LEFT SHIFT @88
      // LINEAR FOUND
      if (linear > 0)
      {
        hashtable = rehash(1);
        return linear + table_size;
      }
      // BOTH QUADRATIC & LINEAR TILL LAST FAILED
      if (linear == 0)
      {
        int temp = -2 * table_size;
        return temp;
      }
      // LINEAR KEY NOT FOUND / REACHED EMPTY BUCKET
      return linear - table_size;
    }

    return quadratic;
  }

  // FLAG LINEAR
  linear = _remove(key, true);
  // TODO: LEFT SHIFT @88
  if (linear > 0)
    hashtable = rehash(1);
  if (linear == 0)
  {
    linear = -table_size;
    return linear;
  }

  return linear;
}

int FlatHash::search(const unsigned int key)
{
  // Write your code
  int linear = 0;
  int quadratic = 0;
  // QUADRATIC
  if (flag == QUADRATIC_PROBING)
  {

    quadratic = _search(key, false);
    // QUADRATIC FAILED
    if (quadratic == 0)
    {
      // LINEAR FOUND
      linear = _search(key, true);
      if (linear > 0)
        return linear + table_size;
      // LINEAR FAILED
      if (linear == 0)
      {
        return -2 * table_size;
      }
      return linear - table_size;
    }

    return quadratic;
  }
  // FLAG LINEAR
  linear = _search(key, true);
  if (linear == 0)
  {
    int temp = -table_size;
    return temp;
  }
  return linear;
}

void FlatHash::clearTombstones()
{
  // Write your code
  for (unsigned int i = 0; i < table_size; i++)
  {
    if (hashtable[i] == thumbstone)
      hashtable[i] = 0;
    hashtable = rehash(1);
  }
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

int _probing(const unsigned int key, unsigned int *local_hashtable, unsigned int size, bool isLinear)
{
  int res = 0;
  unsigned int thumbstone = 1000001;
  // QUADRATIC or LINEAR
  for (unsigned int i = 0; i < size; i++)
  {
    unsigned int index = (isLinear) ? (key + i) % size : (key + i * i) % size;

    if (local_hashtable[index] == 0 || local_hashtable[index] == thumbstone)
    {
      local_hashtable[index] = key;

      return i + 1;
    }
    if (local_hashtable[index] == key)
    {

      res = -i - 1;
      return res;
    }
  }

  // QUADRATIC FAILED, LINEAR
  for (unsigned int i = 0; i < size; i++)
  {
    unsigned int index = (key + i) % size;

    if (local_hashtable[index] == 0 || local_hashtable[index] == thumbstone)
    {
      local_hashtable[index] = key;

      return i + 1;
    }
    if (local_hashtable[index] == key)
    {

      res = -i - 1;
      return res;
    }
  }
  return res;
};

unsigned int *FlatHash::create_table(const unsigned int size)
{
  unsigned int *table = new unsigned int[size];
  for (unsigned int i = 0; i < size; i++)
  {
    table[i] = 0;
  }

  return table;
}

int FlatHash::_insert(const unsigned int key, bool isLinear)
{
  int res = 0;
  for (unsigned int i = 0; i < table_size; i++)
  {
    unsigned int index = isLinear ? hashFunction(key + i) : hashFunction(key + i * i);

    if (hashtable[index] == 0 || hashtable[index] == thumbstone)
    {
      hashtable[index] = key;
      num_of_keys++;
      return i + 1;
    }
    if (hashtable[index] == key)
    {

      res = -i - 1;
      return res;
    }
  }
  return res;
};

void FlatHash::check_load_factor()
{
  float load_factor = (float)getNumofKeys() / (float)getTableSize();
  if (load_factor >= alpha)
  {
    hashtable = rehash(2);
  }
};

int FlatHash::_remove(const unsigned int key, bool isLinear)
{
  int res = 0;
  for (unsigned int i = 0; i < table_size; i++)
  {
    unsigned int index = isLinear ? hashFunction(key + i) : hashFunction(key + i * i);
    if (hashtable[index] == key)
    {
      hashtable[index] = thumbstone;
      num_of_keys--;
      return i + 1;
    }
    if (hashtable[index] == 0)
    {
      res = -i - 1;
      return res;
    }
  }

  return res;
}

unsigned int *FlatHash::rehash(const int factor)
{
  unsigned int *newTable = create_table(table_size * factor);
  for (unsigned int i = 0; i < table_size; i++)
  {
    if (hashtable[i] != 0 && hashtable[i] != thumbstone)
    {
      bool isLinear = (flag == LINEAR_PROBING) ? true : false;
      _probing(hashtable[i], newTable, table_size * factor, isLinear);
    }
  }
  delete[] hashtable;
  table_size *= factor;
  return newTable;
}
int FlatHash::_search(const unsigned int key, const bool isLinear)
{
  int res = 0;
  for (unsigned int i = 0; i < table_size; i++)
  {
    unsigned int index = (isLinear) ? hashFunction(key + i) : hashFunction(key + i * i);
    if (hashtable[index] == key)
      return i + 1;

    if (hashtable[index] == 0)
    {
      res = -i - 1;
      return res;
    }
  }

  return res;
}

unsigned int *FlatHash::shift(const int index)
{
  unsigned int *newTable = create_table(table_size);
  int i = index;

  do
  {
    bool isLinear = (flag == LINEAR_PROBING) ? true : false;
    if (hashtable[i] == 0)
      break;

    if (hashtable[i] != thumbstone)
      _probing(hashtable[i], newTable, table_size, isLinear);

    i = (i + 1) % table_size;
  } while (index != i);

  do
  {

    if (hashtable[i] == 0 || flag == LINEAR_PROBING)
      break;

    if (hashtable[i] != thumbstone)
      _probing(hashtable[i], newTable, table_size, true);

    i = (i + 1) % table_size;
  } while (index != i);

  delete[] hashtable;
  return newTable;
}

#endif
