#include "file.h"
#include <iostream>
#include <vector>
using namespace std;
int main () {
    // vector<Product*> Products;
    // Product* pr = new G_Product("GM01" ,"viclacera" , "type1","300x100",900,2000);
    // Products.push_back(pr);
    // pr = new ST_Product("ST01","ten","hcn","met",100,200);
    // Products.push_back(new G_Product("GM01" ,"viclacera" , "type1","300x100",900,2000));
    // Products.push_back(pr);
    // for(Product* p : Products) {
    //     cout << p->getID() << endl;
    //     cout << p->getSpecial() << " ";
    //     cout << p->getAmount()  << endl;
    // }
    File file;
    file.setProduct("Cty_Hung_Anh.inp");
    file.ShowProduct();
    // for (Product* product : Products) {
    //     delete product;
    // }
}