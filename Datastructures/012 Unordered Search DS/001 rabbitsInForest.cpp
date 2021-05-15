class Solution {
public:
    int numRabbits(vector<int>& answers) {

        unordered_map<int, int> hashmap;
        for(int i=0; i<answers.size(); i++)
            hashmap[answers[i]]++;

        int ans = 0;
        for(auto i:hashmap){

            // number of groups having same color = ceil((float)i.second/(i.first+1))
            // number of rabbits of that color
            ans += ceil((float)i.second/(i.first+1))*(i.first+1);

        }

        return ans;

    }
};
