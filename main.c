#include <stdio.h>
#include "dict.h"
/*int main(void)
{
dict *dic; // Diccionario
object key, value; // Almacenes de datos
// creamos diccionario
dic = dict_new();
// insertamos dos elementos
int_to_obj(1, &key); str_to_obj("Pepe", &value);
dict_add(dic, key, value);
int_to_obj(2, &key); str_to_obj("Juan", &value);
dict_add(dic, key, value);
    object ppvalor;
dict_search(dic,key,&ppvalor);
    char josejuan[64];
    obj_to_str(ppvalor,&josejuan);
dict_remove(dic,key);
    int fdfd=0;
    dict_destroy(dic);
int p=0;



}*/
#include <stdio.h>
#include <stdlib.h>
#include "dict.h"
void main() {
    dict *dic; // Diccionario
    object key, value; // Almacenes de datos
    // creamos diccionario
    dic = dict_new();
    // insertamos dos elementos
    int_to_obj(1, &key); str_to_obj("Pepe", &value);
    dict_add(dic, key, value);
    int_to_obj(2, &key); str_to_obj("Juan", &value);
    dict_add(dic, key, value);
    // buscamos elemento
    char str[50];
    int_to_obj(1, &key);
    dict_search(dic, key, &value);
    obj_to_str(value, str);
    printf("%s", str);
}

