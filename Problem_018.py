#User function Template for python3
#Find number of pairs whose sum is equal to given sum

class Solution:
    def getPairsCount(self, arr, n, k):
        # code here
        Dict = {}
        ans  = 0
        for i in range(n):
            need = (k - arr[i])
            if need in Dict: 
                ans = ans + Dict[need]
            if arr[i] in Dict:
                Dict[arr[i]] = Dict[arr[i]] + 1
            else:
                Dict[arr[i]] = 1
        return ans    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getPairsCount(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends