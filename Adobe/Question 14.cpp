class element
    {
        public:
        int value;
        int index;
        int row;
        int arrsize;
        
        element(int val , int ind , int row_no , int arr_size)
        {
            value = val;
            index = ind;
            row = row_no;
            arrsize = arr_size;
        }
    };
    
    struct compare
    {
        bool operator()(element a , element b)
        {
            return a.value > b.value;
        }
    };

class Solution{
    public:
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
        int mn = INT_MAX , mx = INT_MIN , range = INT_MAX;
        priority_queue<element , vector<element>,compare> minH;
        int low , high;
        
        for(int i=0 ; i<k ;i++)
        {
            minH.push(element(arr[i][0] , 0 , i , n));
            mn = min(arr[i][0] , mn);
            mx = max( arr[i][0] , mx);
        }
        
        while(!minH.empty())
        {
            element temp = minH.top();
            minH.pop();
            int may_be_min = temp.value;
            
            if(range > mx - may_be_min)
            {
                mn = may_be_min;
                range = mx - may_be_min;
                low = mn;
                high = mx;
            }
            
            if(temp.index == temp.arrsize - 1)
                break;
            
            temp.index+=1;
            minH.push(element(arr[temp.row][temp.index] , temp.index , temp.row , n) );
            mx = max( mx , arr[temp.row][temp.index]);
        }
        pair<int,int>p;
        p.first = low;
        p.second = high;
        return p;
          
    }
};