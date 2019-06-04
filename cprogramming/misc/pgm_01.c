

typedef signed char         s8_t;
typedef signed short        s16_t;
typedef signed int          s32_t;
typedef signed long long    s64_t;

typedef unsigned char       u8_t;
typedef unsigned short      u16_t;
typedef unsigned int        u32_t;
typedef unsigned long long  u64_t;



static struct {
        struct net_buf *buf;
        struct k_fifo   fifo;

        u16_t    remaining;
        u16_t    discard;

        bool     have_hdr;
        bool     discardable;

        u8_t     hdr_len;

        u8_t     type;
        union {
                struct bt_hci_evt_hdr evt;
                struct bt_hci_acl_hdr acl;
                u8_t hdr[4];
        };
} rx = {
        .fifo = Z_FIFO_INITIALIZER(rx.fifo),
};


int main()
{

	return 0;
}
