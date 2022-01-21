void DFS(string ch ,  map<string,int>&visit , map<string,list<string>>&graph , list<string>&l)
    {
        visit[ch] = 1;
        for(auto nbr:graph[ch])
        {
            if(!visit[nbr])
            {
                DFS(nbr , visit , graph , l);
            }
        }
        l.push_front(ch);
    }
    void make_graph(string s1 , string s2 , map<string,list<string>>&graph)
    {
        graph[s1].push_back(s2);
    }
    string findOrder(string dict[], int n, int k) {
        //code hereP]]'];../ '
        map<string,list<string>>graph;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j = 0; dict[i][j] ; j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    string s1,s2;
                    s1+=dict[i][j];
                    s2+=dict[i+1][j];
                    make_graph(s1,s2,graph);
                    break;
                }
            }
        }
        
        map<string,int>visit;
        list<string>l;
        
        for(char ch='a' ; ch<='a'+k ; ch++)
        {
            string s ;
            s+=ch;
            if(visit.find(s) == visit.end())
            {
                DFS(s , visit, graph ,l);
            }
        }
        string ans;
       for(auto temp : l)
       {
           ans+=temp;
       }
       return ans;
    }