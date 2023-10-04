#include <bits/stdc++.h>
using namespace std;
int ar[1000];
int dp[1000];
int p[1000];
int lis(int i)
{
    if (dp[i] != -1)
        return dp[i];

    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (ar[j] < ar[i])
        {
            if (lis(j) + 1 > ans)
            {
                ans = max(ans, lis(j) + 1);
                p[i] = j;
            }
        }
    }

    return dp[i] = ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }
    cout << ans << endl;

    int lisp;
    for(int i=0;i<n;i++){
        if(ans==dp[i]){
            lisp=i;
            break;
        }
    }
    cout<<"max lis pos"<<lisp<<endl;
   for(int i=0;i<ans;i++){

    cout<<ar[lisp]<<" ";
        lisp=p[lisp];

   }
}
