import csv
import os

class Account:
    def __init__(self, account_number: int, name: str, balance: float):
        self.account_number = account_number
        self.name = name
        self.balance = balance

    @classmethod
    def create_account(cls):
        print("\n--- Create New Account ---")
        try:
            acc_num = int(input("Enter Account Number: "))
            name = input("Enter Account Holder Name (e.g. Shahriar): ").strip()
            balance = float(input("Enter Initial Balance: "))
            return cls(acc_num, name, balance)
        except ValueError:
            print("[!] Invalid input. Account creation cancelled.")
            return None

    def show_account(self):
        print(f"Acc No: {self.account_number} | Name: {self.name} | Balance: ৳{self.balance:.2f}")


def load_from_file(filepath: str = "accounts.txt") -> list[Account]:
    accounts = []
    if not os.path.exists(filepath):
        return accounts

    with open(filepath, mode="r", newline="", encoding="utf-8") as file:
        reader = csv.reader(file)
        for row in reader:
            if len(row) == 3:
                try:
                    acc_num = int(row[0])
                    name = row[1]
                    balance = float(row[2])
                    accounts.append(Account(acc_num, name, balance))
                except ValueError:
                    continue
    return accounts


def save_to_file(accounts: list[Account], filepath: str = "accounts.txt"):
    with open(filepath, mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        for acc in accounts:
            writer.writerow([acc.account_number, acc.name, acc.balance])


def main():
    while True:
        print("\n===============================")
        print("    BANK MANAGEMENT SYSTEM     ")
        print("===============================")
        print("1. Create New Account")
        print("2. Display Account Details")
        print("3. Deposit Money")
        print("4. Withdraw Money")
        print("5. Display All Accounts")
        print("6. Exit")
        
        choice = input("Enter your choice (1-6): ").strip()
        accounts = load_from_file()

        if choice == "1":
            new_acc = Account.create_account()
            if new_acc:
                # Check for duplicate account number
                if any(acc.account_number == new_acc.account_number for acc in accounts):
                    print(f"\n[!] Account number {new_acc.account_number} already exists!")
                else:
                    accounts.append(new_acc)
                    save_to_file(accounts)
                    print("\n[✓] Account created successfully and saved to file!")

        elif choice == "2":
            try:
                acc_num = int(input("\nEnter Account Number: "))
                found_acc = next((acc for acc in accounts if acc.account_number == acc_num), None)
                if found_acc:
                    print("\n--- Account Details ---")
                    found_acc.show_account()
                else:
                    print("\n[!] Account not found!")
            except ValueError:
                print("\n[!] Invalid account number!")

        elif choice == "3":
            try:
                acc_num = int(input("\nEnter Account Number: "))
                found_acc = next((acc for acc in accounts if acc.account_number == acc_num), None)
                if found_acc:
                    amount = float(input("Enter Amount to Deposit: "))
                    if amount > 0:
                        found_acc.balance += amount
                        save_to_file(accounts)
                        print(f"\n[✓] Amount deposited. New Balance: ৳{found_acc.balance:.2f}")
                    else:
                        print("\n[!] Deposit amount must be positive!")
                else:
                    print("\n[!] Account not found!")
            except ValueError:
                print("\n[!] Invalid input!")

        elif choice == "4":
            try:
                acc_num = int(input("\nEnter Account Number: "))
                found_acc = next((acc for acc in accounts if acc.account_number == acc_num), None)
                if found_acc:
                    amount = float(input("Enter Amount to Withdraw: "))
                    if amount <= 0:
                        print("\n[!] Withdrawal amount must be positive!")
                    elif amount <= found_acc.balance:
                        found_acc.balance -= amount
                        save_to_file(accounts)
                        print(f"\n[✓] Amount withdrawn. Remaining Balance: ৳{found_acc.balance:.2f}")
                    else:
                        print("\n[!] Insufficient balance!")
                else:
                    print("\n[!] Account not found!")
            except ValueError:
                print("\n[!] Invalid input!")

        elif choice == "5":
            if not accounts:
                print("\n[!] No accounts found in record.")
            else:
                print("\n--- All Accounts List ---")
                for acc in accounts:
                    acc.show_account()

        elif choice == "6":
            print("\nExiting Program... Thank You!")
            break
        else:
            print("\n[!] Invalid choice! Please try again.")

if __name__ == "__main__":
    main()
