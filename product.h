#include <iostream>
#include <string>
using namespace std;

//lop sp
 class Product {
protected:
    string id,name;
    string category;
    int quantity;
    double price;
public:
    Product(string id , string name, string category,  int quantity, double price);
    Product(string name , string category , int quantity , double price );
    string getID();
    string getName() ;
    string getCategory();
    int getQuantity() ;
    double getPrice() ;
    void setQuantity(int quantity) ;
    virtual string getSpecial() = 0 ;
    virtual int getAmount() = 0 ;
};

class XM_Product  : public Product  {
    protected:
        string hardness;
    public:
    static int n ;
    public:
        XM_Product(string = "" , string = "" , string = "" ,string ="" ,  int = 0 , double = 0.0);
        XM_Product(string = "" , string = "" ,string ="" ,  int = 0 , double = 0.0);
        string getSpecial() ;
        int getAmount();
        ~XM_Product();
};


class G_Product : public Product 
{
    protected:
        string size ;
    public:
    static int n;
    public:
        G_Product(string = "" , string = "", string = "", string ="" ,int = 0 , double = 0.0);
        G_Product(string = "", string = "", string ="" ,int = 0 , double = 0.0);
        string getSpecial();
        int getAmount();
        ~G_Product();
};

class ST_Product : public Product
{
    protected:
        string measurement;
    public:
    static int n ;
    public:
        ST_Product(string = "" , string = "", string = "", string ="" ,int = 0 , double = 0.0);
        ST_Product(string = "", string = "", string ="" ,int = 0 , double = 0.0);
        string getSpecial();
        int getAmount();
        ~ST_Product();
};