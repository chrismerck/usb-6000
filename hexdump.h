
// print out a buffer in hex

void hexdump(unsigned char * buf, int len)
{
  int i;
  for (i=0;i<len;i++)
  {
    printf("0x%02x",buf[i]);
    if ((i+1)%8 == 0)
    {
      printf("\n");
    } 
    else 
    {
      printf(" ");
    }
  }
  printf("\n");
}

