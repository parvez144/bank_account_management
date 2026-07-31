#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Account Class
class Account {
public:
    int accountNumber;
    string name;
    double balance;

    // Function to take input for new account
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cin.ignore(); // Clear input buffer
        cout << "Enter Account Holder Name (e.g. Arpita): ";
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Function to display account details
    void showAccount() const {
        cout << "Acc No: " << accountNumber 
             << " | Name: " << name 
             << " | Balance: ৳" << balance << endl;
    }
};

// Function to load all records from file into memory
vector<Account> loadFromFile() {
    vector<Account> accounts;
    ifstream inFile("accounts.txt");
    
    if (!inFile) {
        return accounts; // Return empty vector if file does not exist
    }

    string line;
    // Reading file line by line
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string accNumStr, nameStr, balStr;

        // Extracting data separated by comma (,)
        getline(ss, accNumStr, ',');
        getline(ss, nameStr, ',');
        getline(ss, balStr, ',');

        Account acc;
        acc.accountNumber = stoi(accNumStr);
        acc.name = nameStr;
        acc.balance = stod(balStr);

        accounts.push_back(acc);
    }

    inFile.close();
    return accounts;
}

// Function to save all records from memory to file
void saveToFile(const vector<Account>& accounts) {
    ofstream outFile("accounts.txt"); // Overwrites the file with updated data

    for (const auto& acc : accounts) {
        // Saving data separated by comma: AccNo,Name,Balance
        outFile << acc.accountNumber << "," << acc.name << "," << acc.balance << "\n";
    }

    outFile.close();
}

int main() {
    int choice;

    while (true) {
        cout << "\n===============================\n";
        cout << "    BANK MANAGEMENT SYSTEM     \n";
        cout << "===============================\n";
        cout << "1. Create New Account\n";
        cout << "2. Display Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Load existing records from file at the start of every operation
        vector<Account> accounts = loadFromFile();

        switch (choice) {
            case 1: { // Create Account
                Account newAcc;
                newAcc.createAccount();
                accounts.push_back(newAcc);
                saveToFile(accounts);
                cout << "\n[✓] Account created successfully and saved to file!\n";
                break;
            }
            case 2: { // Search & Display Account
                int accNum;
                bool found = false;
                cout << "\nEnter Account Number: ";
                cin >> accNum;

                for (const auto& acc : accounts) {
                    if (acc.accountNumber == accNum) {
                        cout << "\n--- Account Details ---\n";
                        acc.showAccount();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n[!] Account not found!\n";
                break;
            }
            case 3: { // Deposit Money
                int accNum;
                double amount;
                bool found = false;
                cout << "\nEnter Account Number: ";
                cin >> accNum;

                for (auto& acc : accounts) {
                    if (acc.accountNumber == accNum) {
                        cout << "Enter Amount to Deposit: ";
                        cin >> amount;
                        acc.balance += amount;
                        saveToFile(accounts); // Save updated balance
                        cout << "\n[✓] Amount deposited. New Balance: ৳" << acc.balance << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n[!] Account not found!\n";
                break;
            }
            case 4: { // Withdraw Money
                int accNum;
                double amount;
                bool found = false;
                cout << "\nEnter Account Number: ";
                cin >> accNum;

                for (auto& acc : accounts) {
                    if (acc.accountNumber == accNum) {
                        cout << "Enter Amount to Withdraw: ";
                        cin >> amount;
                        if (amount <= acc.balance) {
                            acc.balance -= amount;
                            saveToFile(accounts); // Save updated balance
                            cout << "\n[✓] Amount withdrawn. Remaining Balance: ৳" << acc.balance << endl;
                        } else {
                            cout << "\n[!] Insufficient balance!\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n[!] Account not found!\n";
                break;
            }
            case 5: { // Display All Accounts
                if (accounts.empty()) {
                    cout << "\n[!] No accounts found in record.\n";
                } else {
                    cout << "\n--- All Accounts List ---\n";
                    for (const auto& acc : accounts) {
                        acc.showAccount();
                    }
                }
                break;
            }
            case 6: // Exit
                cout << "\nExiting Program... Thank You!\n";
                return 0;

            default:
                cout << "\n[!] Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
