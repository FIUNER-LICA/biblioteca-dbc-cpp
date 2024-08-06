---
title: C++ DbC Library Documentation
authors:
    - Diaz Zamboni Javier E.
    - Insfrán Jordán F.
    - Garcia Justo
date: 2024-08-06
---

## API Reference

### Classes

#### `contract::violation_error`

Represents an exception thrown when a contract violation occurs.

##### Constructor
```cpp
violation_error(std::string msg);
```
Constructs a `violation_error` object with the specified error message.

##### Member Functions
```cpp
virtual const char* what() const noexcept;
```

Returns a string describing the exception.

----

#### `contract::Invariant`

Manages class invariants and performs invariant checks.

##### Constructor
```cpp
Invariant();
```

##### Member Functions
```cpp
void operator()(bool logix_exp, const std::string msg);
```

Overloaded function call operator to evaluate and enforce class invariants.

```cpp
void add_invariant(std::function<bool()> p_lambda);
```

Adds a new invariant to the collection.


```cpp
void check_invariant();
```

Check all invariants and throws `violation_error` if any invariant fails.

---

#### `contract::Contract`

Handles logical expressions and throws exceptions for contract violations.

##### Member Functions

```cpp
void operator()(bool logic_exp, const std::string msg = "");
```

Evaluates a logical expression and throws an exception with a specified message if the expression is false.

### Functions

#### `contract::precondition`
Evaluates preconditions for a function or method.

```cpp
void precondition(const bool logic_exp, const std::string msg = "");
```

Throws `violation_error` if `logic_exp` is false, with an optional error message.

--- 

#### `contract::postcondition`

Evaluates postconditions for a function or method.

```cpp
void postcondition(const bool logic_exp, const std::string msg = "");
```

Throws `violation_error` if `logic_exp` is false, with an optionar error message.

### Macros
Coming soon...

#### `REQUIRE`

#### `ENSURE`

#### `ASSURE`

#### `INVARIANT`


