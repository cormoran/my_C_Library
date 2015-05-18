#include<stdlib.h>

#define VECTOR_INITIAL_SIZE 10

typedef struct vector{
  void *data;
  size_t databytesize;
  int size;
  int capacity;
}vector;

vector *vector_create(size_t databytesize);

void vector_destroy(vector *v);

void vector_reserve(vector *v,int newsize);

void vector_resize(vector *v,int newsize,void *initdata);

void* vector_at(vector *v,int i);

void vector_erase(vector *v,int idx);

void vector_clear(vector *v);

void vector_shrink_to_fit(vector *v);

void vector_insert(vector *v,int idx,void *data);

void vector_push_back(vector *v,void *data);

void* vector_begin(vector *v);

void* vector_end(vector *v);

int vector_size(vector *v);
