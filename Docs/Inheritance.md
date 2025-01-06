
In C++, inheritance is a fundamental concept in object-oriented programming (OOP) that allows a new class to inherit properties and behaviors from an existing class. There are three main types of inheritance in C++: public, protected, and private. These types determine the access levels of the base class members in the derived class.

Public Inheritance:

- In public inheritance, the public members of the base class become public members of the derived class, and the protected members of the base class become protected members of the derived class.
- The private members of the base class are not accessible in the derived class.
- Public inheritance represents an "is-a" relationship, indicating that the derived class is a specialized 

```
version of the base class.
Copy code
class Base {
public:
    int publicMember;
    void publicFunction() {
        // ...
    }
protected:
    int protectedMember;
private:
    int privateMember;
};

class Derived : public Base {
    // publicMember is public
    // protectedMember is protected
    // privateMember is not accessible
};
```
### Protected Inheritance:

- In protected inheritance, the public and protected members of the base class become protected members of the derived class.
- The private members of the base class are not accessible in the derived class.
- Protected inheritance is less common and is used when you want to restrict external access to the base class members more than with public inheritance.
```
class Derived : protected Base {
    // publicMember is protected
    // protectedMember is protected
    // privateMember is not accessible
};
```

### Private Inheritance:
- In private inheritance, both the public and protected members of the base class become private members of the derived class.
- The private members of the base class are not accessible in the derived class.
- Private inheritance is often used when you want to implement a "has-a" relationship rather than an "is-a" relationship, and you want to encapsulate the implementation details of the base class within the derived class.

```
class Derived : private Base {
    // publicMember is private
    // protectedMember is private
    // privateMember is not accessible
};
```