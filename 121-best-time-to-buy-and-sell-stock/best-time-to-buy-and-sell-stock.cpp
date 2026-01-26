class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // maxProfit stores the maximum profit we can achieve
        int maxProfit = 0;

        // bestBuy stores the minimum price seen so far (best day to buy)
        int bestBuy = prices[0];

        // Traverse prices from day 1 to last day and i is the selling pricies index.
        for (int i = 1; i < prices.size(); i++) {

            /*
             If we sell today, profit would be:
             today's price - best buying price so far
            */
            int profit = prices[i] - bestBuy;

            // Update maximum profit if current profit is higher
            maxProfit = max(maxProfit, profit);

            // Update bestBuy to the lowest price so far
            bestBuy = min(bestBuy, prices[i]);
        }

        // Return the maximum profit found
        return maxProfit;
    }
};
