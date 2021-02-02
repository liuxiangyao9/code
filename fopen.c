#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.c", "r");

    while (1) {
	if ( feof(fp) )
	    break;
	int c = fgetc(fp);
	printf("%c", c);
    }
    
    fclose(fp);

    return 0;
}
