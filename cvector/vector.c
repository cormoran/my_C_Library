#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "vector.h"

vector *vector_create(size_t databytesize){
  vector *v=(vector*)malloc(sizeof(vector));
  v->databytesize=databytesize;
  v->data=malloc(v->databytesize*VECTOR_INITIAL_SIZE);
  v->size=0;
  v->capacity=VECTOR_INITIAL_SIZE;
  return v;
}

void vector_destroy(vector *v){
  free(v->data);
  free(v);
  v=0;
}

void vector_reserve(vector *v,int newsize){
  if(v->size>=newsize)return;
  
  void *newdata=malloc(v->databytesize*newsize);
  v->capacity=newsize;
  for(int i=0;i<v->size;i++){
    memcpy(newdata + v->databytesize*i, v->data + v->databytesize*i, v->databytesize);
  }
  free(v->data);
  v->data=newdata;
}

void vector_resize(vector *v,int newsize,void *initdata){
  vector_reserve(v, ceil(log2(newsize)));
  v->size=newsize;
  for(int i=0;i<v->size;i++){
    memcpy(v->data +v->databytesize*i, initdata, v->databytesize);
  }
}

void vector_push_back(vector *v,void *data){
  if(v->capacity==v->size){
    vector_reserve(v, v->capacity*2);
  }
  memcpy(v->data +v->databytesize*v->size, data, v->databytesize);
  v->size++;
}

void* vector_at(vector *v,int i){
  if(v->size<=i)abort();
  return v->data+v->databytesize*i;
}

void vector_clear(vector *v){
  v->size=0;
}

void vector_shrink_to_fit(vector *v){
  if(v->size==v->capacity)return;
  
  void *newdata=malloc(sizeof(v->databytesize)*v->size);
  v->capacity=v->size;
  for(int i=0;i<v->size;i++){
    memcpy(newdata + v->databytesize*i, v->data + v->databytesize*i, v->databytesize);
  }
  free(v->data);
  v->data=newdata;
}

void vector_erase(vector *v,int idx){
  if(v->size<=idx)abort();
  for(int i=idx;i<v->size-1;i++){
    memcpy(v->data+v->databytesize*i, v->data+v->databytesize*(i+1), v->databytesize);
  }
  v->size--;
}

void vector_insert(vector *v,int idx,void *data){
  if(v->capacity==v->size){
    vector_reserve(v, v->capacity*2);
  }
  if(v->size<idx)idx=v->size;

  for(int i=v->size;i>idx;i--){
    memcpy(v->data+v->databytesize*i,v->data+v->databytesize*(i-1), v->databytesize);
  }
  memcpy(v->data+v->databytesize*idx,data, v->databytesize);
  v->size++;
}

void* vector_begin(vector *v){
  return v->data;
}

void* vector_end(vector *v){
  return v->data + v->databytesize*v->size-1;
}

int vector_size(vector *v){
  return v->size;
}
