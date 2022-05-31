//
// Created by Bingnan.Zhang on 25.05.2022.
//

#ifndef ALGORITHMUSTESTS_STLTEST_HPP
#define ALGORITHMUSTESTS_STLTEST_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

typedef __int64 int64;


using namespace std;

void printVectorDouble(double data){
    cout << data << " ";
}

void testVector(){

    vector<double> v1;
    v1.push_back(20.2);
    v1.push_back(33.032);
    v1.push_back(2.89);
    vector<double>::iterator pBegin = v1.begin();
    vector<double>::iterator pEnd = v1.end();
    for_each(pBegin,pEnd, printVectorDouble);//这里的函数只接受一个参数且无返回值
    for (vector<double>::iterator iter = v1.begin(); iter != v1.end(); ++iter) {
        cout << *iter << " ";
    }
}
void testMap(){
    map<string, double> m1;//key == pair.first und value == pair.second
    //4 Methoden Daten einzufügen
    m1.insert(pair<string,double>("bubble sort", 22.07));
    m1.insert(make_pair("quick sort", 18.91));
    m1.insert(map<string,double>::value_type("shell sort",19.23));
    m1["bucket sort"] = 17.232;
    for (map<string,double>::iterator iter = m1.begin(); iter != m1.end() ; ++iter) {
        cout << (*iter).first << ": " << (*iter).second << endl;
    }

}


class STLtest {

};

class Employee{
public:
    Employee(string name, int age, int64 telephone, string department){
        mName = name;
        mAge = age;
        mTelephoneNum = telephone;
        mDepartment = department;
    }
    void printInfoEmpolyee(){
        cout << "Name: " << mName << ";\t";
        cout << "Age: " << mAge << ";  ";
        cout << "Telephone number: " << mTelephoneNum << ";  ";
        cout << "Department: " << mDepartment  << ";\t"<< endl;
    }

private:
    string mName;
    int mAge;
    int64 mTelephoneNum;
    string mDepartment;
};
//aufbauen mit multimap
class HR{
public:
    HR() = default;
    void insertEmployee(string dep,Employee emp){
        this->mEmployeeList.insert(make_pair(dep,emp));
    }
    void printDepartment(string dep){
        cout << "------ " << dep << " ------" << endl;
        for (map<string,Employee>::iterator iter = mEmployeeList.begin(); iter != mEmployeeList.end(); ++iter) {
            if ((*iter).first == dep){
                (*iter).second.printInfoEmpolyee();
            }
        }
    }
    void printAll(){
        cout << "-------- " << "ALL" << " --------" << endl;
        for (map<string,Employee>::iterator iter = mEmployeeList.begin(); iter != mEmployeeList.end() ; ++iter) {
            (*iter).second.printInfoEmpolyee();
        }
        cout << "---------------------" << endl;
    }
private:
    multimap<string,Employee> mEmployeeList;

};

void testMultiMap(){
    Employee e1 = Employee("Andy",34,1768888888,"development");
    Employee e2 = Employee("Vicky",54,1752222222,"sale");
    Employee e3 = Employee("Jacob",22,1746666666,"financial");
    Employee e4 = Employee("Howard",54,1537777777,"service");
    Employee e5 = Employee("Dave",33,1838888888,"sale");
    HR hr1;
    hr1.insertEmployee("DEVELOPMENT",e1);
    hr1.insertEmployee("SALE",e2);
    hr1.insertEmployee("FINANCIAL",e3);
    hr1.insertEmployee("SERVICE",e4);
    hr1.insertEmployee("SALE",e5);

    //hr1.printAll();
    hr1.printDepartment("SALE");
    hr1.printDepartment("DEVELOPMENT");
    hr1.printDepartment("FINANCIAL");
    hr1.printDepartment("SERVICE");

}

#endif //ALGORITHMUSTESTS_STLTEST_HPP
