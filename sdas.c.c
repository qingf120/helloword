#include <Time.h>
#include <Stdio.h>
#include <Stdlib.h>
char *family="王李张刘陈杨黄赵吴周徐孙马朱胡郭何高林罗郑梁谢宋唐许韩冯邓曹彭曾肖田董袁潘于蒋蔡余杜叶程苏魏吕丁任沈姚卢姜崔钟谭陆汪范金石廖贾夏韦傅方白邹孟熊秦邱江尹薛闫段雷侯龙史陶黎贺顾毛郝龚邵万钱严覃武戴莫孔向汤";
char *boyname="伟刚勇毅俊峰强军平保东文辉力明永健世广志义兴良海山仁波宁贵福生龙元全国胜学祥才发武新利清飞彬富顺信子杰涛昌成康星光天达安岩中茂进林有坚和彪博诚先敬震振壮会思群豪心邦承乐绍功松善厚庆磊民友裕河哲江超浩亮政谦亨奇固之轮翰朗伯宏言若鸣朋斌梁栋维启克伦翔旭鹏泽晨辰士以建家致树炎德行时泰盛雄琛钧冠策腾楠榕风航弘";
char *girlname="秀娟英华慧巧美娜静淑惠珠翠雅芝玉萍红娥玲芬芳燕彩春菊兰凤洁梅琳素云莲真环雪荣爱妹霞香月莺媛艳瑞凡佳嘉琼勤珍贞莉桂娣叶璧璐娅琦晶妍茜秋珊莎锦黛青倩婷姣婉娴瑾颖露瑶怡婵雁蓓纨仪荷丹蓉眉君琴蕊薇菁梦岚苑婕馨瑗琰韵融园艺咏卿聪澜纯毓悦昭冰爽琬茗羽希宁欣飘育滢馥筠柔竹霭凝晓欢霄枫芸菲寒伊亚宜可姬舒影荔枝思丽";
char *mix="BandG";
FILE *fp;
char *tmp;

int options(char *filename , char *bgx , int bgxnum);
int make(int num , char *tmp , int bgxnum , char *bgx , FILE *fp , char *filename);
int makemix(int num , char *tmp , int bgxnum , FILE *fp , char *filename);

int main()
{
int slt;
// system("Graftabl 936");//如果用TC编译连接请去掉这句的注释!否则不支持中文!我用的VC++!
while(1)
{
puts("\n 批量姓名生成器v1.3 By.morning----QQ:88072010\n");//1.3版本重大改进(混合姓名增加输出男/女功能)!
puts(" 1.生成男子名");
puts(" 2.生成女子名");
puts(" 3.生成混合名");
puts(" 0.退出本程序");
puts("---------------------------------------------------------------");
printf("请选择：");
scanf("%d",&slt);
switch(slt)
{
case 1: options("Boyname.txt",boyname,150); break;//150是取名关键字数量以下相同
case 2: options("Girlname.txt",girlname,149); break;
case 3: options("Mixname.txt",mix,149); break;
case 0: exit(0);
default: continue;
}
}
}

//第一个传入的是文件名(准备保存到哪个文件?),第二个传入的是取名关键字字符串,第三个是关键字的个数!
int options(char *filename , char *bgx , int bgxnum) //bgx就是boy或者girl或者mix
{
int num; //作用再往下看三行就知道了
char *fs="a"; //供后面打开文件的方式使用!
puts("\n注意:为避免错误发生请一次最多生成40000个.\n");
printf("你准备生成多少个姓名?：");
scanf("%d",&num);
if (bgx=="BandG")
{
  tmp = malloc(num*10+2);
 //混合姓名我打算以这样的形式输出:"吴龙虎 男" (多了一个TAB+性别)
//混合姓名我打算以这样的形式输出:"郝韵娜 女" (多了一个TAB+性别)
}
else
{
 tmp = malloc(num*7+2);
/*
按照每个名字三个字每个字两字节计算+一个换行符就是7个字节.
为什么加2,是为了防止用户只生成一个姓名而正好又是三个字的,
那么3个字6字节+换行符1个字节+我for循环之后加进去的'\0'!
总共是8个字节超出了范围,当运行到free(tmp)的时候就会出现一
个大大的错误!!!
*/
}

if (tmp!=NULL)
{
puts("内存分配成功,正准备生成.....");
}
else
{
puts("内存分配失败!可能是你输入的数量过大!");
system("pause");
return(1);
}
fp=fopen(filename,"r"); //先用读的方式打开文件,如果文件打开成功代表文件存在!(不知道有没有更好的方法判断文件是否已经存在?)
if (fp!=NULL) //如果文件已经存在↓
{
int x;
fclose(fp);
printf("警告:准备生成的%s已经存在!\n\n",filename);
puts(" 1.追加文件内容");
puts(" 2.覆盖文件内容");
puts(" 0.取消本次操作");
printf("请做出选择：");
scanf("%d",&x);

switch(x)
{
case 1: fs="a"; break; //方式=追加内容
case 2: fs="w"; break; //方式=覆盖内容
case 0:
{
free(tmp);//释放分配的内存
puts("\n已经取消本次操作,按任意键返回主菜单!");
system("pause");
return(0);
}
default:
{
free(tmp);//释放分配的内存
puts("选择超出范围,按任意键返回主菜单!");
system("pause");
return(0);
}
}
fp=fopen(filename,fs);
if (fp==NULL)
{
free(tmp);//如果文件打开失败,那么也把分配的内存释放了.
if (fs=="a")
{
puts("追加文件内容失败!可能文件具有只读属性或者正被使用!");
}
else
{
puts("覆盖文件内容失败!可能文件具有只读属性或者正被使用!");
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
fp=fopen(filename,fs); //运行到这里说明文件不存在,直接以char *fs="a"的方式创建文件!
if (fp==NULL)
{
puts("创建文件失败!");
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
printf("批量姓名已经输出到文件：%s\n",filename);
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
n=rand()%100*2;//乘以2是为了保证n始终是个偶数,以下相同.
tmp[y]=family[n];
tmp[z]=family[n+1];
y+=2;
z+=2;
if(rand()%2==1) //如果rand==1则生成男名
{
n=rand()%bgxnum*2;
tmp[y]=boyname[n];
tmp[z]=boyname[n+1];
y+=2; //4
z+=2; //5
if (rand()%2==1) //如果rand==1则生成3个字的姓名
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

}//for结束
tmp[z-1]='\0';
fputs(tmp,fp);
fclose(fp);
printf("批量姓名已经输出到文件：%s\n",filename);
free(tmp);
system("pause");
return 0;
}
