#include<bits/stdc++.h>
#define ll long long 
using namespace std; 

void setZeroes(vector<vector<ll> >& matrix) {
   ll n_rows = matrix.size();
   ll n_columns = matrix[0].size();
   set<ll> rowSet; 
   set<ll> colSet;
    for(ll i=0;i<n_rows;i++) {
        for(ll j=0;j<n_columns;j++) {
           if(matrix[i][j]== 0 ) {
            rowSet.insert(i);
            colSet.insert(j);
           }
        }
       
    }
    for(auto x : rowSet) {
       for(ll j=0;j<n_columns; j++) {
        matrix[x][j]=0;
       }
    }
    for(auto x : colSet) {
       for(ll i=0;i<n_rows; i++) {
        matrix[i][x]=0;
       }
    }
   for(ll i=0;i<n_rows;i++) {
    for(ll j=0;j<n_columns;j++) {
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
    setZeroes(matrix);
    return 0;
}