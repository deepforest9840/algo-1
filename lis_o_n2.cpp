#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int dp[1000];
int lis(int i){
    if(dp[i]!=-1) return dp[i];

    int ans=1;
    for(int j=0;j<i;j++){

        if(ar[j]<ar[i]){
            ans=max(ans,lis(j)+1);
        }
    }

    return dp[i]=ans;


}
int main(){
memset(dp,-1,sizeof(dp));
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>ar[i];
}
int ans=0;
for(int i=0;i<n;i++){
    ans=max(ans,lis(i));
}
cout<<ans;

}
