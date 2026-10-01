// AF_INET: use IPv4 (vs IPv6)
// SOCK_STREAM: use TCP (vs UDP)
// INADDR_ANY: the server accepts connections from any network interface
//

#ifndef SERVER_SOCKET_HEAD
#define SERVER_SOCKET_HEAD
#ifdef __cplusplus
extern "C"
#endif
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#define PORT 8080
#define SA   struct sockaddr

	void create_bind_socket();
void *on_wait_request(void *arg);
void read_request(struct sockaddr_in *cli, int len);
void write_reply();

#endif
