int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            cnt++;
        }
        if(nums[i] == 0 || i == numsSize - 1){
            ans = cnt > ans ? cnt : ans;
            cnt = 0;
        }
    }
    return ans;
}