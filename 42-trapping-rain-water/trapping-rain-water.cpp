class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int water = 0;

        int lmax = 0;
        int rmax = 0;

        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] >= lmax){
                lmax = height[left];
                }
                else{
                    water += lmax - height[left];
                }
                left++;
            }
            else{
               if(height[right] >= rmax){
                rmax = height[right];
                }
                else{
                    water += rmax - height[right];
                }
                right--;
            }
        }
            return water;
    }
};