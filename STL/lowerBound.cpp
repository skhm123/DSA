/*
https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll BinarySearch(vector<ll> vect, ll target, ll startIndex, ll endIndex) {
    if(startIndex> endIndex) {
        return -1;
    }
    if(startIndex == endIndex) {
        if(vect[startIndex] == target) {
            return startIndex;
        }
        return -1;
    }
        if(startIndex+ 1 == endIndex) {
            if(vect[startIndex]== target) {
            return startIndex;
        }
        else if(vect[endIndex]== target) {
            return endIndex;
        }
        else {
            return -1;
        }
        }
    

    ll midIndex = startIndex+ endIndex;
    midIndex/=2;


    if(vect[midIndex] == target) {
        // check for duplicates. Need first index
        if(vect[midIndex-1] == target) {
            return BinarySearch(vect, target, startIndex, midIndex-1);
        }
        return midIndex;
    }
    else if(vect[midIndex]> target) {
     
        return BinarySearch(vect, target, startIndex, midIndex);
    }
    else if(vect[midIndex]< target) {
        return BinarySearch(vect,target, midIndex+1, endIndex);
    }
    return -1;
}
void executeQueries(vector<ll> vect, ll n , vector<ll> queries, ll q) {
    ll i=0;
    while(i<q) {
        ll query = queries[i];
        ll index = BinarySearch(vect, query, 0, vect.size()-1);
        if(index ==-1) {
            auto Lowerindex = lower_bound(vect.begin(), vect.end(), query);
            cout<< "No "<< (Lowerindex - vect.begin())+1 << "\n";
        }
        else {
            cout<< "Yes "<< index+1<< "\n"; 
        }
        i++;
    }
}
int main() {
    ll n,q;
    cin>>n;
    vector<ll> vect, queries;
    for(ll i=0; i<n; i++) {
        ll input;
        cin>>input;
        vect.push_back(input);
    }
    cin>>q;
    for(ll i=0;i<q;i++) {
        ll input;
        cin>>input;
        queries.push_back(input);
    }
    executeQueries(vect, n, queries, q);
    return 0;
}