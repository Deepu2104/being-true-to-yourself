class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];

        auto common = [&](string a, string b){
            int sz = min(a.size(), b.size());
            int common_length = 0;
            for(int i = 0; i < sz; i++){
                if(a[i] == b[i]){ 
                    common_length++;
                }
                else {
                    break;
                }
            }
            return common_length;
        };

        int ans = 1e9;

        for(int j = 1; j < n; j++){
            int len = common(strs[0], strs[j]);
            ans = min(len, ans);
        }
        if(ans == 1e9) return "";
        return strs[0].substr(0, ans);
    }
};