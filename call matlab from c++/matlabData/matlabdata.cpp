#include "MatlabEngine.hpp"
#include "MatlabDataArray.hpp"
#include <iostream>
void callFevalgcd() {

    // Pass vector containing MATLAB data array scalar
    using namespace matlab::engine;

    // Start MATLAB engine synchronously
    std::unique_ptr<MATLABEngine> matlabPtr = startMATLAB();

    // Create MATLAB data array factory
    matlab::data::ArrayFactory factory;

    // Pass vector containing 2 scalar args in vector    
    std::vector<matlab::data::Array> args({
        factory.createArray<int16_t>({2,2},  {-5, 17, 10, 0}),
        factory.createArray<int16_t>({2,2}, {-15, 3, 100, 0}) });

    // Call MATLAB function and return result
    matlab::data::TypedArray<int16_t> result = matlabPtr->feval(u"gcd", args);
    int16_t v = result[0][1];
    std::cout << "Result: " << v << std::endl;
}

int main() {
    callFevalgcd();
    return 0;
}