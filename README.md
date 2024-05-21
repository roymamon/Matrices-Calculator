# מטלה 2 - (Operator overload)

I.D: 322623323
mail: mamon8521@gmail.com 

this is a second project in systems programming b course
an extension of the first project, Graphs and Algorithms, and operator overloading.

the README regarding the Graphs and Algorithms(project 1) - 
https://github.com/roymamon/Cpp_project1/blob/main/README.md

in this project we overload several operators:

Addition:

1."g1 + g2", adds two graphs(must be the same size) by adding every 2 edges in the same index for example
g3[i][j] = g1[i][j] + g2[i][j]

2." +g1 ", unary plus, multiplies every edge by 1, so  doesnt do anything to the graph.

3." g1 += g2 ", same as g1 + g2, but doesnt create a new graph. it directly changes g1.

4." ++g1 ", adds 1 to all the edges.

Subtraction:

1."g1 - g2", given 2 graphs in the same size, subtracts every edge in g1 by the corresponding edge in g2.
g3[i][j] = g1[i][j] - g2[i][j]

2." -g1 ", unary minus, multiplies every edge by -1, so  it switches the signs.

3." g1 -= g2 ", same as g1 - g2, but doesnt create a new graph. it directly changes g1.

4." --g1 ", subtracts 1 from all the edges.

Comparison:

1." g1==g2 ", checks wether 2 graphs are equal - same size, same edges(and with same weight).

2." g1!=g2 ", checks wether 2 graphs are not equal - different edges or weights or size.

3." g1 > g2 ", checks wether g1 is greater than g2 - returns true if g1 contains g2, if not, if the number of edges of g1 is bigger than g2 then returns true, if also not, if the weights of the edges in g1 is bigger than g2 then returns true.

4." g1 >= g2 ", checks wether g1 > g2 or g1 == g2.

5." g1 < g2 ", same logic as g1 > g2 but the other way around.

6." g1 <= g2 ", checks wether g1 < g2 or g1 == g2.

Multiplication:

1." g1 *= 2 ", multiplication by scalar, multiplies every edge in g1 by 2.

2." g1 * g2 ", graph multiplication, further information regarding matrices multiplication can be found here -
https://en.wikipedia.org/wiki/Matrix_multiplication

Division:

1." g1 /= g2 ", graph division, divides each edge in g1 by the corresponding edge in g2.

Output:

1." << ", output stream operator using friend, which benefits encapsulation, efficiency, and simplified interface.


Makefile: 

using a makefile inorder to make the compilation process easier for us. 
using g++ and mainly making 2 exe files - Test, Demo.

Demo.cpp:

a demo file given by the university inorder to better understand how the operators overloading should work and what should be printed using several examples.
i also added to the given demo the examples i made from Test.cpp inorder to also see the prints to better understand.

Test.cpp:

tests that were given to us and also tests i made myself checking the operators on different graphs,
using asserts(include cassert).



