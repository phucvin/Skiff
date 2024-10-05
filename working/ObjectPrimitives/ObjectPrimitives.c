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
    (i) = (10);
    skiff_println(((skiff_string_t *)skiff_int_to_string(i)));
    skiff_println(((skiff_string_t *)skiff_int_to_string((15))));
    float f;
    (f) = (10.65);
    skiff_println(((skiff_string_t *)skiff_float_to_string(f)));
    skiff_println(((skiff_string_t *)skiff_float_to_string((42.42))));
    skfree_ref_stack(1);
    return 0;
}
