class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        unordered_map<int, int> hashmap;
        int ans = 0;

        for(int i=0; i<wall.size(); i++){
            int pos = 0;
            for(int j=0; j<wall[i].size()-1; j++){
                pos+=wall[i][j];
                hashmap[pos]++;

                ans = max(ans, hashmap[pos]);

            }
        }

        return wall.size()-ans;

    }
};
