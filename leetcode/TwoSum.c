#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target);

int main() {
    int* rv = NULL;
    int nums[3] = {2, 7, 11};
    int numsSize = 3;
    int target = 6;
    rv = twoSum(nums, numsSize, target);

    if (rv != NULL) {
    printf("%d\n", rv[0]);
    printf("%d\n", rv[1]);
    } else {
	printf("NULL\n");
    }

    free(rv);

    return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int* rv = NULL;

    for (int i = 0; i <= numsSize - 2; i++) {
	int j = i + 1;
	if ((nums[i] + nums[j]) == target) {
	    rv = (int*) malloc(2 * sizeof(int));
	    rv[0] = i;
	    rv[1] = j;
	    return rv;
	}
    }

    return NULL;
}
