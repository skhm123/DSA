#include<bits/stdc++.h>
#define ll long long 
using namespace std;
vector<vector<ll> > merge(vector<vector<ll> > intervals) {
    sort(intervals.begin(),intervals.end());
    ll n = intervals.size();
    ll array_limit = INT_MIN;
     vector<ll> values;
    for(ll i=0;i<n;i++) {
        if(intervals[i][1]>array_limit) {
            array_limit= intervals[i][1];
        }
    }
    for(ll i=0;i<array_limit+1;i++) {
        values.push_back(-1);
    }
    for(ll i=0;i<n;i++) {
        ll startIndex = intervals[i][0];
        ll endIndex = intervals[i][1];
        for(ll j = startIndex; j<=endIndex; j++) {
            values[j]=startIndex;
        }
    }
    
    vector<ll> ansVector;
   

    for(ll i=0;i<array_limit+1;i++) {
        ansVector.push_back(-1);
    }
       for(auto x: values) {
        cout<<x<<" ";
    }
     cout<<"\n";
    for(ll i=0;i<n;i++) {
        ll startIndex = intervals[i][0];
        ll endIndex = intervals[i][1];
        ll value = ansVector[startIndex] !=-1 ?ansVector[startIndex]: ansVector[endIndex]!=-1? ansVector[endIndex]: values[startIndex]; 
        for(ll j = startIndex; j<=endIndex; j++) {
            // cout<<value<<"\n";
            ansVector[j]=value;
        }
    }
 
   
    for(auto x: ansVector) {
        cout<<x<<" ";
    }
    cout<<"\n";
    vector<vector<ll> > ans;
    ll startPair=-1, endPair =-1, valueAtIndex=-1;
    for(ll i=0;i<array_limit+1;i++) {
        // cout<< ansVector[i]<<" "<<valueAtIndex<<"\n";
        if(ansVector[i]!= valueAtIndex) {
            valueAtIndex = ansVector[i];
            if(startPair ==-1) {
                // cout<< i<<"\n";
                startPair =i;
                endPair=i;
            }
            else {
                   vector<ll> vect;
                vect.push_back(startPair);
                vect.push_back(endPair);
                ans.push_back(vect);
                vect.clear();
                startPair =-1;
                endPair =-1;
            }
            if(valueAtIndex !=-1) {
                startPair =i;
                endPair = i;
            }
        }
        else if(valueAtIndex!=-1){
             endPair =i;
        }
    }
    // cout<<startPair;
    if(startPair != -1 && endPair !=-1) {
                vector<ll> vect;
                vect.push_back(startPair);
                vect.push_back(endPair);
                ans.push_back(vect);
                vect.clear();
                startPair =-1;
                endPair =-1;
            }
    return ans;
} 
int main() {
    vector<vector<ll> > intervals;
    ll m , n;
    cin>>m>>n;
    for(ll i=0;i<m;i++) {
        vector<ll> vect;
        ll input;
        for(ll j=0;j<n;j++) {
            cin>>input;
            vect.push_back(input);
        }
        intervals.push_back(vect);
        vect.clear();
    }
    vector<vector<ll> >ans = merge(intervals);
    for(ll i=0;i<ans.size();i++) {
    for(ll j=0;j<2;j++) {
        cout<<ans[i][j]<< " ";
    }
    cout<<"\n";
   }
    return 0;
}