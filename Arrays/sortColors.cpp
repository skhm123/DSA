#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void sortColors(vector<int> nums) {
    int n = nums.size();
    for(int i=0;i<n;i++) {
        int number = INT_MAX, index;
        for(int j=i+1;j<n;j++) {
           if(nums[j]<nums[i]) {
            if(number> nums[j]-nums[i])
            {
                number = nums[j]- nums[i];
                index = j;
            }
           }
        }
        if(number!=INT_MAX) {
            swap(nums[i], nums[index]);
        }
    }
     for(auto x: nums) {
        cout<<x<< " ";
    }
}
int main() {
     int n ;
    vector<int> nums;
    cin>>n;
    for(int i=0;i<n;i++) {
        int input; 
        cin>>input;
        nums.push_back(input);
    }
    sortColors(nums);
    return 0;
}