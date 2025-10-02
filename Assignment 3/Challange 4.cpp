#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a single character: ";
    cin >> ch;

    
    if (ch >= '0')
    {
        if (ch <= '9')
        {
            cout << "It is a number." << endl;
        }
        else
        {
            
            if (ch >= 'A')
            {
                if (ch <= 'Z')
                {
                    
                    if (ch == 'A')
                        cout << "It is a vowel." << endl;
                    else if (ch == 'E')
                        cout << "It is a vowel." << endl;
                    else if (ch == 'I')
                        cout << "It is a vowel." << endl;
                    else if (ch == 'O')
                        cout << "It is a vowel." << endl;
                    else if (ch == 'U')
                        cout << "It is a vowel." << endl;
                    else
                        cout << "It is a consonant." << endl;
                }
                else if (ch >= 'a')
                {
                    if (ch <= 'z')
                    {
                       
                        if (ch == 'a')
                            cout << "It is a vowel." << endl;
                        else if (ch == 'e')
                            cout << "It is a vowel." << endl;
                        else if (ch == 'i')
                            cout << "It is a vowel." << endl;
                        else if (ch == 'o')
                            cout << "It is a vowel." << endl;
                        else if (ch == 'u')
                            cout << "It is a vowel." << endl;
                        else
                            cout << "It is a consonant." << endl;
                    }
                    else
                    {
                        cout << "It is neither a vowel, consonant, nor a number." << endl;
                    }
                }
                else
                {
                    cout << "It is neither a vowel, consonant, nor a number." << endl;
                }
            }
            else
            {
                cout << "It is neither a vowel, consonant, nor a number." << endl;
            }
        }
    }
    else
    {
        cout << "It is neither a vowel, consonant, nor a number." << endl;
    }

    return 0;
}
