#include <stdio.h>

#include "linkedlist.h"
#include "error.h"

STATUS_CODES create(list *head)
{
        head = (list *)malloc(sizeof(list));
        if (NULL == head)
                return STATUS_MEMFAIL;
        return STATUS_OK;
}

