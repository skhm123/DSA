#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> nums) {
    int curr_sum =0, max_sum= INT_MIN;
    for(int i=0;i<nums.size();i++) {
        curr_sum= curr_sum+ nums[i];
        if(max_sum< curr_sum) {
            max_sum= curr_sum;
        }
        if(curr_sum<0) {
            curr_sum=0;
        }
    }
    return max_sum;
}
 int main() {
    int n ;
    cin>>n;
    vector<int> vect;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
    vect.push_back(input);
    }
    cout<<maxSubArray(vect);
    return 0;
 }
    