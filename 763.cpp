
763. Partition Labels


class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();
        vector<int> pos(26);
        for(int i = 0; i < n; i++) pos[s[i] - 'a'] = i;

        int mx = -1, prev = 0;
        vector<int> partitions;
        for(int i = 0; i < n; i++){
            mx = max(mx, pos[s[i] - 'a']);
            if(i == mx) {
                partitions.push_back(i - prev + 1);
                prev = i + 1;
                continue;
            }
        }
        return partitions;
    }

};