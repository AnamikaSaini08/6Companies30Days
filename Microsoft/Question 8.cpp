void connect(Node *root)
    {
       // Your Code Here
       queue<Node*>q;
       q.push(root);
       while(q.size())
       {
           Node *temp = q.front();
           q.pop();
           int size = q.size();
           
           for(int i=1 ; i<=size ; i++)
           {
               if(temp->left)
                   q.push(temp->left);
               if(temp->right)
                   q.push(temp->right);
                   
                temp->nextRight = q.front();
                temp = q.front();
                q.pop();
           }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        temp->nextRight = NULL;
       }
    }