int binarySearch_inc( MountainArray &arr , int target , int lb , int ub)
    {
        int ans = -1;
        while(lb <=ub)
        {
            int mid = lb+(ub-lb)/2;
            if(arr.get(mid) == target)
                return mid;
            
            if(arr.get(mid) > target)
                ub = mid-1;
            else
                lb = mid+1;
        }
        return ans;
    }
     int binarySearch_dec( MountainArray &arr , int target , int lb , int ub)
    {
        int ans = -1;
        while(lb <=ub)
        {
            int mid = lb+(ub-lb)/2;
            if(arr.get(mid) == target)
                return mid;
            
            if(arr.get(mid) > target)
                lb = mid+1;
            else
                ub = mid-1;
        }
        return ans;
    }
    
    int peakElement( MountainArray &arr)
    {
         int start = 0;
        int end = arr.length() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(arr.get(mid) > arr.get(mid + 1))
                end = mid;
            else
                start = mid + 1;
        }
        
        return end;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        
       int n = arr.length() , peak = -1;
        if(n<3 || (arr.get(0) > arr.get(1)) )
            return -1;
        
       int pk = peakElement( arr);
    
       if(pk == -1)
           return -1;
       
        int a = binarySearch_inc(arr , target , 0 , pk);
        int b = binarySearch_dec(arr , target , pk+1 , n-1);
        
        if(a!=-1 && b!=-1)
            return min(a,b);
        if(a==-1)
            return b;
        if(b==-1)
            return a;
        return -1;
    
    }