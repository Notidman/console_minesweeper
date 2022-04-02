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
  for(size_t row = 0; row < field->y; ++row)
  {
    for(size_t col = 0; col < field->x; ++col)
    {
      for (cell_around_t where = top; where != left_top + 1; ++where) 
      {
        if (where == top) 
        {
          if (col - 1 >= 0)
          {
            tying_cell(field->cells[row][col], field->cells[row][col - 1], top);
          }
        }
        else if (where == right_top)
        {
          if (row + 1 <= field->x && col - 1 >= 0)
          {
            tying_cell(field->cells[row][col], field->cells[row + 1][col - 1], right_top);
          }
        }
        else if (where == right)
        {
          if (row + 1 <= field->x)
          {
            tying_cell(field->cells[row][col], field->cells[row + 1][col], right);
          }
        }
        else if (where == right_buttom)
        {
          if (row + 1 <= field->x && col + 1 <= field->y)
          {
              tying_cell(field->cells[row][col], field->cells[row + 1][col + 1], right_buttom);
          }
        }
        else if (where == buttom)
        {
          if (col + 1 <= field->y)
          {
            tying_cell(field->cells[row][col], field->cells[row][col + 1], buttom);
          }
        }
        else if (where == left_buttom)
        {
          if (row - 1 >= 0 && col + 1 <= field->y)
          {
            tying_cell(field->cells[row][col], field->cells[row - 1][col + 1], left_buttom);
          }
        }
        else if (where == left)
        {
          if (row - 1 >= 0)
          {
            tying_cell(field->cells[row][col], field->cells[row - 1][col], left);
          }
        }
        else if (where == left_top)
        {
          if (row - 1 >= 0 && col - 1 >= 0)
          {
            tying_cell(field->cells[row][col], field->cells[row - 1][col - 1], left_top);
          }
        }
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

void
active_cell(
    field_s *field)
{

}
