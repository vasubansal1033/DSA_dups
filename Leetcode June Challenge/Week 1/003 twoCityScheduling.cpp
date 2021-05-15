bool myComparator(vector<int>& v1, vector<int>& v2){
        return abs(v1[0]-v1[1])>abs(v2[0]-v2[1]);
}
class Solution {
public:


    int twoCitySchedCost(vector<vector<int>>& costs) {

        // If we see it from the perspective of profit made
        // then we can see that if we arrange them a/c to abs diff
        // and make greedy choice
        // our overall profit would be maximum

        sort(costs.begin(), costs.end(), myComparator);

        int i=0;
        int cityA = costs.size()/2;
        int cityB = cityA;
        int cost_ = 0;
        while(i<costs.size()){

            if(costs[i][0]<costs[i][1] && cityA>0){
                cost_+=costs[i][0];
                cityA--;
                i++;
            }else if(costs[i][0]>costs[i][1] && cityB>0){
                cost_+=costs[i][1];
                cityB--;
                i++;
            }else{
                break;
            }

        }
        if(cityA==0){

            while(i<costs.size()){
                cost_+=costs[i][1];
                i++;
            }

        }
        if(cityB==0){

            while(i<costs.size()){
                cost_+=costs[i][0];
                i++;
            }

        }

        return cost_;


    }
};
