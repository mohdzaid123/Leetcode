class Solution {
public:
    int countOneBits(int num) {
        
        int count = 0;
        while (num) {
            
            count += num & 1;
            
            num >>= 1;
        }
        
        return count;
        
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int &a, int &b) {
            
            int count_a = __builtin_popcount(a);
            // int count_a = countOneBits(a);
            // int count_b = countOneBits(b);
            int count_b = __builtin_popcount(b);
            
            if(count_a == count_b)
                return a<b;
            
            return count_a < count_b;
            
        };
        
        sort(begin(arr), end(arr), lambda);
        
        return arr;
    }
};