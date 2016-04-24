#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	
	time_t timer;
	while(1){
		timer = time(NULL);
		//FILE *p;
		//p = fopen("data","a+");
		printf("%d\n",timer);
		system("pause");
}
	return 0;
}