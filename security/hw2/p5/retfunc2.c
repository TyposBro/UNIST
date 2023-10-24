#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE (512)

void read_and_print_flag(void) {
    char arg[] = "cat /home/retfunc2/flag.txt";
    setreuid(geteuid(), geteuid()); 
    system(arg);
}

void printer(char* str) {
    char buf[BUFSIZE];
    strcpy(buf, str);
    printf("%s\n", buf);
}

int main() {
    setbuf(stdout,NULL);

    char line[520];

    printf("Input: ");
    gets(line);
    if (strlen(line) > BUFSIZE ) {
        printf("Failed!");
        exit(0);
    }
    printer(line);

    return 0;
}


