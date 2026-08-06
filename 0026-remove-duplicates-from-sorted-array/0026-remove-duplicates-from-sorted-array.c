int removeDuplicates(int* nums, int numsSize) {
    int *first = nums;
    int *second = nums + 1;
    while(second < nums+numsSize){
        if(*second != *first){
            *++first = *second;
        }
        second++;
    }
    return (int)(first - nums + 1);
}