class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> visited;

        queue<pair<string, int> > q;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while(!q.empty()){

            auto front = q.front(); q.pop();

            if(front.first == endWord){
                return front.second;
            }

            // put the neighbours in queue. Neighbours are those which have 1 letter different
            // This approach has complexity of 26*length of word
            // The obvious method was to check for each word in dictionary. It'd be length of dictionary*length of word
            // Dictionaries can be very large. So we go for the first mentioned approach
            string tempWord = front.first;
            for(int i=0; i<front.first.size(); i++){
                for(int j=0; j<26; j++){

                    tempWord[i] = 'a'+j;
                    if(dict.find(tempWord)!=dict.end() && visited.find(tempWord)==visited.end()){
                        visited.insert(tempWord);
                        q.push({tempWord, front.second+1});
                    }


                }
                tempWord[i] = front.first[i];
            }


        }

        return 0;

    }
};
