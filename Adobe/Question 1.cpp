vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i =0 , j =0;
        long long sum = 0 ;
        vector<int>ans;
        
        while(j <n)
        {
            sum +=arr[j];
            
            while( sum > s)
            {
                sum -= arr[i];
                i++;
            }
            
            if(sum == s)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            j++;
        }
        ans.push_back(-1);
        return ans;