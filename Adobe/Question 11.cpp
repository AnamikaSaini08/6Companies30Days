string amendSentence (string str)
    {
        // your code here
        string ans;
        
        if(!str.size())
           return ans;
           
        ans += tolower(str[0]);
        for(int i=1 ; str[i] ; i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                ans += " ";
                ans += tolower(str[i]);
            }
            else{
                ans += str[i];
            }
        }
        return ans;
    }