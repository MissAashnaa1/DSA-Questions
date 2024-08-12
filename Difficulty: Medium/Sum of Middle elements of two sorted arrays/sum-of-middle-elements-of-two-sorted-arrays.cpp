//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
      int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int m = arr1.size(), n = arr2.size();
        vector <int> arr3(m+n);
        for(int i = 0 ;i<m;i++){
            arr3[i] = arr1[i];
        }
        for(int i = 0;i<n;i++) arr3[i + m] = arr2[i];
        sort(arr3.begin(),arr3.end());
        int mid= (m+n)/2;
        int sum = arr3[mid]+arr3[mid - 1];
        return sum;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends