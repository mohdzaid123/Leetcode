#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int ans = 0;
        int i = -1;
        int j = -1;

        std::unordered_map<char, int> mp;

        while (true) {
            bool flag1 = false;
            bool flag2 = false;

            // acquire
            while (i < static_cast<int>(s.length()) - 1) {
                flag1 = true;
                i++;
                char ch = s[i];
                mp[ch]++;

                if (mp[ch] > 1) {
                    break;
                } else {
                    int len = i - j;
                    if (len > ans) {
                        ans = len;
                    }
                }
            }

            while (j < i) {
                flag2 = true;
                j++;
                char ch = s[j];
                mp[ch]--;

                if (mp[ch] == 1) {
                    break;
                }
            }

            if (!flag1 && !flag2) {
                break;
            }
        }
        return ans;
    }
};
