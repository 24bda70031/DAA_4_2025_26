#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator to sort jobs in descending order of profit
bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compareJobs);
    
    // Find the maximum deadline to size our slot array
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }
    
    vector<int> slots(maxDeadline + 1, -1);
    int countJobs = 0, jobProfit = 0;
    
    for (int i = 0; i < n; i++) {
        // Find a free time slot starting from the job's deadline
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = arr[i].id; 
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return {countJobs, jobProfit};
}

int main() {
    // 1. Initialize the array of jobs with the provided inputs
    // Format is {id, deadline, profit}
    Job arr[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    
    // 2. Calculate the number of jobs
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 3. Call the scheduling function
    vector<int> result = JobScheduling(arr, n);
    
    // 4. Output the results
    cout << "Number of jobs scheduled: " << result[0] << endl;
    cout << "Total maximum profit: " << result[1] << endl;
    
    return 0;
}
