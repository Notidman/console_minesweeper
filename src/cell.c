#include "cell.h"
#include <stdio.h>

cell_s* 
alloc_cell(bool contains_mine,
    char icon)
{
  cell_s *cell = (cell_s*)
    malloc(sizeof(cell_s));

  cell->cell_around = (cell_s*)
    malloc(sizeof(cell_s) *
        CELL_AROUND_COUNT);
  cell->icon = icon;
  cell->contains_mine = contains_mine;
  cell->activated = false;

  return cell;
}
cell_s* 
free_cell(cell_s* cell)
{
  if ( cell == NULL)
  {
    return NULL;
  }
  else
  {
    free(cell);
  }

  return NULL;
}
