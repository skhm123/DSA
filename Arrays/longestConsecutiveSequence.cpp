#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll longestConsecutive(vector<ll> nums) {
    ll n = nums.size();
    vector<ll> positveNumbers;
    vector<ll> negativeNumbers;
     vector<ll> positiveValues;
       vector<ll> negativeValues;
     ll negative_max_length= 0;
      ll positive_max_length= 0;
    for(ll i=0;i<n;i++) {
        if(nums[i]>=0) {
            positveNumbers.push_back(nums[i]);
        }
        else {
            negativeNumbers.push_back(nums[i]);
        }
    }
    if(positveNumbers.size()!=0) {
 ll positive_array_limit = INT_MIN;
    for(ll i=0;i<positveNumbers.size();i++) {
        if(positveNumbers[i]>positive_array_limit) {
            positive_array_limit= nums[i];
        }
    }
    // vector<ll> positiveValues;
    for(ll i=0;i<positive_array_limit+1;i++) {
        positiveValues.push_back(INT_MIN);
    }
   for(ll i=0;i<positveNumbers.size();i++) {
      positiveValues[positveNumbers[i]] =1;
    }
    // ll positive_max_length= 0;
    ll current_pos_length =0;;
    for(ll i=0;i<positive_array_limit+1;i++) {
        if(positiveValues[i] ==1) {
            current_pos_length+=1;

        }
        else {
            if(current_pos_length> positive_max_length) {
                positive_max_length = current_pos_length;
            }
            current_pos_length=0;
        }
        }
        if(current_pos_length> positive_max_length) {
                positive_max_length = current_pos_length;
            }
    }
   
    if(negativeNumbers.size()!=0) {
    ll negative_array_limit = INT_MIN;
    for(ll i=0;i<negativeNumbers.size();i++) {
        if(abs(negativeNumbers[i])>negative_array_limit) {
            negative_array_limit= nums[i];
        }
    }
    // vector<ll> negativeValues;
    for(ll i=0;i<negative_array_limit+1;i++) {
        negativeValues.push_back(INT_MIN);
    }
   for(ll i=0;i<positveNumbers.size();i++) {
      negativeValues[abs(negativeNumbers[i])] =1;
    }
    // ll negative_max_length= 0;
    ll current_pos_length =0;;
    for(ll i=0;i<negative_array_limit+1;i++) {
        if(negativeValues[i] ==1) {
            current_pos_length+=1;

        }
        else {
            if(current_pos_length> negative_max_length) {
                negative_max_length = current_pos_length;
            }
            current_pos_length=0;
        }
        }
        if(current_pos_length> negative_max_length) {
                negative_max_length = current_pos_length;
            }

    }
cout<<positive_max_length;
if(positiveValues.size() ==0 ) {
    return negative_max_length;
}
if(negativeValues.size() ==0 ){
    return positive_max_length;
}
else {
                   if(negativeValues[1] ==1 && positiveValues[0]==1) {
    ll combinedLength = 0;
    for(ll i=1;i<negativeValues.size();i++) {
        if(negativeValues[i]==1) {
            combinedLength+=1;
        }
        else {break;}
    }
    for(ll i=0;i<positiveValues.size();i++) {
        if(positiveValues[i]==1) {
            combinedLength+=1;
        }
        else {break;}
    }
    return max(positive_max_length, max(negative_max_length, combinedLength));
   }
   else {
    return max(positive_max_length, negative_max_length);
   }
}

}
int main() {
    ll n ;
    vector<ll> nums;
    cin>>n;
    for(ll i=0;i<n;i++) {
        ll input;
        cin>>input;
        nums.push_back(input);
    }
    ll ans= longestConsecutive(nums);
    cout<<ans;
    return 0;
}