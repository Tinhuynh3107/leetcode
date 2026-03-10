/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool *result = malloc(candiesSize * sizeof(bool));
    int max = candies[0];
    int i = 0;

    for(int i = 1; i < candiesSize; i++){
        if(candies[i] > max) max = candies[i];
    }
    
    while(i < candiesSize){

        if(candies[i] + extraCandies >= max){
            result[i] = 1;
        }
        else result[i] = 0;
        i++;
    }

    
    
    *returnSize = candiesSize;
    return result;
}