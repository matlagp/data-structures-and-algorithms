#include <iostream>
#include <stdexcept>

#include "../stacks/array_stack.h"
#include "../stacks/ll_stack.h"

void stack_test(Stack<int> *st) {
    std::cout << "Pushing values 1, 2, 3 to stack...\n";
    st->push(1);
    st->push(2);
    st->push(3);
    st->print();
    std::cout << "Popping a value from stack...\n";
    int x = st->pop();
    std::cout << "Retrieved value: " << x << "\n";
    std::cout << "Now, the stack looks like this:\n";
    st->print();
    std::cout << "Popping another two values: " << st->pop() << ", " << st->pop() << "\n";
    std::cout << "Empty stack:\n";
    st->print();
    try {
        std::cout << "Trying to pop value from an empty stack\n";
        st->pop();
        std::cout << "This should never be printed\n";
    } catch (std::range_error const &e) {
        std::cout << "Catched an exception: " << e.what() << "\n";
    }
}

int main(int argc, char **argv) {
    std::cout << "Presenting a LIFO principle of stack\n";
    std::cout << "Using Array Stack implementation:\n";
    Stack<int> *st = new ArrayStack<int>;
    stack_test(st);
    delete st;
    std::cout << "\n\n";
    std::cout << "Using Linked List Stack implementation:\n";
    st = new ListStack<int>;
    stack_test(st);
    delete st;

    return 0;
}
