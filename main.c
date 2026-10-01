#include "server_socket.h"

int main()
{
	create_bind_socket();
	on_wait_request(NULL);
	return 0;
}
