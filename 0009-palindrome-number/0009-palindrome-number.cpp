class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        long reversed=0;
        long temp=long(x);
        while(temp!=0){
            reversed=10*reversed+temp%10;
            temp/=10;
        }
        return x == reversed || x== reversed/10;
    }
};