/*
------Encapsulation-------

Encapsulation is the Idea to bundling up {data} together, and {methods} that work on that data, we do it because we do not want anyone outside of our class to modify and use that data {directly}.

why Encapsulation?
because we don't want anyone to directly access our data, to interact with it or modify it. because we want to provide our own ways to make it happen.
*/

/* 
-------Abstraction--------- 

hidding the complex things behind the simple procedure to make it simple.
example: click-btn-in-camera, we dont know how behind the seen camera take photo, but we know it will take the photo
And now if another mobile company comes and want camera feature, then they would have to implement their own camera feature.

Abstraction work as a contract
*/

/* 
--------Inheritance---------

1. inheritance is a way to get all the functionality and properties of the base class to your class
2. there are 3 levels of inheritance: private, protected, public

rule 1: if the base class have a user-defined-contructor, than all derived class should also have a user-defined-contructor.

*/

/* 
--------Polymorphism---------

imp-note: the most common use of polymorphism is when a parent class reference is used to refer a child class object.

polymorphism means a function which have many forms
*/

#include <bits/stdc++.h>
using namespace std;

// this is an abstract class, any other class who would inherit this class, they have to provide the implementation of its pure virtual function.
class AbtractEmployee
{
    // obligatory pure virtual function.
    virtual void AskForPromotion() = 0;
};

class Employee : AbtractEmployee
{
protected:
    string name;
    int age = -1;
    string company;

public:
    Employee(string name, int age, string company)
    {
        this->name = name;
        if (age > 17)
            this->age = age;
        this->company = company;
    }

    // if intro function exist in the child class then execute that one
    virtual void Intro()
    {
        cout << "Hi my name is " << name << " and my age is " << age << " and i work in " << company << endl;
    }

    // overriding the function from AbtractEmployee
    void AskForPromotion()
    {
        if (age > 30)
        {
            cout << "Yes, " << name << " you will get a promotion" << endl;
        }
        else
        {
            cout << "Sorry, " << name << " you will not be getting promotion this time" << endl;
        }
    }

    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getCompany()
    {
        return company;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void getAge(int age)
    {
        if (age > 17)
            this->age = age;
    }
    void getCompany(string company)
    {
        this->company = company;
    }
};

class Developer : public Employee
{
private:
    string fav_lang;

public:
    Developer(string name, int age, string company, string fav_lang)
        : Employee(name, age, company)
    {
        this->fav_lang = fav_lang;
    }

    void Intro()
    {
        cout << "Hi my name is " << name << " and my age is " << age << " and i like to code in " << fav_lang << endl;
    }
};

int main()
{

    Employee e1("hitesh", 37, "Amity");

    e1.Intro();
    e1.AskForPromotion();

    Developer d("hitesh", 37, "Amity", "C++");
    Employee *e2 = &d;

    e2->Intro();

    return 0;
}
