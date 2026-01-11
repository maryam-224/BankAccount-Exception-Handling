#include <iostream>
#include <string>
using namespace std;

class BankAccount 
{
private:
    string name;
    double balance;

public:
    // Constructor with validation
    BankAccount(string n, double b) 
    {
        name = n;
        balance = b;

        if (b < 0) 
        {
            throw "Error: Initial balance cannot be negative";
            cout << endl;
        }
       
        cout << "Constructor called for : " << name << endl;
    }

    // Destructor
    ~BankAccount() 
    {
        cout << "Destructor called for : " << name << endl;
    }

    // Withdraw function
    void withdraw(double amount) 
    {
        if (amount > balance) 
        {
            throw "Error: Withdrawal amount exceeds balance";
        }

        balance -= amount;
        cout << "Withdrawal successful" << endl;
        cout << endl;
        cout<<"New balance is : " << balance << endl;
    }

    //For displaying account info
    void display() 
    {
        cout << "Account Holder : " << name << endl;
        cout<< "Balance in account is : " << balance << endl;
       
    }
};

int main() 
{
    // Testing constructor exception
    cout << "Test 1: Constructor Exception" << endl;
   
    try 
    {
        BankAccount* ac1 = new BankAccount("Maryam", 8000);
        ac1->display();

        // This will throw exception during construction
        BankAccount* ac2 = new BankAccount("Fajar", -100);
        ac2->display();  // Never reached

        delete ac1;
        delete ac2;  // Never reached
    }

    catch (const char* error_msg) 
    {
        cout << error_msg << endl;
        // ac1 destructor will be called 
    }

    cout << endl;
    cout << "Test 2: Withdraw Exception" << endl;

    try 
    {
        BankAccount* ac3 = new BankAccount("Urooj", 7800);
        ac3->display();

        // This will throw exception
        ac3->withdraw(8000);

        delete ac3;
    }

    catch (const char* error_msg) 
    {
        cout << error_msg << endl;
        // Destructor for ac3 will be called
    }

    cout << endl;
    cout << "Test 3: Normal Operation" << endl;

    try
    {
        BankAccount* ac4 = new BankAccount("Isma", 2000);
        ac4->display();
        ac4->withdraw(1000);  // Successful withdrawal
        ac4->display();

        delete ac4;
    }

    catch (const char* error_msg) 
    {
        cout << error_msg << endl;
    }

    return 0;
}
