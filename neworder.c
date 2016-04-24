#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DeathChance 1
#define FertileYears 27
#define PregChance 100

void born(int *mborn, int *fborn, int fem, int MC, int year){
	int i, m=0, f=0, t1, t2;
	for(i=0;i<fem && i<10;i++){
		t1 = (rand()%100);
		if(t1<PregChance){
			t2 = (rand()%100);
			if(t2<MC){
				m++;
			}else f++;
		}
		//printf("|||%d %d|||\n",t1, t2);
	}

	mborn[year]=m;
	fborn[year]=f;
}

int killf(int fem){
	int i, f=fem;
	for(i=0;i<f;i++){
		if((rand()%100)<DeathChance)
			fem--;
	}
	return fem;
}

int killm(int male){
	int i, m=male;
	for(i=0;i<m;i++){
		if((rand()%100)<DeathChance)
			male--;
	}
	return male;
}

void sim(int male, int fem, int population, int *mborn, int *fborn, int MC){
	int i, mm=0, mf=0, j, maxp=0;
	for(i=0;fem>0 && male>0 && population<=1000000 && i<1000;i++){
		
		fem = killf(fem);
		male = killm(male);
		born(mborn,fborn,fem,MC,i);
		fem+=fborn[i];
		male+=mborn[i];
		if(i-FertileYears==0){
			male-=MC;
			fem-=(100-MC);
		}
		if(i-FertileYears>0){
			male-=mborn[i-28];
			fem-=fborn[i-28];
		}
		population = male + fem;
		if(maxp<population)
			maxp = population;
		if(mm<male)
			mm=male;
		if(mf<fem)
			mf=fem;
	}
	/*for(j=0;j<28;j++){
			printf("%d:  %d | %d\n", j, mborn[j], fborn[j]);
	}*/

	printf("MC = %d MM=%d MF=%d| MP=%d \t| years=%d \t| m=%d | f=%d\n",MC, mm, mf, maxp, i, male, fem);
}


int main(int argc, char const *argv[]){
	
	srand(time(NULL));
	int population = 100 , preg, nmale, nfem, i;
	int mborn[1000], fborn[1000];
	for(population, i=1;i<100;i++){
		//i=50;
		sim(i,100-i,population, mborn, fborn, i);
	}
	system("pause");

	return 0;
}