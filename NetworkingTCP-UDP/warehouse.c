/*
** server.c -- a stream socket server demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "21657"  // the port users will be connecting to
#define SERVERPORT "5657"
#define MYPORT8 "32657"
#define STATICPORT "31657"
#define MAXBUFLEN 100

#define BACKLOG 10	 // how many pending connections queue will hold
#define MAXDATASIZE 100 // max number of bytes we can get at once 

void sigchld_handler(int s)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

///////////////////////////////////////////////////////////
///Phase 1: The central warehouse has TCP port number _____ and IP address _____
///Phase 1: The central warehouse received information from store#(you should print this 4 times)
///End of Phase 1 for the central warehouse
////Phase 2: The central warehouse has UDP port number _____ and IP address _____
////Phase 2: Sending the truck-vector to outlet store store_1. The truck vector value is <A,B,C>.
////Phase 2: The central warehouse has UDP port number _____ and IP address _____
////Phase 2: The final truck-vector is received from the outlet store store_4, the truck-vector value is: <A,B,C>
////End of Phase 2 for the central warehouse

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	int sockfd, new_fd,sockfd1;  // listen on sock_fd, new connection on new_fd
	struct addrinfo hints, *servinfo, *p,hints1, *servinfo1, *p1;
	struct sockaddr_storage their_addr; // connector's address information
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	char s[INET6_ADDRSTRLEN];
	int rv,rv1;
	char buf[MAXDATASIZE];
	int numbytes,numbytes1;
	struct sockaddr_in *store1;
	 FILE *fp;
	  FILE *fp1;
	  char arpit1111[20];

      int isquared,ide;
	  int val=0;
	  int val1=0;
	  int val2=0,length1=0,val3=0,val11=0,val12=0,val13=0;
	  int length2=0,v1=0,v2=0,v3=0;
int length3=0;
int length4=0;
int buf1=0,buf2=0,buf3=0,buf4=0,buf5=0,buf6=0;
int i=0,j=0;
int counter11111=0,counter=0;
 char buffer11[256];
	char buffer21[256];
	char buffer31[256];
	char buffer41[256];
	int counter2=0;


	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	//////////////////////////////////////////
	int sockfd8;
	struct addrinfo hints8, *servinfo8, *p8;
	int rv8;
	int numbytes8;
	struct sockaddr_storage their_addr8;
	char buf8[MAXBUFLEN];
	socklen_t addr_len8;
	char s8[INET6_ADDRSTRLEN];
/////////////////////////////////////////////Exploring
	struct sockaddr_in addr999999;
   socklen_t addrlen999999;

   

		///////////////////////////////////////////Exploring

	

	////////////////////////////////////////

	if ((rv = getaddrinfo("nunki.usc.edu", PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	//printf("RV");
	//printf("%d",rv);

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	if (p == NULL)  {
		fprintf(stderr, "server: failed to bind\n");
		return 2;
	}

	freeaddrinfo(servinfo); // all done with this structure

	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	/////////////////////////////////Exploring
		addrlen999999 = sizeof(addr999999);
		if (getsockname(sockfd,(struct sockaddr*)&addr999999 , &addrlen999999) == -1) {
  perror("getsockname() failed");
  return -1;
   }

 // printf("%ntohs(addr.sin_port) ;//print port number
     //   cout<<inet_ntoa(addr.sin_addr);//print IP address

	 ///Phase 1: The central warehouse has TCP port number _____ and IP address _____

	 printf("The central warehouse has TCP port number %d", ntohs(addr999999.sin_port));
	 printf("and IP address");
	 printf("%s",inet_ntoa(addr999999.sin_addr));


		/*printf("Experimenting Serving %s:%d\n", inet_ntoa(addr999999.sin_addr),
     ntohs(addr999999.sin_port));
		printf("Port Number");

		printf("%d", ntohs(addr999999.sin_port));
		//printf("%d", ntohs(p->ai_addr));

		printf("Ip Address");

		printf("%s",inet_ntoa(addr999999.sin_addr));

		inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			s, sizeof s);
	printf("Store1:IpAddress connecting to %s\n", s);
	printf("Store1:PortNumber connecting to %s\n", PORT);*/
		
		//printf("%s", inet_ntoa(p->ai_addr));


////////////////////////////////Exploring


	printf("server: waiting for connections...\n");

	while(1) {  // main accept() loop
		sin_size = sizeof their_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s);
		//printf("server: got connection from %s\n", s);

		if (!fork()) { // this is the child process
			close(sockfd); // child doesn't need the listener
			//if (send(new_fd, "Hello, world!", 13, 0) == -1)
				//perror("send");
				if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	    exit(1);
	}

	buf[numbytes] = '\0';

	//printf("Server: received '%s'\n",buf);
	//printf("arpit");
	///////////////////////////////////////////////////////

	


    length1=strlen(buf);
	//printf("arpit");
	//printf("%d",length1);

for(i=0;i<length1;i++)
	{
	if(buf[i]=='<')
		{
		buf1=i+1;
		//printf("buf1");
		//printf("%d",buf1);
		
	    }
	if(buf[i]=='>')
		{
        buf6=i-1;
		//printf("buf6");
		//printf("%d",buf6);
		}
    if(counter11111==0){
	if(buf[i]==',')
		{
		buf2=i-1;
		buf3=i+1;
		//printf("buf2");
		//printf("%d",buf2);
        counter11111=1;
	    //printf("buf3");
		//printf("%d",buf3);
		}
	}
	if(counter11111==1)
		{
     if(buf[i]==',')
			{
		 buf4=i-1;
		 //printf("buf4");
		 //printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf1;i<=buf2;i++)
	{
  arpit1111[j]=buf[i];
 // printf("%c",buf[i]);
  // printf("%c",arpit1111[j]);
  j=j+1;

	}
	arpit1111[j]='\0';
	//printf("Value of first character");
	//printf("%s",arpit1111);
	val1=atoi( arpit1111);
	//printf("Value of first character");
	//printf("%d",(val1));
	//j=0;
	//free(arpit);

	j=0;
//printf("second value");
for(i=buf3;i<=buf4;i++)
	{
	
	//printf("%c",buf[i]);
	 arpit1111[j]=buf[i];
 // printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	
	val2=val2+atoi( arpit1111);
	//printf("Value of Second character");
	//printf("%d",(val2));

	j=0;
//printf("third value");
buf4=buf4+2;
for(i=buf4;i<=buf6;i++)
	{
	
	//printf("%c",buf[i]);
	 arpit1111[j]=buf[i];
  //printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	val3=val3+atoi( arpit1111);
	//printf("Value of third character");
	//printf("%d",(val3));

	///////////////////////////////////////////////////////

	
       /* open the file */
      fp = fopen("results.dat", "a");
      if (fp == NULL) {
         printf("I couldn't open results.dat for appending.\n");
         exit(0);
      }
   
      /* write to the file */
      fprintf(fp, "%d, %d, %d\n", val1, val2, val3);
	   fclose(fp);
/////////////////////////////////////////////////////////
       
	 
      
   
      /* open the file */
      fp1 = fopen("results.dat", "r");
      if (fp1 == NULL) {
        // printf("I couldn't open results.dat for reading.\n");
         exit(0);
      }
   
      while (fscanf(fp1, "%d,%d,%d\n", &i, &isquared, &ide) == 3)
	   {
		 //printf("Phase 1: The central warehouse received information from store#");
         //printf("i: %d,  isquared: %d,  ide: %d\n", i, isquared, ide);
		 val11+=i;
		 val12+=isquared;
		 val13+=ide;
		 counter++;
	   }
	  // printf("value of first");
	   //printf("%d",val11);
	   // printf("value of second");
	   //printf("%d",val12);
	   // printf("value of third");
	  // printf("%d",val13);

	  if(counter==1)
			{
		  printf("Phase 1: The central warehouse received information from store1");
			}
			if(counter==2)
			{
		  printf("Phase 1: The central warehouse received information from store2");
			}
			if(counter==3)
			{
		  printf("Phase 1: The central warehouse received information from store3");
			}
			

	    if(counter==4)
			{
			 printf("Phase 1: The central warehouse received information from store4");
			printf("End of Phase 1 for the central warehouse");
			//printf("The central warehouse has UDP port number _____ and IP address _____");
			//printf("Phase 2: Sending the truck-vector to outlet store store_1. The truck vector value is <A,B,C>.");
			//printf("value of first");
	        //printf("%d",val11);
	        //printf("value of second");
	        //printf("%d",val12);
	        //printf("value of third");
	       // printf("%d",val13);
			//printf("End of Phase1 for the central Warehouse");
			//printf("Phase 2: Sending the truck-vector to outlet store store_1. The truck vector value is <A,B,C>.");

			if(val11<0){v1=val11*-1;}
			if(val11>0){v1=0;}

			if(val12<0){v2=val12*-1;}
			if(val12>0){v2=0;}

			if(val13<0){v3=val13*-1;}
			if(val13>0){v3=0;}

			//printf("value of first");
	       // printf("%d",v1);
	       // printf("value of second");
	       // printf("%d",v2);
	       // printf("value of third");
	        //printf("%d",v3);

			sprintf(buffer11, "%d", v1);
sprintf(buffer21, "%d", v2);
sprintf(buffer31, "%d", v3);
//printf("Buffers");
//printf("%s",buffer11);
//printf("%s",buffer21);
//printf("%s",buffer31);
//printf("arpit");
counter2=0;
buffer41[counter2]='<';
counter2++;
for(j=0;j<(strlen(buffer11));j++)
		{
	if((buffer11[j]!='\0'))
			{
        buffer41[counter2]=buffer11[j];
	    counter2++;
			}
		}
		buffer41[counter2]=',';
        counter2++;
for(j=0;j<(strlen(buffer21));j++)
		{
	if((buffer21[j]!='\0'))
			{
        buffer41[counter2]=buffer21[j];
	    counter2++;
			}
		}
		buffer41[counter2]=',';
        counter2++;
for(j=0;j<(strlen(buffer31));j++)
		{
	if((buffer31[j]!='\0'))
			{
        buffer41[counter2]=buffer31[j];
	    counter2++;
			}
		}
		buffer41[counter2]='>';
        counter2++;
		buffer41[counter2]='\0';
		//printf("final buffer");
		//printf("%s",buffer41);

  //Phase 2: The central warehouse has UDP port number _____ and IP address _____
    memset(&hints1, 0, sizeof hints1);
    hints1.ai_family = AF_UNSPEC;
    hints1.ai_socktype = SOCK_DGRAM;

    if ((rv1 = getaddrinfo("nunki.usc.edu", SERVERPORT, &hints1, &servinfo1)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv1));
        return 1;
    }

    // loop through all the results and make a socket
    for(p1 = servinfo1; p1 != NULL; p1 = p1->ai_next) {
        if ((sockfd1 = socket(p1->ai_family, p1->ai_socktype,
                p1->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p1 == NULL) {
        fprintf(stderr, "talker: failed to bind socket\n");
        return 2;
    }

    if ((numbytes1 = sendto(sockfd1,buffer41,MAXDATASIZE-1, 0,
             p1->ai_addr, p1->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
	inet_ntop(p1->ai_family, get_in_addr((struct sockaddr *)p1->ai_addr),
			s, sizeof s);
	printf("Phase 2: The central warehouse has UDP port number");
	printf("%s",STATICPORT);
	printf("and IP Address %s\n", s);
	printf("Phase 2: Sending the truck-vector to outlet store store_1. The truck vector value is");
	printf("%s",buffer41);
	

    freeaddrinfo(servinfo1);

   // printf("talker: sent %d bytes to %s\n", numbytes1, "nunki.usc.edu");
    close(sockfd1);

	//////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
   

	memset(&hints8, 0, sizeof hints8);
	hints8.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints8.ai_socktype = SOCK_DGRAM;
	hints8.ai_flags = AI_PASSIVE; // use my IP

	if ((rv8 = getaddrinfo("nunki.usc.edu", MYPORT8, &hints8, &servinfo8)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv8));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p8 = servinfo8; p8 != NULL; p8 = p8->ai_next) {
		if ((sockfd8 = socket(p8->ai_family, p8->ai_socktype,
				p8->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd8, p8->ai_addr, p8->ai_addrlen) == -1) {
			close(sockfd8);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p8 == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo8);

	//printf("listener: waiting to recvfrom...\n");

	addr_len8 = sizeof their_addr8;
	if ((numbytes8 = recvfrom(sockfd8, buf8, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr8, &addr_len8)) == -1) {
		perror("recvfrom");
		exit(1);
	}

	inet_ntop(p8->ai_family, get_in_addr((struct sockaddr *)p8->ai_addr),
			s, sizeof s);
	printf("Phase 2: The central warehouse has UDP port number");
	printf("%s",MYPORT8);
	printf("and IP Address %s\n", s);
	

	//printf("listener: got packet from %s\n",
		/*inet_ntop(their_addr8.ss_family,
			get_in_addr((struct sockaddr *)&their_addr8),
			s8, sizeof s8));*/
	//printf("listener: packet is %d bytes long\n", numbytes8);
	buf8[numbytes8] = '\0';
	//printf("listener: packet contains \"%s\"\n", buf8);
	printf("Phase 2: The final truck-vector is received from the outlet store store_4, the truck-vector value is:");
	printf("%s",buf8);
	printf("End of Phase 2 for the central warehouse");

	close(sockfd8);









	///////////////////////////////////////////////////////////////////////////////////////////



            }

   fclose(fp1);
   
     






	/////////////////////////////////////////////////////////
	close(new_fd);
			exit(0);
			
		}
		close(new_fd);
			  // parent doesn't need this
	}

	return 0;
}

