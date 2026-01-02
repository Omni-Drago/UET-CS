#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double loanAmount;
    double yearlyRate;
    double monthlyPayment;
    double monthlyRate;
    double firstMonthInterest;
    double currentBalance;
    double totalInterestPaid = 0.0;
    double loanAmountBeforeLast = 0.0;
    double lastPayment = 0.0;
    int months = 0;

    cout << fixed << setprecision(2);

    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the interest rate per year (e.g., 7.2): ";
    cin >> yearlyRate;

    monthlyRate = yearlyRate / 12.0 / 100.0;
    firstMonthInterest = loanAmount * monthlyRate;

    cout << "The minimum payment must be more than $" << firstMonthInterest << endl;

    do {
        cout << "Enter the monthly payment: ";
        cin >> monthlyPayment;

        if (monthlyPayment <= firstMonthInterest) {
            cout << "Payment is too low. Please enter a valid payment." << endl;
        }
    } while (monthlyPayment <= firstMonthInterest);

    currentBalance = loanAmount;

    while (currentBalance > 0) {
        months++;
        double monthlyInterest = currentBalance * monthlyRate;

        if (currentBalance + monthlyInterest <= monthlyPayment) {
            loanAmountBeforeLast = currentBalance;
            lastPayment = currentBalance + monthlyInterest;
            totalInterestPaid = totalInterestPaid + monthlyInterest;
            currentBalance = 0.0;
        } else {
            double principalPayment = monthlyPayment - monthlyInterest;
            currentBalance = currentBalance - principalPayment;
            totalInterestPaid = totalInterestPaid + monthlyInterest;
        }
    }

    cout << endl;
    cout << "It will take " << months << " months to repay the loan." << endl;
    cout << "Loan amount before last payment: $" << loanAmountBeforeLast << endl;
    cout << "Actual last payment: $" << lastPayment << endl;
    cout << "Total interest paid: $" << totalInterestPaid << endl;

    return 0;
}

