import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Time Complexity: O(N), N -> Number of elements
Space Complexity: O(N), N -> Number of elements

'''

def lin():
    return list(map(int,input().split()))

def findMaxMin(arr,start,end):
    result=[]
    if start==end:
        result=[arr[start]]*2
        return result
    if start==end-1:
        if arr[start]>arr[end]:
            return [arr[start],arr[end]]
        else:
            return [arr[end],arr[start]]
    mid=(start+end)//2
    max1,min1=findMaxMin(arr,start,mid)
    max2,min2=findMaxMin(arr,mid+1,end)
    if max1>max2:
        result.append(max1)
    else:
        result.append(max2)
    if min1<min2:
        result.append(min1)
    else:
        result.append(min2)
    return  result

if __name__=='__main__':
    n=int(input())
    arr=lin()
    maximum,minimum=findMaxMin(arr,0,n-1)
    print("Maximum : "+str(maximum)+"\nMinimum : "+str(minimum)+'\n')
