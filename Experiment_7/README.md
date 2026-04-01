# Cheapest Flight Within K Stops

## Problem Statement
Given:
- `n` cities
- `flights[i] = [u, v, w]` representing a flight from `u` to `v` with cost `w`
- `src` (source), `dst` (destination)
- `k` (maximum allowed stops)

Determine the minimum cost to travel from `src` to `dst` with at most `k` stops. If no such route exists, return `-1`.


## Algorithm

### 1. Graph Construction

Construct an adjacency list representation of the graph:

```cpp
adj[u] = list of (cost, v)
```

For each flight:

```cpp
adj[u].push_back({w, v});
```

---

### 2. Initialization

- Priority queue storing tuples of the form:
  ```cpp
  (cost, node, stops)
  ```

- Stops tracking array:
  ```cpp
  vector<int> st(n, INT_MAX);
  ```

- Initialization:
  ```cpp
  st[src] = 0;
  pq.push({0, src, 0});
  ```

---

### 3. Main Processing Loop

While the priority queue is not empty:

#### a. Extract the Minimum Element

```cpp
auto [cost, u, stops] = pq.top();
pq.pop();
```

#### b. Skip Invalid States

```cpp
if (stops > k || stops > st[u]) continue;
```

#### c. Check Destination

```cpp
if (u == dst) return cost;
```

#### d. Update Stops

```cpp
st[u] = stops;
```

#### e. Explore Neighbors

```cpp
for (auto [edgeCost, v] : adj[u]) {
    pq.push({cost + edgeCost, v, stops + 1});
}
```

---

### 4. No Valid Path

```cpp
return -1;
```


## Complexity Analysis

### Time Complexity
O(E * k * log(n * k))

### Space Complexity
O(E + n * k)


## Example

```cpp
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
```

Possible paths:
- 0 to 2 with cost 500
- 0 to 1 to 2 with cost 200

Output:
```
200
```

---

# Dry Run: Cheapest Flight Within K Stops

## Problem Instance

```
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0
dst = 2
k = 1
```

---

## Graph Representation (Adjacency List)

```
0 -> (100,1), (500,2)
1 -> (100,2)
2 -> {}
```

---

## Initialization

```
st = [0, INF, INF]
priority queue = [(0, 0, 0)]   // (cost, node, stops)
```

---

## Iteration Details

### Iteration 1

Pop:
```
(0, 0, 0)
```

Checks:
- node != destination
- stops <= k

Update:
```
st[0] = 0
```

Push neighbors:
```
(100, 1, 1)
(500, 2, 1)
```

Queue:
```
[(100,1,1), (500,2,1)]
```

---

### Iteration 2

Pop:
```
(100, 1, 1)
```

Checks:
- node != destination
- stops <= k

Update:
```
st[1] = 1
```

Push neighbor:
```
(200, 2, 2)
```

Queue:
```
[(200,2,2), (500,2,1)]
```

---

### Iteration 3

Pop:
```
(200, 2, 2)
```

Checks:
- node == destination → return cost

Result:
```
200
```

---

## Final Output

```
200
```

---
