vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int>mn(N);
        mn[0] = arr[0];
        for(int i=1 ; i<N ; i++)
        {
            mn[i] = min(arr[i] , mn[i-1]);
        }
        
        vector<int>mx(N);
        mx[N-1] = arr[N-1];
        
        for(int i=N-2 ; i>=0 ; i--)
        {
            mx[i] = max( arr[i] , mx[i+1]);
        }
        
        vector<int>v;
        for(int i=0 ; i<N ; i++)
        {
            if(arr[i] > mn[i] && arr[i]<mx[i])
            {
                v.push_back(mn[i]);
                v.push_back(arr[i]);
                v.push_back(mx[i]);return v;
            }
        }
        return v;
    }