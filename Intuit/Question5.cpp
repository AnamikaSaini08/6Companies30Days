int minimum_subarray(vector<int>& num , int mid )
    {
        int n = num.size() , count = 0 , i=0 ;
        int sum = 0;
        
        while(i<n)
        {
            if(num[i] > mid)
                return -1;
            
            if( num[i] + sum <= mid)
            {
                sum = sum + num[i];
                i++;
            }
            else{
                count++;
                sum = 0;
            }
        }
        if(sum)
            count+=1;
        
        return count;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size() , sum=0;
        
        for(int i=0 ; i<n ; i++)
            sum +=nums[i];
        int lb = 0 , ub = sum;
        
        while( lb<= ub )
        {
            int mid = lb +(ub-lb)/2;
            int res = minimum_subarray(nums , mid);
            if(res > m || res == -1)
            {
                lb = mid +1;
            }
            else{
                ub = mid - 1;
            }
        }
        return lb;
    }