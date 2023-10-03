#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
 int ss=0;
int dp[1000];
int r[1000];
int s[1000];

int rod(int ar[],int len){
    if(dp[len]!=-1) return dp[len];
    int ans=0;
    for(int len_to_cut=1;len_to_cut<=len;len_to_cut++){
        ans=max(ans,ar[len_to_cut-1]+rod(ar,len-len_to_cut));

    }
    return dp[len]=ans;
}


int rod2(int ar[],int len){

    for(int i=1;i<=len;i++){
        int ans=0;
        for(int j=0;j<i;j++){
                if(ans<ar[j]+r[i-j-1]){
                ans=max(ans,ar[j]+r[i-j-1]);
                s[i]=j+1;
                }
        }
        r[i]=ans;
        
    }
    return r[len];



}


int main(){
    memset(dp,-1,sizeof(dp));
    int ar[]={1,5,8,9,10,17,17,20};
   cout<< rod(ar,8)<<endl;
   cout<<rod2(ar,8)<<endl;
   for(int i=0;i<=8;i++){
    cout<<s[i]<<" ";
   }



}
