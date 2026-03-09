/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(2* numsSize * sizeof(int));
    int cnt = 0;

    for(int i = 0; i < numsSize * 2; i++){
        if(i < numsSize){
            ans[i] = nums[i];
        }
        else if(i >= numsSize && i < numsSize * 2){
            ans[i] = nums[cnt];

            ++cnt;
        }
    }
    *returnSize = numsSize * 2;
    return ans;
}