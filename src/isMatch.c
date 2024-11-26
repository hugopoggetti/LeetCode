bool isMatch(char* s, char* p)
{
  char* scpy = NULL;
  char* pcpy = NULL;
  while (*s) {
    if (*s == *p || '?' == *p) { s++; p++; }
    else if (*p == '*') { scpy = s+1; pcpy = p++; }
    else if (scpy != NULL) { s = scpy; p = pcpy; }
    else { return false; }
  }
  while (*p == '*') p++;
  return !*p;
}
