/*
 * 2020.2.21
 * 空格替换为Tab与空格
 * */
#include <stdio.h>

int main () {
    char cs[50] = "000000000000000000000000";
    int size = 0;
    int a, b;
    while (cs[size] != '\0') {
	size++;
    }
    a = size / 8;
    b = size % 8;
    for (int i = 0; i < a; i++) {
	printf("Tab-----");
    }
    for (int i = 0; i < b; i++) {
	printf("0");
    }
    printf("\n");

    return 0;
}
