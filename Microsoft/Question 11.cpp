void solve(int n , vector<string>&v , int i)
{
    if(n==0)
        return;
    
    string s1 , s2;
    s1 += v[i];
    s1+='0';
    v.push_back(s1);
   // v.pop_back();
    n--;
    if(n==0)
      return;
      
    s2+=v[i];
    s2 += '1';
    v.push_back(s2);
    solve(n-1 , v , i+1);
}

vector<string> generate(int n)
{
	// Your code here
	vector<string>v;
	if(n==1)
	{
	    	v.push_back("1");
	    	return v;
	}
	if(n==2)
	{
	    	v.push_back("1");
	    	v.push_back("10");
	    	return v;
	}
	v.push_back("1");
	v.push_back("10");
	v.push_back("11");
	solve(n-3 , v , 1);
	return v;
}