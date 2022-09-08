#include "functions.h"

int score_without_realigning(rna_base const *rna1, size_t len1, rna_base const *rna2, size_t len2)
{

    size_t len = len1 >= len2 ? len2 : len1;
    int score = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (rna1[i] == A and rna2[i] == U)
            score++;
        else if (rna1[i] == U and rna2[i] == A)
            score++;
        else if (rna1[i] == C and rna2[i] == G)
            score++;
        else if (rna1[i] == G and rna2[i] == C)
            score++;
        else
            score--;
    }

    return score;
}

int best_alignment(rna_base const *rna_array_1, size_t count1, rna_base const *rna_array_2, size_t count2, long &shift)
{
    return -1;
};