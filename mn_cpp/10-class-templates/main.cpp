#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

public:
    Animal(const std::string &name) : m_name(name) {}
    std::string GetName() { return m_name; }
    virtual std::string MakeSound() = 0;
};

class Dog : public Animal
{
public:
    Dog(const std::string &name) : Animal(name) {}

    void operator=(const Dog &D) { m_name = D.m_name; }

    std::string MakeSound() override { return "woof-woof"; }
};

class Cat : public Animal
{
public:
    Cat(const std::string &name) : Animal(name) {}

    void operator=(const Cat &D) { m_name = D.m_name; }

    std::string MakeSound() override { return "meow-meow"; }
};

template <typename T>
class AnimalTemplate
{
private:
    T m_animal;

public:
    AnimalTemplate(const T &animal) : m_animal(animal) {}
    void GetNameAndMakeSound()
    {
        std::cout << m_animal.GetName() << " goes ";
        std::cout << m_animal.MakeSound() << std::endl;
    }
};

int main()
{
    Dog dog = Dog("Bulldog");
    AnimalTemplate<Dog> dogTemplate(dog);
    dogTemplate.GetNameAndMakeSound();

    Cat cat = Cat("Persian Cat");
    AnimalTemplate<Cat> catTemplate(cat);
    catTemplate.GetNameAndMakeSound();

    std::cin.get();
}