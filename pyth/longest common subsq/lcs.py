
def lcs(str1, str2, len1, len2):
    global dp
    if len1 <= 0 or len2 <= 0:
        return 0
    else:
        if dp[len1-1][len2-1] == -1:
            if str1[len1-1] == str2[len2-1]:
                dp[len1-1][len2-1] = 1 + lcs(str1, str2, len1-1, len2-1)
            else:
                temp1 = lcs(str1, str2, len1-1, len2)
                temp2 = lcs(str1, str2, len1, len2-1)
                dp[len1-1][len2-1] = max(temp1, temp2)
        return dp[len1-1][len2-1]
    
n = 0               #taking input
while n<2:
    if n==0:
        str1 = input()
    else:
        str2 = input()
    n += 1


rows = len(str1)
cols = len(str2)
dp = [[-1]*(cols+1) for j in range(rows+1)]
k = lcs(str1, str2, rows, cols)
print(k)

ans = ""
i = len(str1)-1
j = len(str2)-1

while(i>=0  and  j>=0):    #getting the longest common subsequence
    if str1[i] == str2[j]:
        ans = str1[i] + ans
        i -= 1
        j -= 1
    else:
        if dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1
print (ans)            
    
    
    