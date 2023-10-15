#include "file.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


void File::getWareHouse(string nameFile , Warehouse& warehouse) {
        string id , name ,category ; string special ; int quantity ;double price;
        int vt = 0;
        string line, res= "", token;
        ifstream myfile (nameFile);
        if(myfile.is_open()) {
            while(getline(myfile,line)) {
                stringstream ss(line);
                while(ss >> token) {
                    if(token != ";") {
                        res+=token;
                        res+=" "; 
                    }
                    else {
                        res.pop_back();
                        switch (vt)
                        {
                        case 0:
                            id = res;    res = "";  vt +=1;
                            break;
                        case 1:
                            name = res ; res = ""; vt +=1;
                            break;
                        case 2:
                            category = res; res = ""; vt+=1;
                            break;
                        case 3:
                            special = res ; res = ""; vt+=1; 
                            break;
                        case 4:
                            quantity = stoi(res); res = ""; vt+=1;
                            break;
                        case 5 :
                            price = stod(res) ; res = " "; vt+=1;
                            break;
                        default:
                            break;
                        }
                    }
                }
                char loai  = id[0];
                Product* pr;
                if(1) {               
                if(loai == 'X')  pr =  new XM_Product(id,name,category,special,quantity,price); else
                if(loai == 'G')  pr = new G_Product(id,name,category,special,quantity,price); else
                if(loai == 'S')  pr = new ST_Product(id,name,category,special,quantity,price); 
                warehouse.addProduct(pr);
                }
                vt = 0;   ; res = "";
            }
            myfile.close();
        }
}
void File::getCustomer(string customerFile, CustomerManager &customerManager) {
    int vt = 0;
        int id ; string name ;string phone ; string address;
        string line, res= "", token;
        ifstream myfile (customerFile);
        if(myfile.is_open()) {
            while(getline(myfile,line)) {
                stringstream ss(line);
                while(ss >> token) {
                    if(token != ";") {
                        res+=token;
                        res+=" "; 
                    }
                    else {
                        res.pop_back();
                        switch (vt)
                        {
                        case 0:
                            id = stoi(res);    res = "";  vt +=1;
                            break;
                        case 1:
                            name = res ; res = ""; vt +=1;
                            break;
                        case 2:
                            phone = res; res = ""; vt+=1;
                            break;
                        case 3:
                            address = res ; res = ""; vt+=1;
                            break;
                        default:
                            break;
                        }
                    }
                    
                }
                Customer cs(id,name,phone,address);
                vt = 0;  customerManager.addCustomer(cs) ; res = "";
            }
            myfile.close();
        }
}
void   File::setWareHouse(string nameFile , Warehouse warehouse) {
    ofstream myfile; myfile.open(nameFile);
    if(myfile.is_open()) 
    {
        vector<Product*> warehouseProduct = warehouse.getProductList();
        for (int i = 0; i < warehouse.getProductList().size(); i++)
        {
            myfile << warehouseProduct[i]->getID() << "  ;  " << warehouseProduct[i]->getName() << "  ;  " << warehouseProduct[i]->getCategory() << "  ;  "
            << warehouseProduct[i]->getSpecial() << "  ;  " << warehouseProduct[i]->getQuantity() << "  ;  " << warehouseProduct[i]->getPrice() << "  ;  " << endl;
        }
        myfile.close();
        
    }
  

}
// vector<Product> File::getProduct() { return this->fileProduct; };
// vector<Customer> File::getCustomer() {return this->fileCustomer;};
File::~File() {};
