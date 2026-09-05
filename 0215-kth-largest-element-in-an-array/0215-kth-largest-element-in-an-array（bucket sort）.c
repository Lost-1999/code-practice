#define SIZE 20001
#define OFFSET 10000
int findKthLargest(int* nums, int numsSize, int k) {
    int val[SIZE] = {0};
    for(int i=0;i<numsSize;i++){
        val[nums[i]+OFFSET]++;
    }
    for(int i=SIZE-1;i>=0;i--){
        if(k<=val[i])return i-OFFSET;
        else k-=val[i];
    }
    return -1;    
}
