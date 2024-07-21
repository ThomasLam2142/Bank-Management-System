#include <stdio.h>
#include <string.h>  // For using strlen function

// Function prototypes
void createAccount();
void accountSummary();
void depositFunc(); 
void withdrawFunc();

// Define the Account structure
typedef struct {
    int accountNumber;
    char accountHolderName[100];
    float balance;
} Account;

// Global array to store accounts
#define MAX_ACCOUNTS 100
Account accounts[MAX_ACCOUNTS];
int totalAccountNumber = 0;
int nextAccountIndex = 0;




int main() {
    int state = 0;

    printf("Welcome to the Bank Management System\n");

    while (state != 10) {
        printf("Select from the list:\n");
        printf("1. Create Account\n");
        printf("2. Account Summary\n");
        printf("3. Deposit\n");
        printf("3. Withdraw\n");
        printf("10. Exit\n");

        scanf("%d", &state);  // Read an integer from the user
        
        // Clear the input buffer
        while (getchar() != '\n');

        if (state == 1) {
            createAccount();
        } else if (state == 2) {
            accountSummary();
        }
        else if (state == 3) {
            depositFunc();
        }
        else if (state == 4) {
            withdrawFunc();
        }

        
    }

    // Wait for the user to press Enter
    printf("Press Enter to exit...\n");
    getchar();  // Waits for the user to press Enter

    return 0;
}

// Define the createAccount function
void createAccount() {
    if (nextAccountIndex >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }

    printf("Create Account Function\n\n");
    totalAccountNumber++;

    Account newAccount;

    newAccount.accountNumber = totalAccountNumber;

    printf("Enter your name: \n");
    fgets(newAccount.accountHolderName, sizeof(newAccount.accountHolderName), stdin);
    // Remove trailing newline character if present
    size_t len = strlen(newAccount.accountHolderName);
    if (len > 0 && newAccount.accountHolderName[len - 1] == '\n') {
        newAccount.accountHolderName[len - 1] = '\0';
    }

    printf("Enter your initial balance: ");
    // Read a float from the user
    while (scanf("%f", &newAccount.balance) != 1) {
        printf("Invalid input. Please enter a valid number for balance: ");
        // Clear the invalid input
        while (getchar() != '\n');
    }

    // Clear the input buffer after reading balance
    while (getchar() != '\n');

    // Store the account in the global array
    accounts[nextAccountIndex++] = newAccount;

    printf("Account Created Successfully!\n");
    printf("Account Number: %d\n", newAccount.accountNumber);
    printf("Account Holder Name: %s\n", newAccount.accountHolderName);
    printf("Initial Balance: %.2f\n\n", newAccount.balance);
}

int findAccount(int accountNumber) {
    for (int i = 0; i < nextAccountIndex; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;  // Return the index of the found account
        }
    }
    return -1;  // Return -1 if account not found
}

// Define the deposit function
void depositFunc() {
    int accountNumber;
    float depositAmount;

    printf("Deposit Function\n\n");

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    // Clear the input buffer
    while (getchar() != '\n');

    int accountIndex = findAccount(accountNumber);

    if (accountIndex == -1) {
        printf("Account number not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    while (scanf("%f", &depositAmount) != 1) {
        printf("Invalid input. Please enter a valid number for deposit: ");
        while (getchar() != '\n');
    }

    // Clear the input buffer after reading deposit amount
    while (getchar() != '\n');

    accounts[accountIndex].balance += depositAmount;
    printf("Deposit successful!\n");
    printf("New Balance: %.2f\n\n", accounts[accountIndex].balance);
}

void accountSummary(){
    int accountNumber;
    printf("Account Summary function\n");
    printf("Enter your account number: \n");
    scanf("%d", &accountNumber);

    // Clear the input buffer
    while (getchar() != '\n');

    int accountIndex = findAccount(accountNumber);
    printf("Account Number: %d\n", accounts[accountIndex].accountNumber);
    printf("Account Holder Name: %s\n", accounts[accountIndex].accountHolderName);
    printf("Current Balance: %.2f\n\n", accounts[accountIndex].balance);

}

void withdrawFunc(){
    int accountNumber;
    int withdrawValue;
    printf("Account Summary function\n");
    printf("Enter your account number: \n");
    scanf("%d", &accountNumber);

    // Clear the input buffer
    while (getchar() != '\n');

    int accountIndex = findAccount(accountNumber);

    printf("Current Balance: %.2f\n\n", accounts[accountIndex].balance);

    printf("Enter your value to withdraw: \n");
    scanf("%d", &withdrawValue);
    while (getchar() != '\n');

    
    accounts[accountIndex].balance = accounts[accountIndex].balance - withdrawValue;

    printf("New Balance: %.2f\n\n", accounts[accountIndex].balance);

}