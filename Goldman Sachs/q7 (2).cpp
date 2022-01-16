#include <iostream>
using namespace std;
int main() {
    int n , m, k , i;
    cin>>n>>m>>k;

    int ans = (k + m - 1) % n;
    if(ans == 0)
       cout<<n;
    else
      cout<<ans;
}