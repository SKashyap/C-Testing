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
struct mydata {
    int* ptr;
    int count;
    mydata(int* i): ptr(i), count(1){}
    ~mydata() {
        delete ptr;
        ptr = nullptr;
    }
};

class myshared_ptr {
    private:
    myshared_ptr() {}
    mydata* pointed; // remains same 
    myshared_ptr(int* p) {
        pointed = new mydata(p);
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
    static myshared_ptr make_shared(int val) {
        return myshared_ptr(new int(val));
    }
};
/*
shared ptr imple
*/
int main() {
    myshared_ptr instance = myshared_ptr::make_shared(7);
    cout << instance.get() << endl;
    {
    myshared_ptr another_copy(instance);
    cout << another_copy.get() << endl;
    }
    cout << instance.get() << endl;
}
