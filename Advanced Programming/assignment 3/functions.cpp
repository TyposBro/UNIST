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

int best_alignment(rna_base const *rna1, size_t len1, rna_base const *rna2, size_t len2, long &shift)
{
    using namespace std;
    int score = score_without_realigning(rna1, len1, rna2, len2);
    shift = 0;

    for (size_t tempShift = 1; tempShift < len1; tempShift++)
    {
        int tempScore = 0;
        // cout << "tempShift: " << tempShift << endl;
        for (size_t j = 0; j < len2 and tempShift + j < len1; j++)
        {
            // cout << "j: " << j << endl;
            // cout << "rna1: " << rna1[tempShift + j] << endl;
            // cout << "rna2: " << rna2[j] << endl;

            if (rna1[tempShift + j] == A and rna2[j] == U)
                tempScore++;
            else if (rna1[tempShift + j] == U and rna2[j] == A)
                tempScore++;
            else if (rna1[tempShift + j] == C and rna2[j] == G)
                tempScore++;
            else if (rna1[tempShift + j] == G and rna2[j] == C)
                tempScore++;
            else
                tempScore--;
        }
        if (tempScore > score)
        {
            score = tempScore;
            shift = (long)tempShift;
        }
        else if (tempScore == score and abs((long)tempShift) < abs(shift))
        {
            score = tempScore;
            shift = (long)tempShift;
        }
        // cout << "score: " << score << endl;
        // cout << "tempScore: " << tempScore << endl;
        // cout << "shift: " << shift << endl;
    }

    for (size_t tempShift = 1; tempShift < len1; tempShift++)
    {
        int tempScore = 0;
        for (size_t j = 0; j < len1 and tempShift + j < len2; j++)
        {
            if (rna1[j] == A and rna2[tempShift + j] == U)
                tempScore++;
            else if (rna1[j] == U and rna2[tempShift + j] == A)
                tempScore++;
            else if (rna1[j] == C and rna2[tempShift + j] == G)
                tempScore++;
            else if (rna1[j] == G and rna2[tempShift + j] == C)
                tempScore++;
            else
                tempScore--;
        }
        if (tempScore > score)
        {

            score = tempScore;
            shift = -(long)tempShift;
        }
        else if (tempScore == score and abs((long)tempShift) < abs(shift))
        {

            score = tempScore;
            shift = -(long)tempShift;
        }
    }

    return score;
};