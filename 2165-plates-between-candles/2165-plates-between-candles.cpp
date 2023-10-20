class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // prefixSum
        int n=s.size();
        vector<int> next(n,n), prev(n,n), prefixSum(n,0);
        for(int i=0 ;i<n;i++){
            if(i==0){
                if(s[i]=='|') prev[i]=i;
                else prefixSum[i]=1;
            }
            else{
                if(s[i]=='|') {
                    prev[i]=i;
                    prefixSum[i]=prefixSum[i-1];
                }

                else {
                    prev[i]=prev[i-1];
                    prefixSum[i]=1+prefixSum[i-1];
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(s[i]=='|') next[i]=i;
            }
            else{
                if(s[i]=='|') next[i]=i;
                else next[i]=next[i+1];
            }
        }

        vector<int> ans;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int i=next[l];
            int j=prev[r];
            if(j<=i || j==n ||i==n) ans.push_back(0);
            else ans.push_back(prefixSum[j]-prefixSum[i]);
        }        
        return ans;

        // Binary Search
        // vector<int> bar;
        // int i=0;
        // // O(n)
        // for(auto ch: s){
        //     if(ch=='|') bar.push_back(i);
        //     i++;
        // }
        // vector<int> ans;

        // // 2*n(queries) * logn (binary search of lower_bound and upper_bound)
        // for(auto it:queries){
        //     int l=it[0];
        //     int r=it[1];

        //     int i=lower_bound(bar.begin(), bar.end(), l)-bar.begin();
        //     int j=upper_bound(bar.begin(), bar.end(), r)-bar.begin()-1;

        //     if(j<=i) ans.push_back(0);
        //     else ans.push_back(bar[j]-bar[i]-(j-i));
        // }
        // return ans;
    }
};