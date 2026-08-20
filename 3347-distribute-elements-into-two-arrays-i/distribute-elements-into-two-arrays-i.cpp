class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1, v2;
        
        // Step 1: First two elements
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        // Step 2: Distribute remaining elements
        for (int i = 2; i < nums.size(); i++) {
            if (v1.back() > v2.back()) {
                v1.push_back(nums[i]);
            } else {
                v2.push_back(nums[i]);
            }
        }

        // Step 3: Concatenate v2 into v1
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};
