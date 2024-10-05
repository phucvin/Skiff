#include "/workspaces/Skiff/lib/std/skiff.h"




///////////////////// Start Class Thing /////////////////////////

typedef struct skiff_thing_struct skiff_thing_t;
skiff_string_t * skiff_get_name(skiff_thing_t *);
struct skiff_thing_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    skiff_string_t * (*getName)();
};
struct skiff_thing_class_struct skiff_thing_interface;
struct skiff_thing_struct 
{
    struct skiff_thing_class_struct * class_ptr;
    uint8_t mark;
    skiff_string_t * name;
};
void skiff_thing_static()
{
    skiff_thing_interface.class_refs = 1;
    skiff_thing_interface.struct_size = sizeof(skiff_thing_t);
    skiff_thing_interface.parent = &skiff_any_ref_interface;
    skiff_thing_interface.simple_name = "Thing";
    skiff_thing_interface.getName = skiff_get_name;
}
skiff_thing_t * skiff_thing_new_0(skiff_thing_t * this, skiff_string_t * formal_name)
{
    skiff_thing_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_thing_t));
        this->class_ptr = &skiff_thing_interface;
    }
    skiff_string_t ** name = skalloc_ref_stack();
    *name = formal_name;
    ((this)->name) = *(name);
    skfree_ref_stack(1);
    return this;
}

skiff_string_t * skiff_get_name(skiff_thing_t * this)
{
    skfree_ref_stack(0);
    return this->name;
}

///////////////////// End Class Thing /////////////////////////




///////////////////// Start Class Person /////////////////////////

typedef struct skiff_person_struct skiff_person_t;
int32_t skiff_get_age(skiff_person_t *);
void skiff_inc_age(skiff_person_t *);
struct skiff_person_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    skiff_string_t * (*getName)();
    int32_t (*getAge)();
    void (*incAge)();
};
struct skiff_person_class_struct skiff_person_interface;
struct skiff_person_struct 
{
    struct skiff_person_class_struct * class_ptr;
    uint8_t mark;
    skiff_string_t * name;
    int32_t age;
};
void skiff_person_static()
{
    skiff_person_interface.class_refs = 0;
    skiff_person_interface.struct_size = sizeof(skiff_person_t);
    skiff_person_interface.parent = &skiff_thing_interface;
    skiff_person_interface.simple_name = "Person";
    skiff_person_interface.getName = skiff_get_name;
    skiff_person_interface.getAge = skiff_get_age;
    skiff_person_interface.incAge = skiff_inc_age;
}
skiff_person_t * skiff_person_new_0(skiff_person_t * this, skiff_string_t * formal_name, int32_t age)
{
    skiff_person_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_person_t));
        this->class_ptr = &skiff_person_interface;
    }
    skiff_string_t ** name = skalloc_ref_stack();
    *name = formal_name;
    skiff_thing_new_0((skiff_thing_t *) this, *(name));
    ((this)->age) = (age);
    skfree_ref_stack(1);
    return this;
}

void skiff_inc_age(skiff_person_t * this)
{
    ((this)->age) = (this->age + 1);
    skfree_ref_stack(0);
}

int32_t skiff_get_age(skiff_person_t * this)
{
    skfree_ref_stack(0);
    return (this)->age;
}

///////////////////// End Class Person /////////////////////////


int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_person_static();
    skiff_exception_static();
    skiff_thing_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_thing_t ** thing = skalloc_ref_stack();
    *(thing) = (skiff_thing_t *)(skiff_person_new_0(0, skiff_string_new_0(0, "Dave"), 15));
    skiff_println(((skiff_string_t *)(*thing)->class_ptr->getName(*thing)));
    skiff_person_t ** dave = skalloc_ref_stack();
    *(dave) = (skiff_person_t *)*(thing);
    (*dave)->class_ptr->incAge(*dave);
    skfree_ref_stack(3);
    return (int32_t)(*dave)->class_ptr->getAge(*dave);
}
