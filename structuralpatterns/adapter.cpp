#include <iostream>
using namespace std;

// Abstract Target
class Dog {
public:
    virtual ~Dog() = default;
    virtual void performsConversion() const = 0;
};

// Concrete target
class DogFemale: public Dog {
    public:
    virtual void performsConversion() const override {
        cout << "Dog female performs conversion. " << endl;
    }
};

// Abstract Adaptee
class Cat {
public:
    virtual ~Cat() = default;
    virtual void performsConversion() const = 0;
};

// concrete Adaptee
class catFemale: public Cat {
    public:
    virtual void performsConversion() const override {
        cout << "Cat female performs conversion. " << endl;
    }
};

class DogNature {
public:
    void carryOutNature(Dog *dog) {
        cout << "On with the Dog nature!" << endl;
        dog->performsConversion();
    }
};

// Adapter
class ConversionAdapter: public Dog {
    private:
    Cat* cat;
    public:
    ConversionAdapter(Cat* c): cat(c) {};
    virtual void performsConversion() const override {
        cat->performsConversion();
    }
};

// client code
int main() {
    DogFemale* dogFemale = new DogFemale;
    CatFemale* catFemale = new CatFemale;
    DogNature dogNature;
    // dogNature .carryOutNature (catFemale); // Will not compiler of course since the parameter must be of type Dog*.
    ConversionAdapter* adaptedCat = new ConversionAdapter(catFemale); // catFemale has adapted to become a Dog!
    dogNature.carryOutNature(dogFemale);
    dogNature.carryOutNature(adaptedCat); // So now catFemale, in the form of adaptedCat, participates in the dogNature!
    // Note that catFemale is carrying out her own type of nature in dogNature though.
    
    delete adaptedCat; // adaptedCat is not needed anymore
    delete catFemale; // catFemale is not needed anymore
    delete dogFemale; // dogFemale is not needed anymore, too
    return 0;
}