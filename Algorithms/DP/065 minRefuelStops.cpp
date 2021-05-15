// According to greedy solution here, we might have to travel back to a station to get more fuel
// But since that station could have reached earlier also, we can 'change the order' here
// We can consider that we have a time machine. When we realized we needed more fuel at the farthest station
// we go back in the past and reach that station to make present suitable

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        // with the current fuel, check all the possible stations which can be reached
        // The next station will be the one which has maximum fuel
        // Dijkstra Algorithm inshort

        priority_queue<int> maxHeap;
        maxHeap.push(startFuel);

        int cnt = 0;
        int fuel = 0;
        int stationsIndex = 0;
        while(!maxHeap.empty()){

            int currFuel = maxHeap.top(); maxHeap.pop();
            fuel += currFuel;

            if(fuel>=target) return cnt;
            while(stationsIndex<stations.size() && stations[stationsIndex][0]<=fuel){
                maxHeap.push(stations[stationsIndex][1]);
                stationsIndex++;
            }

            cnt++;

        }

        return -1;

    }
};
