#include <stdio.h>
#include <string.h>

union tipo{
    struct strada *s;
    struct incrocio *i;
};

enum tipo_elemento{
    STRADA, INCROCIO
};
char *nome_tipo_elemento[] = {"Strada","Incrocio"};

struct strada {
    char nome[20];
    enum tipo_elemento next_tipo;
    union tipo next;
};

struct incrocio{
    struct strada *uscita[4];
};

void percorro(struct strada *s){
    printf("Sto percorrendo %s.\n", s->nome);

    switch(s->next_tipo){
        case STRADA:
            percorro(s->next.s);
            break;
        case INCROCIO:
            mostra_incrocio(s->next.i);
            break;
    }
}

void mostra_incrocio(struct incrocio *i){
    printf("Sono all'incrocio\n");
    printf("Queste sono le strade:\n");
    for(int j=0 ; j<4 ; j++){
        if(i->uscita[j] != 0){
            printf("%d %s\n",j,i->uscita[j]->nome);
        }
    }
    int scelta;
    scanf("%d",&scelta);
    printf("Imbocco la strada: %s\n",i->uscita[scelta]->nome);
    percorro(i->uscita[scelta]);
}


int main(){
    struct strada ss[10];
    struct incrocio ii[3];
    strcpy(ss[0].nome ,"Giacomo Leopardi");
    ss[0].next_tipo = STRADA;
    ss[0].next.s = &ss[1];
    strcpy(ss[1].nome ,"Vittorio Emanuele");
    ss[1].next_tipo = INCROCIO;
    ss[1].next.i = &ii[0];
    ii[0].uscita[0] = &ss[2];
    ii[0].uscita[1] = &ss[3];
    ii[0].uscita[2] = 0;
    ii[0].uscita[3] = 0;
    strcpy(ss[2].nome ,"Paolina Bonaparte");
    ss[2].next_tipo = STRADA;
    ss[2].next.s = &ss[1]; 
    strcpy(ss[3].nome ,"24 Maggio");
    ss[3].next_tipo = STRADA;
    ss[3].next.s = &ss[0]; 
    percorro(&ss[0]);  
}