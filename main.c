#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int capacity = 1000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

// Helper function to print the results
void printResult(int** result, int resultSize, int* columnSizes) {
    printf("[");
    for (int i = 0; i < resultSize; i++) {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < columnSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i < resultSize - 1) printf(",");
    }
    printf("]\n");
}

// Helper function to free allocated memory
void freeResult(int** result, int resultSize) {
    for (int i = 0; i < resultSize; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    // Test case 1: [-1,0,1,2,-1,-4]
    int nums1[] = {-1, 0, 1, 2, -1, -4};
    int returnSize1;
    int* returnColumnSizes1;
    printf("\nTest Case 1: Input = [-1,0,1,2,-1,-4]\n");
    printf("Output: ");
    int** result1 = threeSum(nums1, sizeof(nums1)/sizeof(nums1[0]), &returnSize1, &returnColumnSizes1);
    printResult(result1, returnSize1, returnColumnSizes1);
    freeResult(result1, returnSize1);
    free(returnColumnSizes1);

    // Test case 2: [0,1,1]
    int nums2[] = {0, 1, 1};
    int returnSize2;
    int* returnColumnSizes2;
    printf("\nTest Case 2: Input = [0,1,1]\n");
    printf("Output: ");
    int** result2 = threeSum(nums2, sizeof(nums2)/sizeof(nums2[0]), &returnSize2, &returnColumnSizes2);
    printResult(result2, returnSize2, returnColumnSizes2);
    freeResult(result2, returnSize2);
    free(returnColumnSizes2);

    // Test case 3: [0,0,0]
    int nums3[] = {0, 0, 0};
    int returnSize3;
    int* returnColumnSizes3;
    printf("\nTest Case 3: Input = [0,0,0]\n");
    printf("Output: ");
    int** result3 = threeSum(nums3, sizeof(nums3)/sizeof(nums3[0]), &returnSize3, &returnColumnSizes3);
    printResult(result3, returnSize3, returnColumnSizes3);
    freeResult(result3, returnSize3);
    free(returnColumnSizes3);

    return 0;
}
