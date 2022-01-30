class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) 
    {
		vector<int> result, all(move(sums)), with_d;
        
        sort(all.begin(), all.end());
        
		while (all.size() > 1) 
        {
			int d = all[1] - all[0], z = 0, i = 0;
			for (auto t = all.begin(), h = t; h != all.end(); ++h) 
            {
                int s = *h;
                if (i != with_d.size() && with_d[i] == s)
                    ++i;
                else {
                    z += s == 0;
                    *t++ = s;
                    with_d.push_back(s + d);
                }
            }
            all.resize(with_d.size());
            
			if (z != 0)
				result.push_back(d);
            
			else 
            {
				result.push_back(-d);
				swap(all, with_d);
			}
            with_d.clear();
		}
		return result;
    }
};