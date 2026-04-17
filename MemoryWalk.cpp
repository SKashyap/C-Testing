/* 
1. Printing the "Control" Object Layout (Stack)
We can use a pointer-to-byte (uint8_t*) to walk through the internal memory of the vector object itself. This reveals how the pointers are stored.
*/


#include <iostream>
#include <vector>
#include <iomanip>

void print_vector_object_layout(const std::vector<int>& v) {
    const uint8_t* byte_ptr = reinterpret_cast<const uint8_t*>(&v);
    
    std::cout << "--- Vector Object Layout (Stack) ---" << std::endl;
    std::cout << "Address of Vector Object: " << (void*)&v << std::endl;
    std::cout << "Size of Vector Object:    " << sizeof(v) << " bytes" << std::endl;

    for (size_t i = 0; i < sizeof(v); ++i) {
        // Print each byte in hex
        std::cout << std::setw(2) << std::setfill('0') << std::hex 
                  << (int)byte_ptr[i] << " ";
        
        // Every 8 bytes, print a newline for readability (assuming 64-bit pointers)
        if ((i + 1) % 8 == 0) std::cout << std::endl;
    }
    std::cout << std::dec << std::endl;
}
