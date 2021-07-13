//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
/* 
Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Example 2:
Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.

 */


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xor1 = 0;
        for(int i = 0 ; i<n ; i++){
            xor1 = xor1 ^ arr[i] ^(i+1);
        }
        int z = xor1&~(xor1-1);
        int x = 0, y = 0;
        for (int i = 0; i<n; i++){
            if(z & arr[i])x = x ^ arr[i];
            else y = y ^ arr[i];
            if(z&(i+1))x = x^(i+1);
            else y = y^(i+1);
        }
        int *ans = (int*)malloc(sizeof(int));
        bool ind = 0;
        for(int i = 0 ; i<n ;i++){
            if(arr[i]==x){
                ind = 1;
                break;
            }
        }
        ans[0] = ind?x:y ;
        ans[1] = x^y^ans[0] ;
        return ans;
    }
};