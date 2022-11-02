#include<bits/stdc++.h>
#define ll long long 
using namespace std; 

void rotate(vector<vector<ll> >& matrix) {
    ll n = matrix.size();
    for(ll i=0;i<n/2;i++) {
        for(ll j=i;j<=n-i-2;j++) {
            // cout<<i<<" "<<j<<"\n";
            ll temp1, temp2, temp3, temp4;
            temp1 = matrix[i][j];
            temp2= matrix[j][n-1-i];
            temp3= matrix[n-1-i][n-1-j];
            temp4= matrix[n-1-j][i];
            matrix[i][j] = temp4;
            matrix[j][n-1-i] = temp1;
            matrix[n-1-i][n-1-j] = temp2;
            matrix[n-1-j][i] = temp3;
        }
    }
   for(ll i=0;i<n;i++) {
    for(ll j=0;j<n;j++) {
        cout<<matrix[i][j]<< " ";
    }
    cout<<"\n";
   }
}
int main() {
    vector<vector<ll> > matrix;
    ll m , n;
    cin>>m>>n;
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
    rotate(matrix);
    return 0;
}