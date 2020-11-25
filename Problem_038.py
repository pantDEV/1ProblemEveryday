# find medina of two sorted arrays

def median(A, n):

	if n & 1:
		return A[n // 2]
	else:
		return (A[n // 2] + A[n // 2 - 1]) / 2




def findMedian(A, B, n):
	print(A)
	print(B)
	ans = 0.0
	m1 = 0
	m2 = 0
	if n == 2:
		return (max(A[0], B[0]) + min(A[1], B[1]))/2

	else:
		m1 = median(A, n)
		m2 = median(B, n)		

		if m1 == m2:
			return m1
		
		elif m1 < m2:
			
			if n & 1:
				return findMedian(A[n//2 : ], B[: n//2 + 1], n//2 + 1)
			else:
				return findMedian(A[n//2 - 1 : ], B[: n//2 + 1], n//2 + 1)
		else:

			if n & 1:
				return findMedian(A[: n//2 + 1], B[n//2 : ], n//2 + 1)
			else:
				return findMedian(A[: n//2 + 1], B[n//2 - 1 : ], n//2 + 1)



if __name__ == '__main__':

	n   = int(input())
	A   = [int(i) for i in input().split()]
	B   = [int(i) for i in input().split()]

	ans = findMedian(A,B,n)
	print(ans)