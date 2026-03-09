double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double median;

    int* nums3 = malloc((nums1Size + nums2Size) * sizeof(int));

    for(int i = 0; i < nums1Size; i++){
        nums3[i] = nums1[i];
    }

    for(int i = 0; i < nums2Size; i++){
        nums3[nums1Size + i] = nums2[i];
    }

    int temp;
    for(int i = 0; i < nums1Size + nums2Size; i++){
        for(int j = i + 1; j < nums1Size + nums2Size; j++){
            if(nums3[i] > nums3[j]){
                temp = nums3[i];
                nums3[i] = nums3[j];
                nums3[j] = temp;
            }
        }
    }

    int n = nums1Size + nums2Size;

    if(n %2 == 0){
        median = (nums3[n/2] + nums3[n/2 - 1]) / 2.0;
    }
    else{
        median = nums3[n/2];
    }
    return median;
}