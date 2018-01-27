/*Required Headers*/
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
 

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
char *strrlf(char *str)
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}



int main()
{
    char str[100];
    int listen_fd, comm_fd;
    struct sockaddr_in servaddr;


    initscr();
    erase();  refresh();
    char linex[105];

    while(1)
    {
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero( &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 10);
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
        // bzero( str, 100);
        read(comm_fd,str,100);
        strncpy( linex, str, 100-1 ); 
        //printf("Echoing back - %s",str);
        //write(comm_fd, str, strlen(str)+1);
        erase(); refresh();
        mvprintw( 5, 0, "                       ");
        mvprintw( 5, 0, "|%s|", strrlf(linex) );
        refresh();
    }
    endwin();
}
