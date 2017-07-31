# Wot++


### A C++ based interpreter for Wot++.


<br>


\{}\<X\>   \:    Function with name of 'X'.

\()\<I\>   \:    If index 'I' is re:zero, execute.

\[]\<I\>   \:    Loop while value at index 'I' is > 0.

<br>

a-h     \:    Set registers

<br>

\! \<I\>   \:    Boolean NOT the cell at index 'I'

r \<I\>   \:    Set pointer to register 'I'.

\$ \<I\>   \:    Go to cell at index 'I'.

\` \<N\>   \:    Move the instruction pointer 'N' places. (e.g. -2, 5) (P.S. Keep in mind, arguments dont count as instructions, its JUST opcodes themselves so make sure to skip appropriately.)

<br>

\^ \<N\>   \:    Move up 'N' cells.

v \<N\>   \:    Move down 'N' cells.

<br>

\: \<I\>   \:    Output raw value at 'I'.

\. \<I\>   \:    Output ASCII equivalent value at 'I'.

\, \<I\>   \:    Input a single char as ASCII value to 'I'.

\@ \<X\>   \:    Include file 'X'.

<br>

\# \<X\>   \:    Execute function 'X'.

<br>

\? \<I\>   \:    Get value in current register and copy it to index 'I'.

\& \<I\>   \:    Set value in current register to value at index 'I'.

<br>

\~ \<I\>   \:    Push register 'I' to stack.

\| \<I\>   \:    Pop from stack to register 'I'.

\\ \<I\>   \:    Peek at top of stack and push to register 'I'.

<br>

\= \<N\>   \:    Set current cell to 'N'.

\_ \<N\>   \:    Set current register to 'N'.

<br>

\+ \<I\>   \:    Add 'N' to the current cell.

\- \<I\>   \:    Subtract 'N' from current cell.

\* \<I\>   \:    Multiply the current cell by 'N'.

\/ \<I\>   \:    Divide the current cell by 'N'.

\% \<I\>   \:    Divide the current cell by 'N' and store the remainder.
