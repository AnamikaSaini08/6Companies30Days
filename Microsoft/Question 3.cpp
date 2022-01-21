void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
        int n = matrix.size();
        int ri = n-1;
        int ci = n-1;
        int i = 0 , j= 0 , row = 0 ,col=0;
        
        while( row <= ri and col <=ci)
        {
            while(i<=ri and j<=ci)
            {
                swap(matrix[i][col] , matrix[col][j]);
                i++;j++;
            }
            row++;col++;
            i=row; j=col;
        }
        
        int rs =0 , re = n-1 , cs =0 , ce = n-1;
        for(int i=0 ; i<=ri/2 ; i++)
        {
            while(cs<=ce)
            {
                swap(matrix[rs][cs], matrix[re][cs]);
                cs++;
            }
            cs = 0;
            rs++;
            re--;
        }
}