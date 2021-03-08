#include "Handler.h"

#include <iostream>
#include <memory>
#include <vector>

// Every handler is given a chance to 'handle' the object.
// - No object is obligated to do anything
// - The handler doesn't need to be pass by value
int main() {
    using pHandler = std::unique_ptr<Handler>;
    std::vector<pHandler> handlers;
    handlers.push_back(pHandler(new  ErrorHandler));
    handlers.push_back(pHandler(new  FibonacciHandler));
    handlers.push_back(pHandler(new  ErrorHandler {2, 5}));
    handlers.push_back(pHandler(new  FibonacciHandler));
    handlers.push_back(pHandler(new  FibonacciHandler));
    handlers.push_back(pHandler(new  ErrorHandler {3, 21}));

    int i = 6;
    for (const auto& h: handlers) {
        h->request(i);
    }

    return 0;
}

