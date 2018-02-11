#ifndef IMPL_MAKE_OPS_H // personal fuck you to nullcat
#define IMPL_MAKE_OPS_H


wotpp::op_group make_ops() {
    // Create array for instructions.
    wotpp::op_group ops;

    // Fill operations array with default instruction.
    // This means if it encounters an instruction it
    // doesn't understand, it will skip it.
    std::fill(ops.begin(), ops.end(), op_noop);

    int i = 0;

    // Setup operations.
    ops[i++] = op_pshl;
    ops[i++] = op_push;
    ops[i++] = op_stor;
    ops[i++] = op_pop;

    ops[i++] = op_prnt;
    ops[i++] = op_emit;
    ops[i++] = op_prnl;
    ops[i++] = op_emtl;

    ops[i++] = op_sum;
    ops[i++] = op_prod;

    ops[i++] = op_add;
    ops[i++] = op_sub;
    ops[i++] = op_mul;
    ops[i++] = op_div;
    ops[i++] = op_mod;
    ops[i++] = op_neg;
    ops[i++] = op_incr;
    ops[i++] = op_decr;

    ops[i++] = op_lshf;
    ops[i++] = op_rshf;
    ops[i++] = op_lrot;
    ops[i++] = op_rrot;

    ops[i++] = op_and;
    ops[i++] = op_or;
    ops[i++] = op_xor;
    ops[i++] = op_not;

    ops[i++] = op_all;
    ops[i++] = op_any;

    ops[i++] = op_cmeq;
    ops[i++] = op_cmnl;
    ops[i++] = op_cmlt;
    ops[i++] = op_cmmt;

    ops[i++] = op_jump;
    ops[i++] = op_jpeq;
    ops[i++] = op_jpnl;

    ops[i++] = op_jmpr;
    ops[i++] = op_jreq;
    ops[i++] = op_jrnl;

    ops[i++] = op_call;
    ops[i++] = op_ret;

    ops[i++] = op_halt;
    ops[i++] = op_noop;

    return ops;
}


#endif