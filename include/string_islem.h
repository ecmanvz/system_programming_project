#ifndef STRING_ISLEM_H
#define STRING_ISLEM_H

typedef struct {
    char *key;
    char *value;
} Hash;


char* vingul_silme(char *kelime);

char* key_tirnak_silme(char* key);

char* value_Tirnak_Silme(char* value);

Hash* newHash(char* key, char* value);

Hash* yazdir(char *key, char* value);


#endif