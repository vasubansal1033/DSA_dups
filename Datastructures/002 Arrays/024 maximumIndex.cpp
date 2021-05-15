//https://practice.geeksforgeeks.org/problems/maximum-index3307/1#

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here

        vector<int> maxFromEnd(n);
        maxFromEnd[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            maxFromEnd[i] = max(maxFromEnd[i+1], arr[i]);
        }

        int res = 0;
        for(int i=0; i<n; i++){

            int lo = i, hi = n-1;
            while(lo<hi){

                int mid = lo+(hi-lo+1)/2;
                if(maxFromEnd[mid]>=arr[i]) lo = mid;
                else hi = mid-1;

            }

            res = max(res, lo-i+1);

        }

        return res;
    }

};
