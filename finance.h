#include <iostream>
#include <string>
#include <vector> 
using namespace std;
class Finance {
private:
    double totalRevenue;
    double totalExpense;
    vector<pair<string,int> > BudgetReport;
public:
    Finance(double = 1 , double =1 );
    void addRevenue(double revenue);
    void addExpense(double expense);
    void addBudgetReport(pair<string,int>);
    void showBudgetReport();
    double getProfit();
};
