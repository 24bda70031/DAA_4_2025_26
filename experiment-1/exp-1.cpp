// Experiment 1:
// Do the following:
//         1.        Write the recurrence relation for the above function.
//         2.        Using the Master Theorem, find the asymptotic time complexity and clearly state which case of the theorem is applied.
//         3.        Modify the given code to:
//         •        count the number of operations performed, and depth of the recursion tree
//         •        measure the execution time (in milliseconds)
// Print the number of operations and time taken for different input sizes n

// Name: Habis Prakash Deka
// UID: 24BDA70031


#include <bits/stdc++.h>
using namespace std;

long long operations = 0;
int max_depth = 0;
int cur_depth = 0;

int complexRec(int n) {
    cur_depth++;
    max_depth = max(max_depth, cur_depth);
    
    if (n <= 2) {
        cur_depth--;
        return 0;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        operations++; 
        p >>= 1;
    }
    
    // small vector
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }
    
    // reverse
    reverse(small.begin(), small.end());
    operations += n/2;
    
    // recursive calls
    int a = complexRec(n/2);
    int b = complexRec(n/2);
    int c = complexRec(n/2);
    
    cur_depth--;
    return max({a,b,c}) + 1;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    auto start = chrono::high_resolution_clock::now();
    
    int depth = complexRec(n);
    
    auto end = chrono::high_resolution_clock::now();
    auto time_ms = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    cout << endl;
    cout << "Iteration: " << operations << endl;
    cout << "Depth: " << max_depth << endl;
    cout << "Time: " << time_ms.count() << " ms" << endl;
    
    return 0;
}


// 1. Recurrence relation: T(n) = 3T(n/2) + 5n/2;
// 2. a = 3, b = 2, k = 1;
//     case 1 : a > b^k;
//     T(n) = O(n^(log(base 2)3))
// 3. modified.
