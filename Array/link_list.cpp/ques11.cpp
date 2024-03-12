#include <iostream>
#include <vector>
using namespace std;
vector<int> bitwiseEquations(vector<int>& a, vector<int>& b) {
    vector<int> result;
    
    for (int i = 0; i < a.size(); i++) {
        bool found_solution = false;
        long x = 0;
        
        while (x <= a[i]) {
            long y = a[i] - x;
            if ((x ^ y) == b[i]) {
                found_solution = true;
                break;
            }
            x++;
        }
        
        if (found_solution) {
            long value = 2 * x + 3 * (a[i] - x);
            result.push_back(value);
        } else {
            result.push_back(0);
        }
    }
    
    return result;
}

int main() {
    vector<int> a = {29, 36, 57};
    vector<int> b = {25, 18, 3};
    
    vector<int> result = bitwiseEquations(a, b);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    

}