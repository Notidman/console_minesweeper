#include "field.h"
#include <assert.h>
#include <stdio.h>

void 
activate_mines_in_cells(field_s *field,
    size_t mine_count);

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

  field->cells = (cell_s***)
    malloc(sizeof(cell_s**) * y);

  for(size_t i = 0; i < y; ++i)
  {
    field->cells[i] = (cell_s**)
      malloc(sizeof(cell_s*) * y);
  }

  field->x = x;
  field->y = y;
  field->S = (field->x * field->y);
  for(size_t i = 0; i < field->y; ++i)
  {
    for(size_t j = 0; j < field->x; ++j)
    {
      field->cells[i][j] = alloc_cell(false, icon);
    }
  }

  activate_mines_in_cells(field, mine_count);
  tying_field(field);
  return field;
}

void
free_field(field_s *field)
{
  assert(!( field == NULL));
  assert(!(field->cells == NULL));

  for(size_t i = 0; i < field->y; ++i)
  {
    for(size_t j = 0; j < field->x; ++j)
    {
      assert(!(field->cells[i][j] == NULL));
    }
  }

  for(size_t i = 0; i < field->y; ++i)
  {
    for(size_t j = 0; j < field->x; ++j)
    {
      free(field->cells[i][j]);
    }
  }

  for(size_t i = 0; i < field->y; ++i)
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
  for(size_t row = 0; row < field->y - 1; ++row)
  {
    for(size_t col = 0; col < field->x - 1; ++col)
    {
      for(cell_around_t where = top; where != left_top; ++where)
      {
        tying_cell(field->cells[row][col],
            field->cells[row+1][col+1], where);
      }
    }
  }
}

void 
activate_mines_in_cells(
    field_s *field, size_t mine_count)
{
  size_t v = 0;
  for(size_t i = 0; mine_count; ++i)
  {
    if( i >= field->y)  {i = 0;}
    for(size_t j = 0; j < field->x; ++j)
    {
      if( mine_count == 0 ) { break; }
      v = 1 + rand() % mine_count;
      if( v >= mine_count && 
          field->cells[i][j]->contains_mine == false)
      {
        field->cells[i][j]->contains_mine = true;
        --mine_count;
      }

    }
  }
}
