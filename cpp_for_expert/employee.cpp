// 1.1.7
#include <iostream>
// #include <format>
// #include employee;

export struct Employee{
  char firstInitial;
  char lastInitial;
  int employeeNumber;
  int salary;
};

using namespace std;

int main(){
  // 직원 레코드 생성 및 값 채우기
  Employee anEmployee;
  anEmployee.firstInitial = 'J';
  anEmployee.lastInitial = 'D';
  anEmployee.employeeNumber = 42;
  anEmployee.salary = 80000;
  
  // 직원 레코드에 저장한 값 출력하기
  cout << "Employee : " << anEmployee.firstInitial
      << " " << anEmployee.lastInitial << endl;
  cout << "Number : " << anEmployee.employeeNumber << endl;
  cout << "Salary : " << anEmployee.salary << endl;
  return 0;
}
