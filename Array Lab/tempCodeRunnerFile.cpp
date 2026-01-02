#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter characters (abcd): ";
    cin.get(ch);   // takes 'a'
    cout << ch << endl;

    cin.get(ch);   // takes 'b'
    cout << ch << endl;

    cin.putback(ch);   // puts 'b' back into stream
    cin.get(ch);       // takes 'b' again
    cout << ch << endl;

    cin.get(ch);   // takes 'c'
    cout << ch << endl;

    cin.peek();    // shows next char but does not remove it
    cout << "Next char will be: " << (char)cin.peek() << endl;

    cin.clear();   // clears error/garbage input states

    return 0;
}
