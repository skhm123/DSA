#include<bits/stdc++.h>
#define ll long long 
using namespace std;
vector<vector<ll> > generate(ll n ) {
    vector<vector<ll> > vect;
    vector<ll> singleArray;
    singleArray.push_back(1);
    vect.push_back(singleArray);
    if(n==1) {
        return vect;
    }
    singleArray.push_back(1);
    vect.push_back(singleArray);
    if(n==2) {
        return vect;
    }
    ll targetIndex = n-1;
    for(ll i=2;i<=targetIndex; i++) {
        singleArray.clear();
        ll numberOfElements = i+1;
        singleArray.push_back(1);
        for(ll j=1;j<i;j++) {
            singleArray.push_back(vect[i-1][j-1]+vect[i-1][j]);
        }
        singleArray.push_back(1);
        vect.push_back(singleArray);

    }
    return vect;

} 
int main() {
    ll n ;
    cin>>n;
    vector<vector<ll> >vect = generate(n);
    for(ll i=0;i<vect.size();i++) {
     for(ll j=0;j<vect[i].size();j++) {
        cout<<vect[i][j]<< " ";
    }
    cout<<"\n";
   }
    return 0;
}