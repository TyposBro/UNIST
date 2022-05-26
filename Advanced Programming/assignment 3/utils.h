#ifndef UTILS_H
#define UTILS_H

#include "functions.h"
size_t get_input(rna_base *arr);
void print(rna_base const *rna1, size_t len1, rna_base const *rna2, size_t len2, long &shift);
#endif
