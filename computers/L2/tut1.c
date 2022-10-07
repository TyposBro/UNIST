#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>

char* secret = "cBWTwTwC5eKAcDxpwx88";

void print_secret() {
    printf("Ah! %s\n",secret);
    exit(0);
}

char buffer[256];
int i;
void* frame;

void dump_frame(void* frame) {
    uint64_t* pt = (uint64_t*)frame;
    int i = 0;
    for(i = 0; i < 16; i +=1) {
        printf("[%p, %d]: %lx\n", pt-i, i, *(pt-i));
        fflush(stdout);
    }
}

void receive_input() {
    char buf[128];
    frame = __builtin_frame_address(0);
    dump_frame(frame);
    fgets(buffer, 256, stdin);
    strcpy(buf, buffer);
    dump_frame(frame);
}

int run() {
    printf("Can you obtain the secret?\n");
    receive_input();
    printf("returning correctly\n");
}

int main() {
    run();
}
