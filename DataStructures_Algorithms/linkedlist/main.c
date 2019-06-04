//#include <stdio.h>

struct list_head {
        struct list_head *next, *prev;
};

typedef signed char   		__s8;
typedef char 		 	__u8;
typedef signed short int  	__s16;
typedef unsigned short 		__u16;
typedef signed int		__s32;	
typedef unsigned int		__u32;
typedef signed long int		__s64;
typedef signed long int		__u64;

static __always_inline void __write_once_size(volatile void *p, void *res, int size)
{
        switch (size) {
        case 1: *(volatile __u8 *)p = *(__u8 *)res; break;
        case 2: *(volatile __u16 *)p = *(__u16 *)res; break;
        case 4: *(volatile __u32 *)p = *(__u32 *)res; break;
        case 8: *(volatile __u64 *)p = *(__u64 *)res; break;
        default:
                memcpy((void *)p, (const void *)res, size);
        }
}


#define WRITE_ONCE(x, val)				\
({                                                      \
        union { typeof(x) __val; char __c[1]; } __u =   \
                { .__val = (typeof(x)) (val) }; 	\
        __write_once_size(&(x), __u.__c, sizeof(x));    \
        __u.__val;                                      \
})


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)


static inline bool __list_add_valid(struct list_head *new,
                                struct list_head *prev,
                                struct list_head *next)
{
        return true;
}
static inline bool __list_del_entry_valid(struct list_head *entry)
{
        return true;
}


static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
        if (!__list_add_valid(new, prev, next))
                return;

        next->prev = new;
        new->next = next;
        new->prev = prev;
        WRITE_ONCE(prev->next, new);
}



static inline void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
        __list_add(new, head->prev, head);
}



static inline void __list_del_entry(struct list_head *entry)
{
        if (!__list_del_entry_valid(entry))
                return;

        __list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
{
        __list_del_entry(entry);
        entry->next = LIST_POISON1;
        entry->prev = LIST_POISON2;
}


static inline void __list_del(struct list_head * prev, struct list_head * next)
{
        next->prev = prev;
        WRITE_ONCE(prev->next, next);
}


static inline bool __list_add_valid(struct list_head *new,
                                struct list_head *prev,
                                struct list_head *next)
{
        return true;
}
static inline bool __list_del_entry_valid(struct list_head *entry)
{
        return true;
}


struct temp {
        struct list_head         ptr;
        int data;
}

static LIST_HEAD(pending);


int main()
{

	struct temp * ptr_1 = NULL;
	int i  = 0;
	for(i=0; i < 5; i++)
	{
		ptr_1 =(struct temp *)malloc(sizeof(struct temp));
     		list_add(&ptr_1->ptr, &pending);
	}
	return 0;
}
