class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0];
        int maxProfit=0;
        for(int i=0;i<prices.size();i++){
            maxProfit=max(maxProfit, prices[i]-min_price);
            min_price=min(prices[i], min_price);
        }
        return maxProfit;
        
    }
};
// 題意：找出最大收益