#include <stdlib.h>
#include <stdio.h>
void* alloc(void) {
    void* ret = malloc(1024);
    return ret;
}

void report_error(unsigned long found){
    printf("detected error! found ret: %lx\n", found);
}
