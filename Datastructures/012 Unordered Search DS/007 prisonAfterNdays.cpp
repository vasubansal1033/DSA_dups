class Solution {
public:

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {

        if(N==0)
            return cells;

        // m will map a string of state to an int, which is its index in states vector
        unordered_map<string, int> m;
        vector<string> states;

        string currState = "";
        for(int i=0; i<8; i++)
            currState += to_string(cells[i]);

        states.push_back(currState);
        m[currState] = 0;

        int count=1;
        string nextState;

        while(count<=N){

            nextState = "";
            // first prison always 0
            nextState+='0';
            for(int i=1; i<7; i++)
                nextState += (currState[i-1]==currState[i+1]?'1':'0');
            // last prison always 0
            nextState+='0';

            if(m.find(nextState)==m.end()){
                m[nextState] = states.size();
                // push this state in the vector of states
                states.push_back(nextState);
                currState = nextState;
                count++;
                continue;
            }
            break;

        }

        vector<int> res;

        if(count>N){

            for(int i=0; i<8; i++)
                res.push_back(currState[i]-'0');

            return res;

        }

        int k = m[nextState]; // distance from beginning
        int l = count-k; // length of cycle
        int offset = (N-k)%l; // distance from the beginning of cycle

        for(int j=0; j<8; j++){
            res.push_back(states[k+offset][j]-'0');
        }

        return res;

    }
};
