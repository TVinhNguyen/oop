#include "manager.h"

using namespace std;

void SalesManager::addOrder(Order order,CustomerManager &customerList, Warehouse &warehouse) {
    //them don hang vao lich su mua hang cua khach hang
    for(int i  = 0 ; i < customerList.getCustomerList().size() ; i++) {
        if (customerList.getCustomerList()[i].getName() == order.getCustomer().getName()){
        customerList.getCustomerList()[i].addPurchaseHistory(order.getOrderNumber());
        break;
        }
    }
    //cap nhat so luong san pham trong kho;
    vector<Product*> productList = order.getProductList();
    for(int i = 0 ; i < productList.size(); i++) {
        Product* product = productList[i];
        int quantityWarehouse = warehouse.getProductQuantity(product->getID());
        warehouse.updateProduct(product->getID(),quantityWarehouse - product->getQuantity());}
        // cap nhat doanh thu
       
        this->finance.addRevenue(order.getTotalAmount());
        pair<string,int> p(order.getOrderDate(), order.getTotalAmount());
        this->finance.addBudgetReport(p);
        
}
void SalesManager::showBugetReport() 
{
    this->finance.showBudgetReport();
}
void SalesManager::showProfit()
{
    cout << fixed  << setprecision(3) << this->finance.getProfit();
}
// }
// void SalesManager::addCustomer(Customer customer) {
//     this->customerList.push_back(customer);
// }
// void SalesManager::showCustomer(Customer customer) {
//     for(int i  = 0 ; i < this->customerList.size() ; i++) {
//         if(this->customerList[i].getName() == customer.getName()) {
//             this->customerList[i].showPurchaseHistory();
//         }
//     }
// }
// void SalesManager::showName() {
//     for (int i = 0; i < customerList.size(); i++)
//     {
//         customerList[i].show();
//         cout << endl;
//     }
    
// }