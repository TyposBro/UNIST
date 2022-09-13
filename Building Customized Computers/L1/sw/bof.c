#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

char* secret = "cBWTwTwC5eKAcDxpwx88";

void print_secret() {
    printf("Ah! %s\n",secret);
}

char buffer[256];
int i;

void receive_input() {
    char buf[128];
    fgets(buffer, 256, stdin);
    strcpy(buf, buffer);
    //print_secret();
}

int run() {
    printf("Can you obtain the secret?\n");
    receive_input();
}

int main() {
    run();
}
