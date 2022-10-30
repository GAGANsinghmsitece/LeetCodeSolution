class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, minprice;
        if (prices.size() > 1)
            minprice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};
