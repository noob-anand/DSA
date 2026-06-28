class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (ans.size() == 0 || ans[ans.size() - 1] < nums[i]) {
                ans.push_back(nums[i]);
            } else {
                auto l = lower_bound(ans.begin(), ans.end(), nums[i]);
                ans[l - ans.begin()] = nums[i];
            }
        }
        return ans.size();
    }
};