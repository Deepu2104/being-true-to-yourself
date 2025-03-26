
3169. Count Days Without Meetings


Line Sweep Algorithm: 

map<int,int> freq;

freq[meetins[i][0]] ++;

freq[meetings[i][1] + 1]--;


int prev = -1;
for(auto el : freq){
    int cur = el.first;

    // so till here the range is [prev, cur - 1] = count
    we will get the count of element in this range -> prev, cur - 1 ( inclusive ), because if we include
    the current value in prefix sum, then it tells the count starting from cur element (inclusive ) which makes the use of prev completely useless.

    count += el.second;
    prev = el.first;
}


using ll = long long;
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        // let's see if we can merge some intervals?

        vector<pair<int,int>> mergedArray;

        for(int i = 0; i < n; i++){
            if(mergedArray.empty()){
                mergedArray.push_back({meetings[i][0], meetings[i][1]});
            }else if(meetings[i][0] <= mergedArray.back().second){
                mergedArray.back().second = max(mergedArray.back().second, meetings[i][1]);
            }else{
                mergedArray.push_back({meetings[i][0], meetings[i][1]});
            }
        }

        // now since we have proper merged intervals....
        // it's easier to judge the number of gaps starting from 1

        ll answer = 0, startingDay = 1;
        for(int i = 0; i < mergedArray.size(); i++){
            if(startingDay < mergedArray[i].first){
                answer += mergedArray[i].first - startingDay;
            }
            startingDay = mergedArray[i].second + 1ll;
        }

        if(startingDay <= days) answer += days - startingDay + 1ll;
        return answer;
    }
};
