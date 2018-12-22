#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void oneOption(char *option);
int writeDns(char *dns1, char *dns2);
void readFile();
int getAnswer(char *ans);

/*
*   Help information
*/
char *Usage = "\n  chdns: A script to change dns. (NetworkManager) [need sudo]\
               \n         Change /etc/resolv.conf\
                        \n\n\t chdns [dns1] [dns2]\
                        \n\n\tOptions: \
                        \n\n\t -google (8.8.8.8 & 8.8.4.4)\
                        \n\n\t -114dns (114.114.114.114 & 218.85.157.99)\
                        \n\n\t -show print dns file content.(/etc/resolv.conf)\n\n";

/*
*   dns file path.
*/
char *dnsPath = "/etc/resolv.conf";

/*
*   '-h', -google' and '-114dns' pattern
*/
char *help = "-h", *google = "-google", *dns114 = "-114dns", *show = "-show";

/*
*   When there is only one option
*/
void oneOption(char *option){
    if (0 == strcmp(help, option)){
        printf ("%s",Usage);
    }else if (0 == strcmp(google, option)){
        readFile();
        if (1 == getAnswer("  chdns: Do you want to change?(y or n):  ")){
            writeDns("8.8.8.8", "8.8.4.4");
        }else{
            printf ("  Refuse to change.\n");
            return;
        }
    }else if (0 == strcmp(dns114, option)){
        readFile();
        if (1 == getAnswer("  chdns: Do you want to change?(y or n):  ")){
            writeDns("114.114.114.114", "218.85.157.99");
        }else{
            printf ("  Refuse to change.\n");
            return;
        }
    }else if (0 == strcmp (show, option)){
        readFile();
    }else {
        printf ("  chdns: There is no such option.('-h' for help)\n\n");
    }
}

/*
*   Write DNS to /etc/resolv.conf
*/
int writeDns(char *dns1, char *dns2){
    char *ns = "nameserver = ";
    FILE *resolv = fopen (dnsPath,"w+");
    printf ("\n  chdns: Message( nameserver %s nameserver %s)\n\n", dns1, dns2);
    int state = fprintf (resolv, "#Change by chdns\nnameserver %s\nnameserver %s\n\n", dns1, dns2);
    fclose (resolv);

    if (state < 0){
        printf ("  chdns: fail to write.\n\n");
        return 0;
    }else{
        printf ("  chdns: Succeccful!\n\n");
        return 1;
    }
}

/*
*   Read file
*/
void readFile(){
    FILE *resolv = fopen (dnsPath, "r");
    char c = ' ';
    printf ("\n Now file content(%s):\n\t", dnsPath);
    while ((c = fgetc(resolv)) != EOF){
        putchar (c);
        if (c == '\n'){
            printf ("\t");
        }
    }
    fclose (resolv);
    printf ("\n\n");
}

/*
*   Get answer
*/
int getAnswer(char *ans){
    char an;
    printf (ans);
    an = getchar();
//    printf(" answer = %c\n",an);
    if (an == '\n'){
        an = 'y';
    }
    if (an == 'y' || an == 'Y'){
        return 1;
    }else{
        return 0;
    }
}




int main (int argc, char *argv[]){
    if ( argc > 3){
        printf ("  chdns: \n\t Too many variables: %d\n",argc);
    } else {
        switch (argc){
            case 1:
                printf ("\n  chdns: '-h' for help.\n\n");
                break;
            case 2:
                oneOption(argv[1]);
                break;
            case 3:
                readFile();
                if (1 == getAnswer("  chdns: Do you want to change?(y or n):  ")){
                    writeDns(argv[1], argv[2]);
                }else{
                    printf ("  Refuse to change.\n");
                }
                break;
        }
    }
    return 0;
}
