#include <iostream>
#include "manager.h"
#include <iomanip>
using namespace std;
int main() {
    // khoi tao quan ly
    SalesManager salesManager;
    // Khoi tao quan ly don hang
    OrderManager orderManager;
    // Khoi tao loi nhuan 
    Finance finace;
    // Khoi tao kho hang :
    Warehouse warehouse;
    // khoi tao doc , ghi file :
    File file;
    // Them khach hang
    file.setCustomer("Customer.inp");
    for (int i = 0; i < file.getCustomer().size(); i++)
    {
        salesManager.addCustomer(file.getCustomer()[i]) ;
    }
    Customer customer1("Dan","039324582  7", "Address 1");
    Customer customer2("Dan","0393245827", "Address 1");
    Customer customer3("Dan","0393245827", "Address 1");

    salesManager.addCustomer(customer1);
    salesManager.addCustomer(customer2);
    salesManager.addCustomer(customer3);
    //them san pham
    Product product1("XM01" ,"Product 1","type 1",10 ,10000);
    Product product2("XM02" ,"Product 2","type 2" , 20 ,20000);
    Product product5("XM03" , "Product 3","type 1", 40,  15000);
    
    warehouse.addProduct(product1);
    warehouse.addProduct(product2);
    warehouse.addProduct(product5);

    Product product3("XM01","Product 1" , "type 1",2,10000);
    Product product4("XM03","Product 3", "type 3",4,15000);
    
    // tao don hang
    vector<Product> productList1 = {product3};
    vector<Product> productList2 = {product4};
    Order order1(1,customer1,productList1,"2023-09-17","2023-09-19");
    Order order2(2,customer1,productList2,"2023-09-17","2023-09-19");
    cout << fixed << setprecision(3) << order1.getTotalAmount() << endl;

    file.setProduct("warehouse.inp");
    // salesManager.showFileProduct();
    //them don hang
    // salesManager.addOrder(order1,warehouse,finace);
    // salesManager.addOrder(order2,warehouse,finace);
    // salesManager.addCustomer(customer1);
    // salesManager.showCustomer(customer1);
//     for(int i = 0 ; i < file.getProduct().size() ; i++) {
//         warehouse.addProduct(file.getProduct()[i]) ;
//     }
//    warehouse.showWarehouse();
//    cout << fixed <<  setprecision(3) << finace.getProfit();
//    file.setWareHouse("warehouse.inp",warehouse);
//    finace.showBudgetReport();
//     cout << customer2.getId();
    
    salesManager.showName();
    
    return 0;

}