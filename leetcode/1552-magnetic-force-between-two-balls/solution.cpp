class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
       
        sort(position.begin(), position.end());
        int sz = position.size();

        int st = position[0];
        int end = position.back();
        int left = 1;
        int right = end - st;
        if (m == 2) return right;
        while(left < right) {
            int times = 1;
            int mid = left + (right-left)/2;
            st = position[0];
            // cout << "mid = " << mid << endl;
            bool flag = false;
            for(int i = 1; i < sz; i++) {
                int distance = abs(position[i] - st);
                // cout << "curr distance = " << distance << endl;
                if (distance >= mid) {
                    st = position[i];
                    times++;
                }
                // cout << "times = " << times << endl;
                
                if (times >= m) {
                    flag = true;
                    break;
                }
            }
                // cout << "flag = " << flag << endl;

            if (flag == true) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left >= 1 ? left - 1: -1;
    }
};