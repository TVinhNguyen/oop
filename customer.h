#include <iostream> 
#include <vector>
using namespace std;
// khach hang
class Customer {
private:
    int id ;
    string name;
    string phone;
    string address;
    vector<int> purchaseHistory;
public:
    static int soluong ;
public:
    Customer(string name, string phone, string address);
    Customer(int id ,string name, string phone ,string address);
    int getId();
    string getName();  
    void setName(string name);
    string getPhone(); 
    void setPhone(string phone);
    string getAddress(); 
    void setAddress(string address);
    void addPurchaseHistory(int IdOder); // lich su mua hang
    void showPurchaseHistory(); 
    void show();
    
};
class CustomerManager {
    private:
        vector<Customer> customerList;
    public:
        void addCustomer(Customer customer);
        void removeCustomer(int id);
        void setCustomer(string phone );
        void showCustomer(string = "");
        Customer getCustomer(string phone);

        vector<Customer> getCustomerList();
};
