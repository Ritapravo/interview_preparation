//https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

//inefficient solution using insertion sort concept
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long int i = 0, j, t;
            while(i<n){
                if(arr1[i]>arr2[0]){
                    t = arr1[i];
                    arr1[i] = arr2[0];
                    arr2[0] = t;
                }
                j = 1;
                t = arr2[0];
                while(j<m && t>arr2[j]){
                    arr2[j-1] = arr2[j];
                    j++;
                }
                arr2[j-1] = t;
                i++;
            }
        } 
};

//efficient solution using gap concept 
class Solution{
    public:
        //Function to merge the arrays.
        void swap (long long int &a, long long int &b){
            long long int t = a;
            a = b;
            b = t;
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long int gap = ceil((float)(n+m)/2), i, j, tmp;
            while(gap>0){
                i = 0;
                j = i + gap;
                while(j<n){
                    if(arr1[i]>arr1[j]){
                        swap(arr1[i], arr1[j]);
                    }
                    i++;j++;
                }
                j = 0;
                if(gap>n) j = gap%n;
                while(i<n && j<m){
                    if(arr1[i]>arr2[j]){
                        swap(arr1[i], arr2[j]);
                    }
                    i++;j++;
                }
                if(j<m){
                    i = 0; j = i+gap;
                    while(j<m){
                        if(arr2[i]>arr2[j]){
                            swap(arr2[i], arr2[j]);
                        }
                        i++;j++;
                    }
                }
                if (gap==1)break;
                gap = ceil((float)gap/2);
            }
        } 
};
