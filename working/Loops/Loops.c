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
    (i) = (0);
    while(i < 2 && 1)
    {
        skiff_println((skiff_string_new_0(0, "while")));
        (i++);
        skfree_ref_stack(0);
    }
    int32_t j;
    (j) = (4);
    while(1)
    {
        skiff_println((skiff_string_new_0(0, "loop")));
        if(j < 1)
        {
                        skfree_ref_stack(0);
            break;
            skfree_ref_stack(0);
        }
        (j--);
        skfree_ref_stack(0);
    }
    int32_t k;
    (k) = (0);
    while(k < 2)
    {
        skiff_println((skiff_string_new_0(0, "bonk")));
        skfree_ref_stack(0);
        (k++);
    }
    skfree_ref_stack(1);
    return i + j;
}
