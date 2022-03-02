# VissimApi.DriverModel
Modernized Vissim API Framework using C++ 20 and Meta Template Programming.

Vissim's DLL-based APIs, including DriverModel API and Signal Control API, feature a C-style design where various data-tags are dispatched during runtime inside a big (and boring) switch-case structure. 
- This certainly provides efficiency since switch-case structure will be optimized by the compiler as a jump table in machine code. 
- Also the C-style API is very flexible, by virtue of using primitive data types only without any dependencies except system runtimes.

Howerver, there are some nuances with C-style design:

- User code may end up spaghetti-like, mixing boiler-plate interface code with the code that implements the core driver behavior logic.
- User code may ultimately become hard to extend and maintain. The big switch-case structure has to be re-visited again and again for editing, adding, or modifying - clearly a violation of SOLID rule, i.e., *"open for extension, closed for modification"*. 
   
The framework herein provides a different design and implementation - modular, structured, while still computationally efficient, thanks to the modern C++ and its meta template programming. Specifically, this framework features:

- *Seperaton of Concerns* 
  - **Interface**. This part is for interfacing with the Vissim simulator host. it includes the DLL export functions with boiler-plate implementation that a user probably would never need to touch.  
  - **Logic**. This is where the user implements customized driver behavior logic. It is separated from the rest of the framework. A dispatched event will end up somewhere here.
  - **Event**. This part of code is where a **compile-time** static hash gets constructed. This compile-time hash allows us to get rid of the boring switch-case structure, dispatching tagged data types more inteligently.  Again, the hash is a **compile-time** structure, with almost zero extra overhead compared to the use of switch-case structure. Importantly, this new dispatching mechnism helps writing structured, scalable, and maintainable code.
  - **Meta Classes**. These are the low-level C++ template classes facilitating the framework. They are fairly complex but worthwhile to delve into them if you are interested.
  
- *Open for extension, close for modification*
  - The boring switch-case structure is replaced by a compile-time hash-table, with *almost* no additional performance overhead. The hash is constructed during compile time, and is optimized because both the keys (i.e., the event types) and values (i.e., the event callbacks) are known at compile time thus can have static storages. This makes the key-value retrieval during runtime *almost* as fast as accessing global variable.
  - Template specialization enables auto-registration of events during compile time, transparently without involing user code
 
 - *Single Responsibility*
   - User logic is cleanly isolated, and can be extended and maintained easily in a much cleaner way.


# Usage
Details to be added.

# Example
To be added.

# Compiler
The code requries a C++ compiler that supports C++/20. The latest MSVC compiler recommended. 

# Platform
Windows only. But you can customize the interface part of the code to make it work on Linux since this framework uses standard C++ only.

# Acknowledgement
This framework partly uses meta_enum ([Tobias Widlund](https://github.com/therocode/meta_enum)) and semi-map ([Fabian Renn-Giles](https://github.com/hogliux/semimap)). They are customized for this VissimApi.DriverModel framework. Special thanks to Tobias Widlund and Fabian Renn-Giles, for their contributions to the C++ community. 