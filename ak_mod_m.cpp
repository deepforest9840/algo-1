#include<bits/stdc++.h>
using namespace std;

 long long int bigmod(long long int a,long long int b,long long int c){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        long long int value=bigmod(a,b/2,c);
        return (value*value)%c;
    }
    else if(b%2==1){
        long long int x,y;
        x=a%c;
        y=bigmod(a,b-1,c);
        return (x*y)%c;
    }
}
int main(){
    long long int a,b,c;
    cin>>a>>b>>c;
    cout<<bigmod(a,b,c);

}
