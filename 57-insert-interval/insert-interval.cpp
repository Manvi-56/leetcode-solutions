class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& C, vector<int>& newInterval) {

        // This will store the final answer
        vector<vector<int>> ans;

        int i = 0;
        int n = C.size();

        /*
        STEP 1:
        Add all intervals that come completely BEFORE newInterval
        (i.e., their end is smaller than newInterval start)
        */
        while (i < n && C[i][1] < newInterval[0]) {
            ans.push_back(C[i]);
            i++;
        }

        /*
        STEP 2:
        Merge all overlapping intervals with newInterval
        Overlapping condition:
        current interval start <= newInterval end
        */
        while (i < n && C[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], C[i][0]);
            newInterval[1] = max(newInterval[1], C[i][1]);
            i++;
        }

        // Add the merged newInterval
        ans.push_back(newInterval);

        /*
        STEP 3:
        Add all intervals that come AFTER newInterval
        */
        while (i < n) {
            ans.push_back(C[i]);
            i++;
        }

        return ans;
    }
};
