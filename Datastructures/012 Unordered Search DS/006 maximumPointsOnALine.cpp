class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        // brute force: check every possible line On2
        // evalute every point if its on this line -> overall On3
        // optimize - when evaluated a line, store it in hashmap to avoid repeat calculation

        if(points.size()<=2)
            return points.size();

        unordered_map<string, int> m;

        int res = 0;
        for(int i=0; i<points.size()-1; i++){

            int ans = 0;
            int dups = 0;
            m.clear(); // we are checking points having same slope with a common point
            for(int j=i+1; j<points.size(); j++){

                int dy = points[j][1]-points[i][1];
                int dx = points[j][0]-points[i][0];

                if(dy==0 && dx==0){
                    dups++;
                    continue;
                }

                int g = 1;

                if(dy==0){
                    dx = 1;
                }else if(dx == 0){
                    dy = 1;
                }else{

                    g = __gcd(dy, dx);
                    dy/=g;
                    dx/=g;

                }
                string s = to_string(dy)+"/"+to_string(dx);
                m[s]++;

                ans = max(ans, m[s]);

            }

            ans += dups;
            res = max(res, ans);


        }

        return res+1;


    }
};
