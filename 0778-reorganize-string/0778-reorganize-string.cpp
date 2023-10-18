class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        int max=0, letter;
        for(int i=0;i<26;i++){
            if(freq[i]>max){
                max=freq[i];
                letter=i;
            }
        }

        if(max>(s.size()+1)/2) return "";

        char ans[s.size()];
        int idx=0;
        while(freq[letter]>0){
            ans[idx]='a'+letter;
            idx+=2;
            freq[letter]--;
        }
        
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                if(idx>=s.size()) idx=1;
                ans[idx]=i+'a';
                idx+=2;
                freq[i]--;
            }
        }

        string res;
        for(int i=0;i<s.size();i++){
            res+=ans[i];
        }
        return res;
    }
};