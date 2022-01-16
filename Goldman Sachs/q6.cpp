class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        //cout<<str1 <<"   "<<str2<<endl;
        if( (str1 + str2) != (str2 + str1))
             return "";
        
        else if(str1 == str2)
            return str1;
        
        else if(str1.size() > str2.size())
        {
            return gcdOfStrings(str1.substr(str2.size()) , str2);
        }
        else{
            return gcdOfStrings(str2.substr(str1.size()) , str1);
        }
    }
};