#include "cell.h"
#include <stdio.h>
#include <assert.h>

cell_s* 
alloc_cell(bool contains_mine,
    char icon)
{
  cell_s *cell = (cell_s*)malloc(sizeof(cell_s));

  cell->cell_around = (cell_s**)malloc(
      sizeof(cell_s*) * CELL_AROUND_COUNT);

  for(size_t i = 0; i < CELL_AROUND_COUNT; ++i)
  {
    cell->cell_around[i] = NULL;
  }

  cell->icon = icon;
  cell->contains_mine = contains_mine;
  cell->activated = false;

  return cell;
}

void
free_cell(cell_s* cell)
{
  assert(!(cell == NULL));
  free(cell);
  cell = NULL;
}

void
tying_cell(cell_s *dest, cell_s *src,
    cell_around_t where)
{
  assert(!(dest == NULL));
  assert(!(src == NULL));
  assert(!(dest == src));

  dest->cell_around[where] = src;
}
