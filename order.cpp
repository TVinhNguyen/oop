#include "order.h"
// don hang
int Order::soluong = 0;
Order::Order( Customer customer, vector<Product*> productList, string orderDate, string deliveryDate)
:  customer(customer) , productList(productList) ,  orderDate(orderDate) , deliveryDate(deliveryDate) {
	this->soluong++ ; 
	this->orderNumber = soluong;	
    this->totalAmount = 0;
    for(int i = 0 ; i < this->productList.size(); i++) {
        this->totalAmount += this->productList[i]->getPrice()* this->productList[i]->getQuantity();
    }
};
int Order::getOrderNumber() {
    return this->orderNumber;
}
Customer Order::getCustomer() {
    return this->customer;
}
vector<Product*> Order::getProductList() {
    return this->productList;
}
double Order::getTotalAmount() {
    return this->totalAmount;
}
string Order::getOrderDate() {
    return this->orderDate;
}
string Order::getDeliveryDate() {
    return this->deliveryDate;
}
Order::~Order() {
    // for(Product* product : productList) {
    //     delete product;
    // }
}
// quan ly don hang

void OrderManager::addOrder(Order order) {
    this->orderList.push_back(order);
}
void OrderManager::removeOrder(int orderNumber) {
    for (int i = 0; i < this->orderList.size(); i++) {
        if (this->orderList[i].getOrderNumber() == orderNumber) {
            this->orderList.erase(this->orderList.begin() + i);
            break;
        }
    }
}
void OrderManager::updateOrder(Order order) {
    for (int i = 0; i < this->orderList.size(); i++) {
        if (this->orderList[i].getOrderNumber() == order.getOrderNumber()) {
            this->orderList[i] = order;
            break;
        }
    }
}

