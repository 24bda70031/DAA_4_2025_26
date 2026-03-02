def superDigit(n, k):
    # Write your code here
    s = n
    num = 0
    for i in s:
        nu = int(i)
        num += nu
    num = num * k
    size = len(str(num))
    if size == 1:
        return num
    num = str(num)
    while(size != 1):
        ans = 0
        nu = num
        for i in nu:
            ans += int(i)
        if(ans <10):
            break
        num = str(ans)
        size = len(num)
        
    
    return int(ans)
