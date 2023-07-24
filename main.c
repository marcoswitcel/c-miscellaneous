#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>

#include "./logger.c"
#include "./array.c"
#include "./dev-utilities.c"

typedef bool Callable(void *data);

typedef enum Runnable_Task_Types {
  PRINTER,
  PRINTER2,
} Runnable_Task_Types;

typedef struct Runnable_Task {
  Callable *callable;
  Runnable_Task_Types type;
  void *data;
} Runnable_Task;

bool run_task(Runnable_Task *task)
{
  return task->callable(task->data);
}

bool printer(void *data) {
  assert(data);
  int *counter = (int *) data;
  *counter = *counter - 1;
  return *counter < 0; 
}

int main(void)
{
  log_info("Mensagens");
  LOG_TRACE("De onde?");
  LOG_TRACE("Que horas?");
  LOG_TRACE("Que dia?");

  TRACE("Teste");

  int counter = 5;
  bool done = false;
  Runnable_Task task = { .callable = printer, .type = PRINTER, .data = &counter };

  trace_me("Teste do tracme");

  while (true)
  {
    // Apenas por curiosidade
    // unsigned char *base = (unsigned char *) printer;
    // printf("%x    ------  %x", base[6], base[2]);
    if (done) {
      log_info("Nenhum tarefa");
    } else {
      if (run_task(&task)) {
        log_info("  Tarefa executada com sucesso");
        done = true;
      } else {
        log_info("  Tarefa não executada com sucesso");
      }
    }
    sleep(2);
  }

  return EXIT_SUCCESS;
}
