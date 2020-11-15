class Solution:
    def maxProfit(self, prices):
        # find maximum profit if stocks can be bought at most twice# find maximum profit
        n = len(prices)
        arr = prices
        ProfitArr = [0] * n
        currentStock = arr[0]

        for i in range(1, n):
            ProfitArr[i] = ProfitArr[i-1]
            if arr[i] >= currentStock:
                ProfitArr[i] = max(ProfitArr[i-1], arr[i] - currentStock)
            else:
                currentStock = arr[i]

        max2 = arr[n-1]
        profit2 = 0
        ans = ProfitArr[n-1]

        for i in range(n-1, 1, -1):
            if arr[i] > max2:
                max2 = arr[i]
            else:
                profit2 = max(profit2, max2 - arr[i])
            ans = max(ans, ProfitArr[i-1] + profit2)

        return ans


if __name__ == "__main__":
    prices = [int(i) for i in input().split()]
    obj = Solution()
    print(obj.maxProfit(prices))
