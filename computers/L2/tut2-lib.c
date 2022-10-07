#include <stdlib.h>
#include <stdio.h>

void hello(void) {
    printf("Have I called?\n");
}

long add(long a) {
    return a + 1;
}

void dump(long a) {
    printf("???: %ld\n",a);
}
