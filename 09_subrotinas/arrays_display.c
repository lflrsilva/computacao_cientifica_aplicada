/*
  File:   arrays_display.c
  Author: lflrsilva

  Diferentes formas de declaracao do prototype

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
*/

/*
void display(int num[10]) { // C converte num para um ponteiro de inteiros,
                            // pois nenhum parametro pode receber uma matriz inteira
    int i;
    for (i=0; i<10; i++) {
        printf("%d ", num[i]);
    }
}

void display(int num[]) { // num e' uma matriz de inteiros de tamanho desconhecido
                          // C nao fornece nenhuma verificação de limites em matrizes
    int i;
    for (i=0; i<10; i++) {
        printf("%d ", num[i]);
    }
}
*/

void display(int* num) { // Permitido porque qualquer ponteiro pode ser indexado usando [],
                         // como se fosse uma matriz
    int i;
    for (i=0; i<10; i++) {
        printf("%d ", num[i]);
    }
}
