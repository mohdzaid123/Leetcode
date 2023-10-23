class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return 0;
        }
       int x=(log(n)/log(4));

       if(pow(4,x)==n){
           return true;
       }
       return false;

    }
};