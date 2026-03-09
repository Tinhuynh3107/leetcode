int maxArea(int* height, int heightSize) {
    int curr_area = 0;
    int max_area = 0;
    int i = 0;
    int j = heightSize - 1;

    while(i < j){

        curr_area = (j-i) * fmin(height[j], height[i]);
        if(curr_area > max_area){
            max_area = curr_area;
        }

        if(height[i] < height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return max_area;
}