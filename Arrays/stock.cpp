#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int maxProfit(vector<int> prices) {
    int n = prices.size();
    int profit =0;
    int lsf = INT_MAX;
    for(int i=0;i<n;i++) {
        if(lsf>prices[i]) {
            lsf = prices[i];
        }
        if(profit< prices[i]-lsf) {
            profit = prices[i]-lsf;
        }
    }
   
   return profit;
}
int main() {
     int n ;
    vector<int> prices;
    cin>>n;
    for(int i=0;i<n;i++) {
        int input; 
        cin>>input;
        prices.push_back(input);
    }
    int profit =  maxProfit(prices);
    cout<<profit;
    return 0;
}

/*
cp mooves slow and sp moves fast
*/