#include "/workspaces/Skiff/lib/std/skiff.h"




///////////////////// Start Class Container /////////////////////////

typedef struct skiff_container_struct skiff_container_t;
int32_t skiff_get_sub(skiff_container_t *, int32_t);
void skiff_assign_sub(skiff_container_t *, int32_t, int32_t);
struct skiff_container_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    int32_t (*getSub)();
    void (*assignSub)();
};
struct skiff_container_class_struct skiff_container_interface;
struct skiff_container_struct 
{
    struct skiff_container_class_struct * class_ptr;
    uint8_t mark;
};
void skiff_container_static()
{
    skiff_container_interface.class_refs = 0;
    skiff_container_interface.struct_size = sizeof(skiff_container_t);
    skiff_container_interface.parent = &skiff_any_ref_interface;
    skiff_container_interface.simple_name = "Container";
    skiff_container_interface.getSub = skiff_get_sub;
    skiff_container_interface.assignSub = skiff_assign_sub;
}
skiff_container_t * skiff_container_new_0(skiff_container_t * this)
{
    skiff_container_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_container_t));
        this->class_ptr = &skiff_container_interface;
    }
    skfree_ref_stack(0);
    return this;
}

int32_t skiff_get_sub(skiff_container_t * this, int32_t i)
{
    skiff_print((skiff_string_new_0(0, "Getting item at ")));
    skiff_println(((skiff_string_t *)skiff_int_to_string(i)));
    skfree_ref_stack(0);
    return 1;
}

void skiff_assign_sub(skiff_container_t * this, int32_t elt, int32_t i)
{
    skiff_print((skiff_string_new_0(0, "Placing ")));
    skiff_print(((skiff_string_t *)skiff_int_to_string(elt)));
    skiff_print((skiff_string_new_0(0, " at index ")));
    skiff_println(((skiff_string_t *)skiff_int_to_string(i)));
    skfree_ref_stack(0);
}

///////////////////// End Class Container /////////////////////////


int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_container_static();
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_println(((*args)->class_ptr->getSub((*args), 0)));
    (*args)->class_ptr->assignSub((*args), (skiff_string_new_0(0, "New String")), 0);
    skiff_println(((*args)->class_ptr->getSub((*args), 0)));
    skiff_container_t ** c = skalloc_ref_stack();
    *(c) = (skiff_container_new_0(0));
    (*c)->class_ptr->assignSub((*c), (15), 5);
    skfree_ref_stack(2);
    return (*c)->class_ptr->getSub((*c), 1);
}
