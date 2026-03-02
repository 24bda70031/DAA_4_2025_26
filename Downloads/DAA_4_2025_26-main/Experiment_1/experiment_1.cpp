#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long op = 0;
int maxDepth = 0;

void complexRec(int n , int depth) {
    maxDepth = max(maxDepth, depth);

   if (n <= 2) {
   	 	op++;
       return;
   }
  


   int p = n;
   while (p > 0) {
   		
       vector<int> temp(n);
       
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           op+=1;
       }
       p >>= 1;
       
   }
   op++;


   vector<int> small(n);

   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       op++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       op+=n;
   } else {
       reverse(small.begin(), small.end());
       op+=n;
   }
   


   complexRec(n / 2, depth+1);
   complexRec(n / 2, depth+1);
   complexRec(n / 2, depth+1);
};
int main(){
	vector<int> test = {5555, 2564, 1006, 3002, 624, 1208, 4005};
	for (int n : test) {
        op = 0;
        maxDepth = 0;
        auto start = high_resolution_clock::now();
        complexRec(n,1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        
	cout << "n = " << n<< " ops = " << op<<" time(ms) = " << duration.count()<< " maxDepth = " << maxDepth<< endl;
}
}


// T(n) = 3T(n/2) + nlogn + n + n 
//
// Time complexity = O(n^1.58)  