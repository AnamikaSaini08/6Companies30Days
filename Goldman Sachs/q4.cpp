string encode(string str)
{     
  //Your code here 
  int n = str.size();
  string ans;
  
  for(int i=1 ; i<n ; i++)
  {
      int count = 1;
      
      while(str[i] == str[i-1])
      {
          count++;
          i++;
          
          if(i==n){
             break;
          }
      }
      
      string temp ;
      temp = to_string(count);
      
      ans+=str[i-1];
      ans+=temp;
      
  }
  
  if(str[n-2] != str[n-1])
  {
      ans+=str[n-1];
      ans+='1';
  }
  return ans;
}