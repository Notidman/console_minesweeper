#ifndef FIELD_H
#define FIELD_H
#include "cell.h"

typedef struct field
{
  size_t size_x;
  size_t size_y;
  size_t mine_count;

  cell_s** cells;

} field_s;

field_s* 
alloc_field
(
    size_t x, size_t y,
    size_t mine_count
);

field_s* 
free_field(
    field_s *field
);

#endif // FIELD_H
