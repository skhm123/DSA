/*
https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> executeQueries(vector<ll> vect, ll q1, ll q2, ll q3) {
    vect.erase(vect.begin()+q1-1);
    vect.erase(vect.begin()+q2-1, vect.begin()+q3-1);
  
    return vect;
}
int main() {
    ll q1,q2,q3,n;
    cin>>n;
    vector<ll> vect;
    for(ll i=0; i<n; i++) {
        ll input;
        cin>>input;
        vect.push_back(input);
    }

    cin>>q1>>q2>>q3;

    vector<ll>postOpVect = executeQueries(vect,q1,q2,q3);
   cout<<postOpVect.size()<<"\n";
    for(auto i: postOpVect) {
        cout<< i<< " ";
    }
    return 0;
}