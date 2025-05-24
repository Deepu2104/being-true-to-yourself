2942. Find Words Containing Character

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> output_vector;
        for(int i = 0; i < n; i++){
            string current_word = words[i];
            int found = 0;
            for(auto el : current_word) {
                if(el == x){
                    found = 1;
                    break;
                }
            }
            if(found) output_vector.push_back(i);
        }
        return output_vector;

        // Time Complexity : O(N * len(word))
        // Space Complexity : O (N)
        // N is the size of the given array
    }
};