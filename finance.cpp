#include "finance.h"
// quan ly thu chi 

Finance::Finance(double x, double y):totalExpense(x) , totalRevenue(y) {};
void Finance::addRevenue(double revenue){
    this->totalRevenue += revenue;
};
void Finance::addExpense(double expense){
    this->totalExpense += expense;
};
double Finance::getProfit(){
    return this->totalRevenue - this->totalExpense;
};
void Finance::addBudgetReport(pair<string,int> p) {
    this->BudgetReport.push_back(p);
}
void Finance::showBudgetReport() {
    for(const auto& receipt : this->BudgetReport) {
        cout << " Hoa don ngay : " << receipt.first << " So tien :" << receipt.second <<  endl;
    }
    
}
