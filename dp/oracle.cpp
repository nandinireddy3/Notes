#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

pair<int, int> find_max_gcd_subarray(vector<int> &arr) {
    int n = arr.size();
    int max_gcd = -1;
    vector<int> max_subarray;

    for (int i = 0; i < n; i++) {
        int current_gcd = arr[i];
        vector<int> current_subarray;
        current_subarray.push_back(arr[i]);

        for (int j = i + 1; j < n; j++) {
            current_gcd = gcd(current_gcd, arr[j]);
            current_subarray.push_back(arr[j]);

            if (current_gcd > max_gcd) {
                max_gcd = current_gcd;
                max_subarray = current_subarray;
            } else if (current_gcd == max_gcd && current_subarray.size() > max_subarray.size()) {
                max_subarray = current_subarray;
            }
        }
    }

    return make_pair(max_gcd, max_subarray.size());
}

int main() {
    vector<int> arr = {10, 15, 7, 30, 45};
    pair<int, int> result = find_max_gcd_subarray(arr);
    int max_gcd = result.first;
    int max_subarray = result.second;

    cout << "Max GCD: " << max_gcd << endl;
    cout << "Max GCD Subarray: " << max_subarray << endl;

    return 0;
}
