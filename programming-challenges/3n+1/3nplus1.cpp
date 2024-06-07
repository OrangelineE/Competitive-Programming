/*
ID: OrangeLINE
TASK: 3n+1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int get_maxcycle(int i, int j)
{
    int max_cycle = 1;
    
    for(int m = i; m <= j; m++) {
        int cycle = 1;
        int n = m;
        while (n != 1) {
            // cout << "n = " << n << endl;
            if (n % 2 == 0) {
                n = n/2; 
            } else {
                n = 3*n + 1;
            }
            cycle++;
        }

        max_cycle = max(max_cycle, cycle);
    }
    
    return max_cycle;

}

int main() {
    int i;
    int j;
    while (cin >> i >> j) {
        cout << i << " " << j << " " << get_maxcycle(i, j) << endl;
    }
    return 0;
}
