class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> freq;
        queue<pair<char,int>> q;

        for(int i = 0; i < s.length(); i++){
            freq[s[i]]++;
            q.push({s[i] , i});
        }

        while(!q.empty()){
            auto front = q.front();
            if(freq[front.first] == 1){
                return front.second;
            }
            q.pop();
        }
        return -1;
    }
};