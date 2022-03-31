#include "tester.h"
#include <assert.h>
#include <math.h>
#include <assert.h>

void
test_field_content_mines(
    field_s *field, size_t mine_count)
{
  size_t mine_sum = 0;
  for(size_t row = 0; row < field->y; ++row)
  {
    for(size_t col = 0; col < field->x; ++col)
    {
      if ( field->cells[row][col]->contains_mine )
      {
       ++mine_sum;
      }
    }

  }

  assert(!( mine_sum != mine_count ));
}

void
test_field_tying(
    field_s *field)
{
  double mid = sqrt(field->S);
  active_cell(field, mid);
  assert(!(field->cells[0][0]->activated
        == true ));
}
