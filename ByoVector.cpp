#include <bits/stdc++.h>

using namespace std;



/*
std::vector impl
- RAII obj for dynamically increasing arrays
*/

/*
std::vector Interface : 
- constructor : allocates array of some fixed size
- destructor : deallocates, or destroys them. 
- push_back() : add element
- resize()
- pop_back()
- push_front()

data:
- contant : single allocation size
- Current size of array
- current array pointer. 

VEctor : dynamic contiguos array 
deque : non-continguos array blocks tied together to grow dynamically
*/

class myvector {
    const size_t blockSz;
    size_t currSize;

    int* currPtr; // ptr to first
    int* lastPtr; // ptr to last array element + 1
    size_t occupiedSz;

    public:
    myvector(int count): blockSz(10), occupiedSz(count){
        if (blockSz > count) {
            currPtr = new int[blockSz]; // alocate block size
            currSize = blockSz;
        } else {
            auto blockCnt = (count/blockSz) + 1;
            currPtr = new int[blockCnt*blockSz];
            currSize = blockCnt*blockSz;
        }
        lastPtr = (currPtr+count) + 1;
        occupiedSz = count;
    }

    void push_back(int val) {
        if (occupiedSz < currSize) {
            *lastPtr = val;
            lastPtr++;
        } else {
            resize();
            *lastPtr = val;
            lastPtr++;
        }
    }

    void resize() {
        auto newAlloc = new int[currSize + blockSz];
        // copt from 
        for (int i =0; i < occupiedSz; i++) {
            newAlloc[i] = *(currPtr+i);
        }

        delete[] currPtr;
        currPtr = newAlloc;
    }

};
int main() {
    stringstream ss("fzx, max , lax");
    for (string line; std::getline(ss, line, ','); ) {
        cout << line << endl;
    }
}
