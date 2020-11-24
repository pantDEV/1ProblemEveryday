# Search in 2d Matrix
# import numpy as np

class Solution:
    def searchMatrix(self, matrix, target):
      
        if not matrix or not matrix[0]:
            return False
        
        nrows = len(matrix)
        ncols = len(matrix[0])
        low = 0
        high = nrows * ncols - 1
        
        while low <= high:
            
            mid = low + (high - low) // 2
            row, col = divmod(mid, ncols)
            
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                low = mid + 1
            else:
                high = mid - 1
                
        return False


if __name__ == '__main__':

	m,n = map(int, input().split())

	matrix = [[int(input()) for i in range(n)] for j in range(m)]

	# 1 line input separated by space
	# matrix = list(map(int, input().split()))
	# matrix = np.array(matrix).reshape(m,n)
	target = int(input())
	obj = Solution()
	ans = obj.searchMatrix(matrix, target)
	print(ans)

