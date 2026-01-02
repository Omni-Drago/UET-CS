#include <iostream>
#include <string>
using namespace std;

int main() {
    string fruits[4] = {"peach", "apple", "guava", "watermelon"};
    int prices[4] = {60, 70, 40, 30};

    string targetFruit;
    double quantity;
    bool isFound = false;

    cout << "Available fruits: peach, apple, guava, watermelon" << endl;
    cout << "Enter the name of the fruit you want: ";
    cin >> targetFruit;

    cout << "Enter quantity in kgs: ";
    cin >> quantity;

    for (int i = 0; i < 4; i++) {
        if (fruits[i] == targetFruit) {
            double totalBill = prices[i] * quantity;

            cout << "Fruit Found: " << fruits[i] << endl;
            cout << "Price per kg: " << prices[i] << endl;
            cout << "Total Bill: " << totalBill << endl;

            isFound = true;
            break;
        }
    }

    if (!isFound) {
        cout << "Sorry, " << targetFruit << " is not available in our list." << endl;
    }

    return 0;
}