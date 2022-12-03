#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <math.h>


#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

typedef long unsigned s21_size_t;
#define s21_NULL (void*)0

typedef struct mod {
  int flag;
  int width;
  char precision[40];
  char length[10];
  int length_s;
} mod;

typedef struct flags {
  int format_f;
  int sign;
  int width;
  int precision;
  int set_precision;
  int align;
  int length;
  int dot;
  int double_length;
  int spec;
  int if_num;
  int zero_width;
} flags;

int is_delim(char c, const char* delim);
void *s21_insert(const char *src, const char *str, size_t start_index);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strrchr(const char *str, int c);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char* dest, const char* src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strcpy(char* dest, const char* src);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_to_upper(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_sprintf(char *buffer, const char *format, ...);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strtok(char *str, const char *delim);
void *s21_to_lower(const char *str);

int start(const char *s, const char *tc, s21_size_t len_src, s21_size_t len_trim);
int end(const char *s, const char *tc, s21_size_t len_src, s21_size_t len_trim);



#endif  // SRC_S21_STRING_H_
