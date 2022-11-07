#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector< vector<int> > twoSum(vector<int> nums, int startIndex, int target) {
    map<int,int> hashMap;
    set<pair<int,int> > hashStore;
    vector<vector<int> > ans;
    vector<vector<int> >saksham;
    int n = nums.size();
    for(int i=startIndex; i<n;i++) {
        if(hashMap.count(nums[i])) {
            // hashStore.insert(make_pair(i,hashMap[nums[i]]));
            vector<int> lit;
            lit.push_back(i);
            lit.push_back(nums[i]);
            saksham.push_back(lit);
        }
        else {
            hashMap.insert(make_pair(target-nums[i], i));
        }
    }
    // for(auto x: saksham) {
    //     hashStore.insert(make_pair(x[0], x[1]));
    // }
    for(auto x: saksham) {
        vector<int> vect;
        vect.push_back(x[0]);
        vect.push_back(x[1]);
        ans.push_back(vect);
        vect.clear();
    }
    // cout<< "Final Target "<< target<<"\n";
    // for(auto x: ans) {
    //     cout<< x[0] <<  " "<<x[1]<<"\n"; 
    // }
    return ans;
}
vector<vector<int> > fourSum(vector<int> nums, int target)  {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int> > StoreAns;
    vector<vector<int> > actualAns;
    for(int i=0;i<=n-4;i++) {
        for(int j=i+1;j<=n-3;j++) {
            int finalTarget = target-nums[i]-nums[j];
            vector<vector<int> > ans = twoSum(nums,j+1,finalTarget);
            if(ans.size()!=0) {
                for(int k =0;k<ans.size();k++) {
                vector<int> ans1;
                ans1.push_back(nums[i]);
                ans1.push_back(nums[j]);
                ans1.push_back(nums[ans[k][0]]);
                ans1.push_back(nums[ans[k][1]]);
                // sort(ans1.begin(),ans1.end());
                actualAns.push_back(ans1);
                }

            }
        }
    }
    for(auto x: actualAns) {
        StoreAns.insert(x);
    }
    vector<vector<int> >Ans;
    for(auto x: StoreAns) {
        Ans.push_back(x);
    }
    return Ans;   
} 
int main() {
    int n, target;
    cin>>n>>target;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        nums.push_back(input);
    }
    vector<vector<int> > ans= fourSum(nums, target);
    for(auto x: ans) {
        for(auto y: x) {
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    return 0;
}