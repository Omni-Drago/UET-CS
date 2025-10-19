#include <iostream>
#include <string>
using namespace std;

int main()
{
    int date;
    string month;

    cout << "Input Date: ";
    cin >> date;

    cout << "Input Month: ";
    cin >> month;

    if (month == "March" && date >= 21 && date <= 31)
        cout << "Zodiac Sign: Aries and Symbol: The Ram";
    else if (month == "April" && date >= 1 && date <= 19)
        cout << "Zodiac Sign: Aries and Symbol: The Ram";
    else if (month == "April" && date >= 20 && date <= 30)
        cout << "Zodiac Sign: Taurus and Symbol: The Bull";
    else if (month == "May" && date >= 1 && date <= 20)
        cout << "Zodiac Sign: Taurus and Symbol: The Bull";
    else if (month == "May" && date >= 21 && date <= 31)
        cout << "Zodiac Sign: Gemini and Symbol: The Twins";
    else if (month == "June" && date >= 1 && date <= 20)
        cout << "Zodiac Sign: Gemini and Symbol: The Twins";
    else if (month == "June" && date >= 21 && date <= 30)
        cout << "Zodiac Sign: Cancer and Symbol: The Crab";
    else if (month == "July" && date >= 1 && date <= 22)
        cout << "Zodiac Sign: Cancer and Symbol: The Crab";
    else if (month == "July" && date >= 23 && date <= 31)
        cout << "Zodiac Sign: Leo and Symbol: The Lion";
    else if (month == "August" && date >= 1 && date <= 22)
        cout << "Zodiac Sign: Leo and Symbol: The Lion";
    else if (month == "August" && date >= 23 && date <= 31)
        cout << "Zodiac Sign: Virgo and Symbol: The Virgin";
    else if (month == "September" && date >= 1 && date <= 22)
        cout << "Zodiac Sign: Virgo and Symbol: The Virgin";
    else if (month == "September" && date >= 23 && date <= 30)
        cout << "Zodiac Sign: Libra and Symbol: The Scales";
    else if (month == "October" && date >= 1 && date <= 22)
        cout << "Zodiac Sign: Libra and Symbol: The Scales";
    else if (month == "October" && date >= 23 && date <= 31)
        cout << "Zodiac Sign: Scorpio and Symbol: The Scorpion";
    else if (month == "November" && date >= 1 && date <= 21)
        cout << "Zodiac Sign: Scorpio and Symbol: The Scorpion";
    else if (month == "November" && date >= 22 && date <= 30)
        cout << "Zodiac Sign: Sagittarius and Symbol: The Archer";
    else if (month == "December" && date >= 1 && date <= 21)
        cout << "Zodiac Sign: Sagittarius and Symbol: The Archer";
    else if (month == "December" && date >= 22 && date <= 31)
        cout << "Zodiac Sign: Capricorn and Symbol: The Goat";
    else if (month == "January" && date >= 1 && date <= 19)
        cout << "Zodiac Sign: Capricorn and Symbol: The Goat";
    else if (month == "January" && date >= 20 && date <= 31)
        cout << "Zodiac Sign: Aquarius and Symbol: The Water Bearer";
    else if (month == "February" && date >= 1 && date <= 18)
        cout << "Zodiac Sign: Aquarius and Symbol: The Water Bearer";
    else if (month == "February" && date >= 19 && date <= 29)
        cout << "Zodiac Sign: Pisces and Symbol: The Fishes";
    else if (month == "March" && date >= 1 && date <= 20)
        cout << "Zodiac Sign: Pisces and Symbol: The Fishes";
    else
        cout << "Invalid date or month entered!";

    return 0;
}
