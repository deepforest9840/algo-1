#include<bits/stdc++.h>
using namespace std;
string s1,s2;



// int fun(){
//     int l1=s1.length()+1;
//     int l2=s2.length()+1;
//     int c[l1][l2];
//     memset(c,0,sizeof(c));
//     for(int i=1;i<l1;i++){
//         for(int j=1;j<l2;j++){
//             if(s1[i-1]==s2[j-1]){
//                 c[i][j]=c[i-1][j-1]+1;
//             }
//             else{

//                 c[i][j]=max(c[i-1][j],c[i][j-1]);

//             }
//         }
//     }





//     for(int i=0;i<l1;i++){
//         for(int j=0;j<l2;j++){
//             cout<<c[i][j]<<" ";
//         }
//         cout<<endl;
//     }


//     stack<int>st;
//     int i=l1-1,j=l2-1;
    
//     while(i>0&&j>0){

//             int left=c[i][j-1];
//             int upper=c[i-1][j];
//             int corner=c[i-1][j-1];
//             if(left==upper&& upper==corner && corner<c[i][j]){
//                 i--;j--;
//                 st.push(i);
//             }
//          else if(left==upper&& upper==corner && corner==c[i][j]){
//                 j--;
                
//             }
//             if(left>upper){
//                 j--;
//             }
//             if(upper>left){
//                 i--;
//             }



//     }
//     cout<<" stack"<<endl;
//     while(st.size()>0){
//         cout<<s1[st.top()];
//         st.pop();
//     }
// cout<<endl;
//     return c[l1-1][l2-1];

// }

void ks(int wt[],int profit[],int l1,int w){
     l1+=1;
    int  l2=w+1;
    int dp[l1][l2];
    
    for(int i=0;i<l1;i++){

        for(int j=0;j<l2;j++){
             if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
           else if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    cout<<dp[l1-1][l2-1]<<endl;


    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


}
// void ks(int wt[], int profit[], int w, int n) {
//     int dp[n + 1][w + 1];

//     // Initialize the DP table
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= w; j++) {
//             if (i == 0 || j == 0) {
//                 dp[i][j] = 0;
//             } else if (wt[i - 1] <= w) {
//                 dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - wt[i - 1]]);
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     cout << dp[n][w];
// }

int main(){

    int wt[]={3,4,5};
    int profit[]={30,50,60};
    int w=8;
    ks(wt,profit,sizeof(wt)/sizeof(wt[0]),w);



}
