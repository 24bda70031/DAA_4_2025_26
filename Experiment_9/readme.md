# ALGO

Step 1: Compute Sum of array 

Step 2: Initialise a dp with false of size (sum / 2) + 1

Step 3: For each number check if  target <= j <= num is possible subset ot not

Step 4: pick the best x <= Sum/2 

Step 5 Return Answer Sum - 2*x

## Time Complexity and Space Complexity

The program iterators over each element, Target times where target is SUM/2

hence Time Complexity is : O(n * SUM) 

Space Complexity is : O(n)

## Dry Run

For arr = [1, 6, 11, 5]

Total sum = 23
Target = 11

dp = [T, T, F, F, F, T, T, T, F, F, T, T] 

Possible subset sums near 11 → {11}

Best = 11
Answer = 23 - 2*11 = 1
