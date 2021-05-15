string frequencySort(string s) {

    int hashmap[256] = {0};
    for(int i=0; i<s.size(); i++){
        hashmap[s[i]]++;
    }

    sort(s.begin(), s.end(), [=](char a, char b){

        if(hashmap[a]==hashmap[b])
            return a<b;

        return hashmap[a]>hashmap[b];
    });

    return s;
}
