#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int dp[1000];
int lis(int n){
    vector<int>temp;
    temp.push_back(ar[0]);
    for(int i=1;i<n;i++){


        if(ar[i]>temp.back()){

            temp.push_back(ar[i]);
        }
        else{
            int ind=lower_bound(temp.begin(),temp.end(),ar[i])-temp.begin();
            temp[ind]=ar[i];
        }
    }
    return temp.size();
   

   


}
int main(){
memset(dp,-1,sizeof(dp));
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>ar[i];
}
cout<<lis(n);

}
