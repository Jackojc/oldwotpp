#ifndef IMPL_OPS_H
#define IMPL_OPS_H


#define OPERATION(name) void name(wotpp::instr_ptr& ip, wotpp::instr_ptr initial_ip, wotpp::stack_group& stacks, wotpp::heap& heap, bool& running)


#include "ops/stack_manipulation.h"

#include "ops/io.h"

#include "ops/group_math.h"
#include "ops/math.h"

#include "ops/bitshift.h"
#include "ops/logical.h"

#include "ops/group_comparison.h"
#include "ops/comparison.h"

#include "ops/jump.h"
#include "ops/rel_jump.h"
#include "ops/functions.h"

#include "ops/other.h"

#include "make_ops.h"


#endif