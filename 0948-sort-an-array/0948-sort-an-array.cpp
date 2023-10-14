class Solution {
public:

    void heapify(vector<int>& arr, int n, int i)  
    {
      int largest=i;
      int l=2*i+1, r=2*i+2;
      if(l<n && arr[l]>arr[largest]){
          largest=l;
      }
      if(r<n && arr[r]>arr[largest]){
          largest=r;
      }
      
      if(largest!=i){
          swap(arr[i],arr[largest]);
          heapify(arr,n,largest);
      }
      
    }

    void buildHeap(vector<int>& arr, int n)  
    { 
    for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,n,i);
    }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
         buildHeap(nums,n);
        for(int i=n-1;i>=1;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }

         return nums;
    }
};