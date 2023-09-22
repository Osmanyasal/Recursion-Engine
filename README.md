<div id="user-content-toc" align=center>
  <ul>
    <summary><h1 style="display: inline-block;">Recursion Game Engine</h1></summary>
  </ul>
</div>
<div align="center">
            <img align="center" alt="ICON" width="500" height="500" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/43181e63-15a4-49d3-98a7-c059f6e34765" /> 
</div> 
<div align="center">
                <img align="center" title="C++" alt="C++" width="80px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/f79dfb8b-ec5e-43a9-b3ec-7db4555b54e0" />
                &nbsp;&nbsp;
                <img align="center" title="OpenGL" alt="OpenGL" width="100px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/0564acaf-05a8-485d-b417-48a5c37729ab" />
                &nbsp;&nbsp; 
                <img align="center" title="Vulkan" alt="Vulkan" width="100px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/5272de0b-83b4-4c8a-a2a7-97d25bd1cd96" /> 
                &nbsp;&nbsp; 
                <img align="center" title="Linux" alt="Linux" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/e67369bc-582f-4d90-bd92-7765b6f2a357" /> 
                &nbsp;&nbsp;
                <img align="center" title="Mac" alt="Mac" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/a635c69d-cc34-46df-a0ed-de5771609a4d" />
                &nbsp;&nbsp;
                <!-- <img align="center" alt="Windows" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/c1717d00-63d2-426f-a648-18a2d618f849" /> -->
</div>
<div align="center">
                <img align="center" title="GLFW" alt="GLFW" width="60px" src="https://www.glfw.org/img/favicon/favicon-196x196.png" />
                &nbsp;&nbsp; 
                <img align="center" title="pmu_tools" alt="pmu_tools" width="100px" src="http://halobates.de/pmu-tools.png" />
                &nbsp;&nbsp; 
                <img align="center" title="Dear Imgui" alt="Dear Imgui" width="60px" src="https://raw.githubusercontent.com/wiki/sammyfreg/netImgui/Web/img/DearImGui.png" /> 
                &nbsp;&nbsp;
                <img align="center" title="GLM" alt="GLM" width="60px" src="https://github.com/Osmanyasal/glm/blob/5c46b9c07008ae65cb81ab79cd677ecc1934b903/doc/manual/logo-mini.png?raw=true" /> 
                &nbsp;&nbsp; 
                 <img align="center" title="ENTT" alt="ENTT" width="80px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/ca8c3279-3ca3-4c7f-ab77-5aa61bd0aaa9" />
                &nbsp;&nbsp; 
                 <img align="center" title="Doxygen" alt="Doxygen" width="150px" src="https://www.doxygen.nl/images/doxygen.png" /> 
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
 - You can follow the current development status at projects section
 - Main support is on Linux, MacOS and Windows side-supported.
 - Developing fundamentals; OpenGL and glfw3 are preferred, Vulkan and DirectX will be supported later.
 
