class Solution {
public:
    int kth(int a[], int m, int b[], int n, int k) {
        if (m < n) return kth(b,n,a,m,k);
        if (n==0) return a[k-1];
        if (k==1) return min(a[0],b[0]);

        int j = min(n,k/2);
        int i = k-j;
        if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int k = (m+n)/2;
        int m1 = kth(a,m,b,n,k+1);
        if ((m+n)%2==0) {
            int m2 = kth(a,m,b,n,k);
            return ((double)m1+m2)/2.0;
        }
        return m1;
    }
};




class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2)
        return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.

    int lo = 0, hi = N2 * 2;

    while (lo <= hi) {

        int mid2 = (lo + hi) / 2;   // Try Cut 2
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

        if (L1 > R2)
            lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1)
            hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else
            return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.

    }
    return -1;
}
};
