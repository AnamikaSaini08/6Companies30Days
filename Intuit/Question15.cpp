int CanEatInTime(int k , int h , vector<int>&piles )
    {
        int hours = 0 , count= 0;
         
        for(int pile : piles)
        {
            int div = pile / k;
            hours += div;
            if(pile % k !=0)
                hours++;
        }
        return hours<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans = 0 , n = piles.size();
        int lb=1 , ub = 1000000000 , k;
        while(lb <=ub )
        {
           int mid = lb + (ub-lb)/2;
            
           if (CanEatInTime( mid, h , piles) ) 
               ub = mid-1;
           else
               lb = mid + 1;
        }
        
        return lb;
    }