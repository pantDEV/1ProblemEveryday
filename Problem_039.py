# one of the toughest to code for edge cases even after watching solutions
# or maybe I am stupid

class Solution:
    
    def findMedian(self, nums1, nums2):
       
        m = len(nums1)
        n = len(nums2)
        
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        
        low, high = 0, m # nums1 is the shorter array, it can contribute 0 or all of its values to left half
        half = (n+m+1) // 2
        leftMax1, rightMin1, leftMax2, rightMin2 = 0,0,0,0
        
        while low <= high:
            xpart = (low + high) // 2
            ypart = half - xpart
            
           # print(xpart)
            #-----------------------------
            # 1 - why to check for xpart < m --> bcz nums1 can contribute all of its values 
            # 2 - why not check for ypart > 0 --> bcz if xpart < m then nums2 has to contribute atleast one value to left half bcz len(nums1)<= len(nums2)
            
            if xpart < m and nums2[ypart-1] > nums1[xpart]: # leftMax2 > rightMin1
                low = xpart + 1 # move to right
            #-----------------------------    
            # 1 - why to check for xpart > 0 --> bcz it can be equal to 0 :0
            # 2 - why not to check for ypart < n bcz if xpart > 0 then nums2 can not contribute all of its values if nums1 has contributed atleast 1 value to left half as len.nums1 <= nums2.len
           
            elif xpart > 0 and nums2[ypart] < nums1[xpart-1]: # leftMax1 > rightMin2
                high = xpart - 1 # move to left as max of left half is greater than righthalf minimum
                
            else: # Eureka!
                
                leftHalfMax  = 0.0
                rightHalfMin = 0.0
        
                if xpart == 0:
                    #print("ab")
                    leftHalfMax = nums2[ypart-1] #yart must be > 0 to make left half >=1               
                elif ypart == 0:
                    leftHalfMax = nums1[xpart-1] # xpart must be > 0
                        
                else:
                    leftHalfMax = max(nums1[xpart-1], nums2[ypart-1])
                    
                if (n+m) & 1: # total length of merged array is odd
                    return leftHalfMax
                
                else:
                    
                    if xpart == m: # contributes all elements to left half
                        rightHalfMin = nums2[ypart] # xpart == m mtlb ypart < n
                    
                    elif ypart == n: # contributes all elements to left half
                        rightHalfMin = nums1[0]
                    else:
                        rightHalfMin = min(nums1[xpart], nums2[ypart])
                    
                    return (leftHalfMax + rightHalfMin) / 2
                    
                    
if __name__ == '__main__':

    A   = [int(i) for i in input().split()]
    B   = [int(i) for i in input().split()]
    obj = Solution()
    ans = obj.findMedian(A,B)
    print(ans)