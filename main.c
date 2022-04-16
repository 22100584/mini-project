#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int main(void){
#ifdef DEBUG
        printf("=> DEBUGMODE\n");

#endif
Product slist[20];
    int count = 0,menu;
    int index=0;//데이터번호
    index=count;


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
    	else if (menu==7){
		saveproduct(slist,index);
	}
    printf("종료됨!\n");
    return 0;
}

