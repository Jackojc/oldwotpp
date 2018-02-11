// No operation. (skip)
OPERATION(op_noop) {
    ip++;
}


// When encountered, halt the machine and exit.
OPERATION(op_halt) {
    running = false;
}