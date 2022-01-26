int atoi(string str) {
        //Your code here
        int num = 0 , i =0 , flag = 0;
        int n = str.size();
        
        if( n > 0)
        {
            if(str[0] == '-')
            {
                flag = 1;
                i += 1;
            }
            else if( str[0] == '+')
               i += 1;
               
            else if((str[0]>='a' && str[0]<='z') || ( str[0]>='A' && str[0] <='Z'))
               return -1;
        }
        
        for(i=i ; str[i] ; i++)
        {
            if( (str[i]>='a' && str[i]<='z') || ( str[i]>='A' && str[i] <='Z'))
            {
                return -1;
            }
            int temp = str[i] - '0';
            num = num * 10 + temp;
        }
        if(flag)
           num = -num;
        return num;
    }