long long int merge(long long arr[], long long low, long long mid, long long high){
    long long n1 = mid - low + 1, n2 = high - mid;
    long long a[n1], b[n2];
    for(long long int i = 0; i<n1-1; i++)a[i]=arr[low+i];
    for(long long int j = 0; j<n2-1; j++)b[j]=arr[mid+1+j];
    long long i=0, j=0, k=low, count = 0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j])arr[k++]=arr[i++];
        else{
            count += mid -(low+i) + 1;
        }
        while(i<n1)arr[k++]=a[i++];
        while(j<n2)arr[k++]=b[j++];
    }
    return count;
}

long long int mergesort(long long arr[], long long low, long long high){
    
    if(low<high){
        long long mid = low + (high-low)/2 ;
        return    mergesort(arr, low, mid)
                + mergesort(arr, mid+1, high)
                + merge(arr, low, mid, high);
    }
    return 0;
}


long long int inversionCount(long long arr[], long long N)
{
    return mergesort(arr, 0, N-1);
}





/* ============================================================================================= */




long long int merge(long long int arr[], long long int l, long long int mid, long long int h){
    long long int n1 = mid-l+1, n2 = h-mid, inv =0;
    long long int a[n1], b[n2];
    for(long long int i=0; i<n1; i++)a[i] = arr[l+i];
    for(long long int i=0; i<n2; i++)b[i] = arr[mid+i+1];
    long long int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j])arr[k++]=a[i++];
        else{ 
            arr[k++] = b[j++];
            inv += mid -(l+i) + 1;
        }
    }
    while(i<n1)arr[k++]=a[i++];
    while(i<n2)arr[k++]=b[j++]; 
    return inv; 
}

long long int inversions(int arr[], long long int l, long long int h){
    if(l<h){
        long long int mid = (l+h)/2;
        return  inversions(arr, l, mid)+
                inversions(arr, mid +1, h)+
                merge(arr, l, mid, h);
    }
    return 0;
}


long long int inversionCount(long long arr[], long long N)
{
    return inversions(arr, 0, N-1);
}






