#include<bits/stdc++.h>
using namespace std;
string s1,s2;



int fun(){
    int l1=s1.length()+1;
    int l2=s2.length()+1;
    int c[l1][l2];
    memset(c,0,sizeof(c));
    for(int i=1;i<l1;i++){
        for(int j=1;j<l2;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{

                c[i][j]=max(c[i-1][j],c[i][j-1]);

            }
        }
    }





    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


    stack<int>st;
    int i=l1-1,j=l2-1;
    
    while(i>0&&j>0){

            int left=c[i][j-1];
            int upper=c[i-1][j];
            int corner=c[i-1][j-1];
            if(left==upper&& upper==corner && corner<c[i][j]){
                i--;j--;
                st.push(i);
            }
         else if(left==upper&& upper==corner && corner==c[i][j]){
                j--;
                
            }
            if(left>upper){
                j--;
            }
            if(upper>left){
                i--;
            }



    }
    cout<<" stack"<<endl;
    while(st.size()>0){
        cout<<s1[st.top()];
        st.pop();
    }
cout<<endl;
    return c[l1-1][l2-1];

}
int main(){

    cin>>s1>>s2;
   cout<< fun();



}
