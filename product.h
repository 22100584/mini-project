typedef struct{
    char name[20];
    char exp[100]; //설명
    char mass[20]; //중량
    int price; //판매가격
    int dm; // delivery method(1.새벽배송 2. 택배배송)
} Product;

int selectMenu();
int createProduct(Product *p);//제품추가
void readProduct(Product p);//제품 출력
void listProduct(Product *p,int count); // 제품 열거
int updateProduct(Product *p);
int selectDataNo(Product *p, int count);
int deleteProduct(Product *p);
void searchName(Product *p, int count);
void filterPrice(Product *p, int count);// 가격 범위를 정하면 그 범위의 상품 열거

