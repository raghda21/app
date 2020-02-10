
#include <stdio.h>
#include <winsock2.h>  //socket ap's

#pragma comment(lib,"ws2_32.lib")
int main ()
{
    WSADATA wsa;  //only for windows
    SOCKET s;  //socket descriptor
   struct sockaddr_in server;    //only for windows
   printf("\n INitialising Winsock....");
   if (WSAStartup(MAKEWORD(2,2),&wsa)  != 0)
   {
       printf("faild error code :%d",WSAGetLastError());
       return 1;
   }
   printf("initilazing.\n");


//creat a socket
   //we have to first create discriptor and give 1-socket family the 2-socket stream type 3-protocal(usually 0)
   if((s=socket (AF_INET ,SOCK_STREAM,0))== INVALID_SOCKET)
   {
       printf("could not creat socket :%d",WSAGetLastError());
   }
   printf("Socket created successfully \n ");


   server.sin_family=AF_INET;  //ADDRESS FAMILY IPv4
   server.sin_port=htons(80); //putting the host port (http port 80)
   server.sin_addr.s_addr=inet_addr("184.106.153.149");  //putting server address into descriptor

 
     //connection to remote server using TCP/IP
   connect(s,(struct sockaddr *)&server,sizeof(server));
   if(connect(s,(struct sockaddr*)&server , sizeof(server)),0){
       puts("Connect Error");
   }
   else{
       puts("Connection Initialized Successfully.\n");
   }
  /* char message[50]="GET /HTTP/1.1\r\n\r\n";
  // char recv_buf[2000]="";

   send(s,message,strlen(message),0);
  // print("%d",5);
  // recv(s,recv_buf,2000,0);
   //puts(recv_buf);*/

   char  message[200]="GET https://api.thingspeak.com/update?api_key=VV33CG4A57MMN20C&field1=20\r\n\r\n";
               send(s,message,strlen(message),0);


   closesocket (s);


return 0;

}
