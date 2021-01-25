/*
 * 2020.2.21
 * 字符串翻转
 * */
#include <stdio.h>
#define size 3

void reverse(char cs[], char to[]);

int main() {
    char cs[size] = "123";
    char to[size];

    reverse(cs, to);
    printf("main:%s\n", to);

    return 0;
}

void reverse(char cs[], char to[]) {
    int i = size;
    int i2 = 0;

    while(i-1 >= 0) {
	to[i2] = cs[i-1];
	i--;
	i2++;
    }
}
