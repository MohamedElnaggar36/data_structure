#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
    int id;
    char name[20];
    int salary;

public:
    Employee *pNext;
    Employee *pPervious;
    Employee()
    {
        this->id = 0;
        this->salary = 0;
        strcpy(this->name, "");
        pNext = NULL;
        pPervious = NULL;
    }
    Employee(int id, char *name, int salary)
    {
        this->id = id;
        strcpy(this->name, name);
        this->salary = salary;
    }

    void setName(char *name){
        strcpy(name, this->name);
    }
    char* getName(){
        return name;
    }
    void setId(int id){
        this->id = id;
    }
    int getId(){
        return this->id;
    }
    void setSalary(int salary){
        this->salary = salary;
    }
    int getSalary(){
        return this->salary;
    }


    void printEmployee(){
        cout << "Name: " << getName() << endl;
        cout << "Id: " << getId() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "----------------------->>" << endl;
    }

};


class LinkedList
{
protected:
    Employee *pStart;
    Employee *pEnd;
public:
    LinkedList(){
        pStart = pEnd = NULL;
    }

// Setters and getters for pStart and pEnd;
    void addList(Employee *pItem);
    void InsertList(Employee *pItem);
    Employee* searchList(int id);
    char *searchId(int id);
    int DeleteList(int id);
    void freeList();
    void displayAll();
    Employee *removeFirst();
    Employee *removeLast();

    ~LinkedList()
    {
        freeList();
    }
};
void LinkedList::addList(Employee *pItem)
{
    if (!pStart)                    /* Case of empty list Add the first node */
    {
        pItem->pNext = NULL;
        pItem->pPervious = NULL;
        pStart = pEnd = pItem;
    }
    else                            /* Case of existing list nodes Append Node */
    {
        pEnd->pNext = pItem;
        pItem->pPervious = pEnd;
        pItem->pNext = NULL;
        pEnd = pItem;
    }
}

Employee *LinkedList::searchList(int id)   // sequential search
{
    Employee *pItem = NULL;
    pItem = pStart;                         // begin from the first node
    while(pItem && pItem->getId() != id)
    {
        pItem = pItem->pNext;
    }
    return pItem;
}

char *LinkedList::searchId(int id){
    if(searchList(id) != NULL)
        return "Found";
    else
        return "Not Found";
}

void LinkedList::displayAll()
{
    Employee *pItem;
    pItem = pStart;
    while(pItem != NULL)
    {
        pItem->printEmployee();
        pItem = pItem->pNext;
    }
}

int LinkedList::DeleteList(int id)
{
    Employee *pItem;
    int RetFlag = 1;
    pItem = searchList(id); // First search for it
    if (!pItem)
    {
        RetFlag = 0;    //Not found
    }
    else
    {
        // Found
        if (pStart == pEnd) /* Case of one node */
        {
            pStart = pEnd = NULL;
        }
        else if(pItem == pStart) /* Case of first node */
        {
            pStart = pStart->pNext;
            pStart->pPervious = NULL;
        }
        else if(pItem == pEnd) /* Case of last node */
        {
            pEnd = pEnd->pPervious;
            pEnd->pNext = NULL;
        }

        else /* Case of intermediate node */
        {
            pItem->pPervious->pNext = pItem->pNext;
            pItem->pNext->pPervious = pItem->pPervious;
        }
        delete pItem;
    }
    return RetFlag;
}

void LinkedList::freeList()
{
    Employee *pItem;
    while(pStart)
    {
        pItem = pStart;
        pStart = pStart->pNext;
        delete pItem;
    }
    pEnd = NULL;
}

void LinkedList::InsertList(Employee *pNode)
{
    Employee *ptemp;
    if(pStart==NULL)
        addList(pNode); // empty list
    else
    {
        ptemp=pStart;
        while(ptemp && ptemp ->getId() < pNode->getId() )
            ptemp= ptemp->pNext; // find its right location or reach the end
        if(!ptemp)
            addList (pNode); // it will be the last Node
        else if(ptemp==pStart) // it will be the first Node
        {
            pNode->pNext=pStart;
            pNode->pPervious=NULL;
            pStart->pPervious=pNode;
            pStart=pNode;
        }
        else // in any middle loaction
        {
            pNode->pNext=ptemp;
            pNode->pPervious=ptemp->pPervious;
            ptemp->pPervious->pNext=pNode;
            ptemp->pPervious=pNode;
        }
    }
}
Employee* LinkedList::removeFirst(){
    Employee *pNode;
    pNode = pStart;

    if(pStart){
        if(pStart == pEnd){
            pStart = pNode = NULL;
        }
        else{
            pStart = pStart->pNext;
            pStart->pPervious = NULL;
        }
    }
    return pNode;
}
Employee *LinkedList::removeLast(){
    Employee *pNode;
    pNode = pEnd;
    if(pEnd){
        if(pStart == pEnd){
            pStart = pEnd = NULL;
        }
        else{
            pEnd = pEnd->pPervious;
            pEnd->pNext = NULL;
        }
    }
    return pNode;
}

int main()
{
    Employee emp1(1, "Mohamed", 2000);
    Employee emp2(2, "Ahmed", 1500);
    Employee emp3(3, "Omar", 1000);
    LinkedList empList;
    empList.addList(&emp1);
    empList.addList(&emp2);
    empList.addList(&emp3);
    Employee emp4(5, "New User", 500);
    empList.InsertList(&emp4);
    empList.displayAll();

    empList.DeleteList(2);
    cout << "By Removing id: 2 >>" << endl;

    empList.displayAll();
    int id;
    cout << "Enter id to find: ";
    cin >> id;
    cout << "User " << empList.searchId(id) << " >> ";

    cout << "Name: " << empList.searchList(id)->getName() << " - " << "Salary: " << empList.searchList(id)->getSalary() << endl;
    cout << "By Removing Fist >>" << endl;
    empList.removeFirst();
    empList.displayAll();
    cout << "By Removing Last >>" << endl;
    empList.removeLast();
    empList.displayAll();
    empList.freeList();
    cout << "After using freeList >>" << endl;
    cout << empList.searchId(id) << endl;

    return 0;
}
