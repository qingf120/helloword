#include <Time.h>
#include <Stdio.h>
#include <Stdlib.h>
char *family="�������������������������������θ�����֣��л��������˲�����Ф�ﶭԬ���ڽ������Ҷ����κ��������Ҧ¬������̷½������ʯ�μ���Τ������������������Ѧ�ƶ��׺���ʷ����ع�ë�¹�����Ǯ�������Ī������";
char *boyname="ΰ�����㿡��ǿ��ƽ�����Ļ�������������־��������ɽ�ʲ���������Ԫȫ��ʤѧ��ŷ���������ɱ�˳���ӽ��β��ɿ��ǹ���ﰲ����ï�����м�ͱ벩���Ⱦ�����׳��˼Ⱥ���İ�����ܹ����ƺ���������ԣ���ܽ���������ǫ�����֮�ֺ��ʲ����������������ά�������������󳿳�ʿ�Խ��������׵���ʱ̩ʢ��衾��ڲ�����ŷ纽��";
char *girlname="���Ӣ���������Ⱦ���������֥��Ƽ�����ҷ���ʴ��������÷���������滷ѩ�ٰ���ϼ����ݺ�����𷲼Ѽ�������������Ҷ�������������ɺɯ������ٻ�������ӱ¶������������Ǻɵ���ü������ޱݼ���Է�ܰ�������԰��ӽ�������ع���ѱ�ˬ������ϣ����Ʈ�����������������������ܿ�ƺ������˿ɼ���Ӱ��֦˼��";
char *mix="BandG";
FILE *fp;
char *tmp;

int options(char *filename , char *bgx , int bgxnum);
int make(int num , char *tmp , int bgxnum , char *bgx , FILE *fp , char *filename);
int makemix(int num , char *tmp , int bgxnum , FILE *fp , char *filename);

int main()
{
int slt;
// system("Graftabl 936");//�����TC����������ȥ������ע��!����֧������!���õ�VC++!
while(1)
{
puts("\n ��������������v1.3 By.morning----QQ:88072010\n");//1.3�汾�ش�Ľ�(����������������/Ů����)!
puts(" 1.����������");
puts(" 2.����Ů����");
puts(" 3.���ɻ����");
puts(" 0.�˳�������");
puts("---------------------------------------------------------------");
printf("��ѡ��");
scanf("%d",&slt);
switch(slt)
{
case 1: options("Boyname.txt",boyname,150); break;//150��ȡ���ؼ�������������ͬ
case 2: options("Girlname.txt",girlname,149); break;
case 3: options("Mixname.txt",mix,149); break;
case 0: exit(0);
default: continue;
}
}
}

//��һ����������ļ���(׼�����浽�ĸ��ļ�?),�ڶ����������ȡ���ؼ����ַ���,�������ǹؼ��ֵĸ���!
int options(char *filename , char *bgx , int bgxnum) //bgx����boy����girl����mix
{
int num; //���������¿����о�֪����
char *fs="a"; //��������ļ��ķ�ʽʹ��!
puts("\nע��:Ϊ�����������һ���������40000��.\n");
printf("��׼�����ɶ��ٸ�����?��");
scanf("%d",&num);
if (bgx=="BandG")
{
  tmp = malloc(num*10+2);
 //��������Ҵ�������������ʽ���:"������ ��" (����һ��TAB+�Ա�)
//��������Ҵ�������������ʽ���:"������ Ů" (����һ��TAB+�Ա�)
}
else
{
 tmp = malloc(num*7+2);
/*
����ÿ������������ÿ�������ֽڼ���+һ�����з�����7���ֽ�.
Ϊʲô��2,��Ϊ�˷�ֹ�û�ֻ����һ���������������������ֵ�,
��ô3����6�ֽ�+���з�1���ֽ�+��forѭ��֮��ӽ�ȥ��'\0'!
�ܹ���8���ֽڳ����˷�Χ,�����е�free(tmp)��ʱ��ͻ����һ
�����Ĵ���!!!
*/
}

if (tmp!=NULL)
{
puts("�ڴ����ɹ�,��׼������.....");
}
else
{
puts("�ڴ����ʧ��!���������������������!");
system("pause");
return(1);
}
fp=fopen(filename,"r"); //���ö��ķ�ʽ���ļ�,����ļ��򿪳ɹ������ļ�����!(��֪����û�и��õķ����ж��ļ��Ƿ��Ѿ�����?)
if (fp!=NULL) //����ļ��Ѿ����ڡ�
{
int x;
fclose(fp);
printf("����:׼�����ɵ�%s�Ѿ�����!\n\n",filename);
puts(" 1.׷���ļ�����");
puts(" 2.�����ļ�����");
puts(" 0.ȡ�����β���");
printf("������ѡ��");
scanf("%d",&x);

switch(x)
{
case 1: fs="a"; break; //��ʽ=׷������
case 2: fs="w"; break; //��ʽ=��������
case 0:
{
free(tmp);//�ͷŷ�����ڴ�
puts("\n�Ѿ�ȡ�����β���,��������������˵�!");
system("pause");
return(0);
}
default:
{
free(tmp);//�ͷŷ�����ڴ�
puts("ѡ�񳬳���Χ,��������������˵�!");
system("pause");
return(0);
}
}
fp=fopen(filename,fs);
if (fp==NULL)
{
free(tmp);//����ļ���ʧ��,��ôҲ�ѷ�����ڴ��ͷ���.
if (fs=="a")
{
puts("׷���ļ�����ʧ��!�����ļ�����ֻ�����Ի�������ʹ��!");
}
else
{
puts("�����ļ�����ʧ��!�����ļ�����ֻ�����Ի�������ʹ��!");
}
system("pause");
return(1);
}
else
{
if (bgx=="BandG")
{
return(makemix(num , tmp , bgxnum , fp , filename));
}
else
{
return(make(num , tmp , bgxnum , bgx , fp , filename));
}
}
}
fp=fopen(filename,fs); //���е�����˵���ļ�������,ֱ����char *fs="a"�ķ�ʽ�����ļ�!
if (fp==NULL)
{
puts("�����ļ�ʧ��!");
}
else
{
if (bgx=="BandG")
{
return(makemix(num , tmp , bgxnum , fp , filename));
}
else
{
return(make(num , tmp , bgxnum , bgx , fp , filename));
}
}
return(0);
}

int make(int num , char *tmp , int bgxnum , char *bgx , FILE *fp , char *filename)
{
int i,n,y=0,z=1;
srand((unsigned)time(NULL));
for(i=0;i<num;i++)
{
n=rand()%100*2;
tmp[y]=family[n];
tmp[z]=family[n+1];
y+=2;
z+=2;
n=rand()%bgxnum*2;
tmp[y]=bgx[n];
tmp[z]=bgx[n+1];
y+=2;
z+=2;
if (rand()%2==1)
{
n=rand()%bgxnum*2;
tmp[y]=bgx[n];
tmp[z]=bgx[n+1];
tmp[z+1]='\n';
y+=3;
z+=3;
}
else
{
tmp[y]='\n';
y++;
z++;
}

}
tmp[z-1]='\0';
fputs(tmp,fp);
fclose(fp);
printf("���������Ѿ�������ļ���%s\n",filename);
free(tmp);
system("pause");
return(0);
}

int makemix(int num , char *tmp , int bgxnum , FILE *fp , char *filename)
{
int i,n,y=0,z=1;
srand((unsigned)time(NULL));
for(i=0;i<num;i++)
{
n=rand()%100*2;//����2��Ϊ�˱�֤nʼ���Ǹ�ż��,������ͬ.
tmp[y]=family[n];
tmp[z]=family[n+1];
y+=2;
z+=2;
if(rand()%2==1) //���rand==1����������
{
n=rand()%bgxnum*2;
tmp[y]=boyname[n];
tmp[z]=boyname[n+1];
y+=2; //4
z+=2; //5
if (rand()%2==1) //���rand==1������3���ֵ�����
{
n=rand()%bgxnum*2;
tmp[y]=boyname[n]; //4
tmp[z]=boyname[n+1]; //5
tmp[z+1]=9;
tmp[z+2]=-60;
tmp[z+3]=-48;
tmp[z+4]='\n'; //9
y+=6;
z+=6;
}
else
{
tmp[y]=9;
tmp[y+1]=-60;
tmp[y+2]=-48;
tmp[y+3]='\n';
y+=4;
z+=4;
}

}
else
{
n=rand()%149*2;
tmp[y]=girlname[n];
tmp[z]=girlname[n+1];
y+=2;
z+=2;
if (rand()%2==1)
{
n=rand()%149*2;
tmp[y]=girlname[n];
tmp[z]=girlname[n+1];
tmp[z+1]=9;
tmp[z+2]=-59;
tmp[z+3]=-82;
tmp[z+4]='\n';
y+=6;
z+=6;
}
else
{
tmp[y]=9;
tmp[y+1]=-59;
tmp[y+2]=-82;
tmp[y+3]='\n';
y+=4;
z+=4;
}
}

}//for����
tmp[z-1]='\0';
fputs(tmp,fp);
fclose(fp);
printf("���������Ѿ�������ļ���%s\n",filename);
free(tmp);
system("pause");
return 0;
}
