class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp1(n+1,0),dp2(n+1,0);
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                dp2[j] = max(dp1[j],dp2[j-1]);
                if(word1[i-1] == word2[j-1])
                    dp2[j] = max(dp2[j],dp1[j-1]+1);
            }
            dp1 = dp2;
        }
        return m+n - 2* dp2[n];
    }
};