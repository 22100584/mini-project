#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

int selectMenu(){
int menu;
printf("\n*** 리스트메뉴 ***\n");
printf("1. 조회\n");
printf("2. 추가\n");
printf("3. 수정\n");
printf("4. 삭제\n");
printf("5. 이름검색\n");
printf("6. 가격범위설정\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d", &menu);
return menu;
}


int main(void){
Product slist[20];
    int count = 0, menu,result=0;
    int index=0;//데이터번호
    index = count;

 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if(menu==1||menu==3 ||menu==4)
            if(count==0) continue;
        if (menu == 1){
            listProduct(slist,index);
        }
        else if (menu == 2){
             count += createProduct(&slist[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no==0){
              printf("=> 취소됨!\n");
              continue;
            }
          updateProduct(&slist[no-1]);
        }
        else if (menu == 4){
            int no =selectDataNo(slist, index);
            if(no==0){
              printf("=>취소됨");
              continue;
            }
          int deleteok;
          printf("정말로 삭제하시겠습니까?(삭제 :1)");
          scanf("%d", &deleteok);
          if(deleteok ==1){
            if(deleteProduct(&slist[no-1])){
                    
              printf("=> 삭제됨\n");
            count--;
            }
               }
	}
        else if (menu ==5){
            searchName(slist , index);
        }
	
        else if (menu ==6){
          filterPrice(slist, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}

int createProduct(Product *s){
printf("메뉴명은? ");
scanf(" %[^\n]s",s->name); 
printf("설명? ");
scanf(" %[^\n]s",s->exp);
printf("중량? ");
scanf(" %s",s->mass);
printf("가격은? ");
scanf("%d", &s->price);
printf("배송방법은(1.새벽배송 2.택배배송)? ");
scanf("%d", &s->dm);
return 1;
}

void readProduct(Product s){
printf(" %8s,%s %16s %d %d\n",s.name, s.mass,s.exp,s.price,s.dm);
}

void listProduct(Product *s, int count){
printf("Product list\n");
printf("=======================\n");
for( int i=0 ; i<count ; i++){
if(s[i].price==0) continue;
printf("%2d",i+1);
readProduct(s[i]);
}
}

int updateProduct(Product *s){
printf("메뉴명은? ");
scanf(" %[^\n]s",s->name); 
printf("설명? ");
scanf(" %[^\n]s",s->exp);
printf("중량? ");
scanf(" %s",s->mass);
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
printf("%2d",i+1);
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
    if((s[i].price>=alpha)&& (s[i].price<omega)){
      printf("%2d",i+1);
      readProduct(s[i]);
      scnt++;
  }
  }
    if(scnt==0) 
    printf("=> 검색된 데이터 없음!");
    printf("\n");
    }
