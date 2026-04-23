# ALGO

Step 1: initialise dp with -1
Step 2: call solve(i , j, s, t) 
    where i is iterator for string s
        j is iterator for string t

Step 3: check if dp[i][j] is not -1
        if True then return dp[i][j]

Step 4: if j is out of bounds return dp[i][j] = 1

Step 5: if i is out of bounds return dp[i][j] = 0

Step 6: if s[i] == t[j]
            returm dp[i][j] = solve(i+1,j+1,s,t) + solve(i+1,j,s,t)
        else
            return dp[i][j]=solve(i+1,j,s,t); 

## Time Complexity and Space Complexity

Time Complexity: O(n * m) where n is size of string s and m is size of string t

Space Complexity: O(n * m)


## Dry run 


### Initial Call

```
solve(0,0)  → 'r' == 'r'
= solve(1,1) + solve(1,0)
```

---

### Step 1

```
solve(1,1) → 'a' == 'a'
= solve(2,2) + solve(2,1)
```

---

### Step 2

```
solve(2,2) → 'b' == 'b'
= solve(3,3) + solve(3,2)
```

---

### Step 3

```
solve(3,3) → 'b' == 'b'
= solve(4,4) + solve(4,3)
```

---

### Step 4

```
solve(4,4) → 'b' == 'b'
= solve(5,5) + solve(5,4)
```

---

### Step 5

```
solve(5,5) → 'i' == 'i'
= solve(6,6) + solve(6,5)
```

- `solve(6,6)` → 't' == 't'
  ```
  = solve(7,7) + solve(7,6)
  = 1 + 0 = 1
  ```

- `solve(6,5)` → mismatch → 0

```
solve(5,5) = 1
```

---

### Step 6

```
solve(5,4) → mismatch → 0
```

```
solve(4,4) = 1 + 0 = 1
```

---

### Step 7

```
solve(4,3) = 0
```

```
solve(3,3) = 1
```

---

### Step 8

```
solve(3,2) = 1
```

```
solve(2,2) = 2
```

---

### Step 9

```
solve(2,1) = 1
```

```
solve(1,1) = 3
```

---

### Step 10

```
solve(1,0) = 0
```

---

## Final Answer

```
solve(0,0) = 3
```
