class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        s.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // We return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == endWord)
                return steps;
            
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (s.find(word) != s.end()) {
                        s.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }

        // If there is no transformation sequence possible
        return 0;
    }
};