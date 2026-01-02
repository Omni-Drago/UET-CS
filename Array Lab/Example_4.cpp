#include <iostream>
using namespace std;

int main() {
    int arr[8] = {2, 3, 2, 5, 3, 3, 4, 2};
    int n = 8;
    int counted[8] = {0};

    for (int i = 0; i < n; i++) {
        if (counted[i]) continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
        }
        cout << arr[i] << " occurs " << count << " times." << endl;
    }

    return 0;
}
