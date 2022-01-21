vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>ans;
        int i = 0, j= 0;
        deque<int>q;
        
        while(j<n)
        {
            if(q.size() == 0)
                q.push_back(arr[j]);
                
            else{
                while( (q.size() > 0) && (arr[j] > q.back() ) ){
                     q.pop_back();
                }
                q.push_back(arr[j]);
            }
            
            if(j-i+1 == k)
            {
                ans.push_back(q.front());
                if(arr[i] == q.front())
                {
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
       
        return ans;
    }