
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define maxN 10000000
int n;
int a[maxN];
long long s;
long long minS;

void shot(int *first, int *last)
{
    int len = last - first + 1;
    int *l = first;
    int *r = last;
    int pivot = *(l + (rand() % len));
    while (l <= r)
    {
        while (*l < pivot)
            l++;
        while (*r > pivot)
            r--;
        if (l <= r)
        {
            int tmp = *l;
            *l = *r;
            *r = tmp;
            l++;
            r--;
        }
    }
    if (l < last)
        shot(l, last);
    if (first < r)
        shot(first, r);
}

int main()
{
    /* Intializes random number generator */
    srand(time(NULL));

    printf("Array Length: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        printf("%dth element of the Array: ", i + 1);
        scanf("%d", &a[i]);
    }

    shot(a, a + n - 1);

    s = 0;
    for (int i = 1; i < n; ++i)
        s = s + 1LL * abs(a[0] - a[i]);
    minS = s;

    for (int i = 1; i < n; ++i)
    {
        long long diff = 1LL * (a[i] - a[i - 1]);
        s = s + 1LL * (i)*diff - 1LL * (n - i) * diff;
        if (minS > s)
            minS = s;
    }
    printf("%lld\n", minS);
    return 0;
}