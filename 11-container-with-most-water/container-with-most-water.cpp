class Solution {
public:
    int maxArea(vector<int>& height) {

        // Two pointers starting from both ends
        int left = 0;
        int right = height.size() - 1;

        // This will store the maximum area found
        int maxArea = 0;

        // Continue until pointers meet
        while (left < right) {

            // Width between the two bars
            int width = right - left;

            // Height of water is decided by the shorter bar
            int waterHeight = min(height[left], height[right]);

            // Area formed by current pair of bars
            int currentArea = waterHeight * width;

            // Update maximum area
            maxArea = max(maxArea, currentArea);

            /*
             Move the pointer pointing to the smaller height.
             Reason:
             - Area depends on the minimum height
             - Moving the taller bar will only reduce width
             - Moving the shorter bar might find a taller bar
            */
            if (height[left] < height[right]) {
                left++;   // try to increase height
            } else {
                right--;  // try to increase height
            }
        }

        // Return the maximum water that can be stored
        return maxArea;
    }
};
