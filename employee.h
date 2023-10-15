#include <iostream> 
#include <string>
#include <vector>
using namespace std;
// nhan vien
class Employee {
private:
    string name;
    string phone;
    string address;
    string position;
    double salary;
public:
    Employee(string name, string phone, string address, string position, double salary) ;
    string getName();
    string getPhone();
    string getAddress() ;
    string getPosition() ;
    double getSalary() ;
};
// quan ly nhan vien
class EmployeeManager {
private:
    vector<Employee> employeeList;
public:
    void addEmployee(Employee employee);
};
