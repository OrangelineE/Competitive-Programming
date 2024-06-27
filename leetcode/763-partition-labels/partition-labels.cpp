class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ends;
        for(int i = 0; i < s.size(); i++) {
            ends[s[i]] = i;
        }
        int st = 0;
        int end = 0;
        vector<int> ans;
        int i = 0;
        while(i < s.size()) {
            end = ends[s[st]];
            // cout << "end = " << end << endl;
            while(i <= end) {
                // cout << "i = " << i << endl;
                end = max(ends[s[i]], end);
                // cout << "New end = " << end << endl;
                ++i; 
            }
            int interval = i - st;
            // cout << "interval = " << interval << endl;
            ans.push_back(interval);
            st = i;
        }
        return ans;
    } 
};