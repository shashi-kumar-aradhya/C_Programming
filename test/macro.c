#include <stdio.h>
#include <linux/types.h>
struct i2c_msg {
        __u16 addr;     /* slave address                        */
        __u16 flags;
#define I2C_M_TEN               0x0010  /* this is a ten bit chip address */
#define I2C_M_RD                0x0001  /* read data, from slave to master */
#define I2C_M_STOP              0x8000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_NOSTART           0x4000  /* if I2C_FUNC_NOSTART */
#define I2C_M_REV_DIR_ADDR      0x2000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_IGNORE_NAK        0x1000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_NO_RD_ACK         0x0800  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_RECV_LEN          0x0400  /* length will be first received byte */
        __u16 len;              /* msg length                           */
        __u8 *buf;              /* pointer to msg data                  */
};

int main() 
{
	struct temp {
		#define TEMP 10
	}temp;
	struct i2c_msg i2c_msg_1;
	fun();
	printf("size_1 = %ld\n", sizeof(i2c_msg_1));
	printf("size_2 = %ld\n", sizeof(i2c_msg_1.addr));
	printf("size_3 = %ld\n", sizeof(i2c_msg_1.flags));
	printf("size_4 = %ld\n", sizeof(i2c_msg_1.len));
	printf("size_5 = %ld\n", sizeof(i2c_msg_1.buf));
	printf("size_6 = %ld\n", sizeof(*i2c_msg_1.buf));
	printf("size_7 = %ld\n", I2C_M_TEN);
	printf("size_8 = %ld\n", sizeof(temp));
	printf("size_9 = %ld\n", TEMP&10);
	return 0;
}
void fun() 
{
	printf("size_9 = %ld\n", TEMP&10);
}	
