#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "env.h"
#include "tester.h"
#include "painter.h"

int 
main(void)
{
  srand(time(NULL));
  field_s *field = alloc_field(
      X_FIELD, 
      Y_FIELD,
      MINE_COUNT, ICON_CELL);

  draw_field(field);
  test_field_content_mines(field, MINE_COUNT);
  free_field(field);
  return EXIT_SUCCESS;
}
