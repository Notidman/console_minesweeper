#include <stdio.h>
#include "painter.h"
#include "lpct.h"

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

void
draw_field(
    field_s *field)
{
  for(size_t row = 0; row < field->y; ++row)
  {
    for(size_t col = 0; col < field->x; ++col)
    {
      if( row+1 % field->x == 0 ) { puts(""); }
      printf("%s%c %s", get_color(COLOR_FIELD),
        field->cells[row][col]->icon,
        get_color(42));
    }
    puts("");
  }
}

void
clrscr(void)
{
  for(size_t i = 0; i < 100; ++i)
  {
    puts("");
  }
  puts("");
}
