#include "customer.h"

int Customer::soluong = 0;

Customer::Customer(string name, string phone ,string address)
: name(name) , phone(phone), address(address){
    this->soluong++;
    this->id = soluong;
};
Customer::Customer(int id , string name , string phone , string address)
: id(id) , name(name), phone(phone) , address(address) {
    this->soluong++;
};
int Customer::getId() {
    return this->id;
}
string Customer::getName() {
    return this->name;
}
void Customer::setName(string name) {
    this->name = name;
}
string Customer::getPhone() {
    return this->phone;
}
void Customer::setPhone(string phone) {
    this->phone = phone;
}
string Customer::getAddress() {
    return this->address;
}
void Customer::setAddress(string address) {
    this->address = address;
}
void Customer::addPurchaseHistory(int IdOrder) {
    this->purchaseHistory.push_back(IdOrder);
}
void Customer::showPurchaseHistory() {
    for(int i = 0 ; i<this->purchaseHistory.size() ; i++) {
        cout << this->purchaseHistory[i] << " ";
    }
}
void Customer::show() {
    cout << this->name << " " << this->phone << " " << this->address << endl;
}


void CustomerManager::addCustomer(Customer customer) {
    this->customerList.push_back(customer);
}
void CustomerManager::removeCustomer(int id) {
    for(int i = 0 ; i < this->customerList.size() ; i++) {
        if(customerList[i].getId() == id ) {customerList.erase(this->customerList.begin() + i); break; }
    }
}
vector<Customer> CustomerManager::getCustomerList() {
    return this->customerList;
}

void CustomerManager::showCustomer(string phone) {
    if (phone == "") for(int i =0 ; i<this->customerList.size() ; i++) {
        this->customerList[i].show();
    } else 
    {
        for(int i = 0 ; i< this->customerList.size() ; i++) 
        {
            if(this->customerList[i].getPhone() == phone)  customerList[i].show();
        }
    }
    
}


void CustomerManager::setCustomer(string phone) {
    for(int i  = 0  ; i<this->customerList.size(); i++) {
        if(this->customerList[i].getPhone() == phone) {
            cout << "moi nhap lai ten khach hang:" ; 
            string name ; getline(cin , name);
            this->customerList[i].setName(name);
            cout << "moi nhap lai so dien thoai"; 
            getline(cin ,name) ; this->customerList[i].setPhone(name);
            cout << "moi nhap lai dia chi khach hang";
            getline(cin,name) ; this->customerList[i].setAddress(name);
            break;
        }
    }
}
Customer CustomerManager::getCustomer(string phone)
{
    for (int i = 0; i < this->customerList.size(); i++)
    {
        if (this->customerList[i].getPhone() == phone)
            return customerList[i];
    }
    Customer cs(-1, "1", "1", "1");
    return cs;
}
