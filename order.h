#include <iostream> 
#include <string>
#include <vector>
#include "warehouse.h"
#include "customer.h"
using namespace std;

// don hang
class Order {
private:
    int orderNumber;
    Customer customer;
    vector<Product*> productList;
    double totalAmount;
    string orderDate;
    string deliveryDate;
public:
	static int soluong; 
public:
    Order( Customer customer, vector<Product* > productList, string orderDate, string deliveryDate);
    int getOrderNumber();
    Customer getCustomer();
    vector<Product*> getProductList();
    double getTotalAmount();
    string getOrderDate();
    string getDeliveryDate() ;
    ~Order();
};
// quan ly don hang (hoa don)
class OrderManager {
private:
    vector<Order> orderList;
public:
    void addOrder(Order order);  
    void removeOrder(int orderNumber); 
    void updateOrder(Order order);
};
