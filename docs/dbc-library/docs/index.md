---
title: C++ DbC Library Documentation
authors:
    - Diaz Zamboni Javier E.
    - Insfrán Jordán F.
    - Garcia Justo
date: 2024-08-06
---

# C++ Design by Contract Library Documentation

**Garcia Justo - Insfrán Jordán F. - Diaz Zamboni Javier E.**

This library enables you to specify and enforce contracts (preconditions, postconditions, and invariants) in your C++ code, aiming to promote robustness and reliability.

## Table of Contents

- [Installation](#installation)
- [Basic Usage](#basic-usage)
- [Features](#features)
    - [Preconditions](#preconditions)
    - [Postcondition](#postconditions)
    - [Invariants](#invariants)
- [API-Reference](apireference.md)
- [License](license.md)

## Installation

To integrate the DbC library into your C++ project, follow these installation steps:

- Clone the repository from [GitHub](https://github.com/FIUNER-LICA/biblioteca-dbc-cpp)

```bash
git clone https://github.com/FIUNER-LICA/biblioteca-dbc-cpp.git
```

- Include the `contract.h` header file in your project.

```cpp
#include "contract.h"
```

- Ensure your compiler supports C++11 or later.

## Basic Usage

Here's a basic example to get you started with the DbC library using pre and post conditions as functions:

```cpp
#include <iostream>
#include "contract.h"

using namespace contract;

void example_function(int x) {
    precondition(x > 0, "x must be greater than 0");

    // Function logic here

    postcondition(x < 100, "x should be less than 100");
}

int main() {
    try {
        example_function(50);
    } catch (const violation_error& e) {
        std::cerr << "Contract violation: " << e.what() << std::endl;
    }

    return 0;
}
```

## Features

### Preconditions
Preconditions specify conditions that must be true at the entry of a function or method. Here's how to use preconditions effectively:

- **Function Syntax**:
    - As function: `precondition(expression, message)`
    - As class: `precond(expression, message)`
    - As macro: `REQUIRE(expression, message)`

Example:
```cpp
void example_function(int x) {
    precond(x > 0, "x must be greater than 0"); // As class
    
    precondition(x > 0, "x must be greater than 0"); // As function
    
    REQUIRE(x > 0, "x must be greater than 0"); // As macro
    
    // Function logic.
}
```

### Postconditions
Postconditions specify conditions that must be true at the exit of a function or method. They validate the expected outcomes and state changes after the execution of a routine. Here's how to use postconditions effectively:

- **Function Syntax**:
    - As function: `postcondition(expression, message)`
    - As class: `postcond(expression, message)`
    - As macro: `ENSURE(expression, message)`

Example:
```cpp
void example_function(int x) {    
    //Function logic.   
    
    postcondition(x < 100, "x should be less than 100"); // As function

    postcond(x < 100, "x should be less than 100"); // As class
    
    ENSURE(x < 100, "x should be less than 100"); // As macro
}
```

### Invariants
Invariants specify conditions that must be true for a class or object, ensuring its integrity throughout its lifecycle. Here's how to use invariants effectively:


