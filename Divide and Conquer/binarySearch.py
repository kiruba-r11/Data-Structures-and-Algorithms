import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Time Complexity: O(logN), N -> Number of elements
Space Complexity: O(N), N -> Number of elements

'''

def lin():
    return list(map(int,input().split()))

def binarySearch(arr,start,end,s):
    if start>end:
        return -1
    mid=(start+end)//2
    if arr[mid]==s:
        return mid
    if arr[mid]>s:
        return binarySearch(arr,start,mid-1,s)
    else:
        return binarySearch(arr,mid+1,end,s)
    return -1
 
if __name__=='__main__':
    n=int(input())
    arr=lin()
    s=int(input())
    result=binarySearch(arr,0,n-1,s)
    if result+1:
        print("Found at position : "+str(result+1)+'\n')
    else:
        print("Not found\n")
    
