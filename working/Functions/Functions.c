#include "/workspaces/Skiff/lib/std/skiff.h"


int32_t skiff_my_func(int32_t arg, skiff_string_t * formal_arg2, int32_t arg3, skiff_string_t * formal_arg4)
{
    skiff_string_t ** arg2 = skalloc_ref_stack();
    *arg2 = formal_arg2;
    skiff_string_t ** arg4 = skalloc_ref_stack();
    *arg4 = formal_arg4;
    skiff_println(*(arg2));
    skfree_ref_stack(2);
    return arg;
}
int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    int32_t i;
    (i) = (2);
    skiff_string_t ** j = skalloc_ref_stack();
    *(j) = (skiff_string_new_0(0, "Hello World!"));
    skfree_ref_stack(2);
    return skiff_my_func((i), *(j), (5), (skiff_string_new_0(0, "literal string")));
}
