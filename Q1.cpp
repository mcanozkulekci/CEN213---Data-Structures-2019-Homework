#include <iostream>

using namespace std;


void swap(int *x,int *y){
	int temp =*x;
	*x=*y;
	*y =temp;
}

void bubbleSort(int arr[],int n){

	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}

}

void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}




//1. Parametre : ilk array
//2. Parametre : ikinci array
//3. Parametre : sizeof(ilkarray)
//4. Parametre : sizeof(ikinciarray)

bool isSubset(int arr1[],int arr2[],int m,int n){
	int i=0;
	int j=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(arr2[i] == arr1[j])
				break;

		}
		if(j == m)
			return 0;
	}

	return 1;

}
//İkinci Arrayin Sizeı daha küçük olmak zorunda.
bool isSmaller(int m,int n){
	if(n>m){
		cout<<"2inci Array Daha Büyük Olamaz.Tekrar Deneyin."<<"\n";
		return 0;
	}else{
		return 1;
	}
}

int main(){

int *a=NULL;
int *b=NULL;
int n1,n2,m;
int option;
while(1){
	cout<<"Çıkmak için -1e basınız."<<"\n";
	cout<<"Başlamak için 0a basınız.)"<<"\n";
	cin>>option;
	if(option == -1){
		cout<<"Programdan Çıkış Yapıldı!"<<endl;
		break;
	}

	if(option==0){


	cout<<"1. Arrayin Boyutunu Giriniz:"<<"\n";
	cin>>n1;

	a= new int[n1];

	cout<<"1. Arrayin Elemanlarını Giriniz:"<<"\n";

	for(int i=0;i<n1;i++){
	   cin>>a[i];
	}

	bubbleSort(a,n1);
	cout<<"1. Array Sıralanmış: \n";
	printArray(a,n1);
	cout<<"\n";


	cout<<"2. Arrayin Boyutunu Giriniz:"<<"\n";
	cin>>n2;

	while(isSmaller(n1,n2)==0){
		cin>>n2;
		continue;
	}


	b= new int[n2];
	cout<<"2. Arrayin Elemanlarını Giriniz:"<<"\n";
	for(int i=0;i<n2;i++){
	   cin>>b[i];

	}
	bubbleSort(b,n2);
	cout<<"2. Array Sıralanmış:\n";
	printArray(b,n2);


	if(isSubset(a,b,n1,n2)){
		cout <<"2.Array,1.Arrayin Subsetidir.";
	}else{
		cout <<"2.Array,1.Arrayin Subseti DEĞİLDİR.";
	}
	cout<<"\n";

}





delete[] b;
b=NULL;
delete [] a;
a =NULL;

}

   return 0;
}