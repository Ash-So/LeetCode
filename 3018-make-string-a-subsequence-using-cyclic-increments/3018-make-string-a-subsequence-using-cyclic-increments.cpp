class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // TC: O(n) SC:O(1)
        int n = str1.size();
        int m = str2.size();
        int j=0;
        for(int i=0; i<n && j<n ;i++){
            if(str1[i] == str2 [j] || str1[i]+1 == str2[j] || str1[i] - 25 == str2[j]){
                j++;
            }
        }
        return j==m;
    }
};