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

void SwapEmp(Employee &e1, Employee &e2){
        Employee temp(0, 0, "");               //to carry first object data

        temp.id = e1.id;
        temp.salary = e1.salary;
        strcpy(temp.name, e1.name);

        e1.id = e2.id;
        e1.salary = e2.salary;
        strcpy(e1.name, e2.name);

        e2.id = temp.id;
        e2.salary = temp.salary;
        strcpy(e2.name, temp.name);
}

class Sort{
protected:
    Employee *arr;
    int arrSize;

public:
    Sort(){}
    Sort(Employee *arr, int arrSize){
        this->arr = arr;
        this->arrSize = arrSize;
    }
    virtual void getSort() = 0;
    virtual void printSorted() = 0;
};


class SelectionSort:public Sort{
public:
    SelectionSort():Sort(){};
    SelectionSort(Employee arr[], int arrSize):Sort(arr, arrSize){};

    void getSort(){
        int i, j, min_idx;

        for (i = 0; i < arrSize - 1; i++){
            min_idx = i;
            for (j = i+1; j < arrSize; j++)
                if (arr[j].id < arr[min_idx].id)
                    min_idx = j;

            SwapEmp(arr[min_idx], arr[i]);
        }
    }
    void printSorted(){
        cout << "Using Selection Sort >>" << endl;
        for(int i = 0; i < 5; i++){
            cout << arr[i].id << " ";
            cout << arr[i].salary << " ";
            cout << arr[i].name << endl;
        }
        cout << endl;
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
    SelectionSort ss(arrEmp,5);
    ss.getSort();
    ss.printSorted();


    return 0;
}
