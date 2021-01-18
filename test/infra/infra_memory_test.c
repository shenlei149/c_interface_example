#include <criterion/criterion.h>

#include "../../src/infra/infra_memory.h"

TestSuite(infra_memory);

Test(infra_memory, mem)
{
    void *ptr = InfraMemory_ALLOC(100);
    InfraMemory_CALLOC(4, 100);
    InfraMemory_RESIZE(ptr, 200);
    InfraMemory_FREE(ptr);
    cr_assert_null(ptr);
}
