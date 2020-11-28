#median in a row-wise sorted Array

from bisect import bisect_right  # just like upper bound - no. of elements <= 
class Solution:
    def median(self, matrix, r, c):
    	#code here 
        minInt = matrix[0][0]
        maxInt = matrix[0][-1]
        
        for i in range(1,r):
            minInt = min(minInt, matrix[i][0])
            maxInt = max(maxInt, matrix[i][c-1])
        
        need = (r*c+1)//2 # <= n/2
        #print(need)
        while minInt < maxInt:
            mid = (maxInt + minInt) // 2
            #print(mid)
            total = 0
            for i in range (r):
                total += bisect_right(matrix[i], mid)
           # print(total)
            if total < need:
                minInt = mid+1
            else:       # even if we get total == need, low will move towards answer
                maxInt = mid
                
        return maxInt
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        r,c = map(int,input().strip().split())
        matrix = [[0 for j in range(c)] for i in range(r)]
        line1 = [int(x) for x in input().strip().split()]       
        k = 0
        for i in range(r):
            for j in range (c):
                matrix[i][j]=line1[k]
                k+=1
        ans = ob.median(matrix, r, c);
        print(ans)
# } Driver Code Ends