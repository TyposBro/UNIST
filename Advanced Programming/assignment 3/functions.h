#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_LEN 1000
#include <iostream>
enum rna_base
{
    A,
    C,
    U,
    G
};
int score_without_realigning(rna_base const *, size_t, rna_base const *, size_t);

int best_alignment(rna_base const *, size_t, rna_base const *, size_t, long &);

#endif