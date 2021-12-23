#include "csapp.h"

int main(void) {
char *buf, *p, *equal_ptr;
char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE], factor1[MAXLINE], factor2[MAXLINE];
int n1=0, n2=0;

/* Extract the two arguments */
if ((buf = getenv("QUERY_STRING")) != NULL) {
    // fprintf(stderr, "%s\n", buf); //first=123&second=123
    
    p = strchr(buf, '&');
    *p = '\0'; //first=123\0second=123\0
    
    strcpy(arg1, buf);
    equal_ptr = strchr(arg1, '=');
    strcpy(factor1, equal_ptr + 1); //factor1 = 123

    strcpy(arg2, p+1);   
    equal_ptr = strchr(arg2, '=');
    strcpy(factor2, equal_ptr + 1); //factor2 = 123
    
    n1 = atoi(factor1);
    n2 = atoi(factor2);
}

/* Make the response body */
sprintf(content, "QUERY_STRING=%s", buf);
sprintf(content, "Welcome to add.com: ");
sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>",
content, n1, n2, n1 + n2);
sprintf(content, "%sThanks for visiting!\r\n", content);

/* Generate the HTTP response */
printf("Connection: close\r\n");
printf("Content-length: %d\r\n", (int)strlen(content));
printf("Content-type: text/html\r\n\r\n");
printf("%s", content);
fflush(stdout);

exit(0);
}