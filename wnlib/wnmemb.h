/****************************************************************************

COPYRIGHT NOTICE:

  The source code in this file is provided free of charge
  to the author's consulting clients.  It is in the
  public domain and therefore may be used by anybody for
  any purpose.

AUTHOR:

  Will Naylor

****************************************************************************/
#ifndef wnmembH
#define wnmembH


#include "wnlib.h"


void wn_memcpy(ptr out,ptr in,int n);
void wn_memset(ptr out,char c,int n);
void wn_memzero(ptr out,int n);

int wn_memcmp(ptr m1,ptr m2,int len);
bool wn_memeq(ptr m1,ptr m2,int len);



#endif

