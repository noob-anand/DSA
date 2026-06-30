class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i].first < 1 + dp[j].first)
                        dp[i] = {1 + dp[j].first, dp[j].second};
                    else if (dp[i].first == 1 + dp[j].first)
                        (dp[i].second) += (dp[j].second);
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
            maxi = max(dp[i].first, maxi);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i].first == maxi)
                ans += (dp[i].second);
        return ans;
    }
};