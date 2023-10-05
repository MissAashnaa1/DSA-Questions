//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{   
    long long int atmost(string &s,int k){
        int left=0;
        long long int ans=0;
        int freq[26]={0};
        int distinct=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==1){
                distinct++;
            }
            while(distinct>k){
                freq[s[left]-'a']--;
                if(freq[s[left]-'a']==0){
                    distinct--;
                }
                left++;
            }
            ans+=i-left+1;// kisi bi jgh se shuru krenge to jitni length hogi utne hi bnenge atmost distinct strings
            //aaabc => koi frk ni pdhta ki koi kitni br repeat horha h ya kuch
            //we are just looking for the strings when distinct count < k then how many strings could be made
            // while staying with in the limit
            //agr k =3
            //a 1 
            //a aa 2 
            //a aa aaa 3 
            //b ab aab aaab 4 
            //c bc abc aabc aaabc 5
            // when k=2
            //a 1
            //a aa 2
            //a aa aaa 3 
            //aaab aab ab b 4
            //c cb 2
        }
        return ans;
    }
  public:
    long long int substrCount (string s, int k) {
    return atmost(s,k)-atmost(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends