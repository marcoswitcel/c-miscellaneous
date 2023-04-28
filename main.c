#include <stdlib.h>
#include <stdio.h>

#include "./logger.c"

int main(void)
{
  log_info("Mensagens");
  LOG_TRACE("De onde?");
  LOG_TRACE("Que horas?");
  LOG_TRACE("Que dia?");

  TRACE("Teste");
  return EXIT_SUCCESS;
}
