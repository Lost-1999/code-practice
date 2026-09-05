void PercolateUp(int p,int* heap){
    if(p==0)return;
    int temp = heap[p];
    int i;
    for(i=p;i>0 && heap[(i-1)/2] > temp;i = (i-1)/2){
        heap[i] = heap[(i-1)/2];
    }
    heap[i] = temp;
}

void PercolateDown(int p,int* heap,int capacity){
    int i,child;
    int last = heap[p];
    for(i=p;i*2+1<capacity;i=child){
        child = i*2+1;
        if(child+1 < capacity && heap[child] > heap[child+1]){
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
    int heap[k];
    int size = 0;
    while(size < k){
        heap[size] = nums[size];
        PercolateUp(size,heap);
        size++;
    }
    for(int i=k;i<numsSize;i++){
        if(nums[i] > heap[0]){
            heap[0] = nums[i];
            PercolateDown(0,heap,k);
        }
    }
    return heap[0];
}