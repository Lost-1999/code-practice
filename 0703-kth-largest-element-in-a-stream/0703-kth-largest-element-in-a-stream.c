


typedef struct {
    int size;
    int capacity;
    int *heap;
} KthLargest;

void PercolateDown(int p,KthLargest *H){
    int i,child;
    int last = H->heap[p];
    for(i=p;i*2<=H->size;i=child){
        child = i*2;
        if(child != H->size && H->heap[child] > H->heap[child+1]){
            child++;
        }
        if(last > H->heap[child]){
            H->heap[i] = H->heap[child];
        }
        else break;
    }
    H->heap[i] = last;
}
 
void PercolateUp(int x,KthLargest *H){
    int i;
    for(i=++H->size;H->heap[i/2] > x;i/=2){
        H->heap[i] = H->heap[i/2];
    }
    H->heap[i] = x;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if(obj->size < obj->capacity){
        PercolateUp(val,obj);
    }
    else{
        if(obj->heap[1] <= val){
            obj->heap[1] = val;
            PercolateDown(1,obj);
        }
    }
    return obj->heap[1];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *H = malloc(sizeof(*H));
    H->size = 0;
    H->capacity = k;
    H->heap = malloc(sizeof(int)*(k+1));
    H->heap[0] = -10000;
    if(numsSize < k){
        for(int i=1;i<=numsSize;i++){
            PercolateUp(nums[i-1],H);
        } 
    }
    else{
        for(int i=1;i<=k;i++){
            PercolateUp(nums[i-1],H);
        }
        for(int i=k;i<numsSize;i++){
            kthLargestAdd(H,nums[i]);
        } 
    }
    return H;
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/