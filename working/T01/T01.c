#include "/workspaces/Skiff/lib/std/skiff.h"


int32_t skiff_main(skiff_list_t * formal_args)
{
    // skiff_any_ref_static();
    // skiff_list_static();
    // skiff_string_static();
    // skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_println((skiff_string_new_0(0, "t01")));
    skfree_ref_stack(1);
    return 0;
}
