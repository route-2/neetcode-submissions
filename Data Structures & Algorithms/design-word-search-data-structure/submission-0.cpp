class WordDictionary {
public:
    vector<string> store;

    WordDictionary() {}

    void addWord(string word) {
        store.push_back(word);
    }

    bool search(string word) {
        
        for (string w : store) {
            if (w.length() != word.length()) continue;

            int i = 0;
            while (i < w.length()) {
                if (w[i] == word[i] || word[i] == '.') {
                    i++;
                } else {
                    break;
                }
            }
            if (i == w.length()) {
                return true;
            }
        }
        return false;
    }
};