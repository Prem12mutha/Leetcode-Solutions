class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = *min_element(nums.begin() , nums.end());
        int largest = *max_element(nums.begin() , nums.end());

        vector<bool> present(largest - smallest + 1, false);

        for(int num : nums){
            present[num - smallest] = true;
        }

        vector<int> missing;

        for(int i = 0 ; i < present.size() ; i++){
            if(!present[i]){
                missing.push_back(smallest + i);
            }
        }
        return missing;
    }
};