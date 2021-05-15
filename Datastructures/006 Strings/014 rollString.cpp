//https://www.geeksforgeeks.org/roll-characters-string/
class Solution{

	public:
	string findRollOut(string s, long long arr[], int n){
	    // Your code goes here
	    long long int temp[n];
	    memset(temp, 0, sizeof(temp));

	    for(int i=0; i<n; i++) temp[arr[i]-1]++;

	    // since we are talking about first n elements, if temp[i] was increased, all j<i will also have increment
	    for(int i=n-2; i>=0 ; i--) temp[i] = temp[i]+temp[i+1];

	    for(int i=0; i<n; i++)
	        s[i] = 'a' + (s[i]+temp[i]-'a')%26;

	    return s;
	}
};
