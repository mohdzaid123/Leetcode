class Solution {
public:
    int totalMoney(int n) {
        int terms=n/7;
        
        int first=28;
        
        int last=28+(terms-1)*7;  //AP formula for nth term
        
        int result=terms*(first+last)/2;
//         final week remaining days
        int start_money=1+terms;
        // int result=0;
        for(int day=1;day<=(n%7);day++){
            result+=start_money;
            start_money++;
        }
        return result;
        
    }
};