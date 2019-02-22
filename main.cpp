#include <iostream>


// functions
template<typename T>
struct IsPtr
{
    static constexpr bool apply = false;
};

// pattern matching
template<typename T>
struct IsPtr<T *>
{
    static constexpr bool apply = true;
};

// lists
template<typename... Args>
struct Assert
{
    static constexpr bool value = true;
};

template <typename ... Args>
struct count {

};

template<typename Head, typename... Tail>
struct count<Head, Tail...> {
    static const int value = 1 + count<Tail...>::value;
};

template<>
struct count<> {
    static const int value = 0;
};


int main()
{
    static_assert(!IsPtr<int>::apply, "int should be an integral type");
    static_assert(IsPtr<int *>::apply, "int* should be a pointer type");

    static_assert(Assert<>::value, "Assert of nothing");
    static_assert(Assert<int>::value, "Assert of one random type");
    static_assert(Assert<int, float *>::value, "Assert two random type");

    static_assert(count<int, int, int>::value == 3, "template count doens't work");
    return 0;
}