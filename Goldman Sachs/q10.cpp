int *findTwoElement(int *arr, int n) {
        // code here
        int i= 0;
        int *res = new int[2];
       
       while(i<n)
       {
           if(arr[i] != arr[arr[i]-1])
           {
               swap(arr[i] , arr[arr[i]-1]);
           }
           else{
               i++;
           }
       }
       
       for(int i=0 ; i<n ; i++)
       {
           if(arr[i] != i+1)
           {
               res[0] = arr[i];
               res[1] = i+1;
               return res;
           }
       }
    }