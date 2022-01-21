public:
    struct Node
    {
        //structure of each node
        Node *link[26];
        bool flag = false;
        
        bool containKey(char ch)
        {
            return (link[ch-'a'] != NULL);
        }
        
        //newnode insertion
        void put(char ch , Node *node)
        {
            link[ch -'a'] = node;
        }
        
        //return reference
        Node* get(char ch)
        {
            return link[ch-'a'];
        }
        
        bool setEnd()
        {
            flag = true;
        }
        
        bool isEnd()
        {
            return flag;
        }
        
    }*root = new Node();
 
    void insert(string word)
    {
        Node *node = root;
        int n = word.size();
        for(int i=0 ; i<n ; i++)
        {
            if(!node->containKey(word[i]))
            {
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search( vector<vector<string>>&ans , string word)
    {
        Node *node = root;
        for(int i=0 ; i<word.length() ; i++)
        {
            if(!node->containKey(word[i]))
            {
               return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        //Trie t;
        set<string>st;
        for(int i=0 ; i<n ; i++)
        {
            st.insert(contact[i]);
        }
        
        n = st.size();
        int i=0;
        for(string str:st)
        {
            contact[i] = str;
            i++;
        }
      
        for(int i=0 ; i<n ; i++)
            insert(contact[i]);
            
        vector<vector<string> >ans;
        
        string temp;
        int ind = 0;
        for(int i=0 ; s[i] ; i++)
        {
           temp += s[i];
           bool t = search(ans , temp);
           if(t)
           {
               vector<string>str;
               for(int j = 0; j<n ; j++)
               {
                   if(contact[j].substr(0 , i+1) == temp)
                   {
                       str.push_back(contact[j]);
                   }
               }
               ans.push_back(str);
           }
           else{
               vector<string> temp;
               string str;
               str+='0';
               temp.push_back(str);
               ans.push_back(temp);
           }
          
        }
        int k = ans.size();
        for(int i=0 ; i<k ; i++)
        {
            sort(ans[i].begin() , ans[i].end());
        }
        return ans;
    }