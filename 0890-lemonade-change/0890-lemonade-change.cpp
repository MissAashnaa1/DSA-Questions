class Solution {
public:
        bool lemonadeChange( vector<int> &bills) {
        // code here
        int N=bills.size();
        int five=0,ten=0;
        for(int i=0;i<N;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                ten++;
                if(five){
                    five--;
                }
                else return false;
            }
            else if(bills[i]==20){
                if(ten&&five){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five=five-3;
                }
                else return false;
            }
        }
        return true;
    }
};