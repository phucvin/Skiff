#include "/workspaces/Skiff/lib/std/skiff.h"


// Import Files/File
#include "../../lib/Files/./skiff_file.h"







///////////////////// Start Class File /////////////////////////

typedef struct skiff_file_struct skiff_file_t;
skiff_string_t * skiff_read_all(skiff_file_t *);
void skiff_open(skiff_file_t *);
struct skiff_file_class_struct 
{
    int32_t class_refs;
    int32_t struct_size;
    void * parent;
    char * simple_name;
    skiff_string_t * (*readAll)();
    void (*open)();
};
struct skiff_file_class_struct skiff_file_interface;
struct skiff_file_struct 
{
    struct skiff_file_class_struct * class_ptr;
    uint8_t mark;
    skiff_string_t * fileName;
    skiff_list_t * buffer;
    int32_t fileDesc;
    uint8_t isOpen;
};
void skiff_file_static()
{
    skiff_file_interface.class_refs = 2;
    skiff_file_interface.struct_size = sizeof(skiff_file_t);
    skiff_file_interface.parent = &skiff_any_ref_interface;
    skiff_file_interface.simple_name = "File";
    skiff_file_interface.readAll = skiff_read_all;
    skiff_file_interface.open = skiff_open;
}
skiff_file_t * skiff_file_new_0(skiff_file_t * this, skiff_string_t * formal_fileName)
{
    skiff_file_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_file_t));
        this->class_ptr = &skiff_file_interface;
    }
    skiff_string_t ** fileName = skalloc_ref_stack();
    *fileName = formal_fileName;
    ((this)->fileName) = *(fileName);
    ((this)->isOpen) = (0);
    ((this)->buffer) = (skiff_list_new_0(0, 4096));
    skfree_ref_stack(1);
    return this;
}

skiff_file_t * skiff_file_new_1(skiff_file_t * this, int32_t fd)
{
    skiff_file_static();
    if(this == 0) 
    { 
        this = skalloc(1, sizeof(skiff_file_t));
        this->class_ptr = &skiff_file_interface;
    }
    ((this)->fileName) = (skiff_string_new_0(0, ""));
    ((this)->fileDesc) = (fd);
    ((this)->isOpen) = (1);
    ((this)->buffer) = (skiff_list_new_0(0, 4096));
    skfree_ref_stack(0);
    return this;
}

skiff_string_t * skiff_read_all(skiff_file_t * this)
{
    (this)->class_ptr->open(this);
    int32_t read;
    (read) = (0);
    (read) = (skiff_read_to_buffer((this->fileDesc), (this->buffer)));
    skfree_ref_stack(0);
    return skiff_decode_bytes((this->buffer), (read));
}

void skiff_open(skiff_file_t * this)
{
    if((this)->isOpen)
    {
        skfree_ref_stack(0);
        return;
        skfree_ref_stack(0);
    }
    ((this)->fileDesc) = (skiff_open_fd(((this)->fileName)));
    ((this)->isOpen) = (1);
    skfree_ref_stack(0);
}

///////////////////// End Class File /////////////////////////



int32_t skiff_main(skiff_list_t * formal_args)
{
    skiff_any_ref_static();
    skiff_list_static();
    skiff_string_static();
    skiff_file_static();
    skiff_exception_static();
    skiff_list_t ** args = skalloc_ref_stack();
    *args = formal_args;
    skiff_file_t ** myFile = skalloc_ref_stack();
    *(myFile) = (skiff_file_new_0(0, skiff_string_new_0(0, "./testFile.txt")));
    skiff_string_t ** myText = skalloc_ref_stack();
    *(myText) = ((skiff_string_t *)(*myFile)->class_ptr->readAll(*myFile));
    skiff_print(*(myText));
    skfree_ref_stack(3);
    return 0;
}
