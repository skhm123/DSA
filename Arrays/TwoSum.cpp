#include<bits/stdc++.h>
#define int long long
using namespace std; 
vector<int> twoSum(vector<int> nums, int target) {
    map<int, int> numberMap;
    vector<int> ans;
    for(int i=0;i<nums.size();i++) {
            // cout<< nums[i]<<" "<<numberMap.count(nums[i])<< "\n";
            if(numberMap.count(nums[i])) {
                ans.push_back(numberMap[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else {
                // numberMap[nums[i]-target] = i;
                numberMap.insert(make_pair(target- nums[i], i));
            }
        }
    
    return ans;
}   
int main() {
    int n , target;
    cin>>n>>target;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        nums.push_back(input);
    }
    vector<int> ans = twoSum(nums, target);
    for(auto x: ans) {
        cout<<x<< " ";
    }
    return 0;
}