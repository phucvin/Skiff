#include "/workspaces/Skiff/lib/std/skiff.h"


void skiff_test_me(int32_t i)
{
    if(i == 10)
    {
        skiff_println((skiff_string_new_0(0, "i is 10!")));
        skfree_ref_stack(0);
    }
    else if(i > 5)
    {
        skiff_println((skiff_string_new_0(0, "i is gt 5!")));
        skfree_ref_stack(0);
    }
    else
    {
        skiff_println((skiff_string_new_0(0, "i is lt 5!")));
    }
    skfree_ref_stack(0);
}
int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_test_me((20));
    skiff_test_me((0));
    skiff_test_me((10));
    int32_t i;
    (i) = (15);
    if(i == 15)
    {
        skiff_println((skiff_string_new_0(0, "i is 15 or 14")));
    }
    else if(i == 14)
    {
        skiff_println((skiff_string_new_0(0, "i is 15 or 14")));
    }
    else if(i == 10)
    {
        skiff_println((skiff_string_new_0(0, "i is 10")));
    }

    skfree_ref_stack(1);
    return 0;
}
