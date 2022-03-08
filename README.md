# VissimApi.DriverModel
All of Vissim's DLL-based APIs, including DriverModel and Signal Control APIs - feature a uniform C-style design, where various data-tags are dispatched during runtime using switch-case statements.

- In a nutshell, Vissim's C-style APIs provide a very flexible mechanism for user-defined driver-behavior or signal control logics. They only use primitive data types in the interface declaration, hence not requiring any external dependencies.
- Vissim's C-style APIs may also provide some efficiency when switch-case statements can be optimized by the compiler as a jump table. However, that is not always the case, and switch-case statements can be slow during simulation runtime, especially when the number of cases is large (e.g., greater than 7) (see Ref [1] and [2]).

From the software engineering perspective, there are some nuances with Vissim's C-style design as well:

- User code may end up spaghetti-like, mixing boiler-plate interface code with the code that implements the user-defined driver behavior logic.
- User code may ultimately become hard to extend and maintain. The big switch-case structure has to be re-visited again and again for editing, adding, or modifying - an apparent violation of the SOLID principle, i.e., *"open for extension, closed for modification"*. 
   
The framework herein provides a different design and implementation in modern C++ - modular, structured, while still computationally efficient (actually, faster). Specifically, this framework features:

- *Separation of Concerns* 
  - **intf** is responsible for communicating with the Vissim simulator. It includes DLL export functions with minimal boiler-plate code. This part of code is not supposed to be changed by the user.
  - **logic** is where the user implements customized driver behavior logic. The user should implement the DriverModelFactory accordingly.
  - **event** is a type of "glue" code, responsible for "wiring-up" various driver model events. The user is not supposed to change the code in this part.
    - The new event-dispatching mechanism no longer uses "boring" (and slower) switch-case statements. The mechanism now dispatches events to proper event handlers using a faster static table of function pointers.
    - More important, this new mechanism facilitates writing structured, scalable, and maintainable code for sophisticated user-defined logic, thanks to that events are now completely decoupled from user logic.
  - **meta**. Low-level C++ meta enum helper class. Somewhat complex but worthwhile and fun to explore. This part of code is not supposed to be changed by the user.
  
- *Open for extension, close for modification*
  - Those boring and slower switch-case statements are replaced by an array of function pointers automatically constructed at compile time, which leads to faster event dispatching than the original switch statements. 
  - Template specialization enables auto-registration of events during compile time.
 
 - *Single Responsibility*
   - User logic and user events are isolated, and can be extended and maintained easily in a much cleaner way.


# Usage
To be added.

# Example
To be added.

# Benchmark
To be added.

# Compiler
C++ compiler that supports C++/17 or above. The latest MSVC compiler recommended. 

# Platform
Windows only. But you can customize the interface part of the code to make it work on Linux since this framework uses standard C++ only.

# Acknowledgement
This framework partly uses [meta_enum](https://github.com/therocode/meta_enum) originally developed by Tobias Widlund. 

# References
1. ["Is Code Faster Than Data? Switch Statements vs. Arrays".](https://blog.demofox.org/2016/09/26/is-code-faster-than-data-switch-statements-vs-arrays/)
2. ["C++ automatic generation of switch statement".](https://stackoverflow.com/questions/21186314/c-automatic-generation-of-switch-statement)
3. ["CPU Cache".](https://en.wikipedia.org/wiki/CPU_cache)
4. ["Why software developers should care about CPU caches".](https://medium.com/software-design/why-software-developers-should-care-about-cpu-caches-8da04355bb8a)