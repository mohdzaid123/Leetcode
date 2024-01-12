class Solution {
public:
    bool isVowels(char &ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    bool halvesAreAlike(string s) {
        int n=s.length();

        int mid=n/2;

        int i=0,j=mid;

        int countL=0;
        int countR=0;

        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        while(i<n/2&&j<n){
            if(isVowels(s[i])) countL++;

            if(isVowels(s[j])) countR++;

            i++;
            j++;
        }
        return countL==countR;
    }
};