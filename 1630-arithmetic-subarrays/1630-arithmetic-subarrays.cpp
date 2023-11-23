#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;

        for (int i=0; i < l.size(); i++) {
            int left = l[i];
            int right = r[i];

            // Extract subarray  size
            vector<int> subarray(nums.begin() + left, nums.begin() + right + 1);

            // Check if subarray can be rearranged to form an arithmetic sequence
            result.push_back(canFormArithmeticSequence(subarray));
        }

        return result;
    }

private:
    bool canFormArithmeticSequence(const vector<int>& arr) {
        if (arr.size() < 2) {
            return true;  // Single element or empty array is always valid
        }

        // Check if the set of unique elements in the subarray has only one element
        // If yes, the subarray can be rearranged to form an arithmetic sequence
//         check
        unordered_set<int> uniqueElements(arr.begin(), arr.end());

        if (uniqueElements.size() == 1) {
            return true;
        }

        // Sort the subarray and check if the differences are consistents
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int commonDiff = sortedArr[1] - sortedArr[0];
        for (int i = 2; i < sortedArr.size(); ++i) {
            if (sortedArr[i] - sortedArr[i - 1] != commonDiff) {
                return false;
            }
        }

        return true;
    }
};
