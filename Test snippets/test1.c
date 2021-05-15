#include<stdio.h>

void show();
int main(){

//    int i;
//    char x[] = "\0";
//
//    if(printf("%s", x)){
//        printf("ok here");
//    }else{
//        printf("not ok");
//    }

//    char arr[10] = "rectangle";
//    int i;
//    for(i=0; i<=7; i++)
//        printf("%d", arr[i]);
//
//    arr++;

//    char b[] = "12345";
//    int x = strlen(b);
//    printf("here in 3 %d\n", ++x);

//    show();
//    show();

//    char name[] = "AEIOU";
//    int i=0;
//    while(name[i]!='\0'){
//        printf("%c", name[i]);
//        i++;
//    }

    printf(3+"goodbye");
    printf('\n');
    printf("goodbye"+3);

    return 0;
}
void show(){

    auto int i=0;
    register int j=0;
    static int k;
    i++; j++; k++;
    printf("\n%d %d %d",i ,j, k);

}
