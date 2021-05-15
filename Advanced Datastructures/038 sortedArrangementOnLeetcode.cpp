class Solution {
public:
    int* BIT;
    int sz;

    void update(int i, int val){
        // i++;
        for(; i<=sz; i+=i&-i) BIT[i]+=val;
    }
    int getSum(int i){
        // i++;
        int sum = 0;
        for(; i>0; i-=i&-i) sum+=BIT[i];
        return sum;
    }
    int createSortedArray(vector<int>& instructions) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sz = *max_element(instructions.begin(), instructions.end());
        BIT = new int[sz+1];
        memset(BIT, 0, sizeof(int)*(sz+1));

        int mod = 1e9+7;

        long int cost = 0;
        for(int i=0; i<instructions.size(); i++){

            int l = getSum(instructions[i]-1);
            int r = i-getSum(instructions[i]);
            cost+=min(l, r);
            cost = cost%mod;
            update(instructions[i], 1);
        }
        // delete[] BIT;

        return cost;
    }
    ~Solution(){
        delete[] BIT;
    }
};
