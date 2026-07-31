# 🏦 Bank Management System

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Python](https://img.shields.io/badge/Python-3.12-green.svg)
![OOP](https://img.shields.io/badge/Paradigm-Object--Oriented-orange.svg)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)

A robust, console-based **Bank Management System** developed in **C++** and **Python**. The system simulates essential banking operations including account creation, balance inquiry, money deposits, withdrawals, and persistent data storage using file I/O operations with the Bangladeshi Taka (৳) currency format.

---

## 📋 Features

- 👤 **Account Creation**: Register new bank accounts with an Account Number, Holder Name, and Initial Balance.
- 🔍 **Account Search**: Search and display details for any existing account by Account Number.
- 💵 **Deposit Funds**: Instantly deposit money into a specific account and update the balance.
- 💸 **Withdraw Funds**: Safely withdraw funds with automatic balance validation to prevent overdrafts.
- 📊 **Display All Accounts**: View a structured list of all registered accounts in the system.
- 💾 **Data Persistence**: Automatically load and save account data to `accounts.txt` in a CSV-formatted database.

---

## 🛠️ Project Structure

```
bank_account_management/
├── main.cpp                # Core C++ implementation
├── bank_account_management.cpp # Alternative C++ source file
├── main.py                 # Fully functional Python implementation
├── accounts.txt            # Persistent CSV data file (auto-generated)
├── .gitignore              # Git ignore rules for build artifacts
└── README.md               # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- **For C++**: A C++ compiler (such as `g++` / MinGW-w64 or Clang).
- **For Python**: Python 3.8 or higher.

---

## ⚙️ How to Run

### 1️⃣ Running the C++ Version

To compile and run the standalone C++ application using `g++`:

```powershell
# Compile the C++ program into a standalone executable
g++ -static main.cpp -o main.exe

# Run the application
.\main.exe
```

### 2️⃣ Running the Python Version

To execute the Python implementation:

```powershell
python main.py
```

---

## 💾 Data Storage Format (`accounts.txt`)

Data is stored line-by-line in comma-separated format:

```csv
1001,Arpita,5000.00
1002,Shahriar,7500.50
```

---

## 📜 Project Details

- **Submitted To**: Dr. Apurba Adhikari
- **Submitted By**: Arpita Rani Das (ID: JSH2411034F)
- **Date**: July 31, 2026

---

## 📝 License

This project is open-source and available under the [MIT License](LICENSE).
