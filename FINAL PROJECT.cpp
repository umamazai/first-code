#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string name, business, NTN;
    double income, tax = 0;

    
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter business name: ";
    getline(cin, business);

    cout << "Enter NTN: ";
    getline(cin, NTN);

    cout << "Enter annual income: ";
    cin >> income;

    if (income > 600000) {
        if (income <= 1200000) 
            tax = (income - 600000) * 0.15;
        else if (income <= 1600000) 
            tax = 90000 + (income - 1200000) * 0.20;
        else if (income <= 3200000) 
            tax = 170000 + (income - 1600000) * 0.30;
        else if (income <= 5600000) 
            tax = 650000 + (income - 3200000) * 0.40;
        else 
            tax = 1610000 + (income - 5600000) * 0.45;
    }

    cout << "\n--- Tax Summary ---\n";
    cout << "Name: " << name << endl;
    cout << "Business: " << business << endl;
    cout << "NTN: " << NTN << endl;
    cout << "Annual Income: " << income << endl;
    cout << "Total Tax: " << tax << endl;

    ofstream file("yourTax.txt");
    file << "Name: " << name << "\nBusiness: " << business << "\nNTN: " << NTN 
         << "\nAnnual Income: " << income << "\nTotal Tax: " << tax;
    file.close();

    cout << "\nTax details saved to 'yourTax.txt'\n";
    return 0;
}