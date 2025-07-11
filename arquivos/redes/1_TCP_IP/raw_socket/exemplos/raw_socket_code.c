
void initializePorts(char *sendport, char *recvport, int flag)
{
    struct ifreq ifr;

    printf("Enter initializePorts() with send_socket_fd, recv %d %d \n", send_socket_fd, recv_socket_fd);
    /* do we have the rights to do that? */
    if (getuid() && geteuid()) 
    {
        printf("Sorry but need the su rights!\n");
        exit(EXIT_FAILURE);
    }


/*************
//Create Send Socket
*************/

    /* open socket in raw mode */
    send_socket_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (send_socket_fd == -1)
    {
        printf("Error: Could not open socket!\n");
        exit(EXIT_FAILURE);
    }

    /* which interface would you like to use? */
    memset(&ifr, 0, sizeof(ifr));
    strncpy (ifr.ifr_name, sendport, sizeof(ifr.ifr_name) - 1);
    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';

    if (ioctl(send_socket_fd, SIOCGIFINDEX, &ifr) == -1) 
    {
        printf("No such interface: %s\n", sendport);
        close(send_socket_fd);
        exit(EXIT_FAILURE);
    }

    /* is the interface up? */
    ioctl(send_socket_fd, SIOCGIFFLAGS, &ifr);
    if ( (ifr.ifr_flags & IFF_UP) == 0) 
    {
        printf("Interface %s is down\n", sendport);
        close(send_socket_fd);
        exit(EXIT_FAILURE);
    }

    /* just write in the structure again */
    ioctl(send_socket_fd, SIOCGIFINDEX, &ifr);

    /* well we need this to work */
    memset(&send_sa, 0, sizeof (send_sa));
    send_sa.sll_family    = AF_PACKET;
    send_sa.sll_ifindex   = ifr.ifr_ifindex;
    send_sa.sll_protocol  = htons(ETH_P_ALL);
    printf("send port index number %d\n", ifr.ifr_ifindex);

if (flag == SEND_RECV_ON_DIFF_PORTS)
{
   printf("Creating new recv socket on %s \n",recvport);
/*************
//Create recv Socket
*************/

    /* open socket in raw mode */
    recv_socket_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (recv_socket_fd == -1)
    {
        printf("Error: Could not open socket!\n");
        exit(EXIT_FAILURE);
    }

    /* which interface would you like to use? */
    memset(&ifr, 0, sizeof(ifr));
    strncpy (ifr.ifr_name, recvport, sizeof(ifr.ifr_name) - 1);
    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';

    if (ioctl(recv_socket_fd, SIOCGIFINDEX, &ifr) == -1) 
    {
        printf("No such interface: %s\n", recvport);
        close(recv_socket_fd);
        exit(EXIT_FAILURE);
    }

    /* is the interface up? */
    ioctl(recv_socket_fd, SIOCGIFFLAGS, &ifr);
    if ( (ifr.ifr_flags & IFF_UP) == 0) 
    {
        printf("Interface %s is down\n", recvport);
        close(recv_socket_fd);
        exit(EXIT_FAILURE);
    }

    /* just write in the structure again */
    ioctl(recv_socket_fd, SIOCGIFINDEX, &ifr);

    /* well we need this to work */
    memset(&recv_sa, 0, sizeof (recv_sa));
    recv_sa.sll_family    = AF_PACKET;
    recv_sa.sll_ifindex   = ifr.ifr_ifindex;
    recv_sa.sll_protocol  = htons(ETH_P_ALL);

    printf("recv port index number %d\n", ifr.ifr_ifindex);
} //recv_ports

    printf("Exit initializePorts() \n");
} // initializePorts

void recvPacket(void)
{
   struct timeval tv;
   struct timezone tz;
   unsigned long time0, time1;
   int recvlen=0, returnValue;
   unsigned char rcvbuf[100] = {'\0'};
   int rc=0;

    gettimeofday(&tv, &tz);
    time0= tv.tv_sec;
        printf(" getting time %d \n",time0);
   
    if (g_send_recv_flag == SEND_RECV_ON_SAME_PORT)
    {
        printf("Listening on eth0 \n"); 
        initializePorts(ETH0, ETH0, SEND_RECV_ON_SAME_PORT);
    } 
    else
    {
        printf("Listening on eth1 \n");  
        initializePorts(ETH0, ETH1, SEND_RECV_ON_DIFF_PORTS);
    } 

    printf("Listening for data from Havasu \n");
    for(;;)
    {
        gettimeofday(&tv, &tz);
        time1= tv.tv_sec;
        printf("within for loop - getting time %d \n",time1);
        if ( (time1- time0) > 20)
        {
           printf("Receive thread timing out \n"); 
	   break;
        }

        if (g_send_recv_flag == SEND_RECV_ON_SAME_PORT)
        {
            printf("send/rcv from same port \n");

            recvlen = sizeof(send_sa);
            //Receive the message
            returnValue = recvfrom(send_socket_fd, rcvbuf, sizeof(rcvbuf), 0,
                        (struct sockaddr *)&send_sa, (socklen_t*)&recvlen);
            // Print if something was received
      
           if (returnValue > 0)
           {
               //Filter out 'send' messages
               if ( (rcvbuf[0] == DST_MAC_BYTE0) && (rcvbuf[1] == DST_MAC_BYTE1))
               {
                   printf("This is a duplicate of the send packet. Discarding..\n");
                   continue;
               }
               else
               {
                   printf("Receive data! \n");
                   printbuf(rcvbuf, sizeof(rcvbuf));
               }
           }
        }
        else
        {
            printf("Send/recv from diff ports \n");
            recvlen = sizeof(recv_sa);
            //Receive the message
            returnValue = recvfrom(recv_socket_fd, rcvbuf, sizeof(rcvbuf), 0,
                        (struct sockaddr *)&recv_sa, (socklen_t*)&recvlen);
            // Print if something was received
      
           if (returnValue > 0)
           {
               printf("Receive data on eth1! \n");
               printbuf(rcvbuf, sizeof(rcvbuf));
           }
           else
              printf("Error receiving on eth1 \n"); 
        }
        
    }
    printf(" Closing send and recv sockets \n");
    //close(send_socket_fd);
    //close(recv_socket_fd);
    //exit(0);
  //pthread_exit(&rc);
}

void start_listen(int send_recv_flag)
{
    int ret=0;
    g_send_recv_flag = send_recv_flag;

    if (listen_thrd)
    {
        printf("Cancelling any existing listen threads \n");
        ret = pthread_cancel((pthread_t)listen_thrd);
    }

    memset((void*)&listen_thrd, 0, sizeof(listen_thrd));    
    if ( pthread_create(&listen_thrd, 0, (void*)recvPacket, NULL) != 0)
    {
        printf("Error creating listen thread \n");
    }
}

int sendPacket(unsigned char *sendpacket, int sendsize, char *packetName, int send_recv_flag)
{
    int returnValue = 0;
    static unsigned short sequenceNumber = 0;

    // Print message name
    printf("%s\n", packetName);

    // Update the sequence number
    // Only if it is not traffic
    if ( (sendpacket[20] != 0x00) && (sendpacket[21] != 0xAB))
    {
        sendpacket[22] = (sequenceNumber >> 8) & 0xFF;
        sendpacket[23] = sequenceNumber & 0xFF;
        sequenceNumber++;
    }

    printf("Sending data \n");

    // Send the message
    returnValue = sendto(send_socket_fd, sendpacket, sendsize, 0, 
                        (struct sockaddr *)&send_sa, sizeof (send_sa));    
 

    //time_delay(TX_TIME_DELAY);

    //printf("Closing ports \n");
    //close(send_socket_fd);
    //if (send_recv_flag == SEND_RECV_ON_DIFF_PORTS)
    //    close(recv_socket_fd);

    // Return the message
    return returnValue;
}


int main()
{
   start_listen(ON_SAME_PORT); // when send and recv is on eth0
    sendPacket(..);

   start_listen(ON_DIFF_PORTS); // when sending on eth0 and recv on eth1
   sendPacket(..);

// After the second sendPacket, I dont receive my reply on eth1. My receive code captures what I sent on eth0(for the second send)

}
//You need to wait for your threads to exit. See pthread_join(). 


