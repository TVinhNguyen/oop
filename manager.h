#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "finance.h"
#include "order.h"

using namespace std;


// quan ly ban hang

class SalesManager {
private:
    Finance finance;
public:
    
    void addOrder(Order order , CustomerManager &cusmomerList ,Warehouse &warehouse  );
    void showBugetReport();
    void showProfit();
};


