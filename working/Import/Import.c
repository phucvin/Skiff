#include "/workspaces/Skiff/lib/std/skiff.h"


// Import Optional


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



// Import Collections/Array


///////////////////// Start Class Array /////////////////////////

typedef struct skiff_array_struct skiff_array_t;
void skiff_expand(skiff_array_t *, int32_t);
void * skiff_get_sub(skiff_array_t *, int32_t);
int32_t skiff_get_size(skiff_array_t *);
void skiff_remove_at(skiff_array_t *, int32_t);
void skiff_assign_sub(skiff_array_t *, void *, int32_t);
void skiff_append(skiff_array_t *, void *);
void skiff_remove(skiff_array_t *);
struct skiff_array_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    void (*expand)();
    void * (*getSub)();
    int32_t (*getSize)();
    void (*removeAt)();
    void (*assignSub)();
    void (*append)();
    void (*remove)();
};
struct skiff_array_class_struct skiff_array_interface;
struct skiff_array_struct 
{
    struct skiff_array_class_struct * class_ptr;
    uint8_t mark;
    skiff_list_t * data;
    int32_t cap;
    int32_t size;
};
void skiff_array_static()
{
    skiff_array_interface.class_refs = 1;
    skiff_array_interface.struct_size = sizeof(skiff_array_t);
    skiff_array_interface.parent = &skiff_any_ref_interface;
    skiff_array_interface.simple_name = "Array";
    skiff_array_interface.expand = skiff_expand;
    skiff_array_interface.getSub = skiff_get_sub;
    skiff_array_interface.getSize = skiff_get_size;
    skiff_array_interface.removeAt = skiff_remove_at;
    skiff_array_interface.assignSub = skiff_assign_sub;
    skiff_array_interface.append = skiff_append;
    skiff_array_interface.remove = skiff_remove;
}
skiff_array_t * skiff_array_new_0(skiff_array_t * this)
{
    skiff_array_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_array_t));
        this->class_ptr = &skiff_array_interface;
    }
    (this->cap) = (10);
    (this->size) = (0);
    (this->data) = (skiff_list_new_0(0, this->cap));
    skfree_ref_stack(0);
    return this;
}

void skiff_append(skiff_array_t * this, void * formal_elt)
{
    void ** elt = skalloc_ref_stack();
    *elt = formal_elt;
    if(this->size + 1 > this->cap)
    {
        (this)->class_ptr->expand(this, this->cap * 2);
        skfree_ref_stack(0);
    }
    (this->data)->class_ptr->assignSub((this->data), *(elt), this->size);
    (this->size++);
    skfree_ref_stack(1);
}

void skiff_expand(skiff_array_t * this, int32_t newCap)
{
    skiff_println((skiff_string_new_0(0, "Expanding!")));
    skiff_list_t ** oldData = skalloc_ref_stack();
    *(oldData) = (this->data);
    (this->data) = (skiff_list_new_0(0, newCap));
    int32_t i;
    (i) = (0);
    while(i < this->cap)
    {
        (this->data)->class_ptr->assignSub((this->data), ((*oldData)->class_ptr->getSub((*oldData), i)), i);
        skfree_ref_stack(0);
        (i++);
    }
    (this->cap) = (newCap);
    skfree_ref_stack(1);
}

void skiff_remove_at(skiff_array_t * this, int32_t index)
{
    (this->size--);
    int32_t i;
    (i) = (index);
    while(i < this->size)
    {
        (this->data)->class_ptr->assignSub((this->data), ((this->data)->class_ptr->getSub((this->data), i + 1)), i);
        skfree_ref_stack(0);
        (i++);
    }
    skfree_ref_stack(0);
}

void skiff_remove(skiff_array_t * this)
{
    (this)->class_ptr->removeAt(this, this->size - 1);
    skfree_ref_stack(0);
}

void * skiff_get_sub(skiff_array_t * this, int32_t i)
{
    skfree_ref_stack(0);
    return (this->data)->class_ptr->getSub((this->data), i);
}

void skiff_assign_sub(skiff_array_t * this, void * formal_elt, int32_t i)
{
    void ** elt = skalloc_ref_stack();
    *elt = formal_elt;
    (this->data)->class_ptr->assignSub((this->data), *(elt), i);
    skfree_ref_stack(1);
}

int32_t skiff_get_size(skiff_array_t * this)
{
    skfree_ref_stack(0);
    return this->size;
}

///////////////////// End Class Array /////////////////////////



// Import ./SimpleFile
void skiff_simple_function()
{
    skiff_println((skiff_string_new_0(0, "Another file!")));
    skfree_ref_stack(0);
}

#include "../../src/test/resources/Import/./c_header.h"

int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_array_static();
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
