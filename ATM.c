#include <stdio.h>

void Menu(void);
void CheckBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
int changepin(int pin);

int main(void)
{
    int pin = 1234;
    int enteredpin;
    int choice;
    int attempts = 0;
    float balance = 10000.0f;

    printf("===== ATM Machine =====\n");

    while (attempts < 3)
    {
        printf("Enter your PIN: ");

        if (scanf("%d", &enteredpin) != 1)
        {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        if (enteredpin == pin)
        {
            printf("Login successful.\n");
            break;
        }

        attempts++;
        printf("Incorrect PIN.\n");
        printf("Attempts remaining: %d\n", 3 - attempts);
    }

    if (attempts == 3)
    {
        printf("Too many incorrect attempts.\n");
        printf("Account temporarily blocked.\n");
        return 0;
    }

    do
    {
        Menu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                CheckBalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdraw(balance);
                break;

            case 4:
                pin = changepin(pin);
                break;

            case 5:
                printf("Thank you for using the ATM.\n");
                printf("Have a nice day.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void Menu(void)
{
    printf("\n---- Menu ----\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
}

void CheckBalance(float balance)
{
    printf("Current balance: %.2f\n", balance);
}

float deposit(float balance)
{
    float amount;

    printf("Enter amount to deposit: ");

    if (scanf("%f", &amount) != 1)
    {
        printf("Invalid input.\n");
        return balance;
    }

    if (amount <= 0)
    {
        printf("Invalid amount.\n");
    }
    else
    {
        balance += amount;
        printf("%.2f deposited successfully.\n", amount);
        printf("New balance: %.2f\n", balance);
    }

    return balance;
}

float withdraw(float balance)
{
    float amount;

    printf("Enter amount to withdraw: ");

    if (scanf("%f", &amount) != 1)
    {
        printf("Invalid input.\n");
        return balance;
    }

    if (amount <= 0)
    {
        printf("Invalid amount.\n");
    }
    else if (amount > balance)
    {
        printf("Insufficient balance.\n");
    }
    else
    {
        balance -= amount;
        printf("Please collect your cash.\n");
        printf("%.2f withdrawn successfully.\n", amount);
        printf("Remaining balance: %.2f\n", balance);
    }

    return balance;
}

int changepin(int pin)
{
    int currentpin;
    int newpin;

    printf("Enter your current PIN: ");

    if (scanf("%d", &currentpin) != 1)
    {
        printf("Invalid input. PIN was not changed.\n");
        return pin;
    }

    if (currentpin != pin)
    {
        printf("Incorrect PIN.\n");
        return pin;
    }

    printf("Enter your new 4-digit PIN: ");

    if (scanf("%d", &newpin) != 1)
    {
        printf("Invalid input. PIN was not changed.\n");
        return pin;
    }

    if (newpin >= 1000 && newpin <= 9999)
    {
        printf("PIN changed successfully.\n");
        return newpin;
    }

    printf("PIN must contain exactly 4 digits.\n");
    return pin;
}














