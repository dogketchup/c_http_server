#include "server_socket.h"
#include <netinet/in.h>
#include <signal.h>
#include <stdatomic.h>
#include <sys/socket.h>

static volatile int serv_fd, conn_fd;

static struct sockaddr_in serv_addr, cli;

static void signalHandler(int sig)
{
	printf("Interrupt handle %i", sig);
	close(serv_fd);

	// Optionally exit the program after handling
	exit(sig);
}

void create_bind_socket()
{
	serv_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (serv_fd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	} else
		printf("Socket successfully created..\n");
	bzero(&serv_addr, sizeof(serv_addr));
	if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = atol(INADDR_ANY);
	serv_addr.sin_port = PORT;

	if ((bind(serv_fd, (SA *)&serv_addr, sizeof(serv_addr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	} else
		printf("Socket successfully binded..\n");
}

// wait for request and establish one connecion
void *on_wait_request(void *arg)
{
	signal(SIGINT, signalHandler);

	for (;;) {

		if ((listen(serv_fd, 5)) != 0) {
			printf("Listen failed...\n");
			exit(0);
		} else
			printf("Server listening..\n");

		int len = sizeof(cli);

		conn_fd = accept(serv_fd, (SA *)&cli, &len);
		if (conn_fd < 0) {
			printf("server accept failed...\n");
			exit(0);
		} else
			printf("server accept the client...\n");

		const char *accept = "201";
		send(conn_fd, accept, 10, 0);
		close(conn_fd);
	}
}

void read_request(struct sockaddr_in *cli, int len)
{
	// Function for chatting between client and server
}

void write_reply();
