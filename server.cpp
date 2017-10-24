#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>    
#include <string>
#include <iostream>
using namespace std;
short SocketCreate(void){
	short hSocket;
	printf("Create the socket\n");
	hSocket = socket(AF_INET, SOCK_STREAM, 0);
	return hSocket;
}
int BindCreatedSocket(int hSocket){
	int iRetval=-1;
	int ClientPort = 90190;
	struct sockaddr_in  remote={0};
	remote.sin_family = AF_INET; /* Internet address family */
	remote.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
	remote.sin_port = htons(ClientPort); /* Local port */
	iRetval = bind(hSocket,(struct sockaddr *)&remote,sizeof(remote));
    return iRetval;
}
int main(int argc , char *argv[]){
	int socket_desc , sock , clientLen , read_size;
	struct sockaddr_in server , client;
	char client_message[200]={0};
	char message[100] = {0};
	const char *pMessage = "hello aticleworld.com";
	socket_desc = SocketCreate();
	if (socket_desc == -1){
		cout<<"Could not create socket";
		return 1;
	}
	if( BindCreatedSocket(socket_desc) < 0){
		cerr<<("bind failed.");
		return 1;
	}
	listen(socket_desc , 3);
	int sum=0;
	int count_so_far=2;
	while(1){
		cout<<"Waiting for incoming connections...\n";
		clientLen = sizeof(struct sockaddr_in);
		sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);
		if (sock < 0){
			cerr<<("accept failed");
			return 1;
		}
		string msg="yay";
		memset(client_message, '\0', sizeof client_message);
		memset(message, '\0', sizeof message);
		if( recv(sock , client_message , 200 , 0) < 0){
			cout<<("recv failed");
			break;
		}
		sum+=atoi(client_message);
		int ans=((count_so_far*(count_so_far+1))/2)-sum;
		cout<<"value is "<<ans<<endl;
		if( send(sock , msg.c_str() , msg.length() , 0) < 0)
		{
			cout<<"Send failed";
			return 1;
		}
		count_so_far++;
		close(sock);
		sleep(1);
	}
    return 0;
}