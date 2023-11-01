class Solution {
public:
    int maxProfit(vector<int>& a) {
        if(a.size()<2) return 0;
        int min=a[0];
        int profit=0;

        for(int i=0;i<a.size();i++){
            if(a[i]-min > profit){
                profit=a[i]-min;
            }
            if(a[i]<min) min=a[i];
        }
        return profit;
    }
};