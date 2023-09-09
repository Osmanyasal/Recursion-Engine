<div id="user-content-toc" align=center>
  <ul>
    <summary><h1 style="display: inline-block;">Recursion Game Engine</h1></summary>
  </ul>
</div>
<div align="center">
            <img align="center" alt="ICON" width="500" height="500" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/43181e63-15a4-49d3-98a7-c059f6e34765" /> 
</div> 
<div align="center">
                <img align="center" alt="C++" width="80px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/f79dfb8b-ec5e-43a9-b3ec-7db4555b54e0" />
                &nbsp;&nbsp;
                <img align="center" alt="OpenGL" width="100px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/0564acaf-05a8-485d-b417-48a5c37729ab" />
                &nbsp;&nbsp;
                <img align="center" alt="Vulkan" width="100px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/5272de0b-83b4-4c8a-a2a7-97d25bd1cd96" /> 
                &nbsp;&nbsp;
                <img align="center" alt="Linux" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/e67369bc-582f-4d90-bd92-7765b6f2a357" /> 
                &nbsp;&nbsp;
                <img align="center" alt="Mac" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/a635c69d-cc34-46df-a0ed-de5771609a4d" />
                &nbsp;&nbsp;
                <!-- <img align="center" alt="Windows" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/c1717d00-63d2-426f-a648-18a2d618f849" /> -->
</div>

## About <br>
* Cross Platform Game Engine mainly developed for Linux and Unix environments later will be ported to Windows. <br>
* Developed with C++ and Make/Bash scripts, allows other scripting languages in development ```Python, Lua, C# ``` <br>
* The Engine itself contains many profiling tools ```(Perf, Valgrind, Intel Vtune, Advisor...)``` and binary instrumentations ```(chrome://tracing)``` allowing the user to write high-performant code and monitor and optimize the pre-written code.

## To run 🚀 <br>
```
git clone --recurse-submodules https://github.com/Osmanyasal/Recursion-Engine.git
cd ./Recursion-Engine
make run
```
Makefile by default enables PGO (profiler-guided optimizations) meaning it collects data as you use the engine.
<br>
After running the application for a while on a single run, you can re-compile the engine as follows

``` 
make -f optimize [run]
[make run]
```
You can compare before and after performance using defined rules in Makefile.

```
make tma_analiysis  
make monitor_callstack  
mem_check
...
```

## PERFORMANCE MONITORING 🔎<br>
You can use the following makefile targets to collect meaningful metrics <br>
All targets use perf tool and Valgrind, so make sure they're installed<br>
```
make tma_analiysis # makes tma analysis unearths how much of your application {front,back}-end bounded or bad-speculated 
make monitor_callstack # hottest ran functions 
mem_check # runs the Valgrind tool to make a detailed memory analysis.
```
## Currently
 - Main support is on Linux, MacOS and Windows side-supported.
 - Developing fundamentals; OpenGL and glfw3 are preferred, Vulkan and DirectX will be supported later.

## Project Structure
<pre>
[name]/
├── [name]/
│   ├── headers...
│   ├── sources...
│   ├── modules...
│   └── unit tests...
└── tests/
    ├── functional_test1/
    ├── functional_test2/
    ├── integration_test1/
    ├── integration_test2/
    └── ...

     
src/ (source for the application)
lib/ (source for the application library *.{c,cc,cpp} *.{h,hh,cpp})
doc/ (doxygen or any kind of documentation)

src/utils/
     |──foo.hh
     |──foo.cc
     |──foo.test.cc
     └── ...
src/core/
     |──bar.hh
     |──bar.cc
     |──bar.test.cc
     └── ...
src/tests/
    |──functional_test1
    |──functional_test2
    └── ...
</pre>

## Naming Convention
### file names
<pre>
  <b>always *.hh and *.cc</b>
  app1.hh app1.cc
</pre>
### header guards
<pre>
  <b>PROJECT_NAME__FOLDER__SUB_FOLDER__SUB_FOLDER_2__FILE_NAME__HH</b>
  
  #ifndef RECURSION_ENGINE__SRC__UTILS__LOGGER_HH
  #define RECURSION_ENGINE__SRC__UTILS__LOGGER_HH
  ....
  #endif
</pre>
### includes
<pre>
  <b>always use &lt..&gt</b>
  #include&ltutils.hh&gt
  #include&ltevents.hh&gt

  <b>add your new header locations to header file with respect to order</b> 
  INCLUDE := -I./[our_custom_CORE_locatıons]\
             -I./[our_custom_SANDBOX_locatıons]\#3rd party apps
              $(3rd_party_libraries) # 3rd party libraries
    
  INCLUDE := -I./src/core -I./src/core/events\
   						-I./src/core/window\
               ...
  						-I./src/utils\
  						-I./src/utils/optimizations\
  						-I./sandbox/proj1\
  					 	 $(LIB_SPD)\
  						 $(LIB_GLEW)\
  						 $(LIB_GLFW)
</pre>
### namespace
<pre>
  namespace Recursion::submodule1::submodule2{
  
  } // namespace Recursion::core
</pre>
### struct/class
<pre>
  {struct,class} {Struct,Class}Name{
    public:
      // static & public members
    protected:
      // static & protected members
    private:
      // static & private members
  }; 
</pre>
 ### method
<pre>
  void method_name(){}
</pre>
### variables
<pre>
  int variable1,second_variable;
</pre>
 

