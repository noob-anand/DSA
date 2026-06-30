class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int i=0;
        int ans =0;
        int pre = 0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='a') a++;
            if(s[j]=='b') b++;
            if(s[j]=='c') c++;
            while(a>0&&b>0&&c>0){
                 if(s[i]=='a') a--;
            if(s[i]=='b') b--;
            if(s[i]=='c') c--;
            i++;
            
            }
            ans+=i;
        }
        return ans;
    }
};