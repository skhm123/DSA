#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void nextPermutation(vector<int> nums) {
 // this is the question based on the permutation that is solve by usind the STl
        // but for the interview purpose i will write the code
        int index1=-1;
        int index2=-1;
        //we will store the two index as the value with -1;
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                index1=i-1;
                //we will store the index 1 in this way that if the value of nums[i]is greater than the value of the nums[i-1]
                //then we will store i-1 as the index1
                break;
            }
        }
        if(index1!=-1)
            //if the index 1 is not equal to the -1 then we are going to update the index2
        {
            for(int j=n-1;j>0;j--)
            {
                if(nums[j]>nums[index1])
                {
                    index2=j;
                    // this is the condition that you will see that how it will inter the value of the index2 as j
                    break;
                }
            }
            swap(nums[index1],nums[index2]);
            // in this step we will swap the value of the index1 with index2 to get the next permutation 
        }
        //at last reverse the value 
        reverse(nums.begin()+index1+1,nums.end());
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
    nextPermutation(nums);
    return 0;
}

/*
Algorithm for next permutation 
1. Iterate from right and find the first index where a[i-1]<a[i]
2. store index1= i-1
3. again iterate from end and find the index greater than vect[index1]< vect[i]
4. index2 = i;
5. swap 
6. reverse from index+1 to end 
*/