class Solution {
public:

    char incCharOne(char ch){
        if(ch=='9') return '0';
        return ++ch;
    }

    char decCharOne(char ch){
        if(ch=='0') return '9';
        return --ch;
    }


    int openLock(vector<string>& deadends, string target) {

        //Put all the deadends into a map for fast retreival
        unordered_map<string, int> mp;
        for(auto i : deadends){
            mp[i]++;
        }

        queue<pair<int, string>> q;
        unordered_map<string, int> repeated;

        q.push({0, "0000"});
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            string word = front.second;

            if(word == target) return front.first;

            if(mp[word]) continue; //If we reach a dead end, we will not add to queue and continue

            for(int i = 0; i < 4; i++){
                char original = word[i];

                word[i] = incCharOne(original);
                if(!repeated[word]){
                    repeated[word]++;
                    q.push({front.first + 1, word});
                }

                word[i] = decCharOne(original);
                if(!repeated[word]){
                    repeated[word]++;
                    q.push({front.first + 1, word});
                }

                word[i] = original;
            }
        }
        return -1;
    }
};