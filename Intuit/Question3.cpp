int getValue(const string& str, int i, int m)
{
    if (i + m > str.length())
        return -1;
 
    // Find value at index i and length m.
    int value = 0;
    for (int j = 0; j < m; j++)
    {
        int c = str[i + j] - '0';
        if (c < 0 || c > 9)
            return -1;
        value = value * 10 + c;
    }
    return value;
}

int missingNumber(const string& str)
{
   
    for (int i=1; i<=6; ++i)
    {
        int n = getValue(str, 0, i);
        if (n == -1)
           break;
 
        int missingNo = -1;
        bool fail = false;
 
        for (int m=i; m!=str.length(); m += 1 + log10l(n))
        {
            if ((missingNo == -1) &&
                (getValue(str, m, 1+log10l(n+2)) == n+2))
            {
                missingNo = n + 1;
                n += 2;
            }
            else if (getValue(str, m, 1+log10l(n+1)) == n+1)
                n++;
 
            else
            {
                fail = true;
                break;
            }
        }
 
        if (!fail)
          return missingNo;
    }
    return -1; 
}