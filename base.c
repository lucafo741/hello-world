#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int traduzbase(char c){
	if(c=='b')
		return 2;
	if(c=='d')
		return 10;
	if(c=='o')
		return 8;
	if(c=='h')
		return 16;
	return 1;
}

char* toB(int numero, char* x){
	int i, j;

	for(i=0;numero>0;i++){
		x[i]=numero%2;
		numero/=2;

	}
	return x;
}

int fromB(char* numero, int base){
	int i, res=0;

	for(i=0;i<32;i++){
		res += pow(2,i)*numero[i];
	}
	return res;
}

int main(){

	int numero, b, i;
	char base1, base2;
	char *bin;
	bin = (char*)malloc(32*sizeof(char));
	for(i=0;i<32;i++){
		bin[i]=0;;
	}
	scanf("%c",&base1);

	b = traduzbase(base1);
	if(b==8){
		scanf("%o",&numero);
	}
	if(b==10){
		scanf("%d",&numero);
	}
	if(b==16){
		scanf("%x",&numero);
	}
	if(b==2){
		scanf("%s",&bin);
	}

	scanf("%c%c",&base1,&base2);
	if(b!=2){
		bin = toB(numero,bin);
	}


	b = traduzbase(base2);
	if(b==8){
		printf("%o\n",fromB(bin,b));
	}
	if(b==10){
		printf("%d\n",fromB(bin,b));
	}
	if(b==16){
		printf("%x\n",fromB(bin,b));
	}
	if(b==2){
		for(i=31;i>=0;i--){
			printf("%d",bin[i]);
		}
	}

	printf("\n");
	system("pause");
}