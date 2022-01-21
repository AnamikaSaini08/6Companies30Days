int partition(char arr[] , int beg , int end)
    {
    int left,right,flag=1,loc,temp;
    left=beg;
    right=end;
    loc=left;
    while(1)
    {
        if(flag)
        {
            while( (left!=right) && (arr[loc]<=arr[right]) )
                right--;
            
            if(left == right)
               return loc;
               
            swap(arr[loc] , arr[right]);
            loc = right;
            flag=0;
        }
        else{
             while( (left!=right) && (arr[left]<=arr[loc]) )
                left++;
            if(left == right)
               return loc;
               
            swap(arr[loc] , arr[left]);
            loc = left;
            flag=1;
        }
    }
    }
    void quickSort(char arr[] , int low , int high)
    {
         if(high>low )
    {
        int loc=partition(arr , low , high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    quickSort(nuts , 0 , n-1);
	    quickSort(bolts , 0 , n-1);
	}