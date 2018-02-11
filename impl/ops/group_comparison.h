OPERATION(op_all) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = true;

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t x = stacks[stack_id].pop();

        if (!x.chr) {
            o.chr = false;
            stacks[stack_id].push(o);
        }
    }

    ip += 3;
}


OPERATION(op_any) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = false;

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t x = stacks[stack_id].pop();

        if (x.chr) {
            o.chr = true;
            stacks[stack_id].push(o);
        }
    }

    ip += 3;
}