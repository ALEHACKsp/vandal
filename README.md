⚡ Vandal is an in-development, library independent, menu framework written in C++17, currently only coming with direct rendering support for DirectX 9.

# Performance
### CodeFactor

- [![CodeFactor](https://www.codefactor.io/repository/github/cristeigabriel/vandal/badge)](https://www.codefactor.io/repository/github/cristeigabriel/vandal)

### Codacy
- Pending...

# Ideals
- Vandal aims to be an easy to use and implement, performant high level menu framework meant to give users an intuitive and enjoyable experience,
- Vandal also is written to be independent to any library but the STL and render dependencies, often asking for literals to not lead to future usage,
- Vandal is also meant to be a library that's easy to learn from, and easy to contribute to, thus the motivation for the immediate mode idea, making it easy to sort render order, and also making it easy to implement features that'd be problematic on a retained mode scope, such as state-based dependencies.

# Direct development toolchain
The toolchain used by the Vandal creator, where code is tested and reviewed is as follows:
- MSVC Compiler (x86, Language Standard: std:++latest / std::c++17), 
- Visual Studio 2019 IDE. 

# Implementation
To implement Vandal to your software, you must first:
- Link DX9 static libraries to your software (regardless of solutioning system),
- Provide an actual pointer to our D3D9 device (check: Vandal::Handling::Initialize),
- Initialize a styling object and set values as you wish,
- Call a constructor to whatever you may need.


In the future:
- ...

# Features
Vandal is currently very barebones, and in extremely early development. There is currently no control whatsoever, but constructors for:
- Forms,
- Widgets,
- UI,
- Styling,

and for those, you're able to customize them with:
- Borders, with 3 thickness modes:
  - None (0px),
  - Small (1px),
  - Thick (4px),
    - And each can be given a specific color,
    
such as every specific form applet.

# TO-DO
- Controls,
- x11 support [PRIORITY],
- Vulakn support [PRIORITY],
- OpenGL support [PRIORITY].

# Contribution Guidelines
We require that, before making pull requests to Vandal, you:
- Adapt your code to the given clang-format settings,
- Adapt your code to the advised code style (read below),
- Test your code to see if there will be any issues in usage,
- Comment your code to be IntelliSense compatible (this is preferably to be done within headers at a function's definition).

[(For the latter you can use Visual Studio extensions such as CppTripleSlash).](https://marketplace.visualstudio.com/items?itemName=tcbhat.CppTripleSlash-xmldoccommentsforc)

# Code Style
Vandal is written in Pascal Case to make it easy to find and read functions by their name. Vandal doesn't make use of Hungarian Notation, or stuff alike, it is only meant to be intuitive.

# Licensing
There is currently no licensing for Vandal. 

# Credits
@cristeigabriel - Main Vandal developer
