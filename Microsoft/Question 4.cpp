vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        int count = 0;
        int n = r*c;
        vector<int>v;
        
        int rsi = 0, rei = r-1 , csi = 0 , cei = c-1;
        int row ,col;
        
        while(1)
        {
            row = rsi ;
            col = csi;
            
            while(col <= cei)
            {
                v.push_back(mat[row][col]);
                count++;
                if(count==n)
                   return v;
                col++;
            }
            rsi++;  row = rsi ; col--;
            
            while(row <= rei)
            {
                v.push_back(mat[row][col]);
                row++;
                count++;
                if(count==n)
                   return v;
            }
            cei--;  col = cei ;  row--;
            
            
            while(col >=csi)
            {
                v.push_back(mat[row][col]);
                col--;
                count++;
                if(count==n)
                   return v;
            }
            rei--;  row = rei ; col++;
            
            while(row >= rsi)
            {
                v.push_back(mat[row][col]);
                row--;
                count++;
                if(count==n)
                   return v;
            }
            row++ ; csi++ ;
        }
        return v;
    }