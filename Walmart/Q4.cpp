class Solution
{
    public:
    void solve(int i , int j , int a , int b , int &ans ,  vector<vector<int>>&visit)
    {
        if( i<0 || i>=a || j<0 || j>=b || visit[i][j])
            return;
        
        if(i==a-1 && j==b-1)
        {
            ans += 1;
            return;
        }
        
        visit[i][j] = 1;
        solve(i , j+1 , a , b, ans , visit);
        solve(i+1 , j, a, b, ans , visit);
        visit[i][j] = 0;
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        int ans = 0;
        vector<vector<int>>visit(a , vector<int>(b,0));
        solve( 0 , 0 , a , b , ans , visit);
        return ans;
    }
};