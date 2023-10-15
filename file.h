#include "manager.h"
// lop nhap file :
class File {
private:
    // vector<Customer> fileCustomer;
public:
    ~File();
    void getCustomer(string customerFile,CustomerManager &customerManager);
    void getWareHouse(string nameFile,Warehouse& warehouse);
    void setWareHouse(string nameFile,Warehouse warehouse);
    void ShowProduct();
    // vector<Product>  getProduct();
    vector<Customer> getCustomer();

};
