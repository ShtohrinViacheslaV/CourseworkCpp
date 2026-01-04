Mean Free Path of Gas Molecules

📘 Project Description

This project is a coursework assignment focused on modeling the mean free path of gas molecules based on basic principles of molecular physics.

The program calculates the average distance a gas molecule travels before colliding with another molecule, using given physical formulas.
The implementation demonstrates object-oriented programming, file input/output, operator overloading, and data tabulation with graphical visualization.

🧪 Physical Background

The mean free path of gas molecules is calculated using the formula:


<img width="217" height="91" alt="image" src="https://github.com/user-attachments/assets/e9d41bbd-bda2-47fc-88e6-a165ddb0cac1" />


where:

𝑙 — mean free path

𝛿 — molecule diameter

𝑁 — number of molecules

The number of molecules in a given volume is calculated as:


<img width="307" height="81" alt="image" src="https://github.com/user-attachments/assets/6dcb8c40-48bf-456b-a996-da66278ca309" />


where:

𝑝 — gas pressure

𝑇𝑔 — gas temperature


🧱 Class Structure

The main class stores the following data members:

 — Mean free path

 — Molecule diameter
  
 — Number of molecules

 — Gas pressure

—  Gas temperature

⚙️ Implemented Functionality

Methods

—  Reading input data from a file

—  Calculating the number of molecules

—  Calculating the mean free path

—  Writing input data and results to an output file


Constructors

—  Default constructor

—  Parameterized constructor

—  Copy constructor


Operator Overloading

—  Assignment operator (=)

—  Comparison operators:

 ==, !=

 <, <=

 >, >=

📂 Input and Output

Input data is read from a file.

Results, including all input parameters and calculated mean free path, are written to another file.

A separate output file is generated for tabulated values during parameter variation.


🔢 Control Example

The following parameters can be used for testing:

<img width="691" height="278" alt="image" src="https://github.com/user-attachments/assets/9691f08c-23fe-4a88-8f28-5ee4a98bb565" />



📊 Parameter Tabulation and Graph

One parameter with a specified range (e.g., gas temperature) is selected and varied:

From an initial value to a final value

With a fixed step Δ

For each step:

—  The mean free path is calculated

—  Results are written to a file

—  A graph of the dependence is plotted
  

🧩 Demonstration Program

The example program included in the repository demonstrates:

—  Usage of all constructors

—  Invocation of all class methods

—  Application of all overloaded operators

—  File input/output

—  Tabulation and graph plotting
  

🛠 Technologies Used

—  Object-Oriented Programming

—  File I/O

—  Operator Overloading

—  Numerical Computation

—  Data Visualization
  

📎 Notes

This project was developed as part of a coursework assignment and follows academic requirements for clarity, correctness, and demonstration of programming concepts.
