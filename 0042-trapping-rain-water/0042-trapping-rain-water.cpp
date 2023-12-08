class Solution {
public:
    int trap(vector<int>& height) {
//         TC: O(n)  SC: O(1)
        int i=0;
        int j=height.size()-1;
        int maxLeft= 0;
        int maxRight= 0;
        int res=0;

        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>=maxLeft) maxLeft=height[i];
                else res+=maxLeft-height[i];
                i++;
            }
            else{
                if(height[j]>=maxRight) maxRight= height[j];
                else res+=maxRight-height[j];
                j--;
            }
        }
        return res;


        // int i=0;
        // int j=height.size()-1;

        // int maxLeft=height[i];
        // int maxRight=height[j];

        // int result=0;

        // while(i<j){
        //     if(maxLeft <= maxRight){
        //         i++;
        //         maxLeft=max(maxLeft,height[i]);
        //         result+=maxLeft-height[i];
        //     } else{
        //         j--;
        //         maxRight=max(maxRight,height[j]);
        //         result+=maxRight-height[j];
        //     }
        // }
        // return result;
    }
};