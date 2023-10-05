class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();

        if(t.length()>n){
            return "";
        }
        unordered_map<char,int> mp;

        // store karliya
        for(char&ch:t){
            mp[ch]++;
        }

        int requiredCount=t.length();
        int i=0,j=0;
        int minWindowSize=INT_MAX;
        int start_i=0;
        // 
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0){      //mp a->1
                requiredCount--;
            }
            mp[ch]--;

            while(requiredCount==0){
                // start shrinking the value
                int currWindowSize=j-i+1;
                if(minWindowSize>currWindowSize){
                    minWindowSize=currWindowSize;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }

        return minWindowSize==INT_MAX? "":s.substr(start_i,minWindowSize);

    }
};