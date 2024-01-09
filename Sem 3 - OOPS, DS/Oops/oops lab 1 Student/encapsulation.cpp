#include <iostream>
#include <string>

// By encapsulating the data members and providing public member functions to access and modify them, 
// we achieve encapsulation in C++. This way, the internal implementation details of the Person class are hidden, 
// and access to the data is controlled and validated through the defined interfaces.

class Person {
private:
    std::string name;
    int age;

public:
    void setName(const std::string& newName) {
        name = newName;
    }

    std::string getName() const {
        return name;
    }

    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        }
    }

    int getAge() const {
        return age;
    }
};

int main() {
    Person person;

    person.setName("John Doe");
    person.setAge(25);

    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;

    return 0;
}
