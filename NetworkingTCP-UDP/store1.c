/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "21657" // the port client will be connecting to 
#define MYPORT "5657"	// the port users will be connecting to
#define SERVERPORT "9657"
#define MYPORT11 "7657"
#define SERVERPORT11 "11657" 
#define STATICPORT1 "6657"
#define STATICPORT2 "8657"

#define MAXBUFLEN 100

#define MAXDATASIZE 100 // max number of bytes we can get at once 

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void *get_in_addr1(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

/////////Phase 1: store_1 has TCP port number _____ and IP address _____
/////////Phase 1: The outlet vector<A,B,C> for store_1 has been sent to the central warehouse
//End of Phase 1 for store_1
//Phase 2: Store_1 has UDP port ______ and IP address ______
//Phase 2: Store_1 received the truck-vector<A,B,C> from the central warehouse.
//Phase 2: Store_1 has UDP port ______ and IP address ______
//Phase2: The updated truck-vector<A,B,C> has been sent to store_2Phase2: Store_1 updated outlet-vector is <A,B,C>
//Phase 2: Store_1 has UDP port ______ and IP address
//Phase2: truck-vector<A,B,C> has been received from Store_4
//Phase 2: Store_1 has UDP port ______ and IP address
//Phase2: The updated truck-vector<A,B,C> has been sent to store_2Phase2: Store_1 updated outlet vector is <A,B,C>
//End of Phase 2 for store_1

int main(int argc, char *argv[])
{
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	struct hostent *he;
	struct in_addr **addr_list;
	int i=0;
	int globalcounter=0;
	char line [ 128 ]; /* or other suitable maximum line size */
//char line1[5];
int count=0;
int counter=0;

char *la;
char *pr;
int length;

int count1111111=0;

int val1=0,val2=0,val3=0,o1=0,o2=0,o3=0,t1=0,t2=0,t3=0,uo1=0,uo2=0,uo3=0,ut1=0,ut2=0,ut3=0;

	int buf11=0,buf2=0,buf3=0,buf4=0,buf5=0,buf6=0;
	int length1=0,counter11111=0;
	char arpit1111[20];
	int conf1=0,conf2=0,conf3=0;

int j=0;

int sockfd1;
	struct addrinfo hints1, *servinfo1, *p1;
	int rv1;
	int numbytes1;
	struct sockaddr_storage their_addr1;
	char buf1[MAXBUFLEN];
	socklen_t addr_len1;
	char s1[INET6_ADDRSTRLEN];
	char buffer11[256];
    char buffer21[256];
    char buffer31[256];
    char buffer41[256];
    int counter2=0;
	////////////////////////////////Arpit Store 2 connection parameters
	int sockfd3;
    struct addrinfo hints3, *servinfo3, *p3;
    int rv3;
    int numbytes3;
	/////////////////////////////////Arpit Store 2 connection parameters

	//////////////////////////////File Logic Start
    char line1[5];
	char ca[20];
	int sockfd4;
	struct addrinfo hints4, *servinfo4, *p4;
	int rv4;
	int numbytes4;
	struct sockaddr_storage their_addr4;
	char buf4111[MAXBUFLEN];
	socklen_t addr_len4;
	char s4[INET6_ADDRSTRLEN];
	//////////////////////////////////Second Round Connection
	  int sockfd5;
    struct addrinfo hints5, *servinfo5, *p5;
    int rv5;
    int numbytes5;
	struct sockaddr_in addr999999;
   socklen_t addrlen999999;

 

	//////////////////////////////////Second Round Connection
/////////////////////////////////////////////Fetching contents of file
static const char filename[] = "store1.txt";
FILE *file = fopen ( filename, "r" );
if ( file != NULL )
{


while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
{
	if(count==0)
	{
	//printf("cameras");
    length=strlen(line);
	for(i=0;i<length;i++)
		{
		if(line[i]==' ')
			count1111111=i;
		if(line[i]=='\n')
			counter11111=i;
		
		}///for close
	//printf("%d",length);
	//printf("display");
	ca[globalcounter]='<';
	for(j=(count1111111+1);j<counter11111;j++)
		{
		globalcounter=globalcounter+1;
    ca[globalcounter]=line[j];
		}///////for close
	globalcounter=globalcounter+1;
	ca[globalcounter]=',';
	
	
	}// if close
	if(count==1)
	{
	 length=strlen(line);
	for(i=0;i<length;i++)
		{
		if(line[i]==' ')
			count1111111=i;
		if(line[i]=='\n')
			counter11111=i;
		
		}// for close
	//printf("%d",length);
	//printf("display");
	
	for(j=(count1111111+1);j<counter11111;j++)
		{
		globalcounter=globalcounter+1;
    ca[globalcounter]=line[j];
		}// for close
	globalcounter=globalcounter+1;
	ca[globalcounter]=',';
	}// if close
	if(count==2)
	{
	length=strlen(line);
	for(i=0;i<length;i++)
		{
		if(line[i]==' ')
			count1111111=i;
		if(line[i]=='\n')
			counter11111=i;
		
		}// for close
	
	for(j=(count1111111+1);j<counter11111;j++)
		{
		globalcounter=globalcounter+1;
    ca[globalcounter]=line[j];
		}// for close
	globalcounter=globalcounter+1;
	ca[globalcounter]='>';
	}// if close


count=count+1;
}// while close
fclose ( file );

}// if file close
else
{
perror ( filename ); 
}// else close

//printf("Displaying string");	
//fputs ( ca, stdout );

	/////////////////////////////File Logic End
    argc=2;
	if (argc != 2) {
	    fprintf(stderr,"usage: client hostname\n");
	    exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo("nunki.usc.edu", PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}
/////////////////////////////////
	if ((he = gethostbyname("nunki.usc.edu")) == NULL) {  // get the host info
        herror("gethostbyname");
        return 2;
    }
	//printf("Official name is: %s\n", he->h_name);
    //printf("    IP addresses: ");
    addr_list = (struct in_addr **)he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++) {
       // printf("%s ", inet_ntoa(*addr_list[i]));
    }
	////////////////////////////

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("client: connect");
			continue;
		}

		break;
	}
	//////////////////////////////////////////////////
	addrlen999999 = sizeof(addr999999);
		if (getsockname(sockfd,(struct sockaddr*)&addr999999 , &addrlen999999) == -1) {
  perror("getsockname() failed");
  return -1;
   }

 // printf("%ntohs(addr.sin_port) ;//print port number
     //   cout<<inet_ntoa(addr.sin_addr);//print IP address

		//printf("Experimenting Serving %s:%d\n", inet_ntoa(addr999999.sin_addr),
     //ntohs(addr999999.sin_port));
		//printf("Port Number");
		printf("Phase 1: store_1 has TCP port number");
        printf("%d", ntohs(addr999999.sin_port));
        printf("and Ip address");


		//printf("%d", ntohs(p->ai_addr));

		

		printf("%s",inet_ntoa(addr999999.sin_addr));

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			s, sizeof s);
	//printf("Store1:IpAddress connecting to %s\n", s);
	//printf("Store1:PortNumber connecting to %s\n", PORT);

	freeaddrinfo(servinfo); // all done with this structure

	/*if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	    exit(1);
	}

	buf[numbytes] = '\0';

	printf("client: received '%s'\n",buf);*/

	//Phase 1: store_1 has TCP port number _____ and IP address _____
	//Phase 1: The outlet vector<A,B,C> for store_1 has been sent to the central warehouse
	//End of Phase 1 for store_1

	 if (send(sockfd, ca, (globalcounter+1), 0) == -1)
                perror("send");
            close(sockfd);
			printf("Phase 1: The outlet vector");
			for(i=0;i<(globalcounter+1);i++)
			printf("%c",ca[i]);
			
			printf("for store_1 has been sent to the central warehouse\n");
			
            
			printf("End of Phase 1 for store_1");
            

	close(sockfd);


	///////////////////////////////////////////////////////UDP Dtagram Listener Logic

	

// get sockaddr, IPv4 or IPv6:
/*void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}*/



	memset(&hints1, 0, sizeof hints1);
	hints1.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints1.ai_socktype = SOCK_DGRAM;
	hints1.ai_flags = AI_PASSIVE; // use my IP

	if ((rv1 = getaddrinfo("nunki.usc.edu", MYPORT, &hints1, &servinfo1)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv1));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p1 = servinfo1; p1 != NULL; p1 = p1->ai_next) {
		if ((sockfd1 = socket(p1->ai_family, p1->ai_socktype,
				p1->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd1, p1->ai_addr, p1->ai_addrlen) == -1) {
			close(sockfd1);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p1 == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo1);

	printf("listener: waiting to recvfrom...\n");
	//printf("arpit");

	addr_len1 = sizeof their_addr1;
	if ((numbytes1 = recvfrom(sockfd1, buf1, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr1, &addr_len1)) == -1) {
		perror("recvfrom");
		exit(1);
	}
	//printf("Number of bytes");
	//printf("%d",numbytes1);
	inet_ntop(their_addr1.ss_family,
			get_in_addr1((struct sockaddr *)&their_addr1),
			s1, sizeof s1);
	 printf("Phase 2: Store_1 has UDP port %s",MYPORT);
	 printf("and IP address");
	 printf("%s",s1);

	
		
	//printf("listener: packet is %d bytes long\n", numbytes1);
	buf1[numbytes1] = '\0';
	printf("Phase 2: Store_1 received the truck-vector");
	printf("%s", buf1);
	printf("from the central warehouse");

	/////////////////////////////////////////////Buf1

	//printf("Phase2: The updated truck-vector<A,B,C> has been sent to store_2");
    //printf("Phase2: Store_1 updated outlet-vector is <A,B,C>");
    //printf("Truck vector received");
	//printf("listener: packet contains \"%s\"\n", buf1);
	//printf("Outlet vector store1 has");
	//printf("%s", buf1);

	////////////////////////////////////////////
   

	length1=strlen(buf1);
	//printf("arpit");
	//printf("%d",length1);
	counter11111=0;

for(i=0;i<length1;i++)
	{
	if(buf1[i]=='<')
		{
		buf11=i+1;
		//printf("buf1");
		//printf("%d",buf11);
		
	    }
	if(buf1[i]=='>')
		{
        buf6=i-1;
		//printf("buf6");
		//printf("%d",buf6);
		}
    if(counter11111==0){
	if(buf1[i]==',')
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
     if(buf1[i]==',')
			{
		 buf4=i-1;
		// printf("buf4");
		// printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf11;i<=buf2;i++)
	{
  arpit1111[j]=buf1[i];
  //printf("%c",buf1[i]);
   //printf("%c",arpit1111[j]);
  j=j+1;

	}
	arpit1111[j]='\0';
	//printf("Value of first character");
	//printf("%s",arpit1111);
	val1=atoi( arpit1111);//////////////First Truck vector value
	t1=val1;
	//printf("Value of first character");
	//printf("%d",(val1));
	//j=0;
	//free(arpit);

	j=0;
//printf("second value");
for(i=buf3;i<=buf4;i++)
	{
	
	//printf("%c",buf1[i]);
	 arpit1111[j]=buf1[i];
  //printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	
	val2=val2+atoi( arpit1111);///////////Second Truck vector value
	t2=val2;
	//printf("Value of Second character");
	//printf("%d",(val2));

	j=0;
//printf("third value");
buf4=buf4+2;
for(i=buf4;i<=buf6;i++)
	{
	
	//printf("%c",buf1[i]);
	 arpit1111[j]=buf1[i];
  //printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	val3=val3+atoi( arpit1111);///////Third Truck vector value
	t3=val3;
	//printf("Value of third character");
	//printf("%d",(val3));


	////////////////////////////////
    ca[globalcounter+1]='\0';
	length1=strlen(ca);
	//printf("arpit");
	//printf("%d",length1);
	//printf("%s",ca);

	counter11111=0;

for(i=0;i<length1;i++)
	{
	if(ca[i]=='<')
		{
		buf11=i+1;
		//printf("buf1");
		//printf("%d",buf11);
		
	    }
	if(ca[i]=='>')
		{
        buf6=i-1;
		//printf("buf6");
		//printf("%d",buf6);
		}
    if(counter11111==0){
	if(ca[i]==',')
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
     if(ca[i]==',')
			{
		 buf4=i-1;
		 //printf("buf4");
		 //printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf11;i<=buf2;i++)
	{
  arpit1111[j]=ca[i];
  //printf("%c",ca[i]);
   //printf("%c",arpit1111[j]);
  j=j+1;

	}
	arpit1111[j]='\0';
	//printf("Value of first character");
	//printf("%s",arpit1111);
	val1=atoi( arpit1111);//////////////First Truck vector value
	o1=val1;
	//printf("Value of first character");
	//printf("%d",(val1));
	//j=0;
	//free(arpit);

	j=0;
//printf("second value");
for(i=buf3;i<=buf4;i++)
	{
	
	//printf("%c",ca[i]);
	 arpit1111[j]=ca[i];
 // printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	
	val2=atoi( arpit1111);///////////Second Truck vector value
	o2=val2;
	//printf("Value of Second character");
	//printf("%d",(val2));

	j=0;
//printf("third value");
buf4=buf4+2;
for(i=buf4;i<=buf6;i++)
	{
	
	//printf("%c",ca[i]);
	 arpit1111[j]=ca[i];
  //printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	val3=atoi( arpit1111);///////Third Truck vector value
	o3=val3;
	//printf("Value of third character");
	//printf("%d",(val3));
	///////////////////////////////
	//printf("o1");
	//printf("%d",o1);
	//printf("o2");
	//printf("%d",o2);
	//printf("o3");
	//printf("%d",o3);
	//printf("t1");
	//printf("%d",t1);
	//printf("t2");
	//printf("%d",t2);
    //printf("t3");
	//printf("%d",t3);
    if((o1>0)&&(t1>=0))
	{
		t1=t1+o1;
		o1=0;
		conf1=1;
	}
	if(conf1==0)
	{
	if((o1<0)&&(t1>=0))
	{
		uo1=o1*-1;
		if(uo1==t1)
		{
			o1=0;
			t1=0;
			conf2=1;
		}
		if(conf2==0)
		{
		if(t1>uo1)
		{
			//printf("debugging");
			//printf("t1");
			//printf("%d",t1);
				//printf("uo1");
			//printf("%d",uo1);
			//printf("o1");
			//printf("%d",o1);
			 t1=t1+o1;
           o1=0;
		  
		   //printf("o1");
			//printf("%d",o1);
		   //printf("t1");
			//printf("%d",t1);
				//printf("uo1");
			//printf("%d",uo1);
			//printf("debugging");
			conf3=1;
		}
		if(conf3==0)
			{
		if(t1<uo1)
		{
          o1=o1+t1;
		  t1=0;
		}
		    }
		}
	}
	}
conf1=0;
conf2=0;
conf3=0;
	 if((o2>0)&&(t2>=0))
	{
		t2=t2+o2;
		o2=0;
		conf1=1;
	}
	if(conf1==0)
	{
	if((o2<0)&&(t2>=0))
	{
		uo2=o2*-1;
		if(uo2==t2)
		{
			o2=0;
			t2=0;
			conf2=1;
		}
		if(conf2==0)
		{
		if(t2>uo2)
		{
			//printf("debugging");
			//printf("t2");
			//printf("%d",t2);
				//printf("uo1");
			//printf("%d",uo2);
			//printf("o2");
			//printf("%d",o2);
			 t2=t2+o2;
           o2=0;
		  
		   //printf("o2");
			//printf("%d",o2);
		   //printf("t2");
			//printf("%d",t2);
				//printf("uo2");
			//printf("%d",uo2);
			//printf("debugging");
			conf3=1;
		}
		if(conf3==0)
			{
		if(t2<uo2)
		{
          o2=o2+t2;
		  t2=0;
		}
		    }
		}
	}
	}

	conf1=0;
conf2=0;
conf3=0;
	 if((o3>0)&&(t3>=0))
	{
		t3=t3+o3;
		o3=0;
		conf1=1;
	}
	if(conf1==0)
	{
	if((o3<0)&&(t3>=0))
	{
		uo3=o3*-1;
		if(uo3==t3)
		{
			o3=0;
			t3=0;
			conf2=1;
		}
		if(conf2==0)
		{
		if(t3>uo3)
		{
			//printf("debugging");
			//printf("t3");
			//printf("%d",t3);
				//printf("uo1");
			//printf("%d",uo3);
			//printf("o3");
			//printf("%d",o3);
			 t3=t3+o3;
           o3=0;
		  
		   //printf("o3");
			//printf("%d",o3);
		   //printf("t3");
			//printf("%d",t3);
				//printf("uo3");
			//printf("%d",uo3);
			//printf("debugging");
			conf3=1;
		}
		if(conf3==0)
			{
		if(t3<uo3)
		{
          o3=o3+t3;
		  t3=0;
		}
		    }
		}
	}
	}

    //printf("After manipulation");
    //printf("o1");
	//printf("%d",o1);
	//printf("o2");
	//printf("%d",o2);
	//printf("o3");
	//printf("%d",o3);
	//printf("t1");
	//printf("%d",t1);
	//printf("t2");
	//printf("%d",t2);
    //printf("t3");
	//printf("%d",t3);




sprintf(buffer11, "%d", t1);
sprintf(buffer21, "%d", t2);
sprintf(buffer31, "%d", t3);
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

    ///////////////////////////////////////////////Arpit Store2 Connection code

	

   /* if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }*/

    memset(&hints3, 0, sizeof hints3);
    hints3.ai_family = AF_UNSPEC;
    hints3.ai_socktype = SOCK_DGRAM;

    if ((rv3 = getaddrinfo("nunki.usc.edu", SERVERPORT, &hints3, &servinfo3)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv3));
        return 1;
    }

    // loop through all the results and make a socket
    for(p3 = servinfo3; p3 != NULL; p3 = p3->ai_next) {
        if ((sockfd3 = socket(p3->ai_family, p3->ai_socktype,
                p3->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p3 == NULL) {
        fprintf(stderr, "talker: failed to bind socket\n");
        return 2;
    }

    if ((numbytes3 = sendto(sockfd3, buffer41, 20, 0,
             p3->ai_addr, p3->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
inet_ntop(p3->ai_family, get_in_addr((struct sockaddr *)p3->ai_addr),
			s, sizeof s);

	printf("Phase 2: Store_1 has UDP port");
	printf("%s",STATICPORT1);
	printf("and IP address");
	printf("%s",s);
	printf("Phase2: The updated truck-vector");
	printf("%s",buffer41);
	printf(" has been sent to store_2");
	printf("Phase2: Store_1 updated outlet-vector is");
	printf("<");
	printf("%d",o1);
	printf(",");
	printf("%d",o2);
	printf(",");
	printf("%d",o3);
	printf(">");


	


    freeaddrinfo(servinfo3);

    //printf("talker: sent %d bytes to %s\n", numbytes3, "nunki.usc.edu");
    close(sockfd3);
	close(sockfd1);


/////////////////////////////////////////////////////////////////////UDP Datagram listener Logic



	memset(&hints4, 0, sizeof hints4);
	hints4.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints4.ai_socktype = SOCK_DGRAM;
	hints4.ai_flags = AI_PASSIVE; // use my IP

	if ((rv4 = getaddrinfo("nunki.usc.edu", MYPORT11, &hints4, &servinfo4)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv4));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p4 = servinfo4; p4 != NULL; p4 = p4->ai_next) {
		if ((sockfd4 = socket(p4->ai_family, p4->ai_socktype,
				p4->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd4, p4->ai_addr, p4->ai_addrlen) == -1) {
			close(sockfd4);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p4 == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo4);

	printf("listener: waiting to recvfrom...\n");

	addr_len4 = sizeof their_addr4;
	if ((numbytes4 = recvfrom(sockfd4, buf4111, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr4, &addr_len4)) == -1) {
		perror("recvfrom");
		exit(1);
	}

	
		inet_ntop(their_addr4.ss_family,
			get_in_addr((struct sockaddr *)&their_addr4),
			s4, sizeof s4);
	buf4111[numbytes4] = '\0';

	printf("Phase 2: Store_1 has UDP port");
	printf("%s",MYPORT11);
	printf("and Ip Address");
	printf("%s",s4);
	printf("Phase2: truck-vector ");
	printf("%s",buf4111);
	printf("has been received from Store_4");

	//printf("listener: packet is %d bytes long\n", numbytes4);
	
	//printf("listener: packet contains \"%s\"\n", buf4111);
	 //printf("After manipulation");
   // printf("o1");
	//printf("%d",o1);
	//printf("o2");
	//printf("%d",o2);
	//printf("o3");
	//printf("%d",o3);
	//printf("t1");
	//printf("%d",t1);
	//printf("t2");
	//printf("%d",t2);
   // printf("t3");
	//printf("%d",t3);
	////////////////////////////////////////////////////////////////////////////////


	length1=strlen(buf4111);
	//printf("arpit");
	//printf("%d",length1);
	counter11111=0;

for(i=0;i<length1;i++)
	{
	if(buf4111[i]=='<')
		{
		buf11=i+1;
		//printf("buf1");
		//printf("%d",buf11);
		
	    }
	if(buf4111[i]=='>')
		{
        buf6=i-1;
		//printf("buf6");
		//printf("%d",buf6);
		}
    if(counter11111==0){
	if(buf4111[i]==',')
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
     if(buf4111[i]==',')
			{
		 buf4=i-1;
		 //printf("buf4");
		 //printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf11;i<=buf2;i++)
	{
  arpit1111[j]=buf4111[i];
  //printf("%c",buf4111[i]);
   //printf("%c",arpit1111[j]);
  j=j+1;

	}
	arpit1111[j]='\0';
	//printf("Value of first character");
	//printf("%s",arpit1111);
	val1=atoi( arpit1111);//////////////First Truck vector value
	t1=val1;
	//printf("Value of first character");
	//printf("%d",(val1));
	//j=0;
	//free(arpit);

	j=0;
//printf("second value");
for(i=buf3;i<=buf4;i++)
	{
	
	//printf("%c",buf4111[i]);
	 arpit1111[j]=buf4111[i];
  //printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	
	val2=atoi( arpit1111);///////////Second Truck vector value
	t2=val2;
	//printf("Value of Second character");
	//printf("%d",(val2));

	j=0;
//printf("third value");
buf4=buf4+2;
for(i=buf4;i<=buf6;i++)
	{
	
	//printf("%c",buf4111[i]);
	 arpit1111[j]=buf4111[i];
  //printf("%c", arpit1111[j]);
  j=j+1;
  //str3[j]=example1[i];
  //printf("%c",str3[j]);
  //j=j+1;

	}
	arpit1111[j]='\0';
	val3=atoi( arpit1111);///////Third Truck vector value
	t3=val3;
	//printf("Value of third character");
	//printf("%d",(val3));


	////////////////////////////////
   
	///////////////////////////////
	//printf("Final Outlet vectors and Truck vectors");
	//printf("o1");
	/*printf("%d",o1);
	printf("o2");
	printf("%d",o2);
	printf("o3");
	printf("%d",o3);
	printf("t1");
	printf("%d",t1);
	printf("t2");
	printf("%d",t2);
    printf("t3");
	printf("%d",t3);*/
    if((o1>0)&&(t1>=0))
	{
		t1=t1+o1;
		o1=0;
		conf1=1;
	}
	if(conf1==0)
	{
	if((o1<0)&&(t1>=0))
	{
		uo1=o1*-1;
		if(uo1==t1)
		{
			o1=0;
			t1=0;
			conf2=1;
		}
		if(conf2==0)
		{
		if(t1>uo1)
		{
			//printf("debugging");
			//printf("t1");
			//printf("%d",t1);
				//printf("uo1");
			//printf("%d",uo1);
			//printf("o1");
			//printf("%d",o1);
			 t1=t1+o1;
           o1=0;
		  
		  // printf("o1");
			//printf("%d",o1);
		   //printf("t1");
			//printf("%d",t1);
			//	printf("uo1");
			//printf("%d",uo1);
			//printf("debugging");
			conf3=1;
		}
		if(conf3==0)
			{
		if(t1<uo1)
		{
          o1=o1+t1;
		  t1=0;
		}
		    }
		}
	}
	}
conf1=0;
conf2=0;
conf3=0;
	 if((o2>0)&&(t2>=0))
	{
		t2=t2+o2;
		o2=0;
		conf1=1;
	}
	if(conf1==0)
	{
	if((o2<0)&&(t2>=0))
	{
		uo2=o2*-1;
		if(uo2==t2)
		{
			o2=0;
			t2=0;
			conf2=1;
		}
		if(conf2==0)
		{
		if(t2>uo2)
		{
			//printf("debugging");
			//printf("t2");
			//printf("%d",t2);
				//printf("uo1");
			//printf("%d",uo2);
			//printf("o2");
			//printf("%d",o2);
			 t2=t2+o2;
           o2=0;
		  
		  // printf("o2");
			//printf("%d",o2);
		   //printf("t2");
			//printf("%d",t2);
			//	printf("uo2");
			//printf("%d",uo2);
			//printf("debugging");
			conf3=1;
		}
		if(conf3==0)
			{
		if(t2<uo2)
		{
          o2=o2+t2;
		  t2=0;
		}
		    }
		}
	}
	}

	conf1=0;
conf2=0;
conf3=0;
	 if((o3>0)&&(t3>=0))
	{
		t3=t3+o3;
		o3=0;
		conf1=1;
	}
	if(conf1==0)
	{
	if((o3<0)&&(t3>=0))
	{
		uo3=o3*-1;
		if(uo3==t3)
		{
			o3=0;
			t3=0;
			conf2=1;
		}
		if(conf2==0)
		{
		if(t3>uo3)
		{
			//printf("debugging");
			//printf("t3");
			//printf("%d",t3);
				//printf("uo1");
			//printf("%d",uo3);
			//printf("o3");
			//printf("%d",o3);
			 t3=t3+o3;
           o3=0;
		  
		   //printf("o3");
			//printf("%d",o3);
		   //printf("t3");
			//printf("%d",t3);
				//printf("uo3");
			//printf("%d",uo3);
			//printf("debugging");
			conf3=1;
		}
		if(conf3==0)
			{
		if(t3<uo3)
		{
          o3=o3+t3;
		  t3=0;
		}
		    }
		}
	}
	}

   // printf("Second Round Outlet Vectors and Truck vectors");
    //printf("o1");
	//printf("%d",o1);
	//printf("o2");
	//printf("%d",o2);
	//printf("o3");
	//printf("%d",o3);
	//printf("t1");
	//printf("%d",t1);
	//printf("t2");
	//printf("%d",t2);
    //printf("t3");
	//printf("%d",t3);


sprintf(buffer11, "%d", t1);
sprintf(buffer21, "%d", t2);
sprintf(buffer31, "%d", t3);
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
		close(sockfd4);

		/////////////////////////////////////////////////////////Sending to Store2 Second Round
       

   /* if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }*/

    memset(&hints5, 0, sizeof hints5);
    hints5.ai_family = AF_UNSPEC;
    hints5.ai_socktype = SOCK_DGRAM;

    if ((rv5 = getaddrinfo("nunki.usc.edu", SERVERPORT11, &hints5, &servinfo5)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv5));
        return 1;
    }

    // loop through all the results and make a socket
    for(p5 = servinfo5; p5 != NULL; p5 = p5->ai_next) {
        if ((sockfd5 = socket(p5->ai_family, p5->ai_socktype,
                p5->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p5 == NULL) {
        fprintf(stderr, "talker: failed to bind socket\n");
        return 2;
    }

    if ((numbytes5 = sendto(sockfd5, buffer41, 20, 0,
             p5->ai_addr, p5->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
	inet_ntop(p5->ai_family, get_in_addr((struct sockaddr *)p5->ai_addr),
			s, sizeof s);
	printf("Phase 2: Store_1 has UDP port");
	printf("%s",STATICPORT2);
	printf("and IP address");
	printf("%s",s);
	printf("Phase2: The updated truck-vector");
	printf("%s",buffer41);
	printf("has been sent to store_2");
	printf("Phase2: Store_1 updated outlet vector is");
	printf("<");
	printf("%d",o1);
	printf(",");
	printf("%d",o2);
	printf(",");
	printf("%d",o3);
	printf(">");
	printf("End of Phase 2 for store_1");


    freeaddrinfo(servinfo5);

   // printf("talker: sent %d bytes to %s\n", numbytes5, "nunki.usc.edu");
    close(sockfd5);
        


		/////////////////////////////////////////////////////////Sending to Store2 Second Round




	





	////////////////////////////////////////////////////////////////////////////////

	


////////////////////////////////////////////////////////////////////UDP Datagram Listener logic





	//////////////////////////////////////////////Arpit Store2 Connection Code
	


	//////////////////////////////////////////////////////
	

	return 0;
}

