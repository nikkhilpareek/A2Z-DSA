#include<bits/stdc++.h>
using namespace std;

// Armstrong Number is a number that is equal to the sum of cubes of its digits
// ex: 371 = 3^3 + 7^3 + 1^3

void checkArmstrong(int n){
    int sum = 0;
    int temp = n;
    while(n>0){
        int ld = n%10;
        n /= 10;
        sum = sum + (ld*ld*ld);
    }
    if(temp == sum){
        cout<<"Armstrong Number"<<endl;
    }else{
        cout<<"Not Armstrong Number"<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    checkArmstrong(n);
    return 0;
}