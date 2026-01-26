class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1:
        // Sort all intervals based on their start time.
        // This ensures overlapping intervals are placed next to each other.
        sort(intervals.begin(), intervals.end());

        // This vector will store the final merged intervals
        vector<vector<int>> ans;

        // Step 2:
        // Traverse through each interval one by one
        for (int i = 0; i < intervals.size(); i++) {

            /*
             If:
             - ans is empty (first interval)
             OR
             - current interval does NOT overlap with the last merged interval

             Non-overlapping condition:
             current start > last end
            */
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {

                // Add current interval as a new interval
                ans.push_back(intervals[i]);
            }
            else {

                /*
                 Overlapping intervals:
                 Merge them by extending the end time of the last interval
                 End = max(previous end, current end)
                */
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        // Step 3:
        // Return all merged intervals
        return ans;
    }
};
