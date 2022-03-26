#include "field.h"
#include <assert.h>
#include <stdio.h>

void 
shuffle_cells(field_s *field, size_t mine_count);

void
tying_field(field_s *field);

field_s* 
alloc_field(
    size_t x, size_t y,
    size_t mine_count,
    char icon)
{
  assert(!(mine_count >= x*y));
  field_s *field = (field_s*)
    malloc(sizeof(field_s));

  field->cells = (cell_s**)
    malloc(sizeof(cell_s*) * 
        x*y);

  field->x = x;
  field->y = y;
  field->S = (field->x * field->y);
  for(size_t i = 0; i < field->S; ++i)
  {
    field->cells[i] = alloc_cell(false, icon);
  }

  shuffle_cells(field, mine_count);
  tying_field(field);
  return field;
}

void
free_field(field_s *field)
{
  assert(!( field == NULL));
  assert(!(field->cells == NULL));

  for(size_t i = 0; i < field->S; ++i)
  {
    assert(!(field->cells[i] == NULL));
  }

  for(size_t i = 0; i < field->S; ++i)
  {
    free(field->cells[i]);
  }

  free(field->cells);
  free(field);

  field = NULL;
}

void
tying_field(
    field_s *field)
{
}

void shuffle_cells(
    field_s *field, size_t mine_count)
{
  for(size_t i = 0; mine_count; ++i)
  {
    if( i >= field->S)
    {
      i = 0;
    }

    if( 1 + rand() % mine_count >= mine_count / 2)
    {
      field->cells[i]->contains_mine = true;
      --mine_count;
    }

  }
}
