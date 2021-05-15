#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gamingArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string gamingArray(vector<int> arr) {
    
    vector<int> greatestOnLeft(arr.size());
    
    greatestOnLeft[0] = -1; // no element on left
    greatestOnLeft[1] = 0; // obvious
    
    int maxi = 0; // index of maximum element
    
    for(int i=0; i<arr.size(); i++){
        
        if(arr[maxi]>arr[i])
            greatestOnLeft[i] = maxi;
        else
            greatestOnLeft[i] = i;
        
        if(arr[maxi]<arr[i])
            maxi = i;
        
    }
    
    int i = maxi;
    int count = 1;
    while(i!=0){
        i = greatestOnLeft[i-1];
        count++;
    }
    
    if(count%2==0)
        return "ANDY";
    else return "BOB";
    
    // counting the number of elements greater than arr[0] won't work
    // as when we are moving right, we are changing the elements greater than 10
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);

        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = gamingArray(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
