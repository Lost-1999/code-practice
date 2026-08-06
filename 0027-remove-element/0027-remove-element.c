int removeElement(int* nums, int numsSize, int val) {
    int *slow = nums;
    for(int *fast = nums;fast < nums+numsSize;fast++){
        if(*fast != val){
            *slow++ = *fast;
        }
    }
    return (int)(slow-nums);
}