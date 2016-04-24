#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2){
	
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}

int main(){

	int a,b,c;
	printf("2 Numeros Plocs : ");
	scanf(" %d %d", &a, &b);
	swap(&a,&b);
	printf("a:%d  b:%d\n",a,b);
	system("pause");
	return 0;
}