string FirstNonRepeating(string str){
		    // Code here
		    deque<char>q;
		    int arr[30] = {0};
		    char ch = str[0];
		    string ans;
		    
		    ans+=ch;
		    q.push_back(ch);
		    arr[str[0]-'a'] = 1;
		    
		    for(int i=1 ; str[i] ; i++)
		    {
		        if(arr[str[i] - 'a'])
		        {
		            if(q.size() > 0 and q.front() == str[i])
		            {
		                q.pop_front();
		                
		                if(!q.size())
		                   ch = '#';
		                else
		                {
		                    while((q.size() > 0) && (arr[q.front() - 'a'] == 2) )
		                        q.pop_front();
		                        
		                    if( q.size()==0 )
		                       ch = '#';
		                    else
		                       ch = q.front();
		                }
		            }
		            else{
		                arr[str[i] - 'a'] = 2;
		            }
		            ans += ch;
		        }
		        
		        else{
		            arr[str[i] - 'a'] = 1;
		            if(ch == '#')
		               ch = str[i];
		            q.push_back(str[i]);
		            ans+=ch;
		        }
		    }
		    return ans;
		}