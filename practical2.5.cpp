#include <iostream>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string name;
    double amount;
    double annualRate;
    int tenure;

public:

    Loan() {
        loanID = 0;
        name = "None";
        amount = 0;
        annualRate = 0;
        tenure = 0;
    }


    Loan(int id, string n, double amt, double rate, int t) {
        loanID = id;
        name = n;
        amount = amt;
        annualRate = rate;
        tenure = t;
    }


    void input() {
        cout << "Enter Loan ID: ";
        cin >> loanID;
        cout << "Enter Applicant Name: ";
        cin >> name;
        cout << "Enter Loan Amount: ";
        cin >> amount;
        cout << "Enter Annual Interest Rate (%): ";
        cin >> annualRate;
        cout << "Enter Tenure (months): ";
        cin >> tenure;
    }

    double calculateEMI() {
        double R = annualRate / (12 * 100);
        int T = tenure;

        if (R == 0)
            return amount / T;

        double emi = (amount * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
        return emi;
    }

    void display() {
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Applicant Name: " << name << endl;
        cout << "Loan Amount: " << amount << endl;
        cout << "Annual Interest Rate: " << annualRate << "%" << endl;
        cout << "Tenure (months): " << tenure << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of loan accounts: ";
    cin >> n;

    Loan loans[n];


    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Loan " << i + 1 << endl;
        loans[i].input();
    }


    cout << "\n--- Loan Details ---\n";
    for (int i = 0; i < n; i++) {
        loans[i].display();
    }

    return 0;
}
