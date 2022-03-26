#include <stdio.h>
#include <stdlib.h>
#include "field.h"

int 
main(void)
{
  field_s *field = alloc_field(5, 5, 24, '@');

  free_field(field);
  return EXIT_SUCCESS;
}
