#include <bits/stdc++.h>

using namespace std;

// multiple shared_ptr will point to same data block 
// data block allocated once. 

/*
define shared_ptr interface :
sp {
 ptr to datablock. 
 // avoid normal construction -> no datablock created. 
 private constructor
 get() { return value}
 get_raw() { return raw ptr}
 copy ( count++)
 descructor (count-- ; when 0 , delete datablock)
}

sp static create() {
 // create datablock 
 // create sp. set ptr to datablock
}
*/
//data block
template<typename T>
struct mydata {
    T* ptr;
    int count;
    mydata(T* i): ptr(i), count(1){}
    ~mydata() {
        delete ptr;
        ptr = nullptr;
    }
};

template<typename T>
class myshared_ptr {
    private:
    myshared_ptr() {}
    mydata<T>* pointed; // remains same 
    myshared_ptr(T* p) {
        pointed = new mydata<T>(p);
    }
    public:
    void operator=(myshared_ptr& in) {
        pointed = in.pointed; 
        pointed->count++;
    }
    myshared_ptr(myshared_ptr& in) {
        pointed = in.pointed; 
        pointed->count++;
    }
    ~myshared_ptr() {
        pointed->count--;
        if (pointed->count == 0) {
            cout << "deleting " << endl;
            delete pointed->ptr;
            pointed->ptr = nullptr;
            pointed = nullptr;
        }
    }

    int get() {
        cout << "count" << pointed->count << endl;
        return *(pointed->ptr);
    }
    static myshared_ptr<T> make_shared(T val) {
        return myshared_ptr<T>(new T(val));
    }
};
/*
shared ptr imple
*/
int main() {
    myshared_ptr<int> instance = myshared_ptr<int>::make_shared((int)7);
    cout << instance.get() << endl;
    {
    myshared_ptr another_copy(instance);
    cout << another_copy.get() << endl;
    }
    cout << instance.get() << endl;
}
