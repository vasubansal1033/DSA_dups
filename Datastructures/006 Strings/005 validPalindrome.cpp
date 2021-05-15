class Solution {
public:

    bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }

    return true;
}
};


class Solution {
public:

    bool fun(string& s, int i){
        return ((s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'));
    }

    bool isPalindrome(string s) {

        int i(0), j(s.size()-1);



        while(i<j){

            while(i<s.size() && !fun(s, i))
                i++;
            while(j>=0 && !fun(s, j))
                j--;

            if(i>=s.size() || j<0) break;

            if(s[i]==s[j] || (isalpha(s[i])&&(isalpha(s[j])) && abs(s[i]-s[j])=='a'-'A')){
                i++;
                j--;
            }else return false;

        }

        return true;

    }
};
