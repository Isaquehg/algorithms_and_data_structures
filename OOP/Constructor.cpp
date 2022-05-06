#include <iostream>
using namespace std;

class Employee {
  private:
    // Private attribute
    int salary;

  public:
    // Setter
    Employee(int s){
        salary = s;
    }
    // Getter
    int getSalary() {
      return salary;
    }
};

/*
We can create the structor out from the class

Employee::Employee(int s){
    salary = s;
}
*/

int main() {
  Employee myObj(100000);

  cout << myObj.getSalary();

  return 0;
}