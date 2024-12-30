class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long long rev = 0; // Throws a runtime error if Int used.
        if(x<0){
            return false;
        }
        while(x>0){
            int digit = x%10;
            rev = rev*10 + digit;
            x /= 10;
        }
        if(rev == n){
            return true;
        }
        return false;
    }
};
