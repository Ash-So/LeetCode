class Solution {
public:
    bool isArmstrong(int n) {
        int x=0, temp=n, armstrong=0;
        while(temp>0){
            x++;
            temp/=10;
        }
        
        temp =n;
        while(temp>0){
            int lastdigit = temp%10;
            armstrong+= round(pow(lastdigit,x));
            temp/=10;
        }
        if(armstrong==n) return true;
        return false;
    }
};