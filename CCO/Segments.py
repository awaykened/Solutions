// CCO '05 Day 2 Problem 2 - Segments
// http://wcipeg.com/problem/ccc05s2p5

left = []
right = []
n = input()
for i in xrange(n):
    l,r = map(int,raw_input().split())
    left.append(l)
    right.append(r)

dp = [[0 for i in xrange(2)]for i in xrange(n)] #0 for ltor 1 for rtol
#ltor
dp[0][0] = left[0] - 1 + right[0] - left[0]
#rtol
dp[0][1] = right[0] - 1 + abs(left[0] - right[0])
for i in xrange(1,n):
    #ltor
    dp[i][0] = min (abs(right[i] - left[i]) + abs(left[i] - left[i-1]) + dp[i-1][1], abs(right[i]-left[i]) + abs(left[i]-right[i-1]) + dp[i-1][0])
    #rtol
    dp[i][1] = min (abs(left[i] - right[i]) + abs(right[i] - left[i-1]) + dp[i-1][1], abs(left[i]-right[i]) + abs(right[i]-right[i-1]) + dp[i-1][0])

ans = min(dp[n-1][0] + n - right[n-1], dp[n-1][1] + n - left[n-1])
ans += n-1
print ans


