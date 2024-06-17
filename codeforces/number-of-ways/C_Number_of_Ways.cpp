#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

long long calculate (vector<long long>& preSum, const long long& target) {
    long long count_1st = 0;
    long long result = 0;
    //Don't iterate to the last element since if the target is 0, and the last number is 0 it will add wrong values to it. 
    //Plus, the last element should be reserved as well.
    for(int i = 1; i < preSum.size() - 1; i++) {
        
        if (preSum[i] == 2*target) {
            //When the presum is equal to 2*target, it means that it get into the second partition
            //And in this situation, it has count_1st kind of ways to get there.
            result += count_1st;
            // cout << "result = " << result << endl;
        }
        // if it is equal to the target, add 1 to the count, and
        // this means that there are 'count_1st' kinds of possibilities for the first subarray.
        if (preSum[i] == target) {
            count_1st++;
        }
        
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    if (n > 2) {
        vector<int> arr(n, 0);
        vector<long long> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            preSum[i + 1] = arr[i] + preSum[i];
            // cout << "preSum [" << i + 1 << "] = " << preSum[i + 1] << endl;
        }
        long long sum = preSum[n];
        if (sum % 3 == 0) {
            long long target = sum / 3;
           cout << calculate(preSum, target) << endl;
           return 0;
        }
    }
    cout << "0" << endl;    
return 0;
}

