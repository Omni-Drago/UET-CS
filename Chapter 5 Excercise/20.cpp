#include <iostream>

using namespace std;

int main() {
    double loanAmount;
    double yearlyRate;
    double monthlyPayment;
    double monthlyRate;
    double firstMonthInterest;
    double currentBalance;
    int months = 0;

    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the interest rate per year (e.g., 7.2): ";
    cin >> yearlyRate;

    cout << "Enter the monthly payment: ";
    cin >> monthlyPayment;

    monthlyRate = yearlyRate / 12.0 / 100.0;
    firstMonthInterest = loanAmount * monthlyRate;

    if (monthlyPayment <= firstMonthInterest) {
        cout << endl;
        cout << "Warning: The monthly payment is too low." << endl;
        cout << "With this payment, the loan amount will increase." << endl;
        cout << "The loan cannot be repaid." << endl;
        return 1;
    }

    currentBalance = loanAmount;

    while (currentBalance > 0) {
        months++;
        double monthlyInterest = currentBalance * monthlyRate;
        double principalPayment = monthlyPayment - monthlyInterest;
        currentBalance = currentBalance - principalPayment;
    }

    cout << endl;
    cout << "It will take " << months << " months to repay the loan." << endl;

    return 0;
}