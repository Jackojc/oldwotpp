# Wot++ VM design specification.

## Types/Classes.

### Object (A union of multiple data types.):
> Holds a primitive value.
- char (int8_t)
- int (int32)
- ptr (void\*)


### Stack:
> A LIFO container that supports pushing and popping.


### Heap:
> A container that allows data to be stored in any order the user desires.
A couple of example containers that fulfill this role:

- Array
- Linked list




## Memory model/Structures.



### Stacks:
> Operand data.

##### Implementation details:
- Stacks must be at least 256 [Objects](./#object-a-union-of-multiple-data-types) in size.
- A minimum of 8 stacks must be available to the user.

As an example implementation consider the following:
- A = Global data
- B = Function arguments
- C = Return values

_whereby `A` stores all generic global data._

_whereby `B` stores all arguments to be passed into a function._

_whereby `C` stores all output values of a function after transformation._





### Heap:
> A collection of [Objects](./#object-a-union-of-multiple-data-types).

##### Implementation details:
- Heap must be at least 1024 [Objects](./#object-a-union-of-multiple-data-types) in size.






## Operations.

##### Note 1:
- The operations below mostly have to be implemented both for characters _and_ integers.

##### Note 2:
- STACK_ID = The stack in which to perform the operation.
- N = Range of elements to perform the operation on.
- X = Literal value to use in operation.
- ADDR = Address from where to get a value or put a value.

### Stack manipulation operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| PSHL | STACK_ID, X | Push a literal to the stack. |
| PUSH | STACK_ID, ADDR, N | Push an object to the stack. |
| STOR | STACK_ID, ADDR, N | Pop the top item on the stack and save it in the heap. |
| POP | STACK_ID, N | Discard the top value of the stack. |

### I/O operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| PRNT | STACK_ID, N | Print an ASCII value. |
| EMIT | STACK_ID, N | Print a raw value. |
| PRNL | X | Print a literal ASCII value. |
| EMTL | X | Print a literal raw value. |

### Group mathematical operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| SUM | STACK_ID, N | Get the sum of a range of elements. |
| PROD | STACK_ID, N | Get the product of a range of elements. |

### Mathematical operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| ADD | STACK_ID | Consume the top two items on the stack and ADD them. |
| SUB | STACK_ID | Consume the top two items on the stack and SUBTRACT them. |
| MUL | STACK_ID | Consume the top two items on the stack and MULTIPLY them. |
| DIV | STACK_ID | Consume the top two items on the stack and DIVIDE them. |
| MOD | STACK_ID | Consume the top two items on the stack and apply the MODULUS operator to them. |
| NEG | STACK_ID | Consume the top item of the stack and NEGATE it. |
| INCR | STACK_ID, X | Increment the item on top of the stack. |
| DECR | STACK_ID, X | Decrement the item on top of the stack. |

### Bitshift operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| LSHF | STACK_ID | Shift the item on top of the stack to the left by a number of bits. |
| RSHF | STACK_ID | Shift the item on top of the stack to the right by a number of bits. |
| LROT | STACK_ID | Rotate the item on top of the stack to the left by a number of bits. |
| RROT | STACK_ID | Rotate the item on top of the stack to the right by a number of bits. |

### Logical operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| AND | STACK_ID | Consume the top two elements on the stack and AND them. |
| OR | STACK_ID | Consume the top two elements on the stack and OR them. |
| XOR | STACK_ID | Consume the top two elements on the stack and XOR them. |
| NOT | STACK_ID | Consume the top item of the stack and NOT it. |

### Group comparison operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| ALL | STACK_ID, N | Compare a range of elements to see if they are ALL true. |
| ANY | STACK_ID, N | Compare a range of elements to see if ANY are true. |

### Comparison operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| CMEQ | STACK_ID | Check if the top two elements are the same as eachother. |
| CMNL | STACK_ID | Check if the top two elements are not the same as eachother. |
| CMLT | STACK_ID | Check if the top element is less than the top-1 element. |
| CMMT | STACK_ID | Check if the top element is more than the top-1 element. |

### Global jump operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| JUMP | X | Unconditionally jump to an address in the code. |
| JPEQ | STACK_ID, X | Jump to an address in code if the top element in the stack is TRUE. |
| JPNL | STACK_ID, X | Jump to an address in code if the top element in the stack is FALSE. |

### Relative jump operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| JMPR | X | Jump to an address in code relative to the current address. |
| JREQ | STACK_ID, X | Jump to an address in code relative to the current address if the top element in the stack is TRUE. |
| JRNL | STACK_ID, X | Jump to an address in code relative to the current address if the top element in the stack is FALSE. |

### Function operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| CALL | STACK_ID, X | Jump to X and save current instruction pointer in the stack. |
| RET | STACK_ID | Jump to the top value in the stack. |

### Other operators.
| Operation | Arguments | Explanation |
| ----------- | ----------- | ----------- |
| HALT | N/A | Halt execution of the code. |
| NOOP | N/A | No operation, dummy instruction. |