#include <pthread.h>
#include <stdio.h>

struct data {
  int field;
  float number;
};

void *simple(void *parameter) {
  struct data *ptr;
  ptr = (struct data*) parameter;

  printf("Inside extra thread\n");
  printf("field is %d and number is %f\n", ptr->field, ptr->number);

  pthread_exit("Have a nice day!");

}

int main(int argc, char* argv[]) {
  int res;
  pthread_t thread;
  struct data obj;
  void *message;
  
  obj.field = 10;
  obj.number = 1.3333;
  
  res = pthread_create(&thread, NULL, simple, &obj);
  if (res) return -1;
  
  pthread_join(thread, &message);
  printf("Received data is: %s\n", (char*)message);


  return 0;
}
