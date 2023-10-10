#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int l=2;l<n;l++){

        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            dp[i][j]=inf;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+ar[i-1]*ar[k]*ar[j]);
            }
        }
    }
    cout<<"answer is: "<<dp[1][n-1];


}
