#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
#include <string.h>


struct data
{
    float x;
    float y;
    float z;
    int r;
    int g;
    int b;
    int num;
} data[100000];

void Cube(int numDots,int output);
int FindTheNumberOfDots(char *name);
int FindStartingPoint(char *name);
void OnlyReadName(char Name[][100]);
void Processing(int index,char *ch,int space);
int GetData(char *name);
void NearestFarthestPoint(int numDots,int output);
void Sphere(int numDots,float x,float y,float z,float r,int output);
float AverageLength(int numDots);
int Control(int contNum,char *ch);
int Errors(int numDots,int CountNumDots,char *name,int rgbmi,int output);
int StartControl(char *name);
int Ascii_Binary(char *name);
void BiggestSmallestDifference(float received[4],int numDots);
int Rgbon_off(char *name);
int ReadFileName(char fileName[][100]);
int GetDataBinary(char *name,int rgb);
void BatchFileControl(char fileName[][100],int numberOfFiles,int *faultyFile,int output);
void T_BiggestSmallestDifference(char fileName[][100],int numberOfFiles,int *faultyFile,int output);
void T_Cube(char fileName[][100],int numberOfFiles,int *faultyFile,int output);
void T_Average(char fileName[][100],int numberOfFiles,int *faultyFile,int output);
void T_Sphere(char fileName[][100],int numberOfFiles,int *faultyFile,float x,float y,float z,float r,int output);
int main()
{

    float x,y,z,r;
    int numDots,startDot,rgbmi,i;
    int CountNumDots,input,control=0;
    char fileName[100][100];
    int faultyFile[100]= {0};
    int numberOfFiles=ReadFileName(fileName);
    char folderName[30]="output";
    mkdir(folderName);
    FILE *output;
    output=fopen("output\\output.nkt","w");

        printf("\n");
        printf("**********MENU**********\n");
        printf("[1] File control\n");
        printf("[2] Nearest/Farthest Dots\n");
        printf("[3] Cube \n");
        printf("[4] Sphere \n");
        printf("[5] Average Dots Distances \n");
        printf("[0] Exit\n");
        printf("\n");

        fprintf(output,"\n");
        fprintf(output,"**********MENU**********\n");
        fprintf(output,"[1] File control\n");
        fprintf(output,"[2] Nearest/Farthest Dots\n");
        fprintf(output,"[3] Cube \n");
        fprintf(output,"[4] Sphere \n");
        fprintf(output,"[5] Average Dots Distances \n");
        fprintf(output,"[0] Exit\n");
        fprintf(output,"\n");

    while(1)
    {

        printf("\nPlease Make Your Choice: ");
        scanf("%d",&input);
        fprintf(output,"\nCHOICE : ");
        fprintf(output,"%d\n",input);
        switch(input)
        {
        case 1:
            control=1;
            BatchFileControl(fileName,numberOfFiles,faultyFile,output);
            break;
        case 2:
            if(control!=1)
            {
                fprintf(output,"Please Check the Data First...\n");
                printf("Please Check the Data First...\n");
                continue;
            }
            T_BiggestSmallestDifference(fileName,numberOfFiles,faultyFile,output);
            break;
            if(control!=1)
            {
                fprintf(output,"Please Check the Data First...\n");
                printf("Please Check the Data First...\n");
                continue;
            }
        case 3:
            if(control!=1)
            {
                fprintf(output,"Please Check the Data First...\n");
                printf("Please Check the Data First...\n");
                continue;
            }
            T_Cube(fileName,numberOfFiles,faultyFile,output);
            break;
        case 4:
            if(control!=1)
            {
                fprintf(output,"Please Check the Data First...\n");
                printf("Please Check the Data First...\n");
                continue;
            }

            printf("Sphere's..:\nX value: ");
            fprintf(output,"Sphere's..:\nX value: ");
            scanf("%f",&x);
            fprintf(output,"%f\n",x);
            printf("Y value: ");
            fprintf(output,"Y value: ");
            scanf("%f",&y);
            fprintf(output,"%f\n",y);
            printf("Z value: ");
            fprintf(output,"Z value: ");
            scanf("%f",&z);
            fprintf(output,"%f\n",z);
            printf("Radius value: ");
            fprintf(output,"Radius value: ");
            scanf("%f",&r);
            fprintf(output,"%f\n",r);
            T_Sphere(fileName,numberOfFiles,faultyFile,x,y,z,r,output);
            break;
        case 5:
            if(control!=1)
            {
                printf("Please Check the Data First...\n");
                fprintf(output,"Please Check the Data First...\n");
                continue;
            }
            T_Average(fileName,numberOfFiles,faultyFile,output);
            break;
        case 0:
            {
                fclose(output);
                exit(1);
            }
            break;
        }
    }

    return 0;
}

void T_Average(char fileName[][100],int numberOfFiles,int *faultyFile,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int i=0,rgb_mi,CountNumDots;
    for(i=0; i<numberOfFiles; i++)
    {
        if(faultyFile[i]==-1)
            continue;
        printf("\n-->%s\n",fileName[i]);
        fprintf(output,"\n-->%s\n",fileName[i]);
        rgb_mi=Rgbon_off(fileName[i]);
        if(Ascii_Binary(fileName[i])==1)
        {
            CountNumDots=GetData(fileName[i]);
            printf("%f\n",AverageLength(CountNumDots));
            fprintf(output,"%f\n",AverageLength(CountNumDots));
        }
        else
        {
            CountNumDots=GetDataBinary(fileName[i],rgb_mi);
            printf("%f\n",AverageLength(CountNumDots));
            fprintf(output,"%f\n",AverageLength(CountNumDots));
        }
    }
    //fclose(output);
}

void T_Sphere(char fileName[][100],int numberOfFiles,int *faultyFile,float x,float y,float z,float r,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int i=0,rgb_mi,CountNumDots;
    for(i=0; i<numberOfFiles; i++)
    {
        if(faultyFile[i]==-1)
            continue;
        printf("\n-->%s\n",fileName[i]);
        fprintf(output,"\n-->%s\n",fileName[i]);
        rgb_mi=Rgbon_off(fileName[i]);
        if(Ascii_Binary(fileName[i])==1)
        {
            CountNumDots=GetData(fileName[i]);
            Sphere(CountNumDots,x,y,z,r,output);
        }
        else
        {
            CountNumDots=GetDataBinary(fileName[i],rgb_mi);
            Sphere(CountNumDots,x,y,z,r,output);
        }
    }
    //fclose(output);
}

void T_Cube(char fileName[][100],int numberOfFiles,int *faultyFile,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int i=0,rgb_mi,CountNumDots;
    for(i=0; i<numberOfFiles; i++)
    {
        if(faultyFile[i]==-1)
            continue;
        printf("\n-->%s\n",fileName[i]);
        fprintf(output,"\n-->%s\n",fileName[i]);
        rgb_mi=Rgbon_off(fileName[i]);
        if(Ascii_Binary(fileName[i])==1)
        {
            CountNumDots=GetData(fileName[i]);
            Cube(CountNumDots,output);
        }
        else
        {
            CountNumDots=GetDataBinary(fileName[i],rgb_mi);
            Cube(CountNumDots,output);
        }
    }
    //fclose(output);
}

void T_BiggestSmallestDifference(char fileName[][100],int numberOfFiles,int *faultyFile,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int i=0,rgb_mi,CountNumDots;
    for(i=0; i<numberOfFiles; i++)
    {
        if(faultyFile[i]==-1)
            continue;
        printf("\n-->%s\n",fileName[i]);
        fprintf(output,"\n-->%s\n",fileName[i]);
        rgb_mi=Rgbon_off(fileName[i]);
        if(Ascii_Binary(fileName[i])==1)
        {
            CountNumDots=GetData(fileName[i]);
            NearestFarthestPoint(CountNumDots,output);
        }
        else
        {
            CountNumDots=GetDataBinary(fileName[i],rgb_mi);
            NearestFarthestPoint(CountNumDots,output);
        }
    }
    //fclose(output);
}

void BatchFileControl(char fileName[][100],int numberOfFiles,int *faultyFile,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int i,numDots,CountNumDots,rgbmi;
    if(numberOfFiles==-1){
        printf("No files found within the specified folder.");
    }

    for(i=0; i<numberOfFiles; i++)
    {
        printf("\n-->%s\n",fileName[i]);
        fprintf(output,"\n-->%s\n",fileName[i]);
        if(Ascii_Binary(fileName[i])==1)
        {
            if(StartControl(fileName[i])==1)
            {
                numDots=FindTheNumberOfDots(fileName[i]);
                CountNumDots=GetData(fileName[i]);
                rgbmi=Rgbon_off(fileName[i]);
                if(Errors(numDots,CountNumDots,fileName[i],rgbmi,output)==-1)
                {
                    faultyFile[i]=-1;
                    continue;
                }
                else
                {

                    printf("%s File succesfully read\n",fileName[i]);
                    fprintf(output,"%s File succesfully read\n",fileName[i]);
                }
            }
            else
            {
                printf("%s Unable to read file. Error in file format.\n",fileName[i]);
                fprintf(output,"%s Unable to read file. Error in file format.\n",fileName[i]);
                faultyFile[i]=-1;
            }
        }
        else
        {
            if(StartControl(fileName[i])==1)
            {
                numDots=FindTheNumberOfDots(fileName[i]);
                rgbmi=Rgbon_off(fileName[i]);
                CountNumDots=GetDataBinary(fileName[i],rgbmi);
                if((ErrorsBinary(numDots,fileName[i],rgbmi,CountNumDots,output))==-1)
                {
                    faultyFile[i]=-1;
                    continue;
                }
                else
                {
                    fprintf(output,"%s File succesfully read\n",fileName[i]);
                    printf("%s File succesfully read\n",fileName[i]);
                }
            }
            else
            {
                faultyFile[i]=-1;
               fprintf(output,"%s Unable to read file. Error in file format.\n",fileName[i]);
                printf("%s Unable to read file. Error in file format.\n",fileName[i]);
            }
        }
    }
    //fclose(output);
}

int ErrorsBinary(int numDots,char *name,int rgbmi,int CountNumDots,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int dot;
    if((dot=GetDataBinary(name,rgbmi))<0)
    {
        printf("ERROR:\n");
        printf("%d in the %s file. The point data is given without r g b.\n",name,dot*-1);
        fprintf(output,"ERROR:\n");
        fprintf(output,"% d in the% s file. The point data is given without r g b.\n",name,dot*-1);
        //fclose(output);
        return -1;
    }
    else if(numDots!=CountNumDots)
    {
        printf("number of dots in file %s is not valid.\n",name);
        fprintf(output,"number of dots in file %s is not valid.\n",name);
        //fclose(output);
        return -1;
    }
    else
    {
        //fclose(output);
        return 1;
    }
}
int Errors(int numDots,int CountNumDots,char *name,int rgbmi,int output)//*
{
    //FILE *output;
    //output=fopen("output\\output.nkt","a");
    int i,numDotsError=1;
    int errorDots=-1,rgbOnDotsOff=1;
    if(numDots!=CountNumDots)
    {
        printf("ERROR:\n");
        fprintf(output,"ERROR:\n");

        printf("number of dots in file %s is not valid.\n",name);
        fprintf(output,"number of dots in file %s is not valid.\n",name);
        numDotsError=-1;
    }
    for(i=0; i<CountNumDots; i++)
    {
        if(data[i].r==-1)
        {
            errorDots=data[i].num;
            break;
        }
    }
    if(rgbmi==1 && errorDots!=-1)
    {
        printf("ERROR:\n");
        fprintf(output,"ERROR:\n");
        printf("%d in the %s file. The point data is given without r g b.\n",name,errorDots);
        fprintf(output,"%d in the %s file. The point data is given without r g b.\n",name,errorDots);
        rgbOnDotsOff=-1;
    }
    if(rgbOnDotsOff==-1 || numDotsError==-1)
    {
        //fclose(output);
        return -1;
    }
    else
    {
        //fclose(output);
        return 1;
    }
}

void Cube(int numDots,int output)//*
{

    float bigSmallDifference[4]= {0};
    BiggestSmallestDifference(bigSmallDifference,numDots);
    printf("Dot information of the Cube:\n");
    printf("%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),bigSmallDifference[1],bigSmallDifference[2]);
    printf("%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),bigSmallDifference[1],bigSmallDifference[2]-bigSmallDifference[3]);
    printf("%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),(bigSmallDifference[1]-bigSmallDifference[3]),(bigSmallDifference[2]-bigSmallDifference[3]));
    printf("%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),(bigSmallDifference[1]-bigSmallDifference[3]),bigSmallDifference[2]);
    printf("%f %f %f\n",bigSmallDifference[0],bigSmallDifference[1],bigSmallDifference[2]);
    printf("%f %f %f\n",bigSmallDifference[0],(bigSmallDifference[1]-bigSmallDifference[3]),bigSmallDifference[2]);
    printf("%f %f %f\n",bigSmallDifference[0],bigSmallDifference[1],(bigSmallDifference[2]-bigSmallDifference[3]));
    printf("%f %f %f\n",bigSmallDifference[0],(bigSmallDifference[1]-bigSmallDifference[3]),(bigSmallDifference[2]-bigSmallDifference[3]));

    fprintf(output,"Dot information of the Cube:\n");
    fprintf(output,"%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),bigSmallDifference[1],bigSmallDifference[2]);
    fprintf(output,"%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),bigSmallDifference[1],bigSmallDifference[2]-bigSmallDifference[3]);
    fprintf(output,"%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),(bigSmallDifference[1]-bigSmallDifference[3]),(bigSmallDifference[2]-bigSmallDifference[3]));
    fprintf(output,"%f %f %f\n",(bigSmallDifference[0]-bigSmallDifference[3]),(bigSmallDifference[1]-bigSmallDifference[3]),bigSmallDifference[2]);
    fprintf(output,"%f %f %f\n",bigSmallDifference[0],bigSmallDifference[1],bigSmallDifference[2]);
    fprintf(output,"%f %f %f\n",bigSmallDifference[0],(bigSmallDifference[1]-bigSmallDifference[3]),bigSmallDifference[2]);
    fprintf(output,"%f %f %f\n",bigSmallDifference[0],bigSmallDifference[1],(bigSmallDifference[2]-bigSmallDifference[3]));
    fprintf(output,"%f %f %f\n",bigSmallDifference[0],(bigSmallDifference[1]-bigSmallDifference[3]),(bigSmallDifference[2]-bigSmallDifference[3]));


}

void BiggestSmallestDifference(float received[4],int numDots)//*
{
    int i;
    float biggestSmallest[6]= {data[0].x,data[0].x,data[0].y,data[0].y,data[0].z,data[0].z};
    for(i=1; i<numDots; i++)
    {
        if(biggestSmallest[0]<data[i].x)
            biggestSmallest[0]=data[i].x;
        if(biggestSmallest[1]>data[i].x)
            biggestSmallest[1]=data[i].x;
        if(biggestSmallest[2]<data[i].y)
            biggestSmallest[2]=data[i].y;
        if(biggestSmallest[3]>data[i].y)
            biggestSmallest[3]=data[i].y;
        if(biggestSmallest[4]<data[i].z)
            biggestSmallest[4]=data[i].z;
        if(biggestSmallest[5]>data[i].z)
            biggestSmallest[5]=data[i].z;
    }
    float value_Difference[]= {(biggestSmallest[0]-biggestSmallest[1]),(biggestSmallest[2]-biggestSmallest[3]),(biggestSmallest[4]-biggestSmallest[5])};
    float biggestDifference=value_Difference[0];
    for(i=1; i<3; i++)
    {
        if(biggestDifference<value_Difference[i])
            biggestDifference=value_Difference[i];
    }
    received[0]=biggestSmallest[0];
    received[1]=biggestSmallest[2];
    received[2]=biggestSmallest[4];
    received[3]=biggestDifference;
}

int GetDataBinary(char *name,int rgb)//*
{
    int count=0,control=1,error=0;
    int x,y,z,count1=0;
    int size;
    char kar;
    if(rgb==1)
        size=24;
    else
        size=12;
    FILE *fp;
    if((fp=fopen(name,"rb"))==NULL)
    {
        printf("File Opening Error");
        exit(1);
    }
    while(1)
    {
        kar=getc(fp);
        if(kar=='\n')
            count1++;
        if(count1==5)
            break;
    }
    //printf("\nnokta:%d\n",ftell(fp));
    while(1)
    {
        size_t number=fread(&data[count],size,1,fp);
        if(number<1)
            break;
        if(rgb!=1)
        {
            data[count].r=-1;
            data[count].g=-1;
            data[count].b=-1;
        }
        data[count].num=count+1;
        if(data[count].r<=0 && data[count].g<=0 && data[count].b<=0)
        {
            fclose(fp);

            return -1*(count+1);
        }
        count++;
    }
    fclose(fp);
    return count;//nokta numbersi
}

int Ascii_Binary(char *name)//*
{

    char kar;
    char ch[20];
    int i=0,count=0;
    FILE *fp;
    if((fp=fopen(name,"r"))==NULL)
    {
        printf("File Opening Error");

        exit(1);
    }
    while(!feof(fp))
    {
        kar=getc(fp);
        if(kar=='\n')
            count++;
        if(count==5)
            break;
        if(count==4 && kar!='\n')
        {
            ch[i]=kar;
            i++;
        }
    }
    ch[i]='\0';
    char article1[]="DATA ascii";
    if(strcmp(article1,ch)==0)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        fclose(fp);
        return -1;
    }
}
int Rgbon_off(char *name)//*
{

    char kar;
    char ch[20];
    int i=0,count=0;
    FILE *fp;
    if((fp=fopen(name,"r"))==NULL)
    {
        printf("File Opening Error");
        exit(1);
    }
    while(!feof(fp))
    {
        kar=getc(fp);
        if(kar=='\n')
            count++;
        if(count==3)
            break;
        if(count==2 && kar!='\n')
        {
            ch[i]=kar;
            i++;
        }
    }
    ch[i]='\0';
    char article1[]="ALANLAR x y z r g b";
    if(strcmp(article1,ch)==0)
    {
        fclose(fp);

        return 1;
    }
    else
    {
        fclose(fp);

        return -1;
    }
}
int StartControl(char *name)//*
{
    FILE *fp;
    int control=1,i=0,a=0;
    int contNum=1;
    char kar,ch[100];
    if((fp=fopen(name,"r"))==NULL)
    {
        printf("File Opening Error");
        exit(1);
    }
    while(!feof(fp))
    {
        if(contNum>5)
            return 1;
        kar=getc(fp);
        if(kar=='\n')
        {
            ch[a]='\0';
            control=Control(contNum,ch);
            if(control==-1)
                return -1;
            for(i=0; i<=a; i++)
                ch[i]=NULL;
            a=0;
            contNum++;
            continue;
        }
        ch[a]=kar;
        a++;
    }

    fclose(fp);
}

int Control(int contNum,char *ch)//*
{
    int i,j;
    int count;
    switch(contNum)
    {
        {
        case 1:
            if(strcmp(ch,"# Noktalar dosya format")==0)
                return 1;
            else
                return -1;
            break;
        }

        {
        case 2:
            count=0;
            char article[]="VERSION 1";
            for(i=0; i<strlen(article); i++)
            {
                if(ch[i]!=article[i])
                    return -1;
            }
            return 1;
            break;
        }

        {
        case 3:
            count=0;
            char article1[]="ALANLAR x y z r g b";
            char article2[]="ALANLAR x y z";
            for(i=0,j=0; i<strlen(ch), j<strlen(ch); i++,j++)
            {
                if(strlen(ch)<strlen(article2))
                    return -1;
                if(article1[i]!=ch[i] && article2[j]!=ch[j])
                    return -1;
            }
            return 1;
            break;
        }

        {
        case 4:
            count=0;
            char article[]="NOKTALAR ";
            for(i=0; i<strlen(article); i++)
            {
                if(ch[i]!=article[i])
                    return -1;
            }
            //numbernin denetimi
            for(i=strlen(article); i<strlen(ch); i++)
            {
                if(!isdigit(ch[i]))
                    return -1;
            }
            return 1;
            break;
        }

        {
        case 5:
            count=0;
            char article1[]="DATA ascii";
            char article2[]="DATA binary";
            if(strcmp(article1,ch)==0 || strcmp(article2,ch)==0)
                return 1;
            else
                return -1;
        }
        {
        default:
            printf("Error!");
            break;
        }
    }
}

int ReadFileName(char fileName[][100])
{
    int i=0,count=0;
    DIR *d;
    struct dirent *dd;
    d = opendir (".");

    if (d != NULL)
    {
        while ((dd = readdir (d))!=NULL)
        {
            int length = strlen(dd->d_name);
            if (strncmp(dd->d_name + length - 4, ".nkt", 4) == 0)
            {
                strcpy(fileName[i],dd->d_name);
                count++;
                i++;
            }
        }
        closedir (d);
    }
    return count;
}

void OnlyReadName(char Name[][100])
{
    int i=0,count=0;
    DIR *d;
    struct dirent *dd;
    char ch[100];
    d = opendir (".");

    if (d != NULL)
    {
        while ((dd = readdir (d))!=NULL)
        {
            int length = strlen(dd->d_name);
            if (strncmp(dd->d_name + length - 4, ".nkt", 4) == 0)
            {
                strcpy(ch,dd->d_name);
                ch[length-4]='\0';
                strcpy(Name[i],ch);
                i++;
            }
        }
        closedir (d);
    }

}

float AverageLength(int numDots)
{
    int i,j;
    int count=0,countOrt=0;
    float total=0;
    float totalAverage=0;
    int size;

    if(numDots>500)
        size=500;
    else
        size=1;

    for(i=0; i<numDots; i++)
    {
        for(j=i+1; j<numDots; j++)
        {
            total+=sqrt(pow((data[i].x-data[j].x),2)+pow((data[i].y-data[j].y),2)+pow((data[i].z-data[j].z),2));
            count++;
            if(count==size || (i==numDots-1 && j==numDots-1))
            {
                totalAverage+=total/count;
                countOrt++;
                count=0;
                total=0;
            }
        }
    }
    return totalAverage/(float)countOrt;
}

void Sphere(int numDots,float x,float y,float z,float r,int output)
{
    int i;
    float distance;
    for(i=0; i<numDots; i++)
    {
        distance=sqrt(pow((data[i].x-x),2)+pow((data[i].y-y),2)+pow((data[i].z-z),2));
        if(r>=distance)
        {
            //printf("Kürenin içinde Kalan noktalarin Bilgileri:\n");
            printf("\n%d. Dot:%f %f %f",data[i].num,data[i].x,data[i].y,data[i].z);
            fprintf(output,"\n%d. Dot:%f %f %f",data[i].num,data[i].x,data[i].y,data[i].z);
            if(data[i].r!=-1)
            {
                printf(" %d %d %d",data[i].r,data[i].g,data[i].b);
                fprintf(output," %d %d %d",data[i].r,data[i].g,data[i].b);
            }
        }
    }
}

void NearestFarthestPoint(int numDots,int output)
{

    int i,j,maxDisDot1,maxDisDot2,minDisDot1,minDisDot2;
    double distance;
    double maxUz=sqrt(pow((data[0].x-data[1].x),2)+pow((data[0].y-data[1].y),2)+pow((data[0].z-data[1].z),2));
    double minUz=sqrt(pow((data[0].x-data[1].x),2)+pow((data[0].y-data[1].y),2)+pow((data[0].z-data[1].z),2));
    //printf("Islem Yapiliyor\n");
    for(i=0; i<numDots-1; i++)
    {
        for(j=i+1; j<numDots; j++)
        {
            distance=sqrt(pow((data[i].x-data[j].x),2)+pow((data[i].y-data[j].y),2)+pow((data[i].z-data[j].z),2));
            //printf("%d-%d %f\n",i+1,j+1,distance);
            if(maxUz<distance)
            {
                maxUz=distance;
                maxDisDot1=i;
                maxDisDot2=j;
            }

            if(minUz>distance)
            {
                minUz=distance;
                minDisDot1=i;
                minDisDot2=j;
            }
        }
    }
    printf("\nMinimum distance:%f ,Maximum distance:%f",minUz,maxUz);
    fprintf(output,"\nMinimum distance uz:%f ,Maximum distance:%f",minUz,maxUz);
    printf("\nThe farthest points are the %d and %d points.Information of dots: \n",data[maxDisDot1].num,data[maxDisDot2].num);
    fprintf(output,"\nThe farthest points are the %d and %d points.Information of dots: \n",data[maxDisDot1].num,data[maxDisDot2].num);
    printf("%d. Dot:%f %f %f ",data[maxDisDot1].num,data[maxDisDot1].x,data[maxDisDot1].y,data[maxDisDot1].z);
    fprintf(output,"%d. Dot:%f %f %f ",data[maxDisDot1].num,data[maxDisDot1].x,data[maxDisDot1].y,data[maxDisDot1].z);
    if(data[maxDisDot1].r!=-1)
    {
        printf("%d %d %d",data[maxDisDot1].r,data[maxDisDot1].g,data[maxDisDot1].b);
        fprintf(output,"%d %d %d",data[maxDisDot1].r,data[maxDisDot1].g,data[maxDisDot1].b);
    }
    printf("\n%d. Dot:%f %f %f ",data[maxDisDot2].num,data[maxDisDot2].x,data[maxDisDot2].y,data[maxDisDot2].z);
    fprintf(output,"\n%d. Dot:%f %f %f ",data[maxDisDot2].num,data[maxDisDot2].x,data[maxDisDot2].y,data[maxDisDot2].z);
    if(data[maxDisDot2].r!=-1)
    {
        printf("%d %d %d",data[maxDisDot2].r,data[maxDisDot2].g,data[maxDisDot2].b);
        fprintf(output,"%d %d %d",data[maxDisDot2].r,data[maxDisDot2].g,data[maxDisDot2].b);
    }

    printf("\nThe nearest points are the %d and %d points.Information of dots:\n",data[minDisDot1].num,data[minDisDot2].num);
    fprintf(output,"\nThe nearest points are the %d and %d points.Information of dots:\n",data[minDisDot1].num,data[minDisDot2].num);
    printf("%d. Dot:%f %f %f ",data[minDisDot1].num,data[minDisDot1].x,data[minDisDot1].y,data[minDisDot1].z);
    fprintf(output,"%d. Dot:%f %f %f ",data[minDisDot1].num,data[minDisDot1].x,data[minDisDot1].y,data[minDisDot1].z);
    if(data[minDisDot1].r!=-1)
    {
        printf("%d %d %d",data[minDisDot1].r,data[minDisDot1].g,data[minDisDot1].b);
        fprintf(output,"%d %d %d",data[minDisDot1].r,data[minDisDot1].g,data[minDisDot1].b);
    }
    printf("\n%d. Dot:%f %f %f ",data[minDisDot2].num,data[minDisDot2].x,data[minDisDot2].y,data[minDisDot2].z);
    fprintf(output,"\n%d. Dot:%f %f %f ",data[minDisDot2].num,data[minDisDot2].x,data[minDisDot2].y,data[minDisDot2].z);
    if(data[minDisDot2].r!=-1)
    {
        printf("%d %d %d",data[minDisDot2].r,data[minDisDot2].g,data[minDisDot2].b);
        fprintf(output,"%d %d %d",data[minDisDot2].r,data[minDisDot2].g,data[minDisDot2].b);
    }
}

int GetData(char *name)
{
    char ch[15],kar;
    int spaceNumber=0,i=0,a,lineNumber=0,count=0;
    FILE *fp;
    if((fp=fopen(name,"r"))==NULL)
    {
        printf("File Opening Error");
        exit(1);
    }
    //fseek(fp,startDot,SEEK_SET);//Baslangic Noktasina alindi
    //printf("%d\n",startDot);
    //printf("%c\n",getc(fp));
    while(1)
    {
        kar=getc(fp);
        if(kar=='\n')
            count++;
        if(count==5)
            break;
    }
    while(!feof(fp))
    {
        kar=getc(fp);
        if(kar=='\n' && i==0 )//Bosluklari Atlamaya Yariyor...
            continue;
        if(kar==' ')
        {
            ch[i]='\0';
            //printf("%d\n",lineNumber);
            Processing(lineNumber,ch,spaceNumber);
            spaceNumber++;
            i=0;
            continue;
        }
        if(kar=='\n' || kar=='\0')
        {
            if(spaceNumber==5)
            {
                ch[i]='\0';
                Processing(lineNumber,ch,spaceNumber);
            }
            if(spaceNumber==2)
            {
                ch[i]='\0';
                Processing(lineNumber,ch,spaceNumber);
                data[lineNumber].r=-1;
                data[lineNumber].g=-1;
                data[lineNumber].b=-1;
            }
            i=0;
            spaceNumber=0;
            for(a=0; a<15; a++)
                ch[a]=NULL;
            data[lineNumber].num=lineNumber+1;
            lineNumber++;
            //printf("%f %f %f \n",data[lineNumber-1].x,data[lineNumber-1].y,data[lineNumber-1].z);
            continue;
        }
        ch[i]=kar;
        i++;
    }
    if(spaceNumber==5)
    {
        ch[i]='\0';
        Processing(lineNumber,ch,spaceNumber);
    }
    if(spaceNumber==2)
    {
        ch[i]='\0';
        Processing(lineNumber,ch,spaceNumber);
        data[lineNumber].r=-1;
        data[lineNumber].g=-1;
        data[lineNumber].b=-1;
    }
    data[lineNumber].num=lineNumber+1;
    fclose(fp);
    return lineNumber+1;
}

void Processing(int index,char *ch,int space)
{
    float number;
    if(space==0)
        data[index].x=atof(ch);
    else if(space==1)
        data[index].y=atof(ch);
    else if(space==2)
        data[index].z=atof(ch);
    else if(space==3)
        data[index].r=atoi(ch);
    else if(space==4)
        data[index].g=atoi(ch);
    else if(space==5)
        data[index].b=atoi(ch);
}

int FindStartingPoint(char *name)
{
    FILE *f;
    int counter=0,counter2=0;
    char ch;
    if((f=fopen(name,"r"))==NULL)
    {
        printf("File Opening Error");
        exit(1);
    }
    while(!feof(f))
    {
        ch=getc(f);
        counter++;
        if(ch=='\n')
            counter2++;
        if(counter2==5)
            break;
    }
    fclose(f);
    return counter;
}

int FindTheNumberOfDots(char *name)
{
    FILE *f;
    int counter=0,counter2=0,control=0;
    char ch[10],kar,i=0;
    if((f=fopen(name,"r"))==NULL)
    {
        printf("Dosya Açma Hatası");
        exit(1);
    }
    while(!feof(f))
    {
        kar=getc(f);
        if(control==1)
        {
            if(kar=='\n')
            {
                ch[i]='\0';
                return atoi(ch);
            }
            ch[i]=kar;
            i++;
        }

        counter++;
        if(kar=='\n')
            counter2++;
        if(counter2==3 && kar==' ')
            control=1;
    }
}
