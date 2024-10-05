#include "/workspaces/Skiff/lib/std/skiff.h"


void skiff_an_error()
{
    skiff_throw(skiff_exception_new_0(0, skiff_string_new_0(0, "Error message")));
    skiff_println((skiff_string_new_0(0, "Never executed!")));
    skfree_ref_stack(0);
}
void skiff_catch_1(skiff_catch_layer_t * layer, skiff_exception_t * ex)
{
    skiff_println((skiff_string_new_0(0, "Oh no!")));
    skiff_println(((skiff_string_t *)(ex)->class_ptr->getMessage(ex)));
    skfree_set_ref_stack(layer->sp_ref_val);
    longjmp(layer->current_catch_state, 1);
}

int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_start_try(skiff_catch_1, &skiff_exception_interface, sp_ref);
    int skiff_continue_exec_1 = setjmp(catch_layer_tail->current_catch_state);
    if(skiff_continue_exec_1 == 0)
    {
        skiff_an_error();
    }
    skiff_end_try();

    skiff_println((skiff_string_new_0(0, "We resume here!")));
    skiff_list_t ** list = skalloc_ref_stack();
    *(list) = (skiff_list_t *)(0);
    skfree_ref_stack(2);
    return (int32_t)(*list)->class_ptr->getSize(*list);
}
