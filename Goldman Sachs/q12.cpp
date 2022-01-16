string decodedString(string str){
        // code here
        stack<string> s;
        string curstr = "";
        int curnum = 0;
        
        for(int i=0 ; str[i] ; i++)
        {
            if(str[i] == '[')
            {
                s.push(curstr);
                string temp = to_string(curnum);
                s.push(temp);
                curnum = 0;
                curstr = "";
            }
            
            else if(str[i] == ']')
            {
                string temp = s.top();
                s.pop();
                int prevcur = stoi(temp);
                string prevstr = s.top();
                s.pop();
                
                string s;
                for(int k=0 ; k<prevcur ; k++)
                     s += curstr;
                     
                curstr = prevstr + s;
            }
            
            else if(str[i]>='0' && str[i]<='9')
            {
                string temp;
                temp+=str[i];
                int t = stoi(temp);
                curnum = curnum * 10 + t;
            }
            else
              curstr += str[i];
        }
        return curstr;
        
    }