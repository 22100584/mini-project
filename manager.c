//manager.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int selectMenu(){
int menu;
printf("\n*** 리스트메뉴 ***\n");
printf("1. 조회\n");
printf("2. 추가\n");
printf("3. 수정\n");
printf("4. 삭제\n");
printf("5. 이름검색\n");
printf("6. 가격범위검색\n");
printf("7. 저장\n");
printf("8. 중량범위검색\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d", &menu);
return menu;
}

int createProduct(Product *s){
printf("메뉴명은? ");
scanf(" %[^\n]",s->name);
printf("설명? ");
scanf(" %[^\n]",s->exp);
printf("중량? ");
scanf("%d",&s->mass);
printf("가격은? ");
scanf("%d", &s->price);
printf("배송방법은(1.새벽배송 2.택배배송)? ");
scanf("%d", &s->dm);
return 1;
}

void readProduct(Product s){
if(s.dm==1)
    printf("이름: %s\n   설명: %s\n   중량: %d 가격: %d 배송방법: 새벽배송\n",s.name,s.exp,s.mass,s.price);
else if(s.dm==2)
    printf("이름: %s\n   설명: %s\n   중량: %d 가격: %d 배송방법: 택배배송\n",s.name,s.exp,s.mass,s.price);
}

void listProduct(Product *s, int count){
printf("Product list\n");
printf("=======================\n");
for( int i=0 ; i<count ; i++){
if(s[i].price<0) continue;
printf("%2d ",i+1);
readProduct(s[i]);
}
}

int updateProduct(Product *s){
printf("메뉴명은? ");
scanf(" %[^\n]s",s->name);
printf("설명? ");
scanf(" %[^\n]s",s->exp);
printf("중량? ");
scanf("%d",&s->mass);
printf("가격은? ");
scanf("%d", &s->price);
printf("배송방법은(1.새벽배송 2.택배배송)? ");
scanf("%d", &s->dm);
return 1;
}

int selectDataNo(Product *s, int count){
int no;
listProduct(s,count);
printf("번호는 (취소 :0)? ");
scanf("%d", &no);
return no;
}

int deleteProduct(Product *s){
s->price=-1;
return 1;
}

void searchName(Product *s, int count){
int scnt=0;
char search[100];
printf("검색할 이름은? ");
scanf(" %[^\n]s", search);
printf("Product list\n");
printf("=======================\n");
for( int i=0; i<count;i++){
if(s[i].price==-1) continue;
if(strstr(s[i].name,search)){
printf("%2d ",i+1);
readProduct(s[i]);
scnt++;
}
}
if(scnt==0) printf("=> 검색된 데이터 없음!");
printf("\n");
}

void filterPrice(Product *s, int count){
  int alpha, omega,scnt=0;;
  printf("최소가격~최대가격: ");
  scanf("%d %d",&alpha,&omega);
  for(int i=0;i<count;i++){
    if(s[i].price==-1) continue;
	if((s[i].price>=alpha)&& (s[i].price<omega)){
      printf("%2d ",i+1);
      readProduct(s[i]);
      scnt++;
  }
  }
    if(scnt==0)
    printf("=> 검색된 데이터 없음!");
    printf("\n");
    }

void saveProduct(Product *p, int count){
    FILE *fp;
    fp=fopen("score.txt","wt");
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        fprintf(fp,"%s\n",p[i].name);
        fprintf(fp,"%s\n",p[i].exp);
        fprintf(fp,"%d %d %d\n",p[i].mass,p[i].price,p[i].dm);
    }
    fclose(fp);
    printf("=>저장됨! ");
}
int loadProduct(Product *p){
    int  i=0;
    FILE *fp;
    fp=fopen("score.txt","rt");
    for(;i<100;i++){
        fscanf(fp," %[^\n]s",p[i].name);
        if(feof(fp)) break;
        fscanf(fp," %[^\n]s",p[i].exp);
        fscanf(fp,"%d",&p[i].mass);
        fscanf(fp,"%d",&p[i].price);
        fscanf(fp,"%d",&p[i].dm);
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    return i;
}

void filterMass(Product *s, int count){
  int alpha, omega,scnt=0;;
  printf("최소중량~최대중량: ");
  scanf("%d %d",&alpha,&omega);
  for(int i=0;i<count;i++){
    if(s[i].price==-1) continue;
    if((s[i].mass>=alpha)&& (s[i].mass<omega)){
      printf("%2d ",i+1);
      readProduct(s[i]);
      scnt++;
  }
  }
    if(scnt==0)
    printf("=> 검색된 데이터 없음!");
    printf("\n");
    }
