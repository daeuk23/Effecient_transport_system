# Efficient_transport_system 

## Summary Of Purpose
It is an algorithm development project to increase the efficiency of transporting goods.  
We implemented a system that can handle errors and find the best path using C, C++ languages and various testing techniques.  

Each route has restrictions such as weight and cost, and the routes available are also limited.  
This project is designed to take into account travel distances and resource consumption, and choose the most efficient transportation route.  

In addition, it is a highly reusable and flexible program because you can easily change or test the situation by entering the data required for mapping and shipping files.  

In other word This project creates an algorithm template for efficient logistics transportation. It is designed with a structure that calculates the optimal route within limited resources and conditions.

## Skill Used  
C++, C, 3rd party testing tools, Zira (task management)

## Project Period
Nov 13th ~ Dec 8th 2023  
Collaborated with->  
[Daeuk Kim](https://www.linkedin.com/in/daeuk-kim-68628231b/) : Leader (main,mapping,shipping C files, whitebox testing)   
=> Contact for future colaboration : (647)-879-3598, a24738598@gmail.com  
[ZihaoYu](https://www.linkedin.com/in/zhihao-yu-683416229/) : Unit test handler, Error fix about Mapping C file  
[WonJeon](https://www.linkedin.com/in/won-jeon-96488428b/) : collaborated ~ Nov 25th , unfortunately accidental drop-off of a project. (time management, Analyze origin files)  
YungTingHsu : Enhance mapping, shipping C files, Evaluate Test Cases  


## Operable Files  

### Class FIles

**main**  
Program functionality that connects each function and provides a simple interface (including header)  
Shortcut: [main.c](project-starter/main.c), [main.h](project-starter/main.h)  

**Mapping**  
Header and implementation of a file that handles data for maps that are dynamically provided with each distance and the **map** to which goods will be sent.  
Shortcut: [mapping.c](project-starter/mapping.c), [mapping.h](project-starter/mapping.h)

**Shipping**  
Implementing an algorithm for transport efficiency based on the weight coast that can be transported.  
Shortcut: [Shipping.c](project-starter/shipping.c), [Shipping.h](project-starter/shipping.h)

### Helper Files
**BlackBox Helpers**  
Shortcut: [helper1](project-starter/mappingblackboxhelper1.c), [helper2](project-starter/mappingblackboxhelper2.c)

### Testing Files
**Integration Test**  -> removed Dec 5th
**Unit Test**
Unit testing each of the functionalities  
Shortcut: [UnitTest](testing/UnitTesting.cpp)


## Compile In remote 
G++ compiler required  

```bash
g++ -Wall -std=c++17 -g -o main main.c mapping.c shipping.c UnitTesting.cpp
```
Using SSH will be good

## How to test local
[TestingCodes](testingfiles/) : Sequence to test my codes.

### 1. Clone repo

Clone my repo to your local

```bash
git clone https://github.com/daeuk23/Effecient_transport_system.git
cd transportsystem
```  

### 2. Run In source code Editor  

such as vs code, visual studio

```bash
1. start Visual Studio  

2. click "Open a project or solution"  

3. Either run transportsystem or Select Effecient_transport_system.sln  
```  

## Testing results  

### Additional test  
[UnitTest](testing/UnitTesting.cpp) : All the Assertion previously selected  

### Documents  
[TestReport](testing-result-files/Testing_summary&bug_report.docx), [ResultSummary](testing-result-files/Ｔest_Cases.xlsx)
