#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define maxN 10000000
int n;
int a[maxN];
long long s;
long long minS;

void bar(int *first, int *last)
{
    int len = last - first + 1;
    int *l = first;
    int *r = last;
    int pivot = *(l + (rand() % len));
    while (l <= r)
    {
        while(*l < pivot) l ++;
        while(*r > pivot) r --;
        if(l <= r)
        {
            int tmp = *l;
            *l = *r;
            *r = tmp;
            l ++;
            r --;
        }
    }
    if(l < last)
        bar(l, last);
    if(first < r)
        bar(first, r);
}

int main()
{
    /* Intializes random number generator */
    srand(time(NULL));
    //printf("get n: "); 
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        //printf("get a[%d] ", i);
        scanf("%d", &a[i]);
    }  
    bar(a, a+n-1);
    //for(int i = 0; i < n; ++i) printf("%d ", a[i]);
    
    // start from a[0];
    s = 0;
    
    for(int i = 1; i < n; ++i)
        s = s + 1LL * abs(a[0] - a[i]);
    minS = s;

    for(int i = 1; i < n; ++i)
    {
        long long diff = 1LL * (a[i] - a[i - 1]);
        s = s + 1LL * (i) * diff - 1LL * (n - i) * diff;
        if(minS > s)
            minS = s;
        //printf("at %d, sum is %lld\n", i, s);
    }
    printf("%lld\n", minS);
    return 0;
}