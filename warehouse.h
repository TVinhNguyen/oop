#include <iostream>
#include <string>
#include <vector>
#include "product.h"
using namespace std;
// kho hang
class Warehouse {
private:
    vector<Product*> productList;
public:
    ~Warehouse();
    void addProduct(Product* product);
    void removeProduct(string name);
    void updateProduct(string name, int quantity);
    int getProductQuantity(string name);
    void showWarehouse(); 
    vector<Product*> getProductList();
    Product* findID(string id);
    // Product* findName(string name);
    vector<Product*> findCategory(string category);
    vector<Product*> findPrice(double price);
    vector<Product*> findQuantity(int quantity);
};
