#include "functions.h"


void finaev::MEMcpy(void* new_a, void* a, size_t n)
{
  char* cnew_a = (char*)new_a;
  char* ca = (char*)a;
  for (int i = 0; i < n; i++)
  {
    cnew_a[i] = ca[i];
  }
}

char* finaev::increase_str(char* a, size_t old_dl, size_t new_dl)
{
  char* new_a = (malloc((size + 1) * sizeof(char)));
  MEMcpy(new_a, a, old_dl);
  delete[] a;
  a = new_a;
  return a;
}
