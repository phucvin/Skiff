#include "/workspaces/Skiff/lib/std/skiff.h"


int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    int32_t i;
    (i) = (5);
    i = i + 5;
    (i) = (i * 2);
    i = i - 10;
    (i) = (10 - i * 5 + 55);
    skfree_ref_stack(1);
    return i;
}
