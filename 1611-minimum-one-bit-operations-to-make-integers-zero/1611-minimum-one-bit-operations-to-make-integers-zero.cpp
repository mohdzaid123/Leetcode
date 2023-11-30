class Solution {
public:
    int minimumOneBitOperations(int n) {
        int r = n&1;
        // helloo
 
        n>>=1;
        for (int i=2; n>0; i++, n>>=1) if (n&1) r = (1<<i) - r - 1;
        return r;
    }
};