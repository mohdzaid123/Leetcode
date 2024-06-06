class Solution {
public:
   bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};