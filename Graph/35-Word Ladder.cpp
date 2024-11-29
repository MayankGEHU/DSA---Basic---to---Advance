class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(beginWord); 

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            int w = word.size();

            for(int i = 0; i < w; i++) {
                char orignal = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = orignal;
             }
         }
        return 0;
    }
};
