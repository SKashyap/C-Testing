#include <bits/stdc++.h>

using namespace std;

/* Define a proxy struct based on actual vector def'n*/
struct VectorProxy {
    int* begin;
    int* end;
    int* cap_end;
};

/*
Example of how to hacky way change the contents of a vector to simulate the memory overrun condition

*/
int main() {
    vector<int> testVector(10, 9);
    cout << &testVector << endl; 
    VectorProxy* ptr = (VectorProxy*)(&testVector);
    cout << ptr->begin << " and " << ptr->end << endl;
    cout << *(ptr->begin) << " and " << *(ptr->end) << endl;
    *(ptr->end) = 4112;
    cout << *(ptr->begin) << " and " << *(ptr->end) << endl;
}
