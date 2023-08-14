#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Product
class Pizza {
public:
    // Setters for pizza attributes
    void setDough(const string &dough) {
        m_dough = dough;
    }
    void setSauce(const string &sauce) {
        m_sauce = sauce;
    }
    void setTopping(const string &topping) {
        m_topping = topping;
    }

    // Display pizza details
    void open() const {
        cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and " << m_topping << " topping. Mmm." << endl;
    }

private:
    string m_dough;
    string m_sauce;
    string m_topping;
};

// Abstract Builder
class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {};

    // Get the constructed pizza
    Pizza * getPizza() {
        return m_pizza.get();
    }

    // Create a new pizza product
    void createNewPizzaProduct() {
        m_pizza = make_unique<Pizza>();
    }

    // Abstract methods to build pizza attributes
    virtual void builderDough() = 0;
    virtual void builderSauce() = 0;
    virtual void builderTopping() = 0;

protected:
    unique_ptr<Pizza> m_pizza;
};

// ######################################################################
// Concrete Builder: HawaiianPizzaBuilder
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    virtual ~HawaiianPizzaBuilder() {};

    virtual void builderDough() {
        m_pizza->setDough("cross");
    }
    virtual void builderSauce() {
        m_pizza->setSauce("mild");
    }
    virtual void builderTopping() {
        m_pizza->setTopping("ham+pineapple");
    }
};

// Concrete Builder: SpicyPizzaBuilder
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    virtual ~SpicyPizzaBuilder() {};

    virtual void builderDough() {
        m_pizza->setDough("pan baked");
    }
    virtual void builderSauce() {
        m_pizza->setSauce("hot");
    }
    virtual void builderTopping() {
        m_pizza->setTopping("pepperoni+salami");
    }
};

// #######################################################################
// Director: Cook
class Cook {
public:
    // Open and display the pizza
    void openPizza() {
        m_pizzaBuilder->getPizza()->open();
    }

    // Make a pizza using a specified builder
    void makePizza(PizzaBuilder *pb) {
        m_pizzaBuilder = pb;
        m_pizzaBuilder->createNewPizzaProduct();
        m_pizzaBuilder->builderDough();
        m_pizzaBuilder->builderSauce();
        m_pizzaBuilder->builderTopping();
    }

private:
    PizzaBuilder *m_pizzaBuilder;
};

// Main function
int main() {
    Cook cook;
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    SpicyPizzaBuilder spicyPizzaBuilder;

    // Make a Hawaiian pizza
    cook.makePizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    // Make a Spicy pizza
    cook.makePizza(&spicyPizzaBuilder);
    cook.openPizza();
}
