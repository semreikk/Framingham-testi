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
	printf("\t\t\t\t*****Kardiyovasküler Risk Hesaplama****\n\n\n");
	
	printf("\n NOT: Framingham Kalp Çalışmasına Massachusetts'in (ABD) Framingham kasabasından\n 30-62 yaşları arasındaki 5200 kişi katılmıştır. Hastalar, araştırmacılara uzun\n bir dönem içerisinde kardiyovasküler hastalıkların gelişimine katkıda bulunan\n yaygın faktörler ve özellikleri belirlemeye yardımcı olmak amacıyla 1948 yılından beri takip edilmektedir. \n\n\n");
	
	printf("10 yıl içinde kardiyovasküler hastalıkların gelişme riskini hesplamak için lütfen aşağıdaki bilgileri doğru ve eksiksiz biçimde doldurunuz.\n\n");
	
	// yas
	tekrar1:
	printf("Yaş: ");
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
		printf("\n\nGeçersiz yaş. Tekrar Deneyiniz.\n\n");
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
		printf("\n\nGeçersiz LDL değeri. Tekrar Deneyiniz.\n\n");
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
		printf("\n\nGeçersiz HDL kolestrol değeri. Tekrar Deneyiniz.\n\n");
		goto tekrar3;
	}
	
	//tansiyon
	tekrar4:
	printf("Kan Basıncı/tansiyon(Sırayla Büyük/Küçük): ");
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
		printf("\n\nGeçersiz değerler. Tekrar Deneyiniz.\n\n");
		goto tekrar4;
	}
	
	//diyabet
	
	printf("Diyabet(evet/hayır): ");
	scanf("%s",&diyabet);
	
	if(diyabet=="evet" || diyabet == "Evet" || diyabet== "EVET" || diyabet=="e" || diyabet=="E" ){
		puan+=2;
	}
	else if(diyabet=="hayır" || diyabet=="Hayır" || diyabet == "HAYIR" || diyabet=="h" || diyabet =="H"){
		puan+=0;
	}
	
	//sigara
	
	printf("Sigara(e/h): ");
	scanf("%s",&sigara);
	
	if(sigara=="evet" || sigara == "Evet" || sigara== "EVET" || sigara=="e" || sigara=="E" ){
		puan+=2;
	}
	else if(sigara=="hayır" || sigara=="Hayır" || sigara == "HAYIR" || sigara=="h" || sigara =="H"){
		puan+=0;
	}
	
	
	
	// risk hesaplanması
	
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
		    printf("Bir şeyler ters gitti!!!");
			break;			
	}
	printf("\n\n\n10 Yıl içinde kardiyovasküler hastalıklara yakalanma riskiniz %% %d\n\n",yuzde);
	
	// yas karşılaştırması
	
	if(yas>=30 && yas<=34){
		printf("Size düşük riskli diyebilmek için risk %%2 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%3");
	}
	else if(yas>=35 && yas<=39){
		printf("Size düşük riskli diyebilmek için risk %%5'olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%3");
	}
	else if(yas>=40 && yas<=44){
		printf("Size düşük riskli diyebilmek için risk %%7 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%4");
	}
	else if(yas>=45 && yas<=49){
		printf("Size düşük riskli diyebilmek için risk %%11'olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%4");
	}
	else if(yas>=50 && yas<=54){
		printf("Size düşük riskli diyebilmek için risk %%14 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%6");
	}
	else if(yas>=55 && yas<=59){
		printf("Size düşük riskli diyebilmek için risk %%16 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%7");
	}
	else if(yas>=60 && yas<=64){
		printf("Size düşük riskli diyebilmek için risk %%21 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%9");
	}
	else if(yas>=65 && yas<=69){
		printf("Size düşük riskli diyebilmek için risk %%25 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%11");
	}
	else if(yas>=70 && yas<=74){
		printf("Size düşük riskli diyebilmek için risk %%30 olmalıdır.\n");
		printf("Sizin yaşınızdaki diğer insanların 10 yıllık ortalama riski %%14");
	}
	

	return 0;
}
