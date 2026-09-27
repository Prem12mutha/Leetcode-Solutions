class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26];
        for(char c : sentence){
            arr[c - 'a'] = true;
        }

        for(bool b : arr){
            if(!b) return false;
        }
        return true;
    }
};