#include <stdio.h>

int main(){

    char A[3] = {10,11,12};
    char *p = A;
    int i, c;

    printf("%x\n",&A[0]);
    printf("%x\n\n",&A[1]);

    for(i=0;i<100;i++){
        if(*p>=0)
            printf("%x  -  %d  -  %x\n",p,*p,*p);
        else
            printf("%x  -  %d  -  %x\n",p,*p,*p-0xffffff00);
        p++;
    }


return 0;
}
