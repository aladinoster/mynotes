#include <iostream>
#include <cstring>
#include <memory>

#define LOG(x) std::cout << x << std::endl;

class Entity
{
public:
    Entity() { LOG("Created Entity"); }
    ~Entity() { LOG("Destruct Entity"); }
    void Print() {}
};

int main()
{
    /*
        a    b 
        |    |
        \   /
         \ /
         c 
        
    If you delete a pointer then b points to free memory
    */
    {
        // Unique / if I delete one all dies
        LOG("Entity 1");
        std::unique_ptr<Entity> entity(new Entity()); // because the unique_ptr has explicit constructors

        //Preferred way
        LOG("Entity 2");
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>(); // Safer in memory
        entity->Print();
    }
    {
        // Create ref counter to control amount of instances of pointers, when destructed references are reduced by one
        LOG("Shared pointers")
        std::shared_ptr<Entity> e0; //
        {

            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            std::weak_ptr<Entity> weakEntity = sharedEntity; // Copy the pointer but does not increase ref count
            e0 = sharedEntity;
        }
    }
    {
        std::weak_ptr<Entity> e0;
        // You can use  a weak pointer to a shared pointer, once deleted this pointer is safe you can ask I am still existing or not.
        {
            // LOG
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
        }
        if (e0.expired())
        {
            LOG("I have been deleted :(")
        }
    }

    std::cin.get();
}
