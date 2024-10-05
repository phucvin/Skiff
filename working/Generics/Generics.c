#include "/workspaces/Skiff/lib/std/skiff.h"




///////////////////// Start Class Wrapper /////////////////////////

typedef struct skiff_wrapper_struct skiff_wrapper_t;
void * skiff_get_dat(skiff_wrapper_t *);
struct skiff_wrapper_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    void * (*getDat)();
};
struct skiff_wrapper_class_struct skiff_wrapper_interface;
struct skiff_wrapper_struct 
{
    struct skiff_wrapper_class_struct * class_ptr;
    uint8_t mark;
    void * dat;
};
void skiff_wrapper_static()
{
    skiff_wrapper_interface.class_refs = 1;
    skiff_wrapper_interface.struct_size = sizeof(skiff_wrapper_t);
    skiff_wrapper_interface.parent = &skiff_any_ref_interface;
    skiff_wrapper_interface.simple_name = "Wrapper";
    skiff_wrapper_interface.getDat = skiff_get_dat;
}
skiff_wrapper_t * skiff_wrapper_new_0(skiff_wrapper_t * this, void * formal_dat)
{
    skiff_wrapper_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_wrapper_t));
        this->class_ptr = &skiff_wrapper_interface;
    }
    void ** dat = skalloc_ref_stack();
    *dat = formal_dat;
    ((this)->dat) = *(dat);
    skfree_ref_stack(1);
    return this;
}

void * skiff_get_dat(skiff_wrapper_t * this)
{
    skfree_ref_stack(0);
    return (this)->dat;
}

///////////////////// End Class Wrapper /////////////////////////


int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_wrapper_static();
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_wrapper_t ** intData = skalloc_ref_stack();
    *(intData) = (skiff_wrapper_new_0(0, (void *)5));
    skiff_wrapper_t ** dave = skalloc_ref_stack();
    *(dave) = (skiff_wrapper_new_0(0, (void *)skiff_string_new_0(0, "My name Dave!")));
    skiff_println(((skiff_string_t *)(*dave)->class_ptr->getDat(*dave)));
    skfree_ref_stack(3);
    return (int32_t)(*intData)->class_ptr->getDat(*intData);
}
