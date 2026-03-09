/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int *result =(int*)malloc(2 * sizeof(int));
    long S = numsSize * (numsSize + 1) / 2;
    long double P = 1;

    for(int i = 0; i < numsSize; i++) {
        S -= nums[i];
        P *= (long double) (numsSize - i) / nums[i];
    }

    result[0] = round(S / (P - 1));
    result[1] = result[0] + S;

    *returnSize = 2;
    return result;
}