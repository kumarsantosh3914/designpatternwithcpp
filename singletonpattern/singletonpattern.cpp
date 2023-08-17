/*
static StringSingleton &Instance() {
    // This line only runs once, thus creating the only instance in existence
    static std::auto_ptr<StringSingleton> instance( new StringSingleton);
    // dereferencing the variable here, saves the caller from having to use
    // the arrow operator, and removes temptation to try and delete the returned instance.
    return *instance; // always returns the same instance.
}
*/

#include <iostream>
using namespace std;

class StringSingleton {
public:
    // Some accessor functions for the class, itself
    string GetString() const{
        return mString;
    }
    void SetString(const string &newStr) {
        mString = newStr;
    }

    // The magic function, which allows access to the class from anywhere
    // To get the value of the instance of the class, call:
    // StringSingleton &Instance().GetString();
    static StringSingleton &Instance() {
        // This line only runs once, thus creating the only instance in existence
        static auto_ptr<StringSingleton> instance( new StringSingleton );
        // dereferencing the variable here, saves the caller from having to use 
        // the arrow operator, and removes temptation to try and delete the
        // returned instance.
        return *instance;
    }

private:
    // we need to make some given functions private to finish the definition of the singleton
    StringSingleton() {}; // default constructor available only to members or friends of the class

    // Note that the next two functions are not given bodies, thus any attempt
    // to call them implicity will return as compiler errors. This prevents
    // accidental copying of the only instance of the class.
    StringSingleton(const StringSingleton &old); // disallow copy constructor
    const StringSingleton &operator = (const StringSingleton &old); // disallow assignment operator
    // Note that although this should be allowed,
    // some compilers may not implement private destructors
    // This prevents others from deleting our one single instance,  which was otherwise created on the heap
    ~StringSingleton() {};
private:
    string mString;
};