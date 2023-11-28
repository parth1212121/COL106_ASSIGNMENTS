/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "entry.h"



SymEntry ::SymEntry(){  
                                                              // no use....
    left=NULL;
    right=NULL;
}

SymEntry ::SymEntry(string k, UnlimitedRational* v){
    key=k;
    val=v;
    left=NULL;
    right=NULL;
}

SymEntry ::~SymEntry(){                                       // Look into this carefully...............
      delete val;
}