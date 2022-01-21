#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
    int id;
    char name[20];
    int salary;

public:
    Employee *pRight;
    Employee *pLeft;
    Employee()
    {
        this->id = 0;
        this->salary = 0;
        strcpy(this->name, "");
        pRight = NULL;
        pLeft = NULL;
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

class BinaryTree{
    Employee *pParent;
    Employee *Insert(Employee *pRoot, Employee *data);
    Employee *getRoot(Employee *pRoot, Employee *data);
    void inOrder(Employee *pRoot);
    void preOrder(Employee *pRoot);
    void postOrder(Employee *pRoot);

public:
    BinaryTree(){ pParent = NULL; }
    void insertNode(Employee *data);
    Employee *searchTree(int id);
    void deleteNode(int id);
    int getHight(Employee *pNode);

    void inOrderTraverse();
    void preOrderTraverse();
    void postOrderTraverse();
};

void BinaryTree::insertNode(Employee *data){
    pParent = Insert(pParent, data);
}
Employee *BinaryTree::Insert(Employee *pRoot, Employee *data){
    if(pRoot == NULL){
        data->pRight = NULL;
        data->pLeft = NULL;
        return (data);
    }
    else{
        if(data->getId() <= pRoot->getId())
            pRoot->pLeft = Insert(pRoot->pLeft, data);
        else
            pRoot->pRight = Insert(pRoot->pRight, data);
        return (pRoot);
    }
}
Employee *BinaryTree::searchTree(int id){
    Employee *pRoot;
    pRoot = pParent;
    while(pRoot && id != pRoot->getId()){
        if(id < pRoot->getId())
            pRoot = pRoot->pLeft;
        else
            pRoot = pRoot->pRight;
    }
    return pRoot;
}

Employee *BinaryTree::getRoot(Employee *pRoot, Employee *data){

    if(pRoot->getId() != data->getId()){
        if(pRoot->getId() > data->getId()){
            if(pRoot->pLeft->getId() != data->getId())
            return pRoot->pLeft;
        }
        else{
            return pRoot->pRight;
        }
    }
}


void BinaryTree::deleteNode(int id){

    Employee *pNode;
    Employee *pChild;

    pNode = getRoot(pParent, searchTree(id));
    cout << "pParent = " << pParent->getId() << endl;
    cout << "pNode = " << pNode->getId() << endl;
    pChild = searchTree(id);
    cout << "pChild = " << pChild->getId() << endl;


    if(pChild->getId() < pNode->getId()){
        if(pChild->pLeft == NULL && pChild->pRight == NULL){
            pNode->pLeft = NULL;
            pChild = NULL;
        }
        else if(pChild->pLeft != NULL && pChild->pRight == NULL){
            pNode->pLeft = NULL;
            pChild = NULL;
            insertNode(pChild->pLeft);
        }
        else if(pChild->pLeft == NULL && pChild->pRight != NULL){
            pNode->pLeft = NULL;
            pChild = NULL;
            insertNode(pChild->pRight);
        }
        else{
            pNode->pLeft = NULL;
            pChild = NULL;
            insertNode(pChild->pLeft);
            insertNode(pChild->pRight);
        }

    }
    else{
        if(pChild->pLeft == NULL && pChild->pRight == NULL){
            pNode->pRight = NULL;
            pChild = NULL;
        }
        if(pChild->pLeft != NULL && pChild->pRight == NULL){
            pNode->pRight = NULL;
            pChild = NULL;
            insertNode(pChild->pLeft);
        }
        else if(pChild->pLeft == NULL && pChild->pRight != NULL){
            pNode->pRight = NULL;
            pChild = NULL;
            insertNode(pChild->pRight);
        }
        else{
            pNode->pRight = NULL;
            pChild = NULL;
            insertNode(pChild->pLeft);
            insertNode(pChild->pRight);
        }
    }
}

void BinaryTree::inOrderTraverse(){
    inOrder(pParent);
}
void BinaryTree::inOrder(Employee *pRoot){
    if(pRoot){
        inOrder(pRoot->pLeft);
        cout << "Id: " << pRoot->getId() << endl;
        inOrder(pRoot->pRight);
    }
}
void BinaryTree::preOrderTraverse(){
    preOrder(pParent);
}
void BinaryTree::preOrder(Employee *pRoot){
    if(pRoot){
        cout << "Id: " << pRoot->getId() << endl;
        preOrder(pRoot->pLeft);
        preOrder(pRoot->pRight);
    }
}
void BinaryTree::postOrderTraverse(){
    postOrder(pParent);
}
void BinaryTree::postOrder(Employee *pRoot){
    if(pRoot){
        postOrder(pRoot->pLeft);
        postOrder(pRoot->pRight);
        cout << "Id: " << pRoot->getId() << endl;
    }
}
int BinaryTree::getHight(Employee *pNode){
    int h = 0;
    if(pNode != NULL)
    {
        int lHeight = getHight(pNode->pLeft);
        int rHeight = getHight(pNode->pRight);
        int maxHeight = max(lHeight,rHeight);
        h = maxHeight + 1;
    }
    return h;
}



int main()
{
    Employee emp1(5, "Mohamed", 5000);
    Employee emp2(20, "Ali", 2000);
    Employee emp3(4, "Islam", 4000);
    Employee emp4(1, "Ahmed", 2500);
    Employee emp5(6, "Omar", 500);

    BinaryTree tree;
    tree.insertNode(&emp1);
    tree.insertNode(&emp2);

    tree.insertNode(&emp5);
    tree.insertNode(&emp4);
    tree.insertNode(&emp3);




    cout << "in-Order method: " << endl;
    tree.inOrderTraverse();

    cout << "-----------------------" << endl;

    cout << "pre-Order method: " << endl;
    tree.preOrderTraverse();

    cout << "-----------------------" << endl;

    cout << "post-Order method: " << endl;
    tree.postOrderTraverse();

    cout << "Height of 5 = " << tree.getHight(tree.searchTree(5)) << endl;

    int id;
    cout << "Enter id to search: ";
    cin >> id;

    if(tree.searchTree(id) != NULL)
        tree.searchTree(id)->printEmployee();
    else
        cout << "User Not Found >>" << endl;

    return 0;
}
