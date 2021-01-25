/*
 * 2020.1.21
 * 读取多行，输出最长
 */
#include <stdio.h>
#define MAXSIZE 100

int getlin(char cs[], int maxsize);
void copy(char cs[], char to[]);

int main() {

    int r;
    int max = 0;
    char cs[MAXSIZE];
    char to[MAXSIZE];
    
    while((r=getlin(cs, MAXSIZE)) != 0) {
	if (max < r) {
	    max = r;
	    copy(cs, to);
	}
    }

    printf("%s\n", to);
    printf("max:%d\n", max);

    return 0;
}

int getlin(char cs[], int maxsize) {
    int i = 0;
    while (i < MAXSIZE) {
	char c = getchar();
	if (c != '\n') {
	    cs[i] = c;
	} else {
	    break;
	}
	i++;
    }
    cs[i] = '\0';

    return i;
}

void copy(char cs[], char to[]) {
    int i = 0;
    while (cs[i] != '\0') {
	to[i] = cs[i];
	i++;
    }
}
