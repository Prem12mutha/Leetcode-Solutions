class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;
        int height;
        int width;
        
        for(int i = 0 ; i < heights.size() ; i++){

            while(!s.empty() && heights[i] < heights[s.top()]){
                height = heights[s.top()];
                s.pop();
                width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea ,height * width);    
            }
                s.push(i);
        }
        return maxArea;
    }
};