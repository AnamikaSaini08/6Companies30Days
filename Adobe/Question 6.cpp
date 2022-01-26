void solve( int o , int c , string ip ,  vector<string>&ans )
    {
        if(!o and !c)
        {
            ans.push_back(ip);
            return;
        }
        
       string op1 = ip;
       string op2 = ip;
       
       if(o){
             op1 += '(';
            solve( o-1 , c , op1 , ans);
       }
        if(o < c){
           op2 += ')';
           solve( o , c-1 , op2 , ans);
        }
        return ;
       
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        string ip;
        solve( n , n , ip , ans);
        return ans;
    }