// KIJO WAS HERE

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
T maxValue(T a, T b) {
    return a > b ? a : b;
}

template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;
public:
    Pair(A first, B second) : first_(first), second_(second) { }

    A getFirst() const  { return first_; }
    B getSecond() const { return second_; }

    void setFirst(A value)  { first_ = value; }
    void setSecond(B value) { second_ = value; }

    void swapValues() {
            A tmp = first_;
            first_ = static_cast<A>(second_);
            second_ = static_cast<B>(tmp);
    }
    
};

template <typename T>
class Box {
private:
    std::vector<T> items_;
    
public:
    void add(const T& item) { items_.push_back(item); }

    int size() const { items_.size(); }

    T get(int index) const {
        if (index < 0 || index > size())
            throw   std::out_of_range("Box index out of range!");
        return items_[index];
    }

    T total() const {
        T sum = T();
        
        for (unsigned short i = 0; i < size(); i++)
            sum += items_[i];    
        return sum;
    }
};

template <typename T>
int describe(const T& value) {
    return 1;
}

template <>
int describe<std::string>(const std::string& value) {
    return value.size() + 2;
}

template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    FixedArray() {
        for (unsigned short i; i < N; i++)
            data_[i] = T();
    }

    int capacity() const { return N; }

    void set(int index, const T& value) {
        if (index < 0 || index > N)
            throw   std::out_of_range("FixedArray index out of range");
        data_[index] = value;
    }

    T at(int index) const {
        if (index < 0 || index > N)
            throw   std::out_of_range("FixedArray index out of range");
        return data_[index];
    }
};

int main() {
    
    std::cout << "=== C++ Templates Lab ===\n";
    
    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";

    return 0;
}
