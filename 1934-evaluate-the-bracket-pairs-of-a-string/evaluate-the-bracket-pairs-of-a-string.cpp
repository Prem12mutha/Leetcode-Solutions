class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Step 1: Build hashmap
        unordered_map<string,string> mp;
        for(auto &kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        // Step 2: Traverse string
        string result;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                string key;
                i++;
                while(s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                // Step 3: Replace with value or "?"
                if(mp.count(key)) result += mp[key];
                else result += "?";
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
