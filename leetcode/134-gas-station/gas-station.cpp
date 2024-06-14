class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int sz = gas.size();
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if (gas_sum < cost_sum) return -1;
    //O(N^2) exceeds TLE

        // vector<int> diff(sz, 0);
        // for(int i = 0; i < gas.size(); i++) {
        //     diff[i] = gas[i] - cost[i]; 
        // }
        // vector<int> res = diff;
        // for(int i = 1; i < gas.size(); i++) {
        //     for(int j = 0; j < gas.size(); j++) {
        //         if (res[j] >= 0) {
        //             res[j] += diff[(j + i)%sz];
        //             index = j;
        //         }
        //     }
        // }

    // Use greedy to identify a valid start O(N)
    for(int i = 0; i < sz; i++) {
        total += gas[i] - cost[i];
        if(total < 0) {
            total = 0;
            start = i + 1;
        }
    }
        return start;
        
    }
};