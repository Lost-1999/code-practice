void PercolateUp(int p,int* heap){
    int temp = heap[p];
    int i;
    for(i=p;heap[i/2] > temp;i = i/2){
        heap[i] = heap[i/2];
    }
    heap[i] = temp;
}

void PercolateDown(int p,int* heap,int capacity){
    int i,child;
    int last = heap[p];
    for(i=p;i*2<=capacity;i=child){
        child = i*2;
        if(child != capacity && heap[child] > heap[child+1]){
            child++;
        }
        if(heap[child] < last){
            heap[i] = heap[child];
        }
        else break;
    }
    heap[i] = last;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int heap[k+1];
    heap[0] = -10001;
    int size = 1;
    while(size <= k){
        heap[size] = nums[size-1];
        PercolateUp(size,heap);
        size++;
    }
    for(int i=k;i<numsSize;i++){
        if(nums[i] > heap[1]){
            heap[1] = nums[i];
            PercolateDown(1,heap,k);
        }
    }
    return heap[1];
}