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
                <img align="center" alt="Windows" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/c1717d00-63d2-426f-a648-18a2d618f849" />
</div>
   

## To run 🚀 <br>
```console
$ git clone --recurse-submodules https://github.com/Osmanyasal/Recursion-Engine.git
$ cd ./Recursion-Engine
$ make run
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
lib/ (source for the application library *.cpp *.hpp)
doc/ (doxygen or any kind of documentation)

src/utils/
     |──foo
     |──foo.cc
     |──foo.test.cc
     └── ...
src/core/
     |──bar
     |──bar.cc
     |──bar.test.cc
     └── ...
src/tests/
    |──functional_test1
    |──functional_test2
    └── ...
</pre>


