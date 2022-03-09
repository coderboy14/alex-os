#ifndef VFS_H
#define VFS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct VFSObjectHandle {
    
};

struct VFSObjectController {
    void* object_opened(VFSObject* object, uint8_t mode);
    void* object_closed();
    void* object_handle_invoke();
};

struct VFSObject {
    uint8_t object_type;

};

void vfs_open();

#endif