class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
         int n=arr.size();
        if (n<=k) return *max_element(arr.begin(), arr.end());
        deque<int> q(arr.begin()+1, arr.end());
        int count=0, winner=arr[0];
        while(count<k){
            int x=q.front();
            if (x>winner){
                q.push_back(winner);
                winner=x;
                count=1;
                q.pop_front();
            }
            else{
                count++;
                q.pop_front();
                q.push_back(x);
            }
        }
        return winner;
    
    }
};