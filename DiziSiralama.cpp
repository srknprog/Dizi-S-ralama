#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

  struct dugum{
	int veri;
	dugum *sol;
	dugum *sag;
};


void quickSort(int *,int, int);
void shellSort(int *, int );
struct dugum *yeniDugum(int );
struct dugum *elemanEkle(struct dugum* ,int );
void agacYazdir(dugum * , int * , int &);
void treeSort(int * ,int );
void diziSirala(int *,int );


int main(){
	int *dizi,byt;
	int secenek;
	cout<<"Dizinin boyutunu ve sayilari giriniz : ";
	cin>>byt;
	dizi=(int *)malloc(byt*sizeof(int));
	for(int i = 0 ; i < byt ; i++){
		cin>>dizi[i];
	}
	cout<<"\n\nGirilen dizi : ";
	 for(int i = 0 ; i < byt ; i++){
        cout<<dizi[i]<<" ";
    }
menu:	cout<<"\n\n\n---------------------------------\n\n\n\n";
	cout<<"\n\n\nDiziyi Quick Sort Algoritmasi ile siralamak icin 1'e\n\n";
	cout<<"\n\n\nDiziyi Shell Sort Algoritmasi ile siralamak icin 2'e\n\n";
	cout<<"\n\n\nDiziyi Tree Sort Algoritmasi ile siralamak icin 3'e\n\n";
	cout<<"\n\n\nDiziyi Decision Tree  Algoritmasi ile siralamak icin 4'e\n\n";
	cout<<"\n\n\nProgramdan cikmak icin 5'e basiniz.";
	cin>>secenek;
	while(1){
	
	switch(secenek){
		
		case 1:cout<<"\n\nQuickSort ile siralanmis dizi : ";
				quickSort(dizi,0,byt-1);
				diziSirala(dizi,byt);
				break;
				
		case 2:cout<<"\n\nSheþþSort ile siralanmis dizi : ";
				shellSort(dizi,byt);
			   diziSirala(dizi,byt);
			   break;
			   
		case 3:cout<<"\n\nTreeSort ile siralanmis dizi : ";
				treeSort(dizi,byt);
				diziSirala(dizi,byt);
				break;  
		case 5:exit(0);				
	}
	goto menu;
	break;
	
}
   
    return 0;
    
}
	
	void quickSort(int *dizi,int ilk ,int son){
		 int gecici,i,j,pivot; 
	     pivot=ilk; 
	   
	  
	    if(son>ilk){
	        pivot=ilk;
	        i=ilk;
	        j=son;
	        while (i<j){
	            while (dizi[i]<=dizi[pivot] && i<son && j>i){ 
	                i++;
	            }
	            while (dizi[j]>=dizi[pivot] && j>=ilk && j>=i){
	                j--;
	            }
	            if (j>i){ 
	                gecici=dizi[i];
	                dizi[i]=dizi[j];
	                dizi[j]=gecici;
	            }
	        }
	        
	        gecici=dizi[j];
	        dizi[j]=dizi[pivot];
	        dizi[pivot]=gecici;
	        quickSort(dizi,ilk,j-1);
	        quickSort(dizi,j+1,son);
	    }
	}


void shellSort(int *dizi,int boyut){
	int gecici;
  for (int i = boyut / 2; i > 0; i = i / 2)
    {
        for (int j = i; j < boyut; j++)
        {
            for(int k = j - i; k >= 0; k = k - i)
            {
                if (dizi[k+i] >= dizi[k])
                    break;
                else
                {
                    gecici = dizi[k];
                    dizi[k] = dizi[k+i];
                    dizi[k+i] = gecici;
                }
            }
        }
    }
}

struct dugum *yeniDugum(int eleman){
	struct dugum *gecici=(struct dugum *)malloc(sizeof(struct dugum));
	gecici->veri=eleman;
	gecici->sol=gecici->sag=NULL;
	return gecici;
}


struct dugum *elemanEkle(struct dugum* agac,int veri){
	if(agac==NULL){
		return yeniDugum(veri);
	}
	
	if(veri< agac->veri){
		agac->sol = elemanEkle(agac->sol,veri);
	}
	else{
		agac->sag=elemanEkle(agac->sag,veri);
	}
	return agac;
}

void agacYazdir(dugum *kok, int * dizi, int &i){
	if(kok!=NULL){
		agacYazdir(kok->sol,dizi,i);
		dizi[i++]=kok->veri;
		agacYazdir(kok->sag,dizi,i);
	}
}

void treeSort(int *dizi,int byt){
	struct dugum *kok=NULL;
	kok=elemanEkle(kok,dizi[0]);
	for(int i=1 ; i < byt ; i++){
		kok=elemanEkle(kok,dizi[i]);
	}
	int k=0;
	agacYazdir(kok,dizi,k);
}

void diziSirala(int *dizi,int byt){
	for(int i = 0 ; i < byt ; i++){
        cout<<dizi[i]<<" ";
    }
}

