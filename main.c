#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//fflush(stdin); remove(araclistesi.txt); ---->Dosya sildirir (tamamen)
//rename("ismi degisecek dosyanin ismi","dosyanin yeni ismi");
typedef struct
{
    char satidi_mi[10];
    char tarih[12];
    int fiyat;

} satilma;

typedef struct
{
    int arac_no;
    satilma bilgisi;
    char arac_durumu[12];
    char marka[15];
    char model[15];
    int km;
} araba;
void arac_kaydi()
{
    int i=0;
    araba kayit;
    printf("Aracinizin markasini giriniz: ");
    fflush(stdin);
    gets(kayit.marka);
    printf("Aracinizin modelini giriniz: ");
    fflush(stdin);
    gets(kayit.model);
    printf("Arac km'sini giriniz: ");
    scanf("%d",&kayit.km);
    printf("Arac durumu'nu(Birinci El veya Ikinci el diye giriþ yapiniz) belirtiniz:");
    fflush(stdin);
    gets(kayit.arac_durumu);
    srand(time(NULL));
    kayit.arac_no=rand()%100000;
    FILE *dosya;
    dosya=fopen("arabalistesi.txt","a");
    fprintf(dosya,"%d\t%s\t%s\t%d km\t%s*\n",kayit.arac_no,kayit.marka,kayit.model,kayit.km,kayit.arac_durumu);
    fclose(dosya);
    printf("Isleminiz basariyla gerceklesmistir.");
}
void arac_bul()
{

    FILE *dosya;
    char k1;
    char aracno[6],deger[15];
    printf("Lutfen aramak istediginiz aracin numarasini giriniz:");
    scanf("%s",&aracno);
    if((dosya=fopen("arabalistesi.txt","r"))!=NULL)
    {
        while(!feof(dosya))
        {
            fscanf(dosya,"%s",&deger);
            if(aracno[0]==deger[0]&&aracno[1]==deger[1]&&aracno[2]==deger[2]&&aracno[3]==deger[3]&&aracno[4]==deger[4])
                break;

        }
    }
    else
        printf("Arac dosyasi bulunamadi");

    if(aracno[0]==deger[0]&&aracno[1]==deger[1]&&aracno[2]==deger[2]&&aracno[3]==deger[3]&&aracno[4]==deger[4])
    {
        printf("Arac bilgileri sunlardir:\n%d",aracno);
        fopen("arabalistesi.txt","r");
        do
        {
            fscanf(dosya,"%c",&k1);
            printf("%c",k1);

        }
        while(k1!='*');
        fclose(dosya);

    }
    else
        printf("Girdiginiz arac numarasina ait arac bulunamadi");
}
void arac_guncelle()
{
    int aracno,sec,yeni1;
    char yeni[10];
    printf("Guncellemek istediginiz aracin no' sunu giriniz:");
    scanf("%d",&aracno);
    araba a1;
    char km[3],el[4];
    FILE *dosya1, *dosya2;
    printf("Degistirmek istediginiz ozelligi giriniz\n");
    printf("1-Marka 2-Model 3-Kilometre 4-Araç Durumu(El)");
    scanf("%d",&sec);
    dosya1=fopen("arabalistesi.txt","r");
    dosya2=fopen("araci.txt","w");

    switch(sec)
    {
    case 1:
        printf("Lutfen guncel markayi giriniz:");
        gets(yeni);
        if(dosya1!=NULL && dosya2!=NULL)
        {
            while(fscanf(dosya1,"%d\t%s\t%s\t%d %s\t%s %s\n",&a1.arac_no,a1.marka,a1.model,&a1.km,km,a1.arac_durumu,el) !=EOF )
            {
                if(aracno==a1.arac_no)
                fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
                else
                    fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
            }

        }
        printf("\nIsleminiz tamamlanmistir");
        break;
    case 2:
        printf("Lutfen guncel modeli giriniz:");
        gets(yeni);
        if(dosya1!=NULL && dosya2!=NULL)
        {
            while(fscanf(dosya1,"%d\t%s\t%s\t%d %s\t%s %s\n",&a1.arac_no,a1.marka,a1.model,&a1.km,km,a1.arac_durumu,el) !=EOF )
            {
                if(aracno==a1.arac_no)
                fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,yeni,a1.km,km,a1.arac_durumu,el);
                else
                    fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
            }

        }
        printf("\nIsleminiz tamamlanmistir");
        break;
    case 3:
        printf("Lutfen guncel kilometreyi giriniz:");
        scanf("%d",&yeni1);
        if(dosya1!=NULL && dosya2!=NULL)
        {
            while(fscanf(dosya1,"%d\t%s\t%s\t%d %s\t%s %s\n",&a1.arac_no,a1.marka,a1.model,&a1.km,km,a1.arac_durumu,el) !=EOF )
            {
                if(aracno==a1.arac_no)
                fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,yeni1,km,a1.arac_durumu,el);
                else
                    fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
            }

        }
        printf("\nIsleminiz tamamlanmistir");
        break;
    case 4:
        printf("Lutfen guncel arac durumunu giriniz(Birinci El veya Ikinci El):");
        scanf("%s",yeni);
        if(dosya1!=NULL && dosya2!=NULL)
        {
            while(fscanf(dosya1,"%d\t%s\t%s\t%d %s\t%s %s\n",&a1.arac_no,a1.marka,a1.model,&a1.km,km,a1.arac_durumu,el) !=EOF )
            {
                if(aracno==a1.arac_no)
                fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,yeni,el);
                else
                    fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
            }

        }
        printf("\nIsleminiz tamamlanmistir");
        break;
    }


    fclose(dosya1);
    fclose(dosya2);
    remove("arabalistesi.txt");
    rename("araci.txt","arabalistesi.txt");

}
void arac_sat()
{
    char el[4],km[3],tl[3]="TL";
    araba a1;
    int aracno,satis;
    FILE *dosya1, *dosya2, *dosya3;
    printf("Sattiginiz aracin arac no'sunu giriniz:");
    scanf("%d",&aracno);
    printf("Aracinizi ne kadara sattiniz:");
    scanf("%d",&satis);
    dosya1=fopen("arabalistesi.txt","r");
    dosya2=fopen("araci.txt","w");
    dosya3=fopen("satilanlar.txt","a");
    if(dosya1!=NULL && dosya2!=NULL && dosya3!=NULL)
    {
        while(fscanf(dosya1,"%d\t%s\t%s\t%d %s\t%s %s\n",&a1.arac_no,a1.marka,a1.model,&a1.km,km,a1.arac_durumu,el) !=EOF )
        {
            if(aracno==a1.arac_no)
                fprintf(dosya3,"%d\t%s\t%s\t%d %s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,satis,tl,a1.arac_durumu,el);

            else
                fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
        }

    }
    printf("\nArabaniz satilanlar listesine eklenmistir");
    fclose(dosya1);
    fclose(dosya2);
    remove("arabalistesi.txt");
    rename("araci.txt","arabalistesi.txt");






}
void arac_listele()
{
    FILE *dosya;
    char karakter;
    if((dosya=fopen("arabalistesi.txt","r+"))!=NULL)
    {
        karakter=fgetc(dosya);
        while(karakter!=EOF)
        {
            printf("%c",karakter);
            karakter=fgetc(dosya);
        }
    }
    else
        printf("Dosya bulunamadi");
    fclose(dosya);
    printf("Galerimizin arac gecmisi yukaridaki listede verilmistir.\n\n");
}
void arac_sil()
{
    int silinicek_no;
    araba a1;
    char km[3],el[4];
    FILE *dosya1, *dosya2;
    printf("Silmek istediginiz aracin numarasini giriniz:");
    scanf("%d",&silinicek_no);
    dosya1=fopen("arabalistesi.txt","r");
    dosya2=fopen("araci.txt","w");
    if(dosya1!=NULL && dosya2!=NULL)
    {
        while(fscanf(dosya1,"%d\t%s\t%s\t%d %s\t%s %s\n",&a1.arac_no,a1.marka,a1.model,&a1.km,km,a1.arac_durumu,el) !=EOF )
        {
            if(silinicek_no==a1.arac_no);

            else
                fprintf(dosya2,"%d\t%s\t%s\t%d %s\t%s %s\n",a1.arac_no,a1.marka,a1.model,a1.km,km,a1.arac_durumu,el);
        }

    }
    printf("\nSilme islemi tamamlanmistir");
    fclose(dosya1);
    fclose(dosya2);
    remove("arabalistesi.txt");
    rename("araci.txt","arabalistesi.txt");



}
int main()
{
    char space=' ';
    int choose;
start:
    printf("CANDELA CAR BILGI SISTEMINE HOSGELDINIZ\n");
    printf("1-Yeni arac kaydi%3c4-Araba sat\n",space);
    printf("2-Arac Bul%10c5-Araclari Listele\n",space);
    printf("3-Arac guncelle%5c6-Arac Sil\n",space);
    printf("Cikis yapmak icin 0'a basiniz\n");
    printf("Yapacaginiz islemin yanindakis sayiyi giriniz: ");
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        arac_kaydi();
        break;
    case 2:
        arac_bul();
        break;
    case 3:
        arac_guncelle();
        break;
    case 4:
        arac_sat();
        break;
    case 5:
        arac_listele();
        break;
    case 6:
        arac_sil();
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("Lutfen gecerli bir deger giriniz.\n\n");
        goto start;
        break;

    }

    return 0;
}
