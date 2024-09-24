# Command Pattern

This pattern was inspired by [Visitor Design Pattern](https://www.youtube.com/watch?v=PEcy1vYHb8A&ab_channel=CppCon).

## When To Use

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
* Waste memory if items vary in size.
* Needs full definition of types, increasing includes.

## Features

...

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

TODO:
- [x] Reference Semantics Implementation
- [x] Reference Semantics Unit Tests
- [ ] Value Semantics Implementation
- [ ] Value Semantics Unit Tests
- [ ] Benchmarks
