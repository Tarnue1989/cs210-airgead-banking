// ==========================================================
// Name: Kollie Tarnue
// Course: CS 210
// Project: Airgead Banking Investment Calculator
//
// AI Usage Acknowledgment:
// This assignment was developed with assistance from an AI
// tool (ChatGPT) to help organize my ideas and structure
// explanations. All content was reviewed, edited, and
// verified by me before submission.
// ==========================================================

#include <iostream>
#include <iomanip>
using namespace std;

// ==============================
// CLASS DEFINITION
// ==============================
class InvestmentCalculator {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int years;

public:
    InvestmentCalculator(double inv, double dep, double rate, int yrs) {
        initialInvestment = inv;
        monthlyDeposit = dep;
        annualInterest = rate;
        years = yrs;
    }

    void displayInput() {
        cout << "\n==============================" << endl;
        cout << "       USER INPUT DATA        " << endl;
        cout << "==============================" << endl;
        cout << "Initial Investment Amount: $" << fixed << setprecision(2) << initialInvestment << endl;
        cout << "Monthly Deposit: $" << monthlyDeposit << endl;
        cout << "Annual Interest: " << annualInterest << "%" << endl;
        cout << "Number of Years: " << years << endl;
        cout << "==============================\n" << endl;
    }

    void calculateWithoutMonthlyDeposit() {
        double balance = initialInvestment;
        double monthlyInterest;
        double yearlyInterest;

        cout << "========================================" << endl;
        cout << "   Balance and Interest Without Deposits" << endl;
        cout << "========================================" << endl;

        cout << setw(5) << "Year"
            << setw(20) << "Year End Balance"
            << setw(20) << "Interest Earned" << endl;

        for (int i = 1; i <= years; i++) {
            yearlyInterest = 0;

            for (int j = 0; j < 12; j++) {
                monthlyInterest = balance * (annualInterest / 100) / 12;
                balance += monthlyInterest;
                yearlyInterest += monthlyInterest;
            }

            cout << setw(5) << i
                << setw(20) << fixed << setprecision(2) << balance
                << setw(20) << yearlyInterest << endl;
        }

        cout << endl;
    }

    void calculateWithMonthlyDeposit() {
        double balance = initialInvestment;
        double monthlyInterest;
        double yearlyInterest;

        cout << "========================================" << endl;
        cout << "   Balance and Interest With Deposits" << endl;
        cout << "========================================" << endl;

        cout << setw(5) << "Year"
            << setw(20) << "Year End Balance"
            << setw(20) << "Interest Earned" << endl;

        for (int i = 1; i <= years; i++) {
            yearlyInterest = 0;

            for (int j = 0; j < 12; j++) {
                balance += monthlyDeposit;
                monthlyInterest = balance * (annualInterest / 100) / 12;
                balance += monthlyInterest;
                yearlyInterest += monthlyInterest;
            }

            cout << setw(5) << i
                << setw(20) << fixed << setprecision(2) << balance
                << setw(20) << yearlyInterest << endl;
        }

        cout << endl;
    }
};

int main() {
    double investment;
    double monthly;
    double interest;
    int years;

    cout << "**************************************" << endl;
    cout << "******** Airgead Banking App *********" << endl;
    cout << "**************************************" << endl;

    // Input validation (strong version)
    cout << "Initial Investment Amount: ";
    while (!(cin >> investment) || investment < 0) {
        cout << "Invalid input. Enter a positive number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Monthly Deposit: ";
    while (!(cin >> monthly) || monthly < 0) {
        cout << "Invalid input. Enter a positive number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Annual Interest (%): ";
    while (!(cin >> interest) || interest < 0) {
        cout << "Invalid input. Enter a positive number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Number of Years: ";
    while (!(cin >> years) || years <= 0) {
        cout << "Invalid input. Enter a value greater than 0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    InvestmentCalculator calculator(investment, monthly, interest, years);

    calculator.displayInput();
    calculator.calculateWithoutMonthlyDeposit();
    calculator.calculateWithMonthlyDeposit();

    return 0;
}