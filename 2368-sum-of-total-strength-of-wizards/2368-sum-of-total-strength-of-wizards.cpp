class Solution {
public:
    int totalStrength(vector<int>& strength) {
        
        stack<int> s;
        int n=strength.size();
        vector<int> l,r;
        int mod=pow(10,9)+7;
        
        for(int i=0;i<strength.size();i++){
            while(!s.empty() && strength[s.top()]>strength[i]){
                s.pop();
            }
            if(s.empty()){
                l.push_back(-1);
            }
            else{
                l.push_back(s.top());
            }
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && strength[s.top()]>=strength[i]){
                s.pop();
            }
            if(s.empty()){
                r.push_back(-1);
            }
            else{
                r.push_back(s.top());
            }
            s.push(i);
        }
        
        reverse(r.begin(),r.end());
        
        vector<long long > pre(n,0);
        
        pre[0]=strength[0];
        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]+strength[i])%mod;
        }
        
        vector<long long int> pref_pre=pre;
        
        for(int i=1;i<n;i++){
            pref_pre[i]=(pref_pre[i]+pref_pre[i-1])%mod;
        }
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            long long int left=l[i];
            long long int right=r[i];
            //cout<<left<<" "<<right<<" ";
//             pre[i]-pre[j]
//             pre[i]-pre[j+1]
//             pre[i]-pre[j+2] j+2==i-1
                
//             pre[i+1]-pre[j]
//             pre[i+1]-pre[j+1]
//             pre[i+1]-pre[j+2] j+2==i-1
                
            long long int after=right-i; // left right nahi le sakte wale hai 
            long long int before=i-left;
            
//             before*(pre[i]+pre[i+1]+...after)-after*(pre[j]+pre[j+1]+..before)
                
//             before * pre[i+after-1]-pre[i-1]
            
            long long sum1=0,sum2=0;
            
            if(left!=-1){
                sum1=pref_pre[i-1];
                long long s1=0;
                if(left-1>=0){
                    s1=pref_pre[left-1];
                }
                sum1=(sum1-s1)%mod;
                
            }
            else if(left==-1){
                if(i-1>=0){
                    sum1=pref_pre[i-1];
                    before=i+1;
                }
                else{
                    before=1;
                }
            }
            
            // pre[i]+pre[i+1]+...after
            if(right==-1 ){
                sum2=pref_pre[n-1];
                long long s2=0;
                if(i-1>=0){
                    s2=pref_pre[i-1];
                }
                sum2=(sum2-s2)%mod;
                after=n-i;
            }
            else if(right!=-1){
                sum2=pref_pre[i+after-1];
                long long s2=0;
                if(i-1>=0){
                    s2=pref_pre[i-1];
                }
                sum2=(sum2-s2)%mod;
            }
        
            ans=ans+(strength[i]%mod*((before*sum2)%mod-(after*sum1)%mod+mod))%mod;
            ans=(ans)%mod;
        }
        
        return ans;
    }
};