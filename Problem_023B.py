#User function Template for python3
#Max Subarray Product
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr, n):
		# code here
        currentMin = arr[0]
        currentMax = arr[0]
        
        ans = arr[0]

        for i in range(1,n,1):
            
            if arr[i] < 0:
                temp = currentMin
                currentMin = currentMax
                currentMax = temp
                
            currentMin = min(arr[i], arr[i]*currentMin)
            currentMax = max(arr[i], arr[i]*currentMax)
    
            ans = max(ans, currentMax)
        return ans
#{ 
#  Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends