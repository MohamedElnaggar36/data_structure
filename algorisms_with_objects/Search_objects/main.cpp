#include <iostream>
#include <string.h>

using namespace std;

class Employee{
public:
    int id;
    char *name;
    int nameSize;
    int salary;

public:
    Employee (){
        id = 0;
        salary = 0;
        nameSize = strlen(name);
        name = new char(nameSize + 1);
        strcpy(name,"");
        cout << "Default Constructor" << endl;
    }

    Employee(int empId, int empSalary, char *empName){
        id = empId;
        salary = empSalary;
        nameSize = strlen(empName);
        name = new char[nameSize + 1];
        strcpy(name, empName);
    }

    //copy constructor
    Employee (const Employee &emp){
        id = emp.id;
        salary = emp.salary;
        nameSize = emp.nameSize;
        name = new char[nameSize + 1];
        strcpy(name, emp.name);
    }

    void setId(int empId){
        this->id = empId;
    }
    int getIdValue(){
        return id;
    }
    void setSalary(int empSalary){
        empSalary = salary;
    }
    int getSalaryValue(){
        return salary;
    }
    void setName(char empName[]){
        strcpy(name, empName);
    }
    char* getNameValue(){
        return name;
    }
};


class Search{
protected:
    Employee *arr;
    int arrSize;
    int id;
public:
    Search(){}
    Search(Employee *arr, int arrSize, int id){
        this->arr = arr;
        this->arrSize = arrSize;
        this->id = id;
    }

    virtual int getSearch() = 0;
};

class SequentialSearch:public Search{
public:
    SequentialSearch():Search(){};
    SequentialSearch(Employee *arr, int arrSize, int id):Search(arr, arrSize, id){};

    int getSearch(){
        int i = 0, found = 0;
        while ((!found) && (i < arrSize)) {
        if (id == arr[i].id)
            found = 1;
        else
            i++;
        }
        if (found)
            return i;
        else
            return -1;
    }
};




int main()
{
    Employee arrEmp[] = {
        Employee(5,2000,"Mohamed"),
        Employee(4,1000, "Ahmed"),
        Employee(1,500, "MM"),
        Employee(3,5000, "Mohd"),
        Employee(2,3000, "Omar")
    };

    int id;
    cout << "Enter employee id to search: ";
    cin >> id;

    SequentialSearch sSearch(arrEmp, 5, id);
    cout << "Index = " << sSearch.getSearch() << endl;


    return 0;
}
