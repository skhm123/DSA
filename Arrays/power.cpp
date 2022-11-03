#include<bits/stdc++.h>
using namespace std; 
double myPow(double x , double n ) {
     int power = 1;
    bool negative =false;
    if(n)
        if(n<0) {
            // cout<<"h";
            negative = true;
            n = abs(n);
            // cout<<negative;
        }
    double a =x;
        while(power<n) {
                    if(power%2!=0) {
            if(power+1 <=n) {
                 a*=x;
                power+=1;
            }
        }
        else {
            if(power*2<=n) {
                a *=a;
                power*=2;
            }
            else if(power*2>n){
                a = a*x;
                power+=1;
            }
        }
        }
        if(negative) {
            // cout<<"h";
            return 1.0/a;
        }
       
    return a;
}
int main() {
    double x,n;
    cin>>x>>n;
    cout<< myPow(x,n);
    cout<<INT_MIN;
    return 0;
}