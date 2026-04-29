class TimeMap {
public:
     unordered_map<string, unordered_map<int, vector<string>>> keyStore;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
         if (keyStore.find(key) == keyStore.end()) {
            return "";
        }
         int seen = 0;
          for (const auto& [time, _] : keyStore[key]) {
            if (time <= timestamp) {
                seen = max(seen, time);
            }
          }
         return seen == 0 ? "" : keyStore[key][seen].back(); 
    }
};
