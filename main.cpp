#include "ppl2.h"
int main() {
	Warehouse warehouse;
    File file;
    OrderManager orderManager;
    CustomerManager customerList;
    SalesManager manager;
	file.getWareHouse("Warehouse.inp",warehouse);
    file.getCustomer("Customer.inp",customerList);
	GRAPHIC grp;
	char text[] = "oke";
	grp.main();
	while(1) {
		tt:
		int choosen = grp.menu();
//		int h = getch();
//		if(h == 27) break;
		if (choosen == 0) break ; else
		if(choosen == 1) 
		{
			grp.purchase(warehouse,customerList);
			goto tt;
		} else
		{
			grp.manager();
			goto tt;
		}
	}
	

//

//    customerList.showCustomer();
//    Product* pr1 = new G_Product("GM1 ","Viclacera " ,"type1 ","300x300x15 "  , 200  ,  200000 );
//    vector<Product*> productList;
//    productList.push_back(pr1);
//    Customer customer1(1,"thanh", "0393245827","ha noi");
//    Customer customer2(1,"quyen", "0393245829","ha noi");
//
//    customerList.addCustomer(customer1);
//    customerList.addCustomer(customer2);
//
//    Order oder1(1,customer1,productList,"2020-10-9","2020-10-15");  
//    Order oder2(1,customer2,productList,"2020-10-9","2020-10-15");  
//
//
//
//
//    manager.addOrder(oder1,customerList,warehouse);
//    manager.addOrder(oder2,customerList,warehouse);
//    // warehouse.showWarehouse();
//    file.setWareHouse("warehouse.inp" , warehouse);
//    customerList.setCustomer("0987654321");
//    customerList.showCustomer();
//    manager.showBugetReport();
//    manager.showProfit();
////	grp.bgr();

}
	
