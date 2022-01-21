class Solution
{
    public:
    int length( struct Node *head)
    {
        struct Node *temp = head;
        int len = 0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    void deleted(struct Node *t)
    {
        if(!t)
          return;
          
        delete(t->next);
    }
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        int len = length(head);
        
        if( M >= len || N==0)
            return;
        
        struct Node *temp = head , *prev = NULL;
        
        while(temp)
        {
        int i=1;
        
        while( i<=M && temp)
        {
            prev = temp;
            temp = temp->next;
            if(!temp)
               return;
            i++;
        }
        
        struct Node *t = temp;
        i=1;
        while(i<N && temp)
        {
            i++;
            temp = temp->next;
            if(!temp)
            {
                prev->next = NULL;
                deleted(t);
                return;
            }
        }
        
        prev->next = temp->next;
        struct Node *p;
        
        while( t!= temp)
        {
            p = t->next;
            delete(t);
            t = p;
        }
        
        temp = t->next;
        delete(t);
      
        
    }
    }
};