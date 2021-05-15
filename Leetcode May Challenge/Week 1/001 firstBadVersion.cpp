// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        long long int lo(1), hi(n);
        while(lo<hi){

            long long int mid = lo+(hi-mid)/2;
            if(isBadVersion(mid))
                hi = mid;
            else
                lo = mid+1;

        }

        return lo;

    }
};
