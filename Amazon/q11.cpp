void preorder(Node *root , vector<int>&v)
    {
        if(!root)
        {
            v.push_back(-1);
            return;
        }
        v.push_back(root->data);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    
    vector<int> serialize(Node *root) 
    {
        vector<int>v;
        preorder(root,v);
        return v;
    }
    
    int t=0;
    Node* solve(vector<int> &arr)
    {
        if(arr[t] == -1)
        {
            t++;
            return NULL;
        }
        
        Node *newnode = new Node(arr[t]);
        t++;
        newnode->left = solve(arr);
        newnode->right = solve(arr);
        return newnode;
    }
  
    Node * deSerialize(vector<int> &arr)
    {
        
        return solve(arr);
    }