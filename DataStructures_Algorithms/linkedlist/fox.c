
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};


struct fox {
    unsigned long tail_length; /* length in centimeters of tail */
    unsigned long weight; /* weight in kilograms */
    int is_fantastic; /* is this fox fantastic? */
    struct list_head list; /* list of all fox structures */
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)
#if 0
struct fox {
    unsigned long tail_length; /* length in centimeters of tail */
    unsigned long weight; /* weight in kilograms */
    bool is_fantastic; /* is this fox fantastic? */
    struct fox *next; /* next fox in linked list */
    struct fox *prev; /* previous fox in linked list */
};
#endif

#define container_of(ptr, type, member) ({ \
        const typeof( ((type *)0)->member ) *__mptr = (ptr); \
        (type *)( (char *)__mptr - offsetof(type,member) );})
#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)

static LIST_HEAD(fox_list);



static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
//        if (!__list_add_valid(new, prev, next))
                return;

        next->prev = new;
        new->next = next;
        new->prev = prev;
//        WRITE_ONCE(prev->next, new);
}


int main()
{
int i = 0;
for (i = 0; i < 10; i++)
{
struct fox *red_fox;
red_fox = (struct fox *) malloc(sizeof(*red_fox));
red_fox->tail_length = 40;
red_fox->weight = i+10;
red_fox->is_fantastic = -1;
//INIT_LIST_HEAD(&red_fox->list);
list_add(&red_fox->list, &fox_list);
}
	return 0;
}

