class Solution {
public:
    // is it possible to find m places having atleast d distance between them
    bool isPossible(vector<int>& position, int d, int m){

        int last = position[0];
        int cnt = 1;
        for(int i=1; i<position.size(); i++){

            if(position[i]-last>=d){

                last = position[i];
                cnt++;
                if(cnt==m) return true;

            }

        }

        return cnt>=m;

    }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int lo = 0;
        int hi = position[position.size()-1];

        while(lo<hi){

            int mid = lo+(hi-lo+1)/2;
            if(isPossible(position, mid, m))
                lo = mid;
            else
                hi = mid-1;

        }

        return lo;

    }
};
