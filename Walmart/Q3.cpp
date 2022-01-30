class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.size();
        if( n < 3)
            return false;
        
        int A = 0 , B = 0 , flag_A = 0 , flag_B = 0;
        vector<int>v;
        int end_a = -1 , end_b = -1;
        
        if(colors[0] == 'A')
            flag_A = 1;
        else
            flag_B = 1;
        
        for(int i=0 ; i<n ; )
        {
            while( i< n && colors[i] == 'A'){
                A++;
                i++;
            }
            if(A)
              v.push_back(A);
            A = 0;
            
            while( i<n  && colors[i] == 'B'){
                B++;
                i++;
            }
            if(B)
              v.push_back(B);
            B = 0;
        }
        
        int size = v.size();
        int chance = 1 , start;
        
        
        while(1)
        {
            if(chance == 1)
            {
                if(flag_A == 1)
                    start = 0;
                else
                    start = 1;
                
                if(end_a != -1)
                    start = end_a;
                for(int i = start ; i<size ; i+=2){
                    if(v[i] > 2){
                        v[i] -= 1;
                        chance = 0;
                        end_a = i;
                        break;
                    }
                }
                if(chance){
                    return false;
                }
            }
            else{
                if(flag_A == 1)
                    start = 1;
                else
                    start = 0;
                
                if(end_b != -1)
                    start = end_b;
                for(int i = start ; i<size ; i+=2){
                    if(v[i] > 2){
                        v[i] -= 1;
                        chance = 1;
                        end_b = i;
                        break;
                    }
                }
                if(chance==0)
                    return true;
            }
        }
        return false;
    }
};