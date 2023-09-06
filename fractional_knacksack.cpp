#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>product;
    for(int i=0;i<n;i++){

        int v,w;
        cin>>v>>w;
        int a=v/w;
        //a== per kg,w=weight,v=total value=a*w
        product.push_back({a,w});
    }

    sort(product.rbegin(),product.rend());
    int weight;
    cin>>weight;
    int ans=0;

    for(int i=0;i<n;i++){
        int total_v=(product[i].first)*(product[i].second);
        cout<<"total is "<<total_v<<endl;
        if(weight>=product[i].second){

            ans+=total_v;
            weight-=product[i].second;
            continue;
        }
        ans+=weight*product[i].first;
        weight=0;


    }
    cout<<ans<<endl;
}

