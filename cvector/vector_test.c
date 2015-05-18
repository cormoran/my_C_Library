#include<stdio.h>

#include"vector.h"
#include<time.h>

void create_and_destroy_test(int count){
  vector *v;
  for(int i=0;i<count;i++){
    v=vector_create(sizeof(int));
    vector_destroy(v);
  }
}

void pushback_test(int count){
  vector *v=vector_create(sizeof(int));
  for(int i=0;i<count;i++){
    vector_push_back(v, &i);
  }
  vector_destroy(v);
}

void insert_and_erase_test(int count){
  vector *v=vector_create(sizeof(int));
  for(int i=0;i<20;i++){
    vector_push_back(v, &i);
  }
  for(int i=0;i<count;i++){
    vector_insert(v, 10, &i);
  }
  for(int i=0;i<count;i++){
    vector_erase(v, 10);
  }
  vector_destroy(v);
}



void watch_time(void (*func)(int),int cnt){
  clock_t st,en;
  st=clock();
  func(cnt);
  en=clock();

  printf("Time : %fs\n",(double)(en-st)/CLOCKS_PER_SEC);
  
}

int main(){


  int cnt;
  printf("create_and_destory ...... \n");
  puts("Input Value");
  scanf("%d",&cnt);
  watch_time(create_and_destroy_test, cnt);
  printf("ok\n");

  printf("push_back ...... \n");
  puts("Input Value");
  scanf("%d",&cnt);
  watch_time(pushback_test, cnt);
  printf("ok\n");

  printf("insert_and_erase ...... \n");
  puts("Input Value");
  scanf("%d",&cnt);
  watch_time(insert_and_erase_test, cnt);
  printf("ok\n");


  return 0;
}
