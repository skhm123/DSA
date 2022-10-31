/*
https://www.hackerrank.com/challenges/vector-sort/problem?isFullScreen=true
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> sortFunc(vector<ll> vect) {
    sort(vect.begin(), vect.end());
    return vect;
}
int main() {
    ll n;
    cin>>n;
    vector<ll> vect;
    for(ll i=0; i<n; i++) {
        ll input;
        cin>>input;
        vect.push_back(input);
    }
    vector<ll> sorted_vect= sortFunc(vect);
    for(auto i: sorted_vect) {
        cout<< i<< " ";
    }
    return 0;
}