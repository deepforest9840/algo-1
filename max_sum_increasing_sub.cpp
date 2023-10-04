#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int dp[1000];
int s[1000];
int lis(int i){
    //if(dp[i]!=-1) return dp[i];

    int ans=1;
    int sum=0;
    for(int j=0;j<i;j++){

        if(ar[j]<ar[i]){
            sum=max(sum,s[j]);
            ans=max(ans,lis(j)+1);
            
        }
    }
    s[i]=sum+ar[i];
    return ans;


}
int main(){
    freopen("input.txt","r",stdin);
memset(dp,-1,sizeof(dp));
memset(s,0,sizeof(s));
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>ar[i];
}
int ans=0;
for(int i=0;i<n;i++){
    ans=max(ans,lis(i));
}
//lis(0);
cout<<ans<<endl;
for(int i=0;i<=n;i++){
    cout<<s[i]<<" ";
}

}
