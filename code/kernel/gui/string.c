#include "../waresdes.h"
#ifndef NULL
#define NULL ((void*)0)
#endif

int strncmp(const char *s1, const char *s2, int tam){
	for(int i = 0; i < tam; i++){
		if(s1[i] != s2[i]){
			return (unsigned char)s1[i] - (unsigned char)s2[i];
		}
		// Se encontrou o final de qualquer string, parar
		if(s1[i] == '\0' || s2[i] == '\0'){
			break;
		}
	}
	return 0;
}
int strcmp(const char *s1, const char *s2){
	int EQU = 1;
	int i = 0;;
	for(int end = 0;end == 0;){
		if(s1[i] != '\0' || s2[i] != '\0'){
			if(s1[i] == s2[i]){
				EQU = 1;
				end = 0;
			} else {
				EQU = 0;
				end = 1;
			}
		} else if(s1[i] == s2[i]){
			{
				EQU = 1;
				end = 1;
			}
		} else {
			{
				EQU = 0;
				end = 1;
			}
		}
		i++;
	}
	return EQU;
}

int strtam(const char* str){
	int i=0;
	for(;str[i] != '\0';i++);
	return i;
}

int strlen(const char *str){
	int len = 0;
	while(str[len] != '\0'){
		len++;
	}
	return len;
}
char *strcpy(char *dest, const char *src){
	char *orig = dest;
	while((*dest++ = *src++));
	return orig;
}

#define HEAP_SIZE 1024 * 1024  // 1 MB de heap

unsigned char heap[HEAP_SIZE];  // bloco de memória
unsigned int heap_index = 0;    // ponteiro para o próximo espaço livre

void* malloc(unsigned int size) {
    if (heap_index + size >= HEAP_SIZE) {
        // Sem memória suficiente
        return 0;
    }

    void* ptr = &heap[heap_index];
    heap_index += size;
    return ptr;
}