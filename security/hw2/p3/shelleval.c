#include<stdio.h>

int main(void) {
    setbuf(stdout,NULL);

    char shellcode[100];

    printf("Your shellcode: ");
    gets(shellcode);

    printf("%s", shellcode);

    int (*shell)();
    shell = (int (*)()) shellcode;
    (int)(*shell)();
    return 0;
}
