#ifndef CELL_H
#define CELL_H
#include <stdbool.h>

#define CELL_AROUND_COUNT 8

typedef enum cell_around
{
  top = 0,
  right,
  left,
  buttom,
  right_buttom,
  right_top,
  left_top,
  left_buttom,
} cell_around_t;

typedef struct cell
{
  struct cell* cell_around;

  char icon;
  bool enable;
} cell_s;

cell_s* 
alloc_cell(
    void
);

cell_s* 
free_cell(
    cell_s *cell
);

#endif // CEL
