#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int max_length =0;
    // int curr_len =0;
    int startIndex =0;
    int endIndex=-1;
    map<char, int> hashMap;
    for(int i =0;i<n;i++) {
        if(hashMap.count(s[i])&& hashMap[s[i]]>=startIndex && hashMap[s[i]]<=endIndex) {
            int length = endIndex -startIndex+1;
            if(length>max_length) {
                max_length =length;
            }
            startIndex = hashMap[s[i]]+1;
            hashMap[s[i]] =i;
           
            endIndex++;
        }
        else {
            endIndex++;
            if(hashMap.count(s[i])) {
                hashMap[s[i]]=i;
            }
            else {
hashMap.insert(make_pair(s[i],i));
            }
            
            // cout
        }
        // if(hashMap[s[i]]) {
        //     if(max_length<curr_len) {
        //         max_length = curr_len;
        //     }
        //     curr_len =0;
        //     hashMap.clear();
        //     curr_len++;
        //      hashMap[s[i]]++;

        // }   
        // else {
        //     hashMap[s[i]]++;
        //     curr_len++;
        // }
    }
     if(max_length<endIndex -startIndex+1) {
                max_length = endIndex -startIndex+1;
            }
    return max_length;
} 
int main() {
    string s;
    cin>>s;
    cout<< lengthOfLongestSubstring(s);
    return 0;
}