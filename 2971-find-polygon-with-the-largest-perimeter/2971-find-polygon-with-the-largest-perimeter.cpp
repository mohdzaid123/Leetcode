class MinHeap {
    vector<int> heap;
    int n;
    void adjustDown(int parent) {
        int child = 2 * parent + 1;
        while(child < n) {
            if(child + 1 < n && heap[child + 1] < heap[child]) {
                child++;
            }
            if(heap[child] >= heap[parent]) {
                return ;
            }
            swap(heap[child], heap[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
    }
public:
    MinHeap(const vector<int> &nums): heap {nums} {
        n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--) {
            adjustDown(i);
        }
    }
    int pop() {
        int result = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        n--;
        adjustDown(0);
        return result;
    }
    bool empty() const {
        return n == 0;
    }
};

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        MinHeap pq(nums);
        long long result = -1;
        long long current = pq.pop() + pq.pop();
        while(!pq.empty()) {
            int side = pq.pop();
            if(current > side) {
                result = max(result, current + side);
            }
            current += side;
        }
        return result;

        // O(n) time
        // O(n) space
    }
};