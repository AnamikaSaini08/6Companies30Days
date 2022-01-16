string printMinNumberForPattern(string str){
        // code here 
        stack<int>s;
        string ans;
        int count = 1;
        
        for(int i=0 ; str[i] ; i++)
        {
            s.push(count);
            count += 1;
            
            if(str[i] == 'I')
            {
                string temp , temp2;
                while(!s.empty())
                {
                    temp = to_string(s.top());
                    temp2 += temp;
                    s.pop();
                }
                ans += temp2;
            }
        }
        
        s.push(count);
        while(!s.empty())
        {
            string temp = to_string(s.top());
            ans += temp;
            s.pop();
        }
        return ans;
    }