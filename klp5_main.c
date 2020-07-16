#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char *argv[]) {
	
	int yas;
	int ldl;
	int hdl;
	int btansiyon,ktansiyon;
	char diyabet[4];
	char sigara[6];
	int puan=0;
	int yuzde=0;
	
	
	setlocale(LC_ALL,"Turkish");
	printf("\t\t\t\t*****Kardiyovask�ler Risk Hesaplama****\n\n\n");
	
	printf("\n NOT: Framingham Kalp �al��mas�na Massachusetts'in (ABD) Framingham kasabas�ndan\n 30-62 ya�lar� aras�ndaki 5200 ki�i kat�lm��t�r. Hastalar, ara�t�rmac�lara uzun\n bir d�nem i�erisinde kardiyovask�ler hastal�klar�n geli�imine katk�da bulunan\n yayg�n fakt�rler ve �zellikleri belirlemeye yard�mc� olmak amac�yla 1948 y�l�ndan beri takip edilmektedir. \n\n\n");
	
	printf("10 y�l i�inde kardiyovask�ler hastal�klar�n geli�me riskini hesplamak i�in l�tfen a�a��daki bilgileri do�ru ve eksiksiz bi�imde doldurunuz.\n\n");
	
	// yas
	tekrar1:
	printf("Ya�: ");
	scanf("%d",&yas);
	
	if(yas>=30 && yas<=34){
		puan-=1;
	}
	else if(yas>=35 && yas<=39){
		puan+=0;
	}
	else if(yas>=40 && yas<=44){
		puan+=1;
	}
	else if(yas>=45 && yas<=49){
		puan+=2;
	}
	else if(yas>=50 && yas<=54){
		puan+=3;
	}
	else if(yas>=55 && yas<=59){
		puan+=4;
	}
	else if(yas>=60 && yas<=64){
		puan+=5;
	}
	else if(yas>=65 && yas<=69){
		puan+=6;
	}
	else if(yas>=70 && yas<=74){
		puan+=7;
	}
	else{
		printf("\n\nGe�ersiz ya�. Tekrar Deneyiniz.\n\n");
		goto tekrar1;
	}
	
	// ldl
	tekrar2:
	printf("LDL Kolestrol (mg/dl): ");
	scanf("%d",&ldl);
	
	if(ldl<100){
		puan-=3;
	}
	else if(ldl>=100 && ldl<=159){
		puan+=0;
    }
    else if(ldl>=160 && ldl<=189){
    	puan+=1;
	}
	else if(ldl==190){
		puan+=2;
	}
	else{
		printf("\n\nGe�ersiz LDL de�eri. Tekrar Deneyiniz.\n\n");
		goto tekrar2;
	}
	
	//hdl
	tekrar3:
	printf("HDL Kolestrol (mg/dl): ");
	scanf("%d",&hdl);
	
	if(hdl<35){
		puan+=2;
	}
	else if(hdl>=35 && hdl<=44){
		puan+=1;
    }
    else if(hdl>=45 && hdl<=49){
    	puan+=0;
	}
	else if(hdl>=50 && hdl<=59){
		puan+=0;
	}
	else if(hdl==60){
		puan-=1;
	}
	else{
		printf("\n\nGe�ersiz HDL kolestrol de�eri. Tekrar Deneyiniz.\n\n");
		goto tekrar3;
	}
	
	//tansiyon
	tekrar4:
	printf("Kan Bas�nc�/tansiyon(S�rayla B�y�k/K���k): ");
	scanf("%d/%d",&btansiyon,&ktansiyon);
	
	if(btansiyon<120 && ktansiyon<80){
		puan+=0;
	}
	else if((btansiyon>=120 && btansiyon<=129) && (ktansiyon>=80 && ktansiyon<=84)){
		puan+=0;
	}
	else if((btansiyon>=130 && btansiyon<=139) && (ktansiyon>=85 && ktansiyon<=89)){
		puan+=1;
	}
	else if((btansiyon>=140 && btansiyon<=159) && (ktansiyon>=90 && ktansiyon<=99)){
		puan+=2;
	}
	else if((btansiyon==160) && (ktansiyon==100)){
		puan+=3;
	}
	else{
		printf("\n\nGe�ersiz de�erler. Tekrar Deneyiniz.\n\n");
		goto tekrar4;
	}
	
	//diyabet
	
	printf("Diyabet(evet/hay�r): ");
	scanf("%s",&diyabet);
	
	if(diyabet=="evet" || diyabet == "Evet" || diyabet== "EVET" || diyabet=="e" || diyabet=="E" ){
		puan+=2;
	}
	else if(diyabet=="hay�r" || diyabet=="Hay�r" || diyabet == "HAYIR" || diyabet=="h" || diyabet =="H"){
		puan+=0;
	}
	
	//sigara
	
	printf("Sigara(e/h): ");
	scanf("%s",&sigara);
	
	if(sigara=="evet" || sigara == "Evet" || sigara== "EVET" || sigara=="e" || sigara=="E" ){
		puan+=2;
	}
	else if(sigara=="hay�r" || sigara=="Hay�r" || sigara == "HAYIR" || sigara=="h" || sigara =="H"){
		puan+=0;
	}
	
	
	
	// risk hesaplanmas�
	
	switch(puan){
		case -3:
			yuzde=1;
			break;
		case -2:
		case -1:
			yuzde=2;
			break;
		case 0:
			yuzde=3;
			break;
		case 1:
		case 2:
			yuzde=4;
			break;	
		case 3:
			yuzde=6;
		    break;
		case 4:
			yuzde=7;
			break;
		case 5:
			yuzde=9;
			break;
		case 6:	
		    yuzde=11;
		    break;
		case 7:
		    yuzde=14;
		    break;
		case 8:
		    yuzde=18;
		    break;
		case 9:
		    yuzde=22;
		    break;
		case 10:
		    yuzde=27;
		    break;
		case 11:
		    yuzde=33;
		    break;
		case 12:
		    yuzde=40;
		    break;
		case 13:
		    yuzde=47;
			break;
		case 14:
		    yuzde=56;
			break;							 
		default:
		    printf("Bir �eyler ters gitti!!!");
			break;			
	}
	printf("\n\n\n10 Y�l i�inde kardiyovask�ler hastal�klara yakalanma riskiniz %% %d\n\n",yuzde);
	
	// yas kar��la�t�rmas�
	
	if(yas>=30 && yas<=34){
		printf("Size d���k riskli diyebilmek i�in risk %%2 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%3");
	}
	else if(yas>=35 && yas<=39){
		printf("Size d���k riskli diyebilmek i�in risk %%5'olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%3");
	}
	else if(yas>=40 && yas<=44){
		printf("Size d���k riskli diyebilmek i�in risk %%7 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%4");
	}
	else if(yas>=45 && yas<=49){
		printf("Size d���k riskli diyebilmek i�in risk %%11'olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%4");
	}
	else if(yas>=50 && yas<=54){
		printf("Size d���k riskli diyebilmek i�in risk %%14 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%6");
	}
	else if(yas>=55 && yas<=59){
		printf("Size d���k riskli diyebilmek i�in risk %%16 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%7");
	}
	else if(yas>=60 && yas<=64){
		printf("Size d���k riskli diyebilmek i�in risk %%21 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%9");
	}
	else if(yas>=65 && yas<=69){
		printf("Size d���k riskli diyebilmek i�in risk %%25 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%11");
	}
	else if(yas>=70 && yas<=74){
		printf("Size d���k riskli diyebilmek i�in risk %%30 olmal�d�r.\n");
		printf("Sizin ya��n�zdaki di�er insanlar�n 10 y�ll�k ortalama riski %%14");
	}
	

	return 0;
}
