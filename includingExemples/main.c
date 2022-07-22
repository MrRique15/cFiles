#include <stdio.h>
#include "functions/functions.c"

int main(){
    int quit = 1, count = 0;
    User users[10];
    User usuario;
    do{
        quit = menuOpt();
        switch (quit){
            case 1:
                if(count < 10){
                    usuario = colectData(usuario);
                    users[count] = usuario;
                    count++;
                }else{
                    showMsg(messages[2]);
                }
            break;
            case 2:
                for(int i = 0; i < count; i++){
                    showUser(users[i]);
                }
            break;
            case 3:
                showMsg(messages[1]);
                quit = 0;
            break;
            default:
                showMsg(messages[0]);
            break;
        }
    }while(quit != 0);
    return 0;
}