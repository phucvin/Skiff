#include "/workspaces/Skiff/lib/std/skiff.h"




///////////////////// Start Class Optional /////////////////////////

typedef struct skiff_optional_struct skiff_optional_t;
void * skiff_get(skiff_optional_t *);
uint8_t skiff_is_present(skiff_optional_t *);
struct skiff_optional_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    void * (*get)();
    uint8_t (*isPresent)();
};
struct skiff_optional_class_struct skiff_optional_interface;
struct skiff_optional_struct 
{
    struct skiff_optional_class_struct * class_ptr;
    uint8_t mark;
    void * data;
};
void skiff_optional_static()
{
    skiff_optional_interface.class_refs = 1;
    skiff_optional_interface.struct_size = sizeof(skiff_optional_t);
    skiff_optional_interface.parent = &skiff_any_ref_interface;
    skiff_optional_interface.simple_name = "Optional";
    skiff_optional_interface.get = skiff_get;
    skiff_optional_interface.isPresent = skiff_is_present;
}
skiff_optional_t * skiff_optional_new_0(skiff_optional_t * this, void * formal_data)
{
    skiff_optional_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_optional_t));
        this->class_ptr = &skiff_optional_interface;
    }
    void ** data = skalloc_ref_stack();
    *data = formal_data;
    ((this)->data) = *(data);
    skfree_ref_stack(1);
    return this;
}

skiff_optional_t * skiff_static_of(void * formal_data)
{
    void ** data = skalloc_ref_stack();
    *data = formal_data;
    skfree_ref_stack(1);
    return skiff_optional_new_0(0, (void *)*data);
}

skiff_optional_t * skiff_static_empty()
{
    skfree_ref_stack(0);
    return skiff_optional_new_0(0, (void *)0);
}

void * skiff_get(skiff_optional_t * this)
{
    skfree_ref_stack(0);
    return this->data;
}

uint8_t skiff_is_present(skiff_optional_t * this)
{
    skfree_ref_stack(0);
    return this->data != 0;
}

///////////////////// End Class Optional /////////////////////////


int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_optional_static();
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_optional_t ** op = skalloc_ref_stack();
    *(op) = (skiff_static_of((void *)5));
    if((*op)->class_ptr->isPresent(*op))
    {
        skfree_ref_stack(0);
        return (int32_t)(*op)->class_ptr->get(*op);
        skfree_ref_stack(0);
    }
    else
    {
        skfree_ref_stack(0);
        return 0;
    }
    skfree_ref_stack(2);
}
