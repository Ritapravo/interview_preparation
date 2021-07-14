//https://leetcode.com/problems/powx-n/

/* 
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

*/

class Solution {
public:
    double myPow(double x, int n) {
        long int y = n;
        if(y<0)y = -1*y;
        double ans = 1;
        while(y>0){
            if(y%2==1) ans = ans* x;
            y = y/2;
            x *= x;
        }
        if(n<0)return 1/ans;
        return ans;
    }
};

// without using long ..... better method
class Solution {
public:
    double myPow(double x, int n) {
        int y = n;
        double ans = 1;
        while(y!=0){
            if(abs(y%2)==1) 
                ans = n>0? ans* x : ans/x; 
            y = y/2;
            x = x*x;
        }
        return ans;
    }
};

//g++ "03_02_pow(x,n).cpp" && a
//g++ "F:\interview_preparation\03_02_pow(x,n).cpp" && a 