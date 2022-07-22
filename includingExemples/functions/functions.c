#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"
#include "messages.c"

int add(int x, int y){
    return x + y;
}

int menuOpt(){
    int opt;
    printf("Escolha uma opcao:\n");
    printf("[1] - Adicionar usuario\n[2] - Listar usuarios\n[3] - Sair\n");
    scanf("%d", &opt);
    return opt;
}

void showMsg(char *msg){
    printf("%s\n", msg);
}
User colectData(User user){
    printf(messages[3]);
    scanf("%s", user.fullName);
    setbuf(stdin, NULL);
    printf(messages[4]);
    scanf("%d", &user.idade);
    setbuf(stdin, NULL);
    printf(messages[5]);
    scanf("%d", &user.altura);
    setbuf(stdin, NULL);
    printf(messages[6]);
    scanf("%s", user.email);
    return user;
}

void showUser(User user){
    printf("----------------------------------------------------\n");
    printf("%s %s\n", messages[7], user.fullName);
    printf("%s %d\n", messages[8], user.idade);
    printf("%s %d\n", messages[9], user.altura);
    printf("%s %s\n", messages[10], user.email);
}