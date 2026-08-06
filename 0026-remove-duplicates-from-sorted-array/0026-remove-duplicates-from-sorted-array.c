int removeDuplicates(int* nums, int numsSize) {
    int *slow = nums;
    for(int *fast = nums+1;fast < nums+numsSize;fast++){
        if(*fast != *slow){
            *++slow = *fast;
        }
    }
    return (int)(slow - nums + 1);
}