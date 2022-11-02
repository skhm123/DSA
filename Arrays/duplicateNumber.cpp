#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll findDuplicate(vector<ll> nums) {
    // ll sum =0;
    for(ll i=0;i<nums.size();i++) {
        if(nums[abs(nums[i])-1]<0) {
            return abs(nums[i]);
        }
        else {
            nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];
        }
    }
   return -1;
}

int main() {
    ll n;
    cin>>n;
    vector<ll> nums;
    for(ll i=0;i<n;i++) {
        ll input;
        cin>>input;
        nums.push_back(input);
    }
    ll ans = findDuplicate(nums);
    cout<<ans;
    return 0;
}