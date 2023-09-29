class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                increasing = false;
            } else if (nums[i] < nums[i + 1]) {
                decreasing = false;
            }

            // If both flags are false, it's not monotonic.
            if (!increasing && !decreasing) {
                return false;
            }
        }

        return true; // If either flag is true, it's monotonic.
    }
};
