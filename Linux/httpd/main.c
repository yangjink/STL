#include "httpd.h"
#include <pthread.h>

void usage(const char* arg)
{
	printf("Usage: %s   [local_ip]  [local_port]\n",arg);
}

int main(int argc,const char* argv[])
{
	
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}
	
	int listen_sock = startup(argv[1],atoi(argv[2]));

	while(1)
	{
		struct sockaddr_in client;
		socklen_t len = sizeof(client);
		int new_fd = accept(listen_sock,(struct sockaddr*)&client,&len);
		if(new_fd < 0)
		{
			print_log(strerror(errno),WARNING);
			continue;
		}

		printf("get a new client , %s:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

		pthread_t id;
		pthread_create(&id,NULL,handler_request,(void*)new_fd);
		pthread_detach(id);
	}
	
	return 0;
}
