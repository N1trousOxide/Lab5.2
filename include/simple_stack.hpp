//Copyright 2020 <ZaitsevGames & N1trousOxide>

#ifndef INCLUDE_SIMPLE_STACK_HPP_
#define INCLUDE_SIMPLE_STACK_HPP_
#include <memory>
#include <iostream>
#include <utility>
template <typename T>
struct test1{
    T value;
    test1<T> *prev;
};
template <typename T>
class simple_stack
{
private:
    test1<T> *abc;
public:
    simple_stack();
    ~simple_stack();
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    void pop();
    simple_stack(simple_stack &&stack2);
    simple_stack<T>& operator=(simple_stack<T>&& stack);
};

template<typename T>
simple_stack<T>::simple_stack() {
    abc = nullptr;
}

template <typename T>
simple_stack<T>::simple_stack(simple_stack&& st) {
    std::swap(*abc, *st.abc);
}

template <typename T>
simple_stack<T>& simple_stack<T>::operator=(simple_stack<T>&& st) {
    std::swap(*abc, *st.abc);

    return *this;
}

template<typename T>
simple_stack<T>::~simple_stack(){
    delete abc;
}


template <typename T>
void simple_stack<T>::pop() {
    if (!abc) {
        throw std::logic_error("No elements in stack");
    } else {
        abc = abc->prev;
    }
}

template <typename T>
const T& simple_stack<T>::head() const{
    if (!abc) {
        throw std::logic_error("No elements in stack");
    } else {
        return abc->value;
    }
}

template <typename T>
void simple_stack<T>::push(const T& value) {
    auto item = abc;
    abc = new test1<T>{value, item};
}

template <typename T>
void simple_stack<T>::push(T&& value) {
    auto item = abc;
    abc = new test1<T>{std::forward<T>(value), item};
}

#endif // INCLUDE_SIMPLE_STACK_HPP_
