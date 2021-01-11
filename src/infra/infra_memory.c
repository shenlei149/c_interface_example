#include <stdlib.h>

#include "infra_memory.h"
#include "infra_assert.h"

void *InfraMemory_alloc(long nbytes, const char *file, int line)
{
    InfraAssert_ASSERT(nbytes > 0, file, line);
    return malloc(nbytes);
}

void *InfraMemory_calloc(long count, long nbytes, const char *file, int line)
{
    InfraAssert_ASSERT(count > 0, file, line);
    InfraAssert_ASSERT(nbytes > 0, file, line);
    return calloc(count, nbytes);
}

extern void *InfraMemory_resize(void *ptr, long nbytes, const char *file, int line)
{
    InfraAssert_ASSERT(ptr, file, line);
    InfraAssert_ASSERT(nbytes > 0, file, line);
    ptr = realloc(ptr, nbytes);
    return ptr;
}

extern void InfraMemory_free(void *ptr)
{
    if (ptr)
    {
        free(ptr);
    }
}