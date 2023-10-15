#include "product.h"

Product::Product(string id , string name, string category,  int quantity, double price) 
:id(id) , name(name) , category(category) , quantity(quantity) , price(price){} ;

Product::Product(string name, string category,  int quantity, double price) 
: name(name) , category(category) , quantity(quantity) , price(price){} ;

string Product::getID(){
    return this->id;
}
string Product::getName() {
    return this->name;
}
string Product::getCategory() {
    return this->category;
}
int Product::getQuantity() {
    return this->quantity;
}
double Product::getPrice() {
    return this->price;
}
void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}



//xi mang
int XM_Product::n = 0;
XM_Product::XM_Product(string id, string name,string category, string hardness, int quantity, double price) : Product(id,name,category,quantity,price)
 {
    this->hardness  = hardness;
    this->n++;
}
XM_Product::XM_Product(string name , string category , string hardness, int quantity , double price) : Product(name,category,quantity,price)
{  
    this->id = "XM" + to_string(this->n);
    this->n++;
    this->hardness = hardness;
}
string XM_Product::getSpecial() {
    return this->hardness;
}
int XM_Product::getAmount() {return this->n;}
XM_Product::~XM_Product() {};



//gach 
int G_Product::n = 0 ;
G_Product::G_Product(string id, string name,string category, string size, int quantity, double price) : Product(id,name,category,quantity,price)
{
    this->size  = size;
    this->n++;
}
G_Product::G_Product(string name , string category ,string size, int quantity , double price) : Product(name,category,quantity,price)
{  
    this->id = "G" + to_string(this->n);
    this->n++;
    this->size = size;
}
string G_Product::getSpecial() {
    return this->size;
}
int G_Product::getAmount() {return this->n;}
G_Product::~G_Product() {};




//Sat thep

int ST_Product::n = 0 ;
ST_Product::ST_Product(string id, string name,string category, string measurement, int quantity, double price) : Product(id,name,category,quantity,price)
{
    this->measurement  = measurement;
    this->n++;
}
ST_Product::ST_Product(string name , string category ,string size, int quantity , double price) : Product(name,category,quantity,price)
{  
    this->id = "ST" + to_string(this->n);
    this->n++;
    this->measurement = measurement;
}
string ST_Product::getSpecial() {
    return this->measurement;
}
int ST_Product::getAmount() {return this->n;}
ST_Product::~ST_Product() {};

