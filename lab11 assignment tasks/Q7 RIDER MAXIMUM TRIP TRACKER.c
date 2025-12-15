#include <stdio.h>
#include <stdlib.h>

int maxtotal_trip(int tips[], int n, int i);

int main(){
	int n; //num of stops
	int i;

	printf("Enter num of delivery stops: ");
	scanf("%d",&n);

	int tips[n];
	printf("Enter tip amounts for %d stops: \n",n);
	for(i=0;i<n;i++){
		printf("\ntip for stop %d: \n",i+1);
		scanf("%d", &tips[i]);
	}

	int result=maxtotal_trip(tips,n,0);
	printf("Maximum total tip collection is: %d\n",result);

	return 0;
}

int maxtotal_trip(int tips[], int n, int i){

	if(i>=n){
		return 0;
	}
	if (i==n-1) {
		return tips[i];
	}

	int take=tips[i]+maxtotal_trip(tips,n,i+1);
	int skip;
	if(i+2<=n){
		skip=maxtotal_trip(tips,n,i+2);
	}
	else{
		skip=0;
	}
	if(take>skip){
		return take;
	}
	else{
		return skip;
	}
}

