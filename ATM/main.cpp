#include <iostream>

#include <conio.h>

#include <string>


// getch => used to hold the screen until the user presses any key
/*
1.CHECK BALANCE
2. WITHDRAW CASH
3. USER DETAILS
4. UPDATE MOBILE NUMBER
*/

class atm {
private :
    long int account_no;
    std :: string name;
    int PIN;
    int Balance;
    std :: string mobile_no;

public :
    void setData(long int account_no,std :: string name , int pin , int balance , std ::  string mobile_no) {
    this->account_no = account_no;
    this->name = name;
    this->PIN = pin;
    this->Balance = balance;
    this->mobile_no = mobile_no;
}

    long int getAccountno() {
    return account_no;
}
    std :: string getName() {
    return name;
}
    int getPIN() {
    return PIN;

}
    int getBalance() {
    return Balance;
}
    std :: string getMobileNo() {
    return mobile_no;
}


    void cash_Withdraw(int amount) {
    if (amount > 0 && amount < Balance) {
        Balance = Balance - amount ;
        std :: cout << "Please Collect Your Cash" << std :: endl;
        std :: cout << "Available Balance : " << Balance << std :: endl;
        _getch();
    }

    else {
        std :: cout << "Invalid Input or Insufficient Balance" << std :: endl;
        _getch();   // uses to hold the scrren util user presses any button
    }
}

    void SetMobileNo(std :: string old_mobno , std :: string new_mobno) {

    if (old_mobno == mobile_no) {
        mobile_no = new_mobno;
        std :: cout << "Your Mobile Number is Updated successfully" << std :: endl;
        _getch();
    }
    else {
        std:: cout << "Invalid Mobile Number , Try Again" << std :: endl;
        _getch();
    }
}


};



using namespace std;
int main() {
    int choice = 0;
    int enterPin;
    long int enterAccount_no;

    system("cls"); // to clear the screen

    atm user1;
    user1.setData(1234567,"Avinash",1234,45000,"9994330518");

    do {
        system("cls");

        std :: cout << "WELCOME TO THE ATM " << std :: endl;
        std :: cout << "Enter Your Account Number : " << std :: endl;
        cin >> enterAccount_no;
        std :: cout << "Enter Your PIN : " << std :: endl;
        cin >> enterPin;

        if ((enterAccount_no == user1.getAccountno()) && (enterPin == user1.getPIN())) {
            do {
                int amount = 0 ;
                string old_mobile_no;
                string new_mobile_no;

                system("cls");


                std :: cout << "WELCOME TO ATM" << std :: endl;
                std :: cout << "Select Options : " << std :: endl;
                std :: cout << "1. Check Balance" << std :: endl;
                std :: cout << "2. CASH WITHDRAWAL" << std :: endl;
                std :: cout << "3. USER DETAILS" << std :: endl;
                std :: cout << "4. UPDATE MOBILE NUMBER" << std :: endl;
                std :: cout << "5. EXIT" << std :: endl;

                cin >> choice ;

                 switch(choice) {
                     case 1 :
                            std :: cout << "Your Balance is : " << user1.getBalance() << std :: endl;
                            _getch();
                            break;
                     case 2 :
                            std :: cout << "Enter the amount you wanted to withdraw : " << std :: endl;
                            cin >> amount;
                            user1.cash_Withdraw(amount);
                            break;
                     case 3 :
                            std :: cout << "Name :" << user1.getName()<< std :: endl;
                            std :: cout << "Mobile Number : " << user1.getMobileNo()<< std :: endl;
                            std :: cout << "Available Balance: " << user1.getBalance()<< std :: endl;
                            _getch();
                            break;
                     case 4 :
                            std :: cout << "Enter Your Old Mobile Number : " << std :: endl;
                            cin >> old_mobile_no;
                            std :: cout << "Enter Your New Mobile Number : " << std :: endl;
                            cin >> new_mobile_no;
                            user1.SetMobileNo(old_mobile_no,new_mobile_no);
                            break;
                     case 5 :
                            exit(0);
                            //_getch();
                     default :
                            std :: cout << "Invalid Input" << std :: endl;
                 }
            }while (1);
        }else {
            std :: cout << "Invalid Account Number and Pin" << std :: endl;
            _getch();
        }
    }while (1);



    return 0;
}
