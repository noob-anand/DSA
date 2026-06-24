class Solution {
public:
    int lcs(string& s, string& t){
        int n= s.size();
        int m= t.length();
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++){
            prev[j]=0;
        }
        for(int i=0;i<=n;i++){
            curr[0]=0;
        }
        for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]){
            curr[j] = 1+prev[j-1];
        }
        else{
            curr[j] = max(curr[j-1],prev[j]);
        }
        }
        prev = curr;
        }
        return prev[m];
    }
    int longestpalindrome(string s){
        string t= s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
    int minInsertions(string s) {
        int n= s.size();
        return n-longestpalindrome(s);
    }
};