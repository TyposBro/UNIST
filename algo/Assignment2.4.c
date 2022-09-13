
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define Length 10000000

void bar(int *first, int *last)
{
    int cur_size = last - first + 1;
    int *left = first;
    int *right = last;
    int piv = *(left + (rand() % cur_size));
    do
    {
        if (left > right)
            break;

        while (*right > piv)
            right--;
        while (*left < piv)
            left++;
        if (left <= right)
        {
            int foo = *left;
            *left = *right;
            *right = foo;
            right--;
            left++;
        }
    } while (1);

    if (first < right)
        bar(first, right);
    if (left < last)
        bar(left, last);
}

int len = 0;
int arr[Length];
long long sum = 0;
long long res = 0;
int i = 0;
int main()
{

    //* generate random number
    srand(time(NULL));

    // printf("Array Length: ");
    scanf("%d", &len);

    while (i < len)
    {
        scanf("%d", &arr[i]);
        i++;
    }

    bar(arr, arr + len - 1);
    i = 1;
    while (i < len)
    {
        sum += 1LL * abs(arr[0] - arr[i]);
        i++;
    }
    res = sum;

    int i = 1;
    while (i < len)
    {
        long long d = (arr[i] - arr[i - 1]) * 1LL;
        sum += 1LL * (i)*d - 1LL * (len - i) * d;
        if (res > sum)
            res = sum;
        i++;
    }
    printf("%lld\n", res);
    return 0;
}