#include <stdio.h>
#include "../include/string_islem.h"


char* virgul_silme(char *kelime){

    char* virgulsuz = malloc(sizeof(char) *1024);
    int length = strlen(kelime);
    int t=0;

    char *noktalivirgul = ":";
    char *virgul = ",";

    for(int i=0;i < length;i++){
        if( strcmp(&kelime[i],virgul)){// burda virgul olup olmadğını kontrol ediyor 
            virgulsuz[t++] = kelime[i];// virgul olmayan char değerini virgulsuz değerine atıyor
        }
    }
    return virgulsuz;
    free(virgulsuz);
}


char* key_tirnak_silme(char* key){

    char* tirnaksiz_key = malloc(sizeof(char) *1024);
    int length = strlen(key);
   
    int t =0;
    for(int i= 1; i <(length -1) ;i++){// burda gelen key değerinin ilk ve son değerlerindeki tırnakları tirnaksiz_key  değerine atıyor
        tirnaksiz_key[t++] = key[i];
    }
    return tirnaksiz_key;
}

char* value_Tirnak_Silme(char* value){
    // value char dizisinden tırnakları siliyoruz
    char* value_tirnaksiz = malloc(sizeof(char) *1024);
    int length = strlen(value);
    int t =0;
    for(int i= 1; i <(length-2) ;i++){
        value_tirnaksiz[t++] = value[i];
    }
    return value_tirnaksiz;
}

Hash* newHash(char* key, char* value){
    //aldığımız key ve value değerlerini hash yapısının içine koyuyoruz
    Hash* hash = malloc(sizeof(Hash));

    int valuelengith = strlen(value);
    int keylength = strlen(key);

    hash->value = (char *) malloc(sizeof(char)*(valuelengith+1));
    hash->key = (char *) malloc(sizeof(char)*(keylength+1));

    hash->key = key;
    hash->value = value;

    return hash;
}

Hash* yazdir(char *key, char* value)
{
    
    char *s = "}";
    char *ss = "{";
   
    if(!(strcmp(value,s) != 0 && strcmp(value,ss) != 0)){
      return;
    }

    char *sonValue = value_Tirnak_Silme(virgul_silme(value));
    char *sonKey = key_tirnak_silme(virgul_silme(key));

    Hash* y = newHash(sonKey,sonValue);

    return y;
   
}
