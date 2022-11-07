#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long 
using namespace std;
vector<ll> majorityElement(vector<ll> nums) {
    unordered_map<ll,ll> index;
    vector<ll> ans;
    for(ll i=0;i<nums.size();i++) {
        index[nums[i]]+=1;
    }
    for(auto x: index) {
      if(x.second> (nums.size()/3)) {
        ans.push_back(x.first);
      }
    }
    return ans;

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
    // cout<< majorityElement(nums);
    vector<ll> ans = majorityElement(nums);
    return 0;
}