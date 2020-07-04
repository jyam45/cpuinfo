#include <stdio.h>
#include "cpuid.h"

#define MAXCACHES 5

int main( int argc, char** argv )
{
  //size_t ncache=0;
  //basic_info_t binfo;
  //cache_param_t caches[MAXCACHES];
  //extend_info_t xinfo;

  //cpuid_basic_info(&binfo);
  //cpuid_print_basic_info(&binfo);

  //ncache = cpuid_cache_params(MAXCACHES,caches);
  //cpuid_print_cache_params(ncache,caches);

  //cpuid_extend_info(&xinfo);
  //cpuid_print_extend_info(&xinfo);
  //
  
  cpuid_info_t cpu;
  read_cpuid_info( &cpu ); 
  write_cpuid_info( &cpu ); 

  return (0);
}
