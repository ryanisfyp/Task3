#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <time.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <netinet/in.h> 
 
int main()
{
    time_t clock;
int epoch_time = 0;
  time_t rawtime; 
time_t epoch_time_as_time_t = epoch_time; 


  struct tm * timeinfo; 
    char dataSending[1025]; 
    int clintListn = 0, clintConnt = 0;
    struct sockaddr_in ipOfServer;
    clintListn = socket(AF_INET, SOCK_STREAM, 0); 
    memset(&ipOfServer, '0', sizeof(ipOfServer));
    memset(dataSending, '0', sizeof(dataSending));
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
    ipOfServer.sin_port = htons(7778);        
    bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
    listen(clintListn , 20);
 
    while(1)
    {
	        clock = time(NULL);
  		time ( &rawtime );
  		timeinfo = localtime ( &rawtime );

        printf("\n\nWaiting for client connection...\n"); 
        clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);
 	
	printf("Connected. Client time : %s" , asctime (timeinfo) ); 
////////////////////////////////
timeinfo = localtime(&epoch_time_as_time_t);
if(epoch_time >= 0 && epoch_time < 12)
{    
printf("its morning", epoch_time);
snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Morning");
write(clintConnt, dataSending, strlen(dataSending));
}

else if(epoch_time >= 12 && epoch_time < 14)
{    
printf("its afternoon", epoch_time);
snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Afternoon");
write(clintConnt, dataSending, strlen(dataSending));
}

else if(epoch_time >= 14 && epoch_time < 19)
{    
printf("its evening", epoch_time);
snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Evening");
write(clintConnt, dataSending, strlen(dataSending));
}

else if(epoch_time >= 19 && epoch_time < 24)
{    
printf("its night", epoch_time);
snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Night");
write(clintConnt, dataSending, strlen(dataSending));
}



       
 
        close(clintConnt);
        sleep(1);
     }
 
     return 0;
}
