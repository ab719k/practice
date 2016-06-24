/*

demo_tester for updating random sensor data to m2x server

*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <stdio.h>
#include <string.h>

#define MODULE_TEST


#define APPL_TRACE_ERROR1 printf
#define APPL_TRACE_ERROR2 printf
#define APPL_TRACE_WARNING1 printf


#define UINT32_TO_STREAM(p, u32) {*(p)++ = (uint8_t)(u32); *(p)++ = (uint8_t)((u32) >> 8); *(p)++ = (uint8_t)((u32) >> 16); *(p)++ = (uint8_t)((u32) >> 24);}
#define UINT24_TO_STREAM(p, u24) {*(p)++ = (uint8_t)(u24); *(p)++ = (uint8_t)((u24) >> 8); *(p)++ = (uint8_t)((u24) >> 16);}
#define UINT16_TO_STREAM(p, u16) {*(p)++ = (uint8_t)(u16); *(p)++ = (uint8_t)((u16) >> 8);}
#define UINT8_TO_STREAM(p, u8)   {*(p)++ = (uint8_t)(u8);}
#define INT8_TO_STREAM(p, u8)    {*(p)++ = (int8_t)(u8);}
#define ARRAY32_TO_STREAM(p, a)  {register int ijk; for (ijk = 0; ijk < 32;           ijk++) *(p)++ = (uint8_t) a[31 - ijk];}
#define ARRAY16_TO_STREAM(p, a)  {register int ijk; for (ijk = 0; ijk < 16;           ijk++) *(p)++ = (uint8_t) a[15 - ijk];}
#define ARRAY8_TO_STREAM(p, a)   {register int ijk; for (ijk = 0; ijk < 8;            ijk++) *(p)++ = (uint8_t) a[7 - ijk];}

#define STREAM_TO_UINT8(u8, p)   {u8 = (uint8_t)(*(p)); (p) += 1;}
#define STREAM_TO_UINT16(u16, p) {u16 = ((uint16_t)(*(p)) + (((uint16_t)((uint16_t)*((p) + 1))) << 8)); (p) += 2;}
#define STREAM_TO_UINT24(u32, p) {u32 = (((uint32_t)(*(p))) + ((((uint32_t)(*((p) + 1)))) << 8) + ((((uint32_t)(*((p) + 2)))) << 16) ); (p) += 3;}
#define STREAM_TO_UINT32(u32, p) {u32 = (((uint32_t)(*(p))) + ((((uint32_t)(*((p) + 1)))) << 8) + ((((uint32_t)(*((p) + 2)))) << 16) + ((((uint32_t)(*((p) + 3)))) << 24)); (p) += 4;}

#define STREAM_TO_ARRAY32(a, p)  {register int ijk; register uint8_t *_pa = (uint8_t *)a + 31; for (ijk = 0; ijk < 32; ijk++) *_pa-- = *p++;}
#define STREAM_TO_ARRAY16(a, p)  {register int ijk; register uint8_t *_pa = (uint8_t *)a + 15; for (ijk = 0; ijk < 16; ijk++) *_pa-- = *p++;}
#define STREAM_TO_ARRAY8(a, p)   {register int ijk; register uint8_t *_pa = (uint8_t *)a + 7; for (ijk = 0; ijk < 8; ijk++) *_pa-- = *p++;}


#define NULL     0
#define FALSE  0
#define TRUE   (!FALSE)
typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned int    UINT32;
typedef unsigned long long  UINT64;
typedef signed   int    INT32;
typedef signed   char   INT8;
typedef signed   short  INT16;
typedef unsigned char   BOOLEAN;
typedef unsigned long   UINTPTR;



int socket_client_open(UINT8 *sock_name)
{
    int sock = -1;
	char errorstring[80];
	struct sockaddr_un server_address;
	int status;

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sock < 0)
    {
		strerror_r(errno, errorstring, sizeof(errorstring));
        printf("socket_client_open: socket failed(%s)", errorstring);
		return -1;
    }

	/* Set socket parameters */
    memset((char *) &server_address, 0, sizeof(server_address));
    server_address.sun_family = AF_UNIX;
	server_address.sun_path[0] = 0;
	
	strncat(server_address.sun_path, (char*)sock_name,
            sizeof(server_address.sun_path)-1-strlen(server_address.sun_path));

    /* Connect to the server socket */
    status = connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));

    if (status < 0)
    {
        strerror_r(errno, errorstring, sizeof(errorstring));
        printf("socket_client_open: connect(%s) failed(%s)",
                server_address.sun_path, errorstring);
        close(sock);
        return -1;
    }

    return sock;
}

void send_data(int m2x_sock_fd)
{
	UINT8 buffer[16];
	UINT16 len = 0;
	UINT8 *ptr;
	int status = 0;
	char errorstring[80];
        int n=0;
        int i =0;
	ptr = buffer;

    
	UINT8 buffer1[12]={0x0a, 0x00, 0x6f, 0x2a, 0x45, 0x20, 0x01, 0x18, 0x10, 0x00, 0xe6, 0x01};
	UINT8 buffer2[12]={0x0a, 0x00, 0x6d, 0x2a, 0x45, 0x20, 0x01, 0x18, 0x10, 0x00, 0x95, 0x27};
	UINT8 buffer3[12]={0x0a, 0x00, 0x6e, 0x2a, 0x45, 0x20, 0x01, 0x18, 0x10, 0x00, 0xe9, 0x00};
	UINT8 buffer4[12]={0x0a, 0x00, 0xa1, 0x2a, 0x45, 0x20, 0x01, 0x18, 0x10, 0x00, 0xe6, 0x01};
	UINT8 buffer5[16]={0x0e, 0x00, 0xa0, 0xbb, 0x45, 0x20, 0x01, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	UINT8 buffer6[16]={0x0e, 0x00, 0xa1, 0xbb, 0x45, 0x20, 0x01, 0x18, 0x10, 0x00, 0xc8, 0x00, 0x58, 0xff, 0x00, 0x00};

/*

0a 00 6f 2a 45 20 01 18 10 00 e6 01
0a 00 6d 2a 45 20 01 18 10 00 95 27 
0a 00 6e 2a 45 20 01 18 10 00 e9 00 
0a 00 6f 2a 45 20 01 18 10 00 e6 01 
0e 00 a0 bb 45 20 01 18 10 00 00 00 00 00 00 00
0e 00 a1 bb 45 20 01 18 10 00 c8 00 58 ff 00 00 

*/

  printf("Sending 3D Data:", buffer, len+2);
  i=1;
  while(i < 1000)
  { 
    if (m2x_sock_fd > 0)
    {
          buffer1[11]= rand() % (n+i);           
          buffer2[11]= rand() % (n+i);           
          buffer3[11]= rand() % (n+i);           
          buffer4[11]= rand() % (n+i);           
          buffer5[11]= rand() % (n+i);           
          buffer6[11]= rand() % (n+i);                     
          buffer1[10]= rand() % (n+i);           
          buffer2[10]= rand() % (n+i);           
          buffer3[10]= rand() % (n+i);           
          buffer4[10]= rand() % (n+i);           
          buffer5[10]= rand() % (n+i);           
          buffer6[10]= rand() % (n+i);

          switch(n++)
          {
          case 0:
               status = write(m2x_sock_fd, buffer1, 12);
               break;
          case 1:
               status = write(m2x_sock_fd, buffer2, 12);
               break;
          case 2:
               status = write(m2x_sock_fd, buffer3, 12);
               break;
          case 3:
               status = write(m2x_sock_fd, buffer4, 12);
               break;               
          case 4:
               status = write(m2x_sock_fd, buffer5, 16);
               break;
          case 5:
              status = write(m2x_sock_fd, buffer6, 16);
               break;                
          }
          if(n>4) n=0;
/*		status = write(m2x_sock_fd, buffer1, 12);*/
		if(status < 0)
		{
			strerror_r(errno, errorstring, sizeof(errorstring));
			printf("Write to M2x socket failed: %s", errorstring );
		}
           sleep(10);
	}
	else
	{
		printf("Socket not connected with M2X ");
	}	
        i++;
  }
  printf("exit");
}



int main(int argc, char *argv[])
{
    int server_fd = 0;
    int client_fd = 0;

/*    server_fd = socket_server_open ("/tmp/wiced_m2x_sock");
    printf("socket_local_client: fd = %d \n", server_fd);
    if(server_fd > 0)
    {
        printf("socket_local_server: opening server socket successful \n");
    }
    else
    {
        printf("socket_local_server: returned error %d \n", errno );
        exit(0);
    }
*/
    client_fd = socket_client_open("/tmp/wiced_m2x_sock" );
    printf("socket_local_client: fd = %d \n", client_fd);

    if(client_fd > 0)
    {
        printf("socket_local_client: opening client socket successful \n");
        send_data(client_fd);

    }
    else
        printf("socket_local_client: returned error %d \n", errno );
     
    close(server_fd);   
    close(client_fd);   
}

