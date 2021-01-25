/*
 * 判断一个数是质数还是合数
 */
#include <stdio.h>

int main() {
    for (int i = 2; i <= 100; i++) {
        int state = 0;
        for (int j = 2; j <= i-1; j++) {
            if ( i%j==0 ) {
        	state = 1;
            }
        }
        if (state == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
