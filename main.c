#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *pSig;
};

typedef struct s_nodo t_nodo;
typedef struct s_nodo* t_nodoPtr;

void push(t_nodoPtr* ptrNodo, int valor);
int pop(t_nodoPtr* ptrNodo);
t_nodoPtr crear_nodo(int valor);

int main()
{
    int val;
    t_nodoPtr ptrPila = NULL;

    printf("\nPusheando 1 2 3 4...\n");
    push(&ptrPila, 1);
    push(&ptrPila, 2);
    push(&ptrPila, 3);
    push(&ptrPila, 4);

    printf("\nLos elementos de la pila, desapilados, son:\n");
    while (ptrPila != NULL)
    {
        val = pop(&ptrPila);
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}

/**
 * Función que agrega un nodo a la pila (por el tope de la pila)
 */
void push(t_nodoPtr* ptrNodo, int valor)
{
    t_nodoPtr ptrNuevo = crear_nodo(valor);

    if (ptrNuevo != NULL)
    {
        ptrNuevo->pSig = *ptrNodo;
        *ptrNodo = ptrNuevo;
    }
}

/**
 * Función que saca un nodo de la pila (por el tope de la pila)
 * @return el valor del nodo que se saca
 */
int pop(t_nodoPtr* ptrNodo)
{
    int valor = (*ptrNodo)->valor;

    t_nodoPtr ptrElim = *ptrNodo;
    *ptrNodo = (*ptrNodo)->pSig;

    free(ptrElim);

    return valor;
}

/**
 * Función que crea un nodo
 * @return un puntero al nodo creado, o NULL
 */
 t_nodoPtr crear_nodo(int valor)
 {
    t_nodoPtr ptrNuevo = malloc(sizeof(t_nodo));

    if (ptrNuevo != NULL)
    {
        ptrNuevo->valor = valor;
        ptrNuevo->pSig = NULL;
    }

    return ptrNuevo;
 }
