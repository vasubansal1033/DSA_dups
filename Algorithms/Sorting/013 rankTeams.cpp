string rankTeams(vector<string>& votes) {

    int arr[26][votes[0].size()];
    for(int i=0; i<26; i++)
        for(int j=0; j<votes[0].size(); j++){
            arr[i][j] = 0;
        }

    for(int i=0; i<votes.size(); i++){
        for(int j=0; j<votes[0].size(); j++)
            arr[(votes[i][j]-'A')][j]++;
    }


    sort(votes[0].begin(), votes[0].end(), [&](char a, char b){

        for(int i=0; i<votes[0].size(); i++){
            if(arr[a-'A'][i]>arr[b-'A'][i])
                return true;
            else if(arr[a-'A'][i]<arr[b-'A'][i])
                return false;
            else
                continue;
        }
        return a<b;
    });

    return votes[0];

}
