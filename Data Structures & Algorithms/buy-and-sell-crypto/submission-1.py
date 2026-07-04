class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret = 0
        length = len(prices)
        print(length)
        for l in range(length):
            for r in range(l,length):
                p = prices[r] - prices[l]
                if ret < p:
                    ret = p
        return ret