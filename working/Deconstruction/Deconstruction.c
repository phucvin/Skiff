#include "/workspaces/Skiff/lib/std/skiff.h"




///////////////////// Start Class Person /////////////////////////

typedef struct skiff_person_struct skiff_person_t;
int32_t skiff_person_get_age(skiff_person_t *);
void skiff_person_set_age(skiff_person_t *, int32_t);
skiff_string_t * skiff_person_get_name(skiff_person_t *);
void skiff_person_set_name(skiff_person_t *, skiff_string_t *);
struct skiff_person_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    int32_t (*getAge)();
    void (*setAge)();
    skiff_string_t * (*getName)();
    void (*setName)();
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
    skiff_person_interface.class_refs = 1;
    skiff_person_interface.struct_size = sizeof(skiff_person_t);
    skiff_person_interface.parent = &skiff_any_ref_interface;
    skiff_person_interface.simple_name = "Person";
    skiff_person_interface.getAge = skiff_person_get_age;
    skiff_person_interface.setAge = skiff_person_set_age;
    skiff_person_interface.getName = skiff_person_get_name;
    skiff_person_interface.setName = skiff_person_set_name;
}
skiff_person_t * skiff_person_new_0(skiff_person_t * this, int32_t age, skiff_string_t * name)
{
    skiff_person_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_person_t));
        this->class_ptr = &skiff_person_interface;
    }
    (this->age) = age;
    (this->name) = name;
    return this;
}
int32_t skiff_person_get_age(skiff_person_t *this)
{
    return (this)->age;
}
void skiff_person_set_age(skiff_person_t *this, int32_t new_value)
{
    (this)->age = new_value;
}
skiff_string_t * skiff_person_get_name(skiff_person_t *this)
{
    return (this)->name;
}
void skiff_person_set_name(skiff_person_t *this, skiff_string_t * new_value)
{
    (this)->name = new_value;
}


///////////////////// End Class Person /////////////////////////




///////////////////// Start Class Teacher /////////////////////////

typedef struct skiff_teacher_struct skiff_teacher_t;
skiff_string_t * skiff_teacher_get_grade(skiff_teacher_t *);
void skiff_teacher_set_grade(skiff_teacher_t *, skiff_string_t *);
struct skiff_teacher_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    int32_t (*getAge)();
    void (*setAge)();
    skiff_string_t * (*getName)();
    void (*setName)();
    skiff_string_t * (*getGrade)();
    void (*setGrade)();
};
struct skiff_teacher_class_struct skiff_teacher_interface;
struct skiff_teacher_struct 
{
    struct skiff_teacher_class_struct * class_ptr;
    uint8_t mark;
    skiff_string_t * name;
    int32_t age;
    skiff_string_t * grade;
};
void skiff_teacher_static()
{
    skiff_teacher_interface.class_refs = 1;
    skiff_teacher_interface.struct_size = sizeof(skiff_teacher_t);
    skiff_teacher_interface.parent = &skiff_person_interface;
    skiff_teacher_interface.simple_name = "Teacher";
    skiff_teacher_interface.getAge = skiff_person_get_age;
    skiff_teacher_interface.setAge = skiff_person_set_age;
    skiff_teacher_interface.getName = skiff_person_get_name;
    skiff_teacher_interface.setName = skiff_person_set_name;
    skiff_teacher_interface.getGrade = skiff_teacher_get_grade;
    skiff_teacher_interface.setGrade = skiff_teacher_set_grade;
}
skiff_teacher_t * skiff_teacher_new_0(skiff_teacher_t * this, int32_t age, skiff_string_t * name, skiff_string_t * grade)
{
    skiff_teacher_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_teacher_t));
        this->class_ptr = &skiff_teacher_interface;
    }
    (this->age) = age;
    (this->name) = name;
    (this->grade) = grade;
    return this;
}
skiff_string_t * skiff_teacher_get_grade(skiff_teacher_t *this)
{
    return (this)->grade;
}
void skiff_teacher_set_grade(skiff_teacher_t *this, skiff_string_t * new_value)
{
    (this)->grade = new_value;
}


///////////////////// End Class Teacher /////////////////////////


int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_teacher_static();
    skiff_list_static();
    skiff_string_static();
    skiff_person_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_teacher_t ** data = skalloc_ref_stack();
    *(data) = (skiff_teacher_new_0(0, 15, skiff_string_new_0(0, "James"), skiff_string_new_0(0, "10th")));
        int32_t pAge;
    pAge = ((skiff_person_t *) *data)->age;
    skiff_string_t ** pName = skalloc_ref_stack();
    *pName = ((skiff_person_t *) *data)->name;

    skiff_print((skiff_string_new_0(0, "Name:")));
    skiff_println(*(pName));
    if(instance_of((skiff_any_ref_t *)*data, &skiff_teacher_interface))
    {
        int32_t age;
        age = ((skiff_teacher_t *) *data)->age;
        skiff_string_t ** name = skalloc_ref_stack();
        *name = ((skiff_teacher_t *) *data)->name;
        skiff_string_t ** grade = skalloc_ref_stack();
        *grade = ((skiff_teacher_t *) *data)->grade;
        skiff_println(*(name));
        skiff_println(*(grade));
        skfree_ref_stack(2);
    }
    else if(instance_of((skiff_any_ref_t *)*data, &skiff_person_interface))
    {
        skiff_person_t ** p = skalloc_ref_stack();
        *p = (skiff_person_t *) *data;
        skiff_println(((skiff_string_t *)(*p)->class_ptr->getName(*p)));
        skfree_ref_stack(1);
    }

    skfree_ref_stack(3);
    return pAge;
}
