#ifndef FLATHASH_H
#define FLATHASH_H

#include <iostream>
using namespace std;

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
  int linear_probing(const unsigned int key);
  int quadratic_probing(const unsigned int key);
  void check_load_factor();
  int _remove(const unsigned int key, bool isLinear);
  unsigned int *rehash_resize();
  unsigned int *rehash();
  int _search(const unsigned int key, const bool isLinear);
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
  int res = 0;
  int q = 0;
  int l = 0;

  // FLAG QUADRATIC
  if (flag == QUADRATIC_PROBING)
  {
    q = _remove(key, false);
    // QUADRATIC FAILED
    if (q == -1 - table_size)
    {
      // LINEAR
      l = _remove(key, true);
      // TODO: LEFT SHIFT @88
      // LINEAR FOUND
      if (l > 0)
      {
        hashtable = rehash();
        return l + table_size;
      }
      // BOTH QUADRATIC & LINEAR TILL LAST FAILED
      if (l == -1 - table_size)
      {
        res = -2 * table_size;
        return res;
      }
      // LINEAR REACHED 0
      return l - table_size;
    }

    return res;
  }

  res = _remove(key, true);
  // TODO: LEFT SHIFT @88
  if (res > 0)
    hashtable = rehash();
  if (res == -1 - table_size)
  {
    res = -table_size;
    return res;
  }

  return res;
}

int FlatHash::search(const unsigned int key)
{
  // Write your code
  int res = 0;
  int q = 0;
  if (flag == QUADRATIC_PROBING)
  {
    q = _search(key, false);
    if (q == -table_size)
    {
      res = _search(key, true);
      if (res < 0)
      {
        return res - table_size;
      }
      return res + table_size;
    }
    return q;
  }
  // FLAG LINEAR
  res = _search(key, true);
  return res;
}

void FlatHash::clearTombstones()
{
  // Write your code
  for (unsigned int i = 0; i < table_size; i++)
  {
    if (hashtable[i] == thumbstone)
      hashtable[i] = 0;
    hashtable = rehash();
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
  unsigned int thumbstone = 1000001;
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
      i += 1;
      i = -i;
      return i;
    }
  }
  return 0;
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

int FlatHash::linear_probing(const unsigned int key)
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

int FlatHash::quadratic_probing(const unsigned int key)
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

void FlatHash::check_load_factor()
{
  float load_factor = (float)getNumofKeys() / (float)getTableSize();
  if (load_factor >= alpha)
  {
    hashtable = rehash_resize();
  }
};

int FlatHash::_remove(const unsigned int key, bool isLinear)
{
  int res = 0;
  for (unsigned int i = 0; i < table_size; i++)
  {
    unsigned int input = isLinear ? key + i : key + i * i;
    unsigned int index = hashFunction(input);
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

  res = -1 - table_size;
  return res;
}

unsigned int *FlatHash::rehash_resize()
{
  unsigned int *newTable = create_table(table_size * 2);
  for (unsigned int i = 0; i < table_size; i++)
  {
    if (hashtable[i] != 0 && hashtable[i] != thumbstone)
    {
      bool isLinear = (flag == LINEAR_PROBING) ? true : false;
      _probing(hashtable[i], newTable, table_size * 2, isLinear);
    }
  }
  delete[] hashtable;
  table_size *= 2;
  return newTable;
}

unsigned int *FlatHash::rehash()
{
  unsigned int *newTable = create_table(table_size);
  for (unsigned int i = 0; i < table_size; i++)
  {
    if (hashtable[i] != 0 && hashtable[i] != thumbstone)
    {
      bool isLinear = (flag == LINEAR_PROBING) ? true : false;
      _probing(hashtable[i], newTable, table_size, isLinear);
    }
  }
  delete[] hashtable;
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

  res = -table_size;
  return res;
}

#endif
