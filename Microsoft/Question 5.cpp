vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>>s;
       vector<int>v;
       
       for(int i=0 ; i<n ; i++)
       {
           if(!s.size())
           {
               s.push({price[i] , i});
               v.push_back(1);
           }
           
           else if( s.top().first > price[i])
           {
               s.push({price[i] , i});
               v.push_back(1);
           }
           else{
               while(s.size() and s.top().first <= price[i])
               {
                   s.pop();
               }
               if(!s.size())
               {
                   v.push_back(i+1);
               }
               else{
                    int len = i - s.top().second;
                    v.push_back(len);
               }
               s.push({price[i] , i});
           }
       }
       return v;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}