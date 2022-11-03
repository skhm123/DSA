#include<bits/stdc++.h>
#define ll long long 
using namespace std; 

bool binarySearch(vector<ll> vect, ll start, ll end, ll target) {
    if(start==end ) {
        if(vect[start] == target) {
            return true;
        }
        else {
            return false;
        }
    }
    if(start>end) {
        return false;
    }
    ll mid = (start+end)/2;
    if(vect[mid]== target) {
        return true;

    }
    else if(vect[mid]>target) {
        return binarySearch(vect,start, mid-1,target);
    }
    else if(vect[mid]<target) {
        return binarySearch(vect, mid+1, end, target);
    }

}

bool searchMatrix(vector<vector<ll> >& matrix, ll target) {
    ll m = matrix.size();
    ll n = matrix[0].size();
    
   for(ll i=0;i<m;i++) {
        if(matrix[i][0]<=target && matrix[i][n-1]>=target) {
            return binarySearch(matrix[i],0,n-1, target);
        }
   }
   return false;
}
int main() {
    vector<vector<ll> > matrix;
    ll m , n;
    ll target;
    cin>>m>>n>>target;
    for(ll i=0;i<m;i++) {
        vector<ll> vect;
        ll input;
        for(ll j=0;j<n;j++) {
            cin>>input;
            vect.push_back(input);
        }
        matrix.push_back(vect);
        vect.clear();
    }
    cout<< searchMatrix(matrix, target);
    return 0;
}