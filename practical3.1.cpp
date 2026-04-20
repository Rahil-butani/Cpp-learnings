#include<iostream>
using namespace std;


class Employee{
    private:
    string name;
    double basic_salary;
    double bonus;
    public:
    Employee(string na="Unknown",double bsalary=0.0,double bns=0.0){
        name=na;
        basic_salary=bsalary;
        bonus=bns;
    }
    inline double calculate_new_salary(){
        return basic_salary+bonus;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Basic Salary "<<basic_salary<<endl;
        cout<<"Bonus Applied: "<<bonus<<endl;
        cout<<"New salary: "<<calculate_new_salary()<<endl;
    }
};
int main(){
    int n,i;
    string na;
    double bsalary;
    char choice;
    double bns;
    cout<<"Enter total number of Employees: "<<endl;
    cin>>n;
    Employee *emp=new Employee[n];
    for(i=0;i<n;i++){
    cout<<"Enter your name: "<<endl;
    cin>>na;
    cout<<"Enter you basic salary"<<endl;
    cin>>bsalary;
    cout<<"Want to Apply Bonus(y/n): ";
    cin>>choice;
    if (choice=='y' || choice=='Y'){
        cout<<"Enter the amount of bonus: "<<endl;
        cin>>bns;
        emp[i]=Employee(na,bsalary,bns);
    }
    else{
        emp[i]=Employee(na,bsalary);
    }
}
    for(i=0;i<n;i++){
        cout<<"Employee details: "<<endl;
        emp[i].display();
    }

return 0;
}
