//
// Created by alber on 20/10/2024.
//

#ifndef DICT_H
#define DICT_H
#define MAX_DATA  64
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {int type; char data[MAX_DATA];} object;
//paso de tipos a el campo de dato char del objeto
void int_to_obj(int src, object *dst){
 dst->type = 0;
 dst->data[0] = src; //ints los mas simples
}
void float_to_obj(float src, object *dst){
 dst->type = 1;
 snprintf(dst->data, sizeof dst->data, "%f", src); // funcion que mueve automaticamente floats a strings

}
//**
void str_to_obj(char *src, object *dst){
 dst->type = 2;
 // Asegurarse de no exceder el tamaño de dst->data
 strncpy(dst->data, src, MAX_DATA - 1); // Copiar hasta MAX_DATA-1 caracteres para dejar espacio al terminador nulo
 dst->data[MAX_DATA - 1] = '\0'; //sacado de internet -_-
}
//conversiones de obj a tipos
void obj_to_int(object src, int *dst){
*dst=src.data[0];} //int
void obj_to_float(object src, float *dst){
char pepe[64];
for(int z=0;z<strlen(src.data);z++){
pepe[z]=src.data[z];
}
*dst=strtod(pepe,NULL); //funcion que pasa de arrays a floats
;}
//estoy en ello saca un corazon **
void obj_to_str(object src, char *dst){
 strncpy(dst, src.data, MAX_DATA);
 dst[MAX_DATA - 1] = '\0'; //sacado de internet
 }
//Estructuras nodo
typedef struct st_dict_node {
object key;
object value;
struct st_dict_node *next;
} dict_node;
typedef struct {
dict_node *first;
int len;
} dict;
dict *dict_new(){
    dict *dic = (dict*) malloc(sizeof(dict));
    dic->first = NULL;
    dic->len=0;

};
//utlidades varias, porfavor acabar con mi sufrimiento
int dict_add(dict *dic, object key, object value){
    dict_node *nodoaux = (dict_node*) malloc(sizeof(dict_node));
    if (nodoaux != NULL) {
    //asignaciones varias
    nodoaux->key = key;
    nodoaux->value = value; //bendito autopilot
     nodoaux->next =dic->first;
     dic->first = nodoaux;
    dic->len++;
       return 0;
    }
    else{
     return -1; // falo si no se pudo asignar memoria
    }
};

int dict_search(dict *dic, object key, object *dst){
dict_node *nodoaux = (dict_node*) malloc(sizeof(dict_node));
nodoaux = dic->first;

 char juanito[64];
 char menganito[64];
 for(int i=0;i<dic->len;i++){ //gracias autopilot
 obj_to_str(nodoaux->key, &juanito);
 obj_to_str(key, &menganito);
   if(juanito[0]==menganito[0]){
    obj_to_str(nodoaux->value, &menganito);
    *dst=nodoaux->value;


    return 0;}
  else {
   nodoaux=nodoaux->next;
  }
 }
 free(nodoaux);
 return -1;
};
int dict_remove(dict *dic, object key){
 dict_node *nodoaux;
 dict_node *nodoaux2;

 nodoaux = dic->first;
 nodoaux2= dic->first;

 char juanito[64];
 char menganito[64];
 for(int i=0;i<dic->len;i++){ //gracias autopilot
  obj_to_str(nodoaux->key, &juanito);
  obj_to_str(key, &menganito);
  if(juanito[0]==menganito[0]){
   for(int j=0;j<i-1;j++) {
    nodoaux2 = nodoaux2->next;
   }
   if(nodoaux==dic->first) {
    dic->first = nodoaux->next; //si eliminamos el primer elemento se mueve una posicion
   }
   nodoaux2->next=NULL;
   free(nodoaux);
   dic->len--;

   return 0;}
  else {
   nodoaux=nodoaux->next;
  }
 }
 free(nodoaux);
 return -1;
};

dict_node *dict_first(dict *dic){
 return dic->first;
};
dict_node *dict_next(dict *dic, dict_node *current){
 return current->next;
};
dict_destroy(dict *dic) {
  dict_node *nodeaux=dic->first;
 for(int i=0;i<dic->len;i++) {
  free(nodeaux);
 }
 free(dic);
 return 0;
}
// los diccionarios seran iguales cuando compartan el mismo contenido en las mismas entradas
int dict_equals(dict *dic1, dict *dic2) {
 dict_node *nodoaux = dic1->first;
 dict_node *nodoaux2 = dic2->first;
 char juanito[64];
 char menganito[64];
 if(dic1->len!=dic2->len){return -1;}else {
  for(int i=0;i<dic1->len;i++){
   obj_to_str(nodoaux->value, &juanito);
   obj_to_str(nodoaux2->value, &menganito);
   if(strcmp(juanito, menganito) == 0){return -1;}
  }
  return 0;
 }

};

#endif //DICT_H
