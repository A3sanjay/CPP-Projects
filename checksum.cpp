#include <iostream>
#include <climits>
unsigned int add_checksum(unsigned int n);
unsigned int add_checksum(unsigned int n) {

    if (n > 99999999) {
        return 4294967295;
    }
    else {
    unsigned int digits [8] = {n%10, (n/10)%10, (n/100)%10, (n/1000)%10, (n/10000)%10, (n/100000)%10, (n/1000000)%10, (n/10000000)%10};
    for (int x{0}; x <= 7; x = x + 2) {
            digits [x] = 2 * digits [x];
            if (digits [x] >= 10) {
                digits [x] = digits [x] - 9;
            }
        }
    int sum{};
    sum = digits [0] + digits [1] + digits [2] + digits [3] + digits [4] + digits [5] + digits [6] + digits [7];
    unsigned int result{};
    result = (9*sum)%10;
    unsigned int final [9] = {(n/10000000)%10, (n/1000000)%10, (n/100000)%10, (n/10000)%10, (n/1000)%10, (n/100)%10, (n/10)%10, n%10, result};
    unsigned int new_number{};
    new_number = result + 10*final[7] + 100*final[6] + 1000*final[5] + 10000*final[4] + 100000*final[3] + 1000000*final[2] + 10000000*final[1] + 100000000*final[0];
return new_number;    
}
}
void add_checksum(unsigned int array[], std::size_t capacity);
void add_checksum(unsigned int array[], std::size_t capacity) {
    for (int x{0}; x < capacity; x++) {
        if (array[x] > 999999999) {
        array[x] = 4294967295;
        }
        else {
        array[x] = add_checksum(array[x]);
        }
}    
}
bool verify_checksum(unsigned int n);
bool verify_checksum(unsigned int n) {
    if (n < 999999999 && n%10 == add_checksum(n/10)%10) {
        return true;
    }
    else {
        return false;
    }
}
unsigned int remove_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n) {
    if (n <= 999999999 && n%10 == add_checksum(n/10)%10) {
        return n/10;
    }
    else {
        return 4294967295;
    }
}
void remove_checksum(unsigned int array[], std::size_t capacity);
void remove_checksum(unsigned int array[], std::size_t capacity) {
    for (int x{0}; x < capacity; x++) {
        if (array[x] <= 999999999 && array[x]%10 == add_checksum(array[x]/10)%10) {
        array[x] = array[x]/10;
        }
        else {
        array[x] = 4294967295;
        }
}

}
