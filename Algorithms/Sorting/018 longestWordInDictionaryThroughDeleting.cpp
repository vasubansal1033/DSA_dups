bool isLCS(string s, string d_i){

    int i(0), j(0);
    while(i<s.size()){

        if(s[i]==d_i[j]){
            i++;
            j++;
        }else{
            i++;
        }
        if(j==d_i.size())
            return true;
    }
    return false;

}
string findLongestWord(string s, vector<string>& d) {

    // sort(d.begin(), d.end(), [](string a, string b){
    //     return a<b;
    // });

    string maxLengthString = "";

    for(int i=0; i<d.size(); i++){
        string str = "";
        if(isLCS(s, d[i]))
            str = d[i];
        if(maxLengthString.size()<str.size() || (maxLengthString.size()==str.size() && maxLengthString>str))
            maxLengthString = str;
    }

    return maxLengthString;

}
