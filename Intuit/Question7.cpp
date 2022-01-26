int no_of_days( vector<int>& weights , int mid )
    {
        int total = 0 , cal_day = 0 ;
        int n = weights.size();
        
        for(int i =0 ; i<n ; i++)
        {
            if(weights[i] > mid)
                return -1;
            
            if(weights[i] + total <= mid)
                total = (weights[i] + total);
            else{
                i--;
                cal_day++;
                total = 0;
            }
        }
        if(total)
            cal_day +=1;
        
        return cal_day;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lb = 1 , ub = 500000;
        while(lb <= ub)
        {
            int mid = lb + (ub-lb)/2;
            int cal_days = no_of_days(weights , mid);
            
            if(cal_days == -1)
                lb = mid+1;
            
            else if(cal_days <= days)
                ub = mid-1;
            else
                lb = mid+1;
        }
        return lb;
        
    }