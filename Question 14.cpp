int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>mp;
        queue<Node *>q;
        Node *tar ;
        int tm=0;
        
        q.push(root);
        while(!q.empty())
        {
            struct Node *temp = q.front();  q.pop();
            
            if(temp->data == target)
            {
                tar = temp;
            }
            
            if(temp->left){
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            
            if(temp->right){
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
      
        while(q.size())
          q.pop();
          
        q.push(tar);
        int visit[10004] = {0};
        visit[tar->data] = 1;
        
        while(!q.empty())
        {
            int count =0 , size=q.size() , i=1;
            
            while(i<=size)
            {
                struct Node *temp = q.front();  
                q.pop();
                if(temp->left){
                    if(visit[temp->left->data] !=1)
                    {
                        visit[temp->left->data] = 1;
                        q.push(temp->left);
                        count=1;
                    }
                }
                
                if(temp->right){
                    if(visit[temp->right->data] !=1)
                    {
                        visit[temp->right->data] = 1;
                        q.push(temp->right);
                        count=1;
                    }
                }
                
                if( mp.find(temp) != mp.end() )
                {
                    if(visit[mp[temp]->data] !=1)
                    {
                        visit[mp[temp]->data] = 1;
                        q.push(mp[temp]);
                        count=1;
                    }
                }
                i++;
            }
            if(count)
               tm++;
        }
        return tm;
    }