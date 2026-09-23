class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";  // use string as a stack
        for(char c : s){
            if(!st.empty() && st.back() == c){
                st.pop_back();   // remove duplicate
            } else {
                st.push_back(c); // keep character
            }
        }
        return st;
    }
};
