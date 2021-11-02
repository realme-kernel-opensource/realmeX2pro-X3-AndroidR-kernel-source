#ifndef _OPPO_KERNEL2USER_H
#define _OPPO_KERNEL2USER_H

#include <net/sock.h>

/*NLMSG_MIN_TYPE is 0x10,so user to kernel we start at 0x20,kernel to user we start at 0x30*/
enum{
    OPPO_FOREGROUND_ANDROID_UID		= 0x20,
    OPPO_MPTCP_UID					= 0x21,
    OPPO_SEND_TCP_RETRANSMIT		= 0x30,
    OPPO_SEND_NETWORK_SCORE			= 0x31,
};

#define MAX_PARA_LEN 100
#define MAX_MPTCP_APP_LEN 100
#define MAX_LINK_LEN 32

struct general_oppo_info {
    u32 para_type;
    u32 para_one;
    u32 para_two;
    u32 para_three;
    char para_array[MAX_PARA_LEN];
};

extern u32 oppo_foreground_uid;
extern int oppo_kernel_send_to_user(int msg_type, char *payload, int payload_len);
extern void oppo_handle_retransmit(const struct sock *sk, int type);
extern uid_t get_uid_from_sock(const struct sock *sk);
extern int get_link_index_from_sock(const struct sock *sk);

#endif