#include <iostream>
using namespace std;

int main() {
    int redRoses, whiteRoses, tulips;
    double totalPrice, discountPrice;

    const double redPrice = 2.00;
    const double whitePrice = 4.10;
    const double tulipPrice = 2.50;

    cout << "Red Rose: ";
    cin >> redRoses;

    cout << "White Rose: ";
    cin >> whiteRoses;

    cout << "Tulips: ";
    cin >> tulips;

    totalPrice = (redRoses * redPrice) + (whiteRoses * whitePrice) + (tulips * tulipPrice);

    cout << "Original Price: " << totalPrice;

    if (totalPrice > 200) {
        discountPrice = totalPrice - (totalPrice * 0.20);
        cout << "Price after Discount: " << discountPrice;
    }

    return 0;
}
