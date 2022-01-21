int solve(Node *root , int tar , int &count)
{
    if(!root)
       return 0;

    int l = solve(root->left , tar ,  count);
    int r = solve(root->right , tar ,  count);
    
    int sum = root->data + l + r;
    if(sum == tar)
    {
        count++;
    }
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count = 0 , sum = 0;
	solve(root , X , count);
	return count;
}