#include<iostream>
#include<string>
#include<vector>
#include"../account/account.h"
#include"../user/user.h"
#include"../utilities/utilities.h"

using namespace std;

User::User() {}
User::User(string fullName, string citizenID, string phoneNumber, __int64 balance) {
    this->fullName = fullName;
    this->citizenID = citizenID;
    this->phoneNumber = phoneNumber;
    this->balance = balance;
}
User::~User() {}
//Getter, Setter
//Fullname
string User::getFullName() {
    return this->fullName;
}
void User::setFullName(string fullName) {
    this->fullName = fullName;
}
//citizenID
string User::getCitizenID() {
    return this->citizenID;
}
void User::setCitizenID(string citizenID) {
    this->citizenID = citizenID;
}
//ID
string User::getPhoneNumber() {
    return this->phoneNumber;
}
void User::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
//balance
__int64 User::getBalance() {
    return this->balance;
}
void User::setBalance(__int64 balance) {
    this->balance = balance;
}

//enter data
void User::inData(string phoneNumber) {
    this->phoneNumber = phoneNumber;
    cout << "Enter full name of User: ";
    getline(cin, this->fullName);
    for (__int16 i = 0; i < this->fullName.length(); i++) {
        this->fullName[i] = toupper(this->fullName[i]);     // tự động viết hoa tên
    }
    cout << "Enter citizen ID: ";
    getline(cin, citizenID);
    cout << "Enter first balance: ";
    cin >> this->balance;

}

//display infor
void User::displayData() {
    cout << "FullName of Customer: " << this->fullName << endl;
    cout << "Accout ID of Customer: " << this->phoneNumber << endl;
    cout << "Citizen ID of Customer: " << this->citizenID << endl;
    cout << "Balace of Customer :" << this->balance << endl;
}

//Out Data format
void User::outData() {
    // theo định dạng khi in ra cho đẹp
    //c_str() convert string c++ sang kiểu chuỗi trong c
    printf("%-20s%-30s%-20s%-20d$\n", this->phoneNumber.c_str(), this->fullName.c_str(), this->citizenID.c_str(), this->balance);
}

//read data from string
void User::readData(string s) {
    for (__int16 i = 0; i < 20; i++) {
        // nếu như gặp 2 kí tự khoảng cách liền nhau, thì sẽ gán phoneNumber hàm subtr()
        if (s[i] == ' ' && s[i + 1] == ' ') {
            //VD : hàm subtr(0, 3) : lấy kí tự trong chuỗi là stt 0,1,2
            this->phoneNumber = s.substr(0, i - 0);
            break;
        }
    }
    for (__int16 i = 20; i < 50; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            this->fullName = s.substr(20, i - 20);
            break;
        }
    }
    for (__int16 i = 50; i < 70; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            this->citizenID = s.substr(50, i - 50);
            break;
        }
    }
    for (__int16 i = 70; i < 90; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            //hàm stoi() chuyển chuỗi kí tự thành chuỗi số
            this->balance = stoi(s.substr(70, i - 70));
            break;
        }
    }

}


//write data into file
void User::writeData(FILE* dataFile) {
    fprintf(dataFile, "%-20s%-30s%-20s%-20d$\n", this->phoneNumber.c_str(), this->fullName.c_str(), this->citizenID.c_str(), this->balance);
}

//Updating Account
void User::updatingAccount() {
    __int16 choice = 0;
    string newFullName;
    string newCitizenID;
    do {
        system("cls");
        drawline(84, '=');
        cout << "\n";
        drawline(20, '=');
        cout << " UPDATING INFORMATION OF YOUR ACCOUNT ";
        drawline(25, '=');
        cout << "\n";
        cout << "\t\t" << "1. Modify your full name " << endl;
        cout << "\t\t" << "2. Modify your citizen ID" << endl;
        cout << "\t\t" << "3. Exit" << endl;
        drawline(84, '=');
        cout << "\n" << "Enter Number (1-3) to select mode: ";
        choice = choiceNumber(1, 3, "Please enter valid mode : ");
        switch (choice) {
        case 1:
            system("cls");
            cout << "Enter your full name to modify: ";
            cin.ignore();
            getline(cin, newFullName);
            for (__int16 i = 0; i < newFullName.length(); i++) {
                newFullName[i] = toupper(newFullName[i]);     // tự động viết hoa tên
            }
            this->setFullName(newFullName);
            break;
        case 2:
            system("cls");
            cout << "Enter your citizen ID to modify: ";
            cin.ignore();
            getline(cin, newCitizenID);
            this->setCitizenID(newCitizenID);
            break;
        case 3:
            break;
        default:
            break;
        }


    } while (choice != 3);
}

//change password
void User::changePassword(Account& accounts) {
    system("cls");
    drawline(84, '=');
    cout << "\n";
    drawline(20, '=');
    cout << " CHANGE PASSWORD ";
    drawline(25, '=');
    cout << "\n";

    string oldPass, newPass, cfPass;
    //kiem tra mat khau cu
    do {
        cout << "Enter your Password: ";
        cin >> oldPass;
        if (accounts.getPassWord() != oldPass) {
            cout << "Password invalid ! Enter again!" << endl;
        }
    } while (accounts.getPassWord() != oldPass);
    //nhap mat khau moi
    system("cls");
    cout << "Enter new password: ";
    cin >> newPass;

    // xac nhan mat khau moi
    do {
        cout << "Confirm new password: ";
        cin >> cfPass;
        if (cfPass != newPass) {
            cout << "Confirm password invalid ! Enter again !" << endl;
        }
    } while (cfPass != newPass);
    //gan mat khau moi vao account
    accounts.setPassWord(newPass);
    cout << "Change password succesfully" << endl;
    cout << "Press any key to continue";
}

//transfer money
void User::transferMoney(Account& account, vector<User>& users) {
    bool isTrueID = false;
    string pass, idTransfer, nameTransfer;
    __int16 count = -1;
    __int64 money = 0;
    system("cls");
    drawline(84, '=');
    cout << "\n";
    drawline(33, '=');
    cout << " TRANSFER MONEY ";
    drawline(34, '=');
    cout << "\n";
    //kiem tra mat khau
    do {
        cout << "After transfer money, Please Enter your Password: ";
        cin >> pass;
        if (account.getPassWord() != pass) {
            cout << "Password invalid ! Enter again!" << endl;
        }
    } while (account.getPassWord() != pass);
    // system("cls");
    drawline(84, '=');
    cout << "\n";
    drawline(33, '=');
    cout << " TRANSFER MONEY ";
    drawline(34, '=');
    users[0].displayData();  //debug
    //nhap ID muon chuyen tien, kiem tra ID
    do {
        cout << endl << "Enter ID of the person you want to transfer money: ";
        // cin.ignore();
        cin >> idTransfer;
        getline(cin, idTransfer);
        cin.ignore();
        cout << "Enter full name of person you want to transfer money: ";
        cin.ignore();
        getline(cin, nameTransfer);
        for (__int16 i = 0; i < nameTransfer.length(); i++) {
            nameTransfer[i] = toupper(nameTransfer[i]);     // tự động viết hoa tên
        }
        cout << "\n";
        for (__int16 i = 0; i < users.size(); i++) {
            if (users[i].getPhoneNumber() == idTransfer && users[i].getFullName() == nameTransfer) {
                // isTrueID = true;
                count = i;
            }
        }
        // system("cls");
        if (count == -1) {
            cout << "ID or Name Invalid ! Enter again !" << endl;
        }
    } while (count == -1);

    cout << "Enter the amount you want to transfer: ";
    do {
        cin >> money;
        if (this->getBalance() < money) {
            cout << "Insufficient funds in bank account ! Enter again !" << endl;
        }
    } while (this->getBalance() < money);
    this->setBalance(this->getBalance() - money);
    users[count].setBalance(users[count].getBalance() + money);
    cout << "Transfer money successfully!" << endl;
    cout << "Press any key to continue";
}

//withdraw money
void User::withdrawMoney(Account& account) {
    string pass;
    __int64 money;
    system("cls");
    drawline(84, '=');
    cout << "\n";
    drawline(20, '=');
    cout << " WITHDRAW MONEY ";
    drawline(25, '=');
    cout << "\n";
    //kiem tra mat khau cu
    do {
        cout << "Enter your Password: ";
        cin >> pass;
        if (account.getPassWord() != pass) {
            cout << "Password invalid ! Enter again!" << endl;
        }
    } while (account.getPassWord() != pass);
    system("cls");
    drawline(84, '=');
    cout << "\n";
    drawline(20, '=');
    cout << " WITHDRAW MONEY ";
    drawline(25, '=');
    cout << "\n" << "Enter the amount you want to withdraw: ";
    do {
        cin >> money;
        if (this->getBalance() < money) {
            cout << "Insufficient funds in bank account ! Enter again !" << endl;
        }
    } while (this->getBalance() < money);
    this->setBalance(this->getBalance() - money);
    cout << "Withdraw successfully!" << endl;
    cout << "Press any key to continue";
}

//view Transaction history
void User::viewTransactionHistory() {}
