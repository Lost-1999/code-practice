void moveZeroes(int* nums, int numsSize) {
    int *slow = nums;
    int *end = nums+numsSize;
    for(int *fast = nums;fast < nums+numsSize;fast++){
        if(*fast != 0){
            *slow++ = *fast;
        }
    }
    while(slow < end){
        *slow++ = 0;
    }
}