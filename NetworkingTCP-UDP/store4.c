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
#define MYPORT "17657"
#define SERVERPORT "7657"
#define MYPORT11 "19657"
#define STATICPORT11 "18657"
#define STATICPORT12 "20657"

#define SERVERPORT8 "32657"


#define MAXDATASIZE 100 // max number of bytes we can get at once
#define MAXBUFLEN 100

void *get_in_addr1(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
//Phase 1: store_4 has TCP port number _____ and IP address _____
//Phase 1: The outlet vector<A,B,C> for store_4 has been sent to the central warehouse
//End of Phase 1 for store_4
//Phase 2: Store_4 has UDP port ______ and IP address ______
//Phase 2: Store_4 received the truck-vector<A,B,C> from store_3
//Phase 2: Store_4 has UDP port ______ and IP address ______
//Phase2: The updated truck-vector<A,B,C> has been sent to store_1
//Phase2: Store_4 updated outlet-vector is <A,B,C>
//Phase 2: Store_4 has UDP port ______ and IP address ______
//Phase2: truck-vector<A,B,C> has been received from Store_3
//Phase 2: Store_4 has UDP port ______ and IP address ______
//Phase2: The updated truck-vector<A,B,C> has been sent to the central warehouse
//Phase2: Store_4 updated outlet vector is <A,B,C>
//End of Phase 2 for store_4
//

int main(int argc, char *argv[])
{
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	struct hostent *he;
	struct in_addr **addr_list;
	int conf1=0,conf2=0,conf3=0;
	int i=0;
	int globalcounter=0;
	char line [ 128 ]; /* or other suitable maximum line size */

	/////////////////////////////////////////////Store2 Parameters

    int sockfd2;
	struct addrinfo hints2, *servinfo2, *p2;
	int rv2;
	int numbytes2;
	struct sockaddr_storage their_addr2;
	char buf22[MAXBUFLEN];
	socklen_t addr_len2;
	char s2[INET6_ADDRSTRLEN];
	char buf2[256];
	char buffer11[256];
    char buffer21[256];
    char buffer31[256];
    char buffer41[256];
    int counter2=0;
	int sockfd8;
    struct addrinfo hints8, *servinfo8, *p8;
    int rv8;
    int numbytes8;
	struct sockaddr_in addr999999;
    socklen_t addrlen999999;
	////////////////////////////////////////////Store2 Parameters
//char line1[5];
int count=0;
int counter=0;

char *la;
char *pr;
int length;

int count1111111=0;
int counter11111=0;

int sockfd7;
	struct addrinfo hints7, *servinfo7, *p7;
	int rv7;
	int numbytes7;
	struct sockaddr_storage their_addr7;
	char buf7[MAXBUFLEN];
	socklen_t addr_len7;
	char s7[INET6_ADDRSTRLEN];



int val1=0,val2=0,val3=0,o1=0,o2=0,o3=0,t1=0,t2=0,t3=0,uo1=0,uo2=0,uo3=0,ut1=0,ut2=0,ut3=0;

	int buf11=0,buf21=0,buf3=0,buf4=0,buf5=0,buf6=0;
	int length1=0;
	char arpit1111[20];

int j=0;
////////////////////////////////Arpit Store 2 connection parameters
	int sockfd3;
    struct addrinfo hints3, *servinfo3, *p3;
    int rv3;
    int numbytes3;
	/////////////////////////////////Arpit Store 2 connection parameters

	//////////////////////////////File Logic Start
    char line1[5];
	char ca[20];
/////////////////////////////////////////////Fetching contents of file
static const char filename[] = "store4.txt";
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
	/*printf("Official name is: %s\n", he->h_name);
    printf("    IP addresses: ");
    addr_list = (struct in_addr **)he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++) {
        printf("%s ", inet_ntoa(*addr_list[i]));
    }*/


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

	addrlen999999 = sizeof(addr999999);
		if (getsockname(sockfd,(struct sockaddr*)&addr999999 , &addrlen999999) == -1) {
  perror("getsockname() failed");
  return -1;
   }

		printf("Phase 1: store_4 has TCP port number");
        printf("%d", ntohs(addr999999.sin_port));
        printf("and Ip address");
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
			
			printf("for store_4 has been sent to the central warehouse\n");
			
            
			printf("End of Phase 1 for store_4");
			close(sockfd);
            ////////////////////////////////////////////////////////////Store2 Receiving data

			

	memset(&hints2, 0, sizeof hints2);
	hints2.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints2.ai_socktype = SOCK_DGRAM;
	hints2.ai_flags = AI_PASSIVE; // use my IP

	if ((rv2 = getaddrinfo("nunki.usc.edu", MYPORT, &hints2, &servinfo2)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv2));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p2 = servinfo2; p2 != NULL; p2 = p2->ai_next) {
		if ((sockfd2 = socket(p2->ai_family, p2->ai_socktype,
				p2->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd2, p2->ai_addr, p2->ai_addrlen) == -1) {
			close(sockfd2);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p2 == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo2);

	printf("listener: waiting to recvfrom...\n");

	addr_len2 = sizeof their_addr2;
	if ((numbytes2 = recvfrom(sockfd2, buf22, 20 , 0,
		(struct sockaddr *)&their_addr2, &addr_len2)) == -1) {
		perror("recvfrom");
		exit(1);
	}

	
		inet_ntop(their_addr2.ss_family,
			get_in_addr1((struct sockaddr *)&their_addr2),
			s2, sizeof s2);
	//printf("listener: packet is %d bytes long\n", numbytes2);
	buf22[numbytes2] = '\0';
	printf("Phase 2: Store_4 has UDP port");
	printf("%s",MYPORT);
	printf("and IP address");
	printf("%s",s2);
	printf("Phase 2: Store_4 received the truck-vector");
	printf("%s",buf22);
	printf("from store_3");
	//printf("listener: packet contains \"%s\"\n", buf22);
    
	/*printf("Truck vector received:");
	printf("%s",buf22);
	printf("length");
	printf("%d",(strlen(buf22)));*/
	ca[globalcounter+1]='\0';
	/*printf("Outlet vector store2 has");
	printf("%s",ca);
	printf("length");
	printf("%d",(strlen(ca)));*/

	///////////////////////////////////////////////////////////////////////////////////////////////Logic to retreive outlet vectors and Truck vectors
   

   //////////////////////////////////////////
  
   length1=strlen(buf22);
	//printf("arpit");
	//printf("%d",length1);
	counter11111=0;

for(i=0;i<length1;i++)
	{
	if(buf22[i]=='<')
		{
		buf11=i+1;
		//printf("buf1");
		//printf("%d",buf11);
		
	    }
	if(buf22[i]=='>')
		{
        buf6=i-1;
		//printf("buf6");
		//printf("%d",buf6);
		}
    if(counter11111==0){
	if(buf22[i]==',')
		{
		buf21=i-1;
		buf3=i+1;
		//printf("buf21");
		//printf("%d",buf21);
        counter11111=1;
	    //printf("buf3");
		//printf("%d",buf3);
		}
	}
	if(counter11111==1)
		{
     if(buf22[i]==',')
			{
		 buf4=i-1;
		 //printf("buf4");
		 //printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf11;i<=buf21;i++)
	{
  arpit1111[j]=buf22[i];
 // printf("%c",buf22[i]);
  // printf("%c",arpit1111[j]);
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
	
	//printf("%c",buf22[i]);
	 arpit1111[j]=buf22[i];
 // printf("%c", arpit1111[j]);
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
	
	//printf("%c",buf22[i]);
	 arpit1111[j]=buf22[i];
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
		buf21=i-1;
		buf3=i+1;
		//printf("buf21");
		//printf("%d",buf21);
        counter11111=1;
	   // printf("buf3");
		//printf("%d",buf3);
		}
	}
	if(counter11111==1)
		{
     if(ca[i]==',')
			{
		 buf4=i-1;
		// printf("buf4");
		// printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf11;i<=buf21;i++)
	{
  arpit1111[j]=ca[i];
 // printf("%c",ca[i]);
  // printf("%c",arpit1111[j]);
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
  //printf("%c", arpit1111[j]);
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
	/*printf("o1");
	printf("%d",o1);
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
			//	printf("uo1");
			//printf("%d",uo1);
			//printf("o1");
			//printf("%d",o1);
			 t1=t1+o1;
           o1=0;
		  
		   //printf("o1");
			//printf("%d",o1);
		  // printf("t1");
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
			//	printf("uo1");
			//printf("%d",uo3);
			//printf("o3");
			//printf("%d",o3);
			 t3=t3+o3;
           o3=0;
		  
		   //printf("o3");
			//printf("%d",o3);
		  // printf("t3");
			//printf("%d",t3);
			//	printf("uo3");
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

   /* printf("After manipulation");
    printf("o1");
	printf("%d",o1);
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





sprintf(buffer11, "%d", t1);
sprintf(buffer21, "%d", t2);
sprintf(buffer31, "%d", t3);
/*printf("Buffers");
printf("%s",buffer11);
printf("%s",buffer21);
printf("%s",buffer31);
printf("arpit");*/
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

   /////////////////////////////////////////

    ///////////////////////////////////////////////Arpit Store3 Connection code

	

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

	printf("Phase 2: Store_4 has UDP port");
	printf("%s",STATICPORT11);
	printf("and IP address");
	printf("%s",s);
	printf("Phase2: The updated truck-vector");
	printf("%s",buffer41);
	printf(" has been sent to store_1");
	printf("Phase2: Store_4 updated outlet-vector is");
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
	close(sockfd2);

	//////////////////////////////////////////////Arpit Store3 Connection Code


	//////////////////////////////////////////////////////////////////////////////////////////////
	
    

	memset(&hints7, 0, sizeof hints7);
	hints7.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints7.ai_socktype = SOCK_DGRAM;
	hints7.ai_flags = AI_PASSIVE; // use my IP

	if ((rv7 = getaddrinfo("nunki.usc.edu", MYPORT11, &hints7, &servinfo7)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv7));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p7 = servinfo7; p7 != NULL; p7 = p7->ai_next) {
		if ((sockfd7 = socket(p7->ai_family, p7->ai_socktype,
				p7->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd7, p7->ai_addr, p7->ai_addrlen) == -1) {
			close(sockfd7);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p7 == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo7);

	printf("listener: waiting to recvfrom...\n");

	addr_len7 = sizeof their_addr7;
	if ((numbytes7 = recvfrom(sockfd7, buf7, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr7, &addr_len7)) == -1) {
		perror("recvfrom");
		exit(1);
	}

	//printf("listener: got packet from %s\n",
		inet_ntop(their_addr7.ss_family,
			get_in_addr((struct sockaddr *)&their_addr7),
			s7, sizeof s7);
		printf("Phase 2: Store_4 has UDP port");
		printf("%s",MYPORT11);
		printf("and IP address");
		printf("%s",s7);
	//printf("listener: packet is %d bytes long\n", numbytes7);
	buf7[numbytes7] = '\0';
	//printf("listener: packet contains \"%s\"\n", buf7);
	printf("Phase2: truck-vector");
	printf("%s",buf7);
	printf("has been received from Store_3");
	
	/////////////////////////////////////
	 /*printf("Before manipulation");
    printf("o1");
	printf("%d",o1);
	printf("o2");
	printf("%d",o2);
	printf("o3");
	printf("%d",o3);
	printf("t1");
	printf("%d",t1);
	printf("t2");
	printf("%d",t2);
    printf("t3");
	printf("%d",t3);
	length1=strlen(buf7);
	printf("arpit");
	printf("%d",length1);*/
	counter11111=0;

for(i=0;i<length1;i++)
	{
	if(buf7[i]=='<')
		{
		buf11=i+1;
		//printf("buf1");
		//printf("%d",buf11);
		
	    }
	if(buf7[i]=='>')
		{
        buf6=i-1;
		//printf("buf6");
		//printf("%d",buf6);
		}
    if(counter11111==0){
	if(buf7[i]==',')
		{
		buf21=i-1;
		buf3=i+1;
		//printf("buf21");
		//printf("%d",buf21);
        counter11111=1;
	   // printf("buf3");
		//printf("%d",buf3);
		}
	}
	if(counter11111==1)
		{
     if(buf7[i]==',')
			{
		 buf4=i-1;
		 //printf("buf4");
		 //printf("%d",buf4);
		    }
		}
	
	}
j=0;
for(i=buf11;i<=buf21;i++)
	{
  arpit1111[j]=buf7[i];
 // printf("%c",buf7[i]);
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
	
	//printf("%c",buf7[i]);
	 arpit1111[j]=buf7[i];
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
	
	//printf("%c",buf7[i]);
	 arpit1111[j]=buf7[i];
 // printf("%c", arpit1111[j]);
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

/*
	 printf("Before Before manipulation");
    printf("o1");
	printf("%d",o1);
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
		 //  printf("t1");
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
			//	printf("uo1");
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
			//	printf("uo1");
			//printf("%d",uo3);
			//printf("o3");
			//printf("%d",o3);
			 t3=t3+o3;
           o3=0;
		  
		  // printf("o3");
			//printf("%d",o3);
		   //printf("t3");
			//printf("%d",t3);
			//	printf("uo3");
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

	/* printf("After manipulation");
    printf("o1");
	printf("%d",o1);
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

	sprintf(buffer11, "%d", t1);
sprintf(buffer21, "%d", t2);
sprintf(buffer31, "%d", t3);
/*printf("Buffers");
printf("%s",buffer11);
printf("%s",buffer21);
printf("%s",buffer31);
printf("arpit");*/
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
		close(sockfd7);

////////////////////////////////////////////////////////////Store4111111111111111111111111111111

 

   /* if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }*/

    memset(&hints8, 0, sizeof hints8);
    hints8.ai_family = AF_UNSPEC;
    hints8.ai_socktype = SOCK_DGRAM;

    if ((rv8 = getaddrinfo("nunki.usc.edu", SERVERPORT8, &hints8, &servinfo8)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv8));
        return 1;
    }

    // loop through all the results and make a socket
    for(p8 = servinfo8; p8 != NULL; p8 = p8->ai_next) {
        if ((sockfd8 = socket(p8->ai_family, p8->ai_socktype,
                p8->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p8 == NULL) {
        fprintf(stderr, "talker: failed to bind socket\n");
        return 2;
    }

    if ((numbytes8 = sendto(sockfd8, buffer41, 20, 0,
             p8->ai_addr, p8->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }

	inet_ntop(p8->ai_family, get_in_addr((struct sockaddr *)p8->ai_addr),
			s, sizeof s);
	printf("Phase 2: Store_4 has UDP port");
	printf("%s",STATICPORT12);
	printf("and IP address");
	printf("%s",s);
	printf("Phase2: The updated truck-vector");
	printf("%s",buffer41);
	printf("has been sent to Central warehouse");
	printf("Phase2: Store_4 updated outlet vector is");
	printf("<");
	printf("%d",o1);
	printf(",");
	printf("%d",o2);
	printf(",");
	printf("%d",o3);
	printf(">");
	printf("End of Phase 2 for store_4");

    freeaddrinfo(servinfo8);

    //printf("talker: sent %d bytes to %s\n", numbytes8, "nunki.usc.edu");
    close(sockfd8);



/////////////////////////////////////////////////////////////

	
	


////////////////////////////////////////////////////////////Store2 Receiving data

	//
	

	return 0;
}

