//Copyright 2020 <ZaitsevGames & N1trousOxide>

#include <simple_stack.hpp>
#include <stack.hpp>
#include <any>

int main(){
        stack <std::any> stack;
        stack.push(1);
        stack.push(20);
        stack.push_emplace<std::any>(2, 3, 5, 8, "abc", 4.2);
        std::cout << std::any_cast<double>(stack.head());
    return 0;
}
