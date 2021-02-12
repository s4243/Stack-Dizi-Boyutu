#include<stdio.h>
#include<stdlib.h>
int* dizi;
int boyut = 2;
int tepe = 0;
int pop() {
	if (tepe <= boyut / 4)//dizinin boyutu eger 1/4 düþer ise
	{
		int* dizi2 = (int*)malloc(sizeof(int) * boyut / 2);//dizinin boyutunu 2 bol
		for (int i = 0; i < boyut; i++)
			dizi2[i] = dizi[i];
		//free(dizi);
		dizi = dizi2;
		
		boyut /= 2;//boyut ikiye bol
		
	}
	return dizi[--tepe];
}
void push(int a)
{
	if (tepe >= boyut)
	{
		int* dizi2 = (int*)malloc(sizeof(int) * boyut * 2);//eger dizimiz doldu ise mesela dizi 2ifade alýyor ise o zaman 2 ile çarparýz ve hafýzada o kadar yer ayýrýrýz
		for (int i = 0; i < boyut; i++)
			dizi2[i] = dizi[i];//dizi i deki boyuta olan ifadelere kadar dizi2 aktar
		//free(dizi);//dizi dizi2 gosterdigi zaman dizi nýndegerlerini dizi 2 gecirdigimiz için dizi içindekileri silip dizi2 gosterelim 
		dizi = dizi2;//dizi dinamik bir diziye atabilmemiz için onun da pointer olmasý gerekir
		boyut *= 2;

	}
	dizi[tepe++] = a;
}
void bastir() {
	printf("boyut:%d\n", boyut);
	for (int i = 0;i < tepe;i++)
	{
		printf("%d\n", dizi[i]);
	}
}
int main()
{
	dizi = (int*)malloc(sizeof(int) * 2);// iki deger alan diziyi ilk cagrýlan yerde yazdýrmak dinamik dizi
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	bastir();
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());
	bastir();
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
	bastir();
}