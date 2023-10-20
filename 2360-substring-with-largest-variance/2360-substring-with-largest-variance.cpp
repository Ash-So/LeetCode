class Solution {
public:
    int largestVariance(string s) {
        // O(26*26*N)  O(26)
        int ans=0;
        unordered_map<char, int> freq;

        for(auto& c:s){
            freq[c]++;
        }

        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if( ch1 == ch2 || freq[ch1] == 0 || freq[ch2] == 0 ) continue;

                for(int rev=1;rev<=2;rev++){
                    int c1=0, c2=0;
                    for(auto& c:s){
                        c1+= c==ch1;
                        c2+= c==ch2;

                        if(c1<c2) c1=c2=0;
                        if(c1>0 & c2>0) ans=max(ans,c1-c2);
                    }
                    reverse(s.begin(), s.end());
                }
            }   
        }
        return ans;
    }
};