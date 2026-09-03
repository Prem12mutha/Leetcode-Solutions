class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // If minimum is even, there cannot be any odd number.
        if (mn % 2 == 0) {
            for (int x : nums1) {
                if (x % 2 != 0)
                    return false;
            }
        }

        return true;
    }
};