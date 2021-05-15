class Solution{
public:
    int getElement(int arr1[], int arr2[], int n, int m, int idx){
        if(idx<n) return arr1[idx];
        else return arr2[idx-n];
    }
    void setElement(int arr1[], int arr2[], int n, int m, int idx, int val){
        if(idx<n) arr1[idx] = val;
        else arr2[idx-n] = val;
    }
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here

	    int sz = n+m;
	    for(int gap = ceil(sz/2); gap>=1; gap/=2){

	        for(int i=gap; i<sz; i++){

	            int temp = getElement(arr1, arr2, n, m, i);
	            int j;
	            for(j=i; j-gap>=0 && getElement(arr1, arr2, n, m, j-gap)>temp; j-=gap){
	                setElement(arr1, arr2, n, m, j, getElement(arr1, arr2, n, m, j-gap));
	            }
	            setElement(arr1, arr2, n, m, j, temp);

	        }

	    }

	}
};
