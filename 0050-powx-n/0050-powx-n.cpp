class Solution {
 double m(double x, int n) {
		// Your code goes here
        if(n==0)return 1;
        if(n<0){
            n=abs(n);
            x=1/x;
        }
        if(n%2)
        return m(x,n-1)*x;
        else return m(x*x,n/2);
	}
public:
	double myPow(double x, int n) {
		// Your code goes here
       
    return m(x,n);
	}
};