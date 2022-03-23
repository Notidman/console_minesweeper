#include "field.h"

field_s* 
alloc_field(
    size_t x, size_t y,
    size_t mine_count,
    char icon)
{
  field_s *field = (field_s*)
    malloc(sizeof(field_s));

  field->cells = (cell_s**)
    malloc(sizeof(cell_s*) * 
        x*y);
  field->size_x = x;
  field->size_y = y;
  
  size_t field_size = (x * y) - 1;
  for(size_t i = 0; i < field_size;
      ++i)
  {
    field->cells[i] = alloc_cell(0, '*');
  }


}

field_s* 
free_field(field_s *field)
{
}
