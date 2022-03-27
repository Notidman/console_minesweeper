#include "painter.h"
#include <stdio.h>

void 
draw_field_with_mines(
  field_s *field)
{
  for(size_t row = 0; row < field->y; ++row)
  {
    for(size_t col = 0; col < field->x; ++col)
    {
      if( row+1 % field->x == 0 ) { puts(""); }

      printf("%d ", field->cells[row][col]->contains_mine);

    }
    puts("");
  }
}
