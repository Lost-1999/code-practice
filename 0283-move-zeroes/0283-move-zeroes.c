void moveZeroes(int* nums, int numsSize) {
    int numof0 = 0;
    int *slow = nums;
    for(int *fast = nums;fast < nums+numsSize;fast++){
        if(*fast == 0){
            numof0++;
        }
        else{
            *slow++ = *fast;
        }
    }
    while(numof0--){
        *slow++ = 0;
    }
}