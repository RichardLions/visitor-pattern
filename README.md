# Visitor Pattern

This pattern was inspired by [Visitor Design Pattern](https://www.youtube.com/watch?v=PEcy1vYHb8A&ab_channel=CppCon).

## When To Use

This pattern decouples operations from types. Allowing for easy addition of new operations.

General:
* This pattern is best for adding operations over adding types.
* Restricts the operations to the public interface of the types.

Reference Semantics:
* Virtual function calls.
* Fragmented memory on the heap.
* Can use forward declarations of types.

Value Semantics:
* No Virtual function calls.
* Continuous memory.
* More natural to use semantic types.
* Wastes memory if types vary in size.
* Needs full definition of types, may increase include dependencies.

## Features

### Reference Semantics

Create a Type:
```cpp
class Type
{
public:
    virtual ~Type() = default;
    virtual void Accept(const TypeVisitor& visitor) = 0;
};

class TypeA final : public Type
{
public:
    void Accept(const TypeVisitor& visitor) override { visitor.Visit(*this); } 
};
```

Create an Operation:
```cpp
class TypeVisitor
{
public:
    virtual ~TypeVisitor() = default;
    virtual void Visit(TypeA& type) const = 0;
};

class TypeOperationA final : public TypeVisitor
{
public:
    void Visit(TypeA& type) const override {}
};
```

Call an Operation:
```cpp
using Types = std::vector<std::unique_ptr<Type>>;

Types types{};
types.push_back(std::make_unique<TypeA>());
for(const std::unique_ptr<Type>& type : types)
{
    type->Accept(TypeOperationA{});
}
```

### Value Semantics

Creating a Type, no inheritance:
```cpp
class TypeA
{
public:
};
```

Create an Operation, no inheritance:
```cpp
class TypeOperationA
{
public:
    static void Visit(Type& type) { std::visit(TypeOperationA{}, type); }
    void operator()(TypeA& type) const {}
};
```

Call an Operation:
```cpp
using Type = std::variant<TypeA, ...>;
using Types = std::vector<Type>;

Types types{};
types.emplace_back(TypeA{});
for(Type& type : types)
{
    TypeOperationA::Visit(type);
}
```

## Setup

This repository uses the .sln/.proj files created by Visual Studio 2022 Community Edition.
Using MSVC compiler, Preview version(C++23 Preview). 

### Catch2
The examples for how to use the pattern are written as Unit Tests.

Launching the program in Debug or Release will run the Unit Tests.

Alternative:
Installing the Test Adapter for Catch2 Visual Studio extension enables running the Unit Tests via the Test Explorer Window. Setup the Test Explorer to use the project's .runsettings file.

### vcpkg
This repository uses vcpkg in manifest mode for it's dependencies. To interact with vcpkg, open a Developer PowerShell (View -> Terminal).

To setup vcpkg, install it via the Visual Studio installer. To enable/disable it run these commands from the Developer PowerShell:
```
vcpkg integrate install
vcpkg integrate remove
```

To add additional dependencies run:
```
vcpkg add port [dependency name]
```

To update the version of a dependency modify the overrides section of vcpkg.json. 

To create a clean vcpkg.json and vcpkg-configuration.json file run:
```
vcpkg new --application
```

### TODO
- [x] Reference Semantics Implementation
- [x] Reference Semantics Unit Tests
- [x] Value Semantics Implementation
- [x] Value Semantics Unit Tests
- [x] Benchmarks
