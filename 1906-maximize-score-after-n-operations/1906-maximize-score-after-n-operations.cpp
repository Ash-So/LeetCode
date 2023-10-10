class Solution {
public:
    int maxScore(vector<int>& nums) {
        int length = nums.size(), operations = length / 2;
    vector<vector<int>> gcd(length, vector<int>(length));
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            gcd[i][j] = __gcd(nums[i], nums[j]);
        }
    }
    int size = 1 << length;
    vector<int> dp(size);
    for (int mask = 0; mask < size; mask++) {
        int iThOperation = __builtin_popcount(mask);
        if ((iThOperation & 1) != 0) continue;
        for (int x = 0; x < length; x++) {
            if (((mask & (1 << x)) != 0)) continue;
            for (int y = x + 1; y < length; y++) {
                if (((mask & (1 << y)) != 0)) continue;
                int newMask = mask | (1 << x) | (1 << y);
                int score = gcd[x][y] * ((iThOperation >> 1) + 1);
                dp[newMask] = max(dp[mask] + score, dp[newMask]);
            }
        }
    } return dp[size - 1];

    }
};