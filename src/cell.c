#include "cell.h"
#include <stdio.h>

cell_s* 
alloc_cell(void)
{
  cell_s *cell = (cell_s*)
    malloc(sizeof(cell_s));

  cell->cell_around = (cell_s*)
    malloc(sizeof(cell_s) *
        CELL_AROUND_COUNT);

  return cell;
}
cell_s* 
free_cell(cell_s* cell)
{
  if ( cell == NULL ||
      cell->cell_around == NULL)
  {
    return NULL;
  }
  else
  {
    free(cell->cell_around);
    free(cell);
  }

  return NULL;
}
