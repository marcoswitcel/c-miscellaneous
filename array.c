
typedef struct Array {
  unsigned lentgh;
  char data[];
} Array;

Array *create_array(unsigned length)
{
  Array *array = malloc(sizeof(Array) + length * sizeof(char));
  array->lentgh = length;

  return array;
}

void destroy_array(Array *array)
{
  free(array);
}

#define ARRAY_GET(array, index)        (array->data[index])
#define ARRAY_SET(array, index, value) (array->data[index] = value)
#define ARRAY_ITERATE(array) for (unsigned index = 0; index < array->lentgh; index++)

