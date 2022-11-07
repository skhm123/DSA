#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> merge(vector<ll> arr1, vector<ll> arr2, ll& count) {
    ll n = arr1.size();
    ll m = arr2.size();
    ll i=0, j=0;
    vector<ll> ans;
    while(i<n && j<m) {
        if(arr1[i]>arr2[j]*2) {
            count= count+1;
        }
        if(arr1[i]< arr2[j]) {  
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j]) {
            ans.push_back(arr2[j]);
            j++;
        }
        else {
            ans.push_back(arr1[i]);
            ans.push_back(arr2[j]);
            i++;
            j++;
        }
    }
    while(i<n) {
        ans.push_back(arr1[i]);
    i++;
    }
    while(j<m) {
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}
vector<ll> mergeSort(vector<ll>vect, ll startIndex, ll endIndex, ll &count) {
    if(startIndex == endIndex) {
        vector<ll> oneArray;
        oneArray.push_back(vect[startIndex]);
        return oneArray;
    }
        ll mid = (startIndex+endIndex)/2;
        vector<ll> arr1= mergeSort(vect, startIndex, mid, count);
        vector<ll> arr2 = mergeSort(vect, mid+1,endIndex, count);
        vector<ll> ans = merge(arr1, arr2, count);
        return ans;
}
int main() {
    ll n ;
    cin>>n;
    vector<ll> vect;
    ll count =0;
    for(ll i=0;i<n;i++) {
        ll input;
        cin>>input;
        vect.push_back(input);
    }
    vector<ll> ans = mergeSort(vect,0,n-1, count);
    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<"\n" <<count;
    return 0;
}