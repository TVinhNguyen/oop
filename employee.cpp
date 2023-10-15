#include <employee.h>
// lop nhan vien

Employee::Employee(string name, string phone, string address, string position, double salary):name(name),phone(phone),address(address),position(position),salary(salary) {}
string Employee::getName() {
        return this->name;
    }
string Employee::getPhone() {
        return this->phone;
    }
string Employee::getAddress() {
        return this->address;
    }
string Employee::getPosition() {
        return this->position;
    }
double Employee::getSalary() {
        return this->salary;
    }

//quan ly nhan vien

void EmployeeManager::addEmployee(Employee employee){
    this->employeeList.push_back(employee);
}

