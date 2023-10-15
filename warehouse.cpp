#include "warehouse.h"
// lop kho
Warehouse::~Warehouse() {
    // for(Product* product : this->productList) {
    //     delete product;
    // } 
}
void Warehouse::addProduct(Product* product) {
    this->productList.push_back(product);
   }
void Warehouse::removeProduct(string name) {
    for (int i = 0; i < this->productList.size(); i++) {
        if (this->productList[i]->getName() == name) {
            this->productList.erase(this->productList.begin() + i);
            break;
        }
    }
}
void Warehouse::updateProduct(string id , int quantity) {
    for (int i = 0; i < this->productList.size(); i++) {
        if (this->productList[i]->getID() == id) {
            this->productList[i]->setQuantity(quantity);
            break;
        }
    }
}
int Warehouse::getProductQuantity(string id) {
    for (int i = 0; i < this->productList.size(); i++) {
        if (this->productList[i]->getID() == id) {
            return this->productList[i]->getQuantity();
        }
    }
    return 0;
}
void Warehouse::showWarehouse() {
    for (int i = 0; i < this->productList.size()  ; i++)
    {
        cout << i << " "  << this->productList[i]->getID() << " " << this->productList[i]->getName() << " " << this->productList[i]->getQuantity()  
        <<  " "  << this->productList[i]->getSpecial() << endl;
    }
    
}
vector<Product*> Warehouse::getProductList() {
    return this->productList;
}
 Product* Warehouse::findID(string id){
     for(int i = 0 ; i<this->productList.size() ; i++) {
         if(this->productList[i]->getID() == id) return this->productList[i];
     }
     Product* p = new G_Product("0","1","1"," 1",1,1);
     return p;
 };
// Product* Warehouse::findName(string name) {
//      for(int i = 0 ; i<this->productList.size() ; i++) {
//         if(this->productList[i]->getName() == name) return this->productList[i];
//     }
//     Product p("1" ,"1" ,"1",1,1);
//     return p;
// };
vector<Product*> Warehouse::findCategory(string type) {
    vector<Product*> p ;
      for(int i = 0 ; i<this->productList.size() ; i++) {
        if(this->productList[i]->getCategory() == type) p.push_back(this->productList[i]);
    }
    return p;
};
vector<Product*> Warehouse::findPrice(double Price) {
    vector<Product*> p ;
      for(int i = 0 ; i<this->productList.size() ; i++) {
        if(this->productList[i]->getPrice() == Price) p.push_back(this->productList[i]);
    }
    return p;
};
vector<Product*> Warehouse::findQuantity(int quantity) {
    vector<Product*> p ;
      for(int i = 0 ; i<this->productList.size() ; i++) {
        if(this->productList[i]->getQuantity() == quantity) p.push_back(this->productList[i]);
    }
    return p;
};
