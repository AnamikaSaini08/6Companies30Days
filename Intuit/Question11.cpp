class Solution {
public:
      Node* construct(vector<vector<int>>& grid, int i, int j, int width) {
        if (width==1) return new Node(grid[i][j],true);  
            
        width /= 2; 
        auto ii = i+width, jj = j+width; 
        
        auto ul = construct(grid,i,j,width);
        auto ur = construct(grid,i,jj,width);
        auto ll = construct(grid,ii,j,width);
        auto lr = construct(grid,ii,jj,width);
        
        auto allLeaves = ul->isLeaf && ur->isLeaf && ll->isLeaf && lr->isLeaf;
        auto allMatch = (ul->val + ur->val + ll->val + lr->val)%4==0;
        
        return (allLeaves && allMatch) ? new Node(ul->val, true) : new Node(1, false, ul, ur, ll, lr);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0,0,grid.size());
    }
};