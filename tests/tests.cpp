#include <iostream>
#include "../include/matrix.h"
#include "string"

int main() {
    std::cout << "Test 1: ()" << std::endl;
    try {
        matrix m(5,4);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 2: ()" << std::endl;
    try {
        matrix m(0,4);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: -2") != 0)  << std::endl;
    }
    std::cout << "Test 3: ()" << std::endl;
    try {
        matrix m(-1,4);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: -2") != 0)  << std::endl;
    }
    std::cout << "Test 4: ()" << std::endl;
    try {
        matrix m(123);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 5: ()" << std::endl;
    try {
        double buf[5] = {1,2,3,4,5};
        matrix m(buf, 4);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 6: ()" << std::endl;
    try {
        double buf[5] = {1,2,3,4,5};
        matrix m(buf, 5);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 7: ()" << std::endl;
    try {
        double buf[5] = {1,2,3,4,5};
        matrix m(buf, 6);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 8: ()" << std::endl;
    try {
        char buf[14] = "{{1,2,3,4,5}}";
        matrix m(buf);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 9: ()" << std::endl;
    try {
        char buf[22] = "{{1},{2},{3},{4},{5}}";
        matrix m(buf);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 10: ()" << std::endl;
    try {
        char buf[25] = "{{1},{2},{3},{4},{5, 6}}";
        matrix m(buf);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 3") != 0)  << std::endl;
    }
    std::cout << "Test 11: ()" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 12: ()" << std::endl;
    try {
        char buf[27] = "{{1,2,3},{lalala},{7,8,9}}";
        matrix m(buf);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 3") != 0)  << std::endl;
    }
    std::cout << "Test 13: identity" << std::endl;
    try {
        matrix m = matrix::identity(5);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 14: identity" << std::endl;
    try {
        matrix m = matrix::identity(0);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 8") != 0)  << std::endl;
    }
    std::cout << "Test 15: diagonal" << std::endl;
    try {
        double buf[5] = {1,2,3,4,5};
        matrix m = matrix::diagonal(buf, 4);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 16: diagonal" << std::endl;
    try {
        double buf[5] = {1,2,3,4,5};
        matrix m = matrix::diagonal(buf, 5);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 17: diagonal" << std::endl;
    try {
        double buf[5] = {1,2,3,4,5};
        matrix m = matrix::diagonal(buf, 6);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 10") != 0)  << std::endl;
    }
    char buf[18] = "{{1,2,3},{4,5,6}}";
    matrix x(buf);
    std::cout << "Test 18: rows" << std::endl;
    try {
        int i = x.rows();
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 19: columns" << std::endl;
    try {
        int i = x.columns();
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 20: set(1,2,10)" << std::endl;
    try {
        x.set(1,2,10);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 21: set(100,-1,10)" << std::endl;
    try {
        x.set(100,-1,10);
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 12") != 0)  << std::endl;
    }
    std::cout << "Test 22: [0]" << std::endl;
    try {
        matrix m = x[0];
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 23: [1]" << std::endl;
    try {
        matrix m = x[1];
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 24: [3]" << std::endl;
    try {
        matrix m = x[3];
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 14") != 0)  << std::endl;
    }
    std::cout << "Test 25: *=" << std::endl;
    try {
        x *= 6;
        std::cout << "True" << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 26: [0][0]" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        matrix n = m[0][0];
        std::cout << n << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 27: +" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{1,1,1},{1,1,1},{1,1,1}}";
        matrix n(buf2);
        matrix sum = n + m;
        std::cout << sum << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 28: +=" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{1,1,1},{1,1,1},{1,1,1}}";
        matrix sum(buf2);
        sum += m;
        std::cout << sum << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 29: -" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{1,1,1},{1,1,1},{1,1,1}}";
        matrix n(buf2);
        matrix sum = m - n;
        std::cout << sum << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 30: -=" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{1,1,1},{1,1,1},{1,1,1}}";
        matrix sum(buf2);
        m -= sum;
        std::cout << m << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 31: -matrix" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        matrix n = -m;
        std::cout << n << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 32: ==" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        matrix n(buf);
        std::cout << std::boolalpha << (m==n) << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 33: ==" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{3,4,3},{4,5,6},{7,8,9}}";
        matrix n(buf2);
        std::cout << std::boolalpha << (m==n) << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 34: !=" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        matrix n(buf);
        std::cout << std::boolalpha << (m!=n) << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 35: !=" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{3,4,3},{4,5,6},{7,8,9}}";
        matrix n(buf2);
        std::cout << std::boolalpha << (m!=n) << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 36: matrix * matrix" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{3,4,3},{4,5,6},{7,8,9}}";
        matrix n(buf2);
        matrix pr = m * n;
        std::cout << pr << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 37: *= matrix" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{3,4,3},{4,5,6},{7,8,9}}";
        matrix n(buf2);
        m *= n;
        std::cout << m << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 38: |" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{3,4,3},{4,5,6},{7,8,9}}";
        matrix n(buf2);
        matrix sum = m | n;
        std::cout << sum << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 39: /" << std::endl;
    try {
        char buf[26] = "{{1,2,3},{4,5,6},{7,8,9}}";
        matrix m(buf);
        char buf2[26] = "{{3,4,3},{4,5,6},{7,8,9}}";
        matrix n(buf2);
        matrix sum = m / n;
        std::cout << sum << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Test 40: /" << std::endl;
    try {
        char buf[26] = "{{1}}";
        matrix m(buf);
        char buf2[26] = "{{3,2}}";
        matrix n(buf2);
        matrix sum = m / n;
        std::cout << sum << std::endl;
    }
    catch (error_catcher error) {
        std::cerr << "TESTED: " << std::boolalpha << (bool)(strstr(error.what(), "Error code: 29") != 0)  << std::endl;
    }
    std::cout << "Testing completed." << std::endl;
    return 0;
}
