public:
    int longestMountain(vector<int>& arr) {
        
        int n= arr.size();
        int ans = 0 , i=0;
        bool peak = false , valley = false;
        
        if( n< 3)
            return 0;
        int start;
        
        while(i<n-1)
        {
            //peak
            if(arr[i] < arr[i+1])
            {
                peak = true;
                 start = i;
                while(i<n-1 and arr[i] < arr[i+1])
                {
                    i++;
                }
            
            //valley
            while( i<n-1 and arr[i] > arr[i+1])
            {
                valley = true;
                i++;
            }
            
            //
            if(peak and valley)
            {
                ans = max(ans , i-start+1);
            }
            peak= false;
            valley = false;
          
            }
            else
                i++;
        }
        return ans;
    }