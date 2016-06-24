/*****************************************************************************
**
**  Name:           sock_util.c
**
**  Description:    Socket API
**
**  Copyright (c) 2013, Broadcom Corp., All Rights Reserved.
**  Broadcom Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/


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

#define LISTEN_BACKLOG 5


/*******************************************************************************
 **
 ** Function         socket_server_open
 **
 ** Description     
 **                 
 **                 
 **
 ** Returns          int
 **
 *******************************************************************************/
int socket_server_open(unsigned char *socket_name)
{
    int sock = -1;
    struct sockaddr_un server_address;
    int status;
    char errorstring[80];

    /*sock = socket(AF_UNIX, SOK_STREAM, 0);*/
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock < 0) 
    {
        strerror_r(errno, errorstring, sizeof(errorstring));
        printf("socket_server_open: socket failed(%s) \n", errorstring);
        return -1;
    }

    memset((char *) &server_address, 0 , sizeof(server_address));
/*    server_address.sun_family = AF_UNIX;
    server_address.sun_path[0] = 0;*/
    server.sin_addr.s_addr = inet_addr("104.131.167.239");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );    

    strncat(server_address.sun_path, (char*)socket_name, sizeof(server_address.sun_path)-1-strlen(server_address.sun_path));

     /* Remove old socket (if previous server closed without removing it) */
    if (unlink(server_address.sun_path) == 0)
    {
        printf("socket_server_open: removed old file:%s \n", socket_name);
    }

    
    if (bind(sock, (struct sockaddr *) &server_address,
            sizeof(server_address)) < 0)
    {
        strerror_r(errno, errorstring, sizeof(errorstring));
        printf("socket_server_open: bind failed(%s) \n", errorstring);
        close(sock);
        return -1;
    }

    /* Set up queue for incoming connections. */
    status = listen(sock, LISTEN_BACKLOG);
    if (status < 0)
    {
        strerror_r(errno, errorstring, sizeof(errorstring));
        printf("socket_server_open: listen failed(%s) \n", errorstring);
        close(sock);
        return -1;
    }

    return sock;
}
/*******************************************************************************
 **
 ** Function         accept_socket_conn
 **
 ** Description     
 **                 
 **                 
 **
 ** Returns          int
 **
 *******************************************************************************/

int accept_socket_conn(int server_fd )
{
    int max_fd = -1;
    int new_fd = -1;
    fd_set socks_rd;
    int status = 0;
    unsigned short length;
    unsigned char buf[20];
    char errorstring[80];

    while (1)
    {
        FD_ZERO(&socks_rd);
        FD_SET(server_fd, &socks_rd);
        max_fd  = server_fd;

        status = select (max_fd + 1, &socks_rd, (fd_set *) NULL,(fd_set *) NULL,NULL);
        if(status < 0)
        {   
            strerror_r(errno, errorstring, sizeof(errorstring));
            printf("server: select failed(%s) \n", errorstring);
            exit(0);
        }
        else
        {
             length  = 0;

            if(FD_ISSET(server_fd, &socks_rd))
            {
                new_fd = accept(server_fd, NULL, NULL);
                if ( new_fd < 0) 
                {
                    strerror_r(errno, errorstring, sizeof(errorstring));
                    printf("server: accept error %s \n", errorstring);
                }
                else
                {
                    printf("server: client connected %d \n", new_fd);
                    break;
                }
            }
        }
    }
    return new_fd;
}

/*******************************************************************************
 **
 ** Function         read_socket
 **
 ** Description     
 **                 
 **                 
 **
 ** Returns          int
 **
 *******************************************************************************/

int read_socket(int * ptr_read_fd, unsigned char *buf)
{
    int max_fd = -1;
    int read_fd = -1;
    fd_set socks_rd;
    int status = 0;
    unsigned short length;
    char errorstring[80];

    read_fd = *ptr_read_fd ;

    while (1)
    {
        FD_ZERO(&socks_rd);
        FD_SET(read_fd, &socks_rd);
        max_fd  = read_fd;

        status = select (max_fd + 1, &socks_rd, (fd_set *) NULL,(fd_set *) NULL,NULL);
        if(status < 0)
        {   
            strerror_r(errno, errorstring, sizeof(errorstring));
            printf("server: select failed(%s) \n", errorstring);
            exit(0);
        }
        else
        {
            length  = 0;
            
            /* If there is something to read from the socket */
            if (FD_ISSET(read_fd, &socks_rd))
            {
                /* Read length */
                status = read(read_fd, (void *)&length, 2);
                if(status <= 0 )
                {
                    strerror_r(errno, errorstring, sizeof(errorstring));
                    printf("server: read failed(%s) \n", errorstring);
                    close(read_fd);
                    read_fd = -1;
                }
                /*read data */
                status = read(read_fd, (unsigned char *) buf, length);
                if(status <= 0 )
                {
                    strerror_r(errno, errorstring, sizeof(errorstring));
                    printf("server: read failed(%s) \n", errorstring);
                    close(read_fd);
                    read_fd = -1;
                }
                break;
            }
        }
    }
    *ptr_read_fd = read_fd;
    return status;
}

/*******************************************************************************
 **
 ** Function         socket_client_open
 **
 ** Description     
 **                 
 **                 
 **
 ** Returns          void
 **
 *******************************************************************************/

int socket_client_open(char *sock_name)
{
    int sock = -1;
    char errorstring[80];
    struct sockaddr_un server_address;
    int status;

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sock < 0)
    {
        strerror_r(errno, errorstring, sizeof(errorstring));
        printf("socket_client_open: socket failed(%s) \n", errorstring);
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
        printf("socket_client_open: connect(%s) failed(%s) \n",
                server_address.sun_path, errorstring);
        close(sock);
        return -1;
    }

    return sock;
}
