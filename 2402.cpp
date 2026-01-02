using ll = long long;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());
        multiset<pair<ll,ll>> occupiedRooms;
        set<ll> freeRooms;
        for(ll i = 0; i < n; i++) freeRooms.insert(i);
        map<ll,ll> freq;

        for(ll i = 0; i < meetings.size(); i++){
            // if any free rooms available
            ll startTime = meetings[i][0];
            ll endTime = meetings[i][1];

            auto it = occupiedRooms.lower_bound({startTime + 1, INT_MIN});
            if(it != occupiedRooms.begin()){1
                auto prevIt = prev(it);
                // can i traverse from it->begin to prevIT
                // and find the minimum valued room?
                // since n is small here? i cannot see a good reason not to
                auto traverseIt = occupiedRooms.begin();
                while(true){
                    freeRooms.insert(traverseIt->second);
                    if(traverseIt == prevIt) {
                        occupiedRooms.erase(traverseIt);
                        break;
                    }
                    occupiedRooms.erase(traverseIt);
                    traverseIt++;
                } 
            }

            if(freeRooms.size()){
                auto it = freeRooms.begin();
                freq[*it]++;
                occupiedRooms.insert({endTime, *it});
                freeRooms.erase(it);
            }else{
                // we look among the occupiedRooms and give the first
                // room where meeting ends
                if(occupiedRooms.size()){                      
                    ll occupiedRoomStartTime = it->first;
                    ll occupiedRoom = it->second;
                    occupiedRooms.erase(it); // find the room and erase
                    
                    // find the new endTime for meeting and push back in set
                    ll duration = endTime - startTime;
                    ll endTime = max(startTime, occupiedRoomStartTime) + duration;
                    occupiedRooms.insert({endTime, occupiedRoom});
                    freq[occupiedRoom]++;
                }
            }
        }

        ll maxOccupiedRoom = -1, maxFreq = -1;
        for(auto [room, times] : freq){
            if(times > maxFreq){
                maxFreq = times;
                maxOccupiedRoom = room;
            }
        }
        return maxOccupiedRoom;
    }
};
