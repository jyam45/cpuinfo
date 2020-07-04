#include <stdio.h>
#include "cpuid.h"

#define MAXCACHES 5

int main( int argc, char* argv )
{
  const char* cache_type_str[4]={"","D","I",""};
  char head[16]={'\0'};
  size_t i;

  cpuid_info_t cpu;
  read_cpuid_info( &cpu ); 

  printf("#ifndef CPU_H_HEADER_GUIRD\n");
  printf("#define CPU_H_HEADER_GUIRD\n");

  // Features
  printf("/**********************************/\n");
  printf("/** Instruction Set Architecture **/\n");
  printf("/**********************************/\n");
  printf("#define HAVE_F16C              %u\n",((cpu.basic_info.features[0]&F_F16C)?1:0));
  printf("#define HAVE_FPU               %u\n",((cpu.basic_info.features[1]&F_FPU)?1:0));
  printf("#define HAVE_MMX               %u\n",((cpu.basic_info.features[1]&F_MMX)?1:0));
  printf("#define HAVE_FPU               %u\n",((cpu.basic_info.features[1]&F_FPU)?1:0));
  printf("#define HAVE_MMX               %u\n",((cpu.basic_info.features[1]&F_MMX)?1:0));
  printf("#define HAVE_SSE               %u\n",((cpu.basic_info.features[1]&F_SSE)?1:0));
  printf("#define HAVE_SSE2              %u\n",((cpu.basic_info.features[1]&F_SSE2)?1:0));
  printf("#define HAVE_SSE3              %u\n",((cpu.basic_info.features[0]&F_SSE3)?1:0));
  printf("#define HAVE_SSSE3             %u\n",((cpu.basic_info.features[0]&F_SSSE3)?1:0));
  printf("#define HAVE_SSE4_1            %u\n",((cpu.basic_info.features[0]&F_SSE4_1)?1:0));
  printf("#define HAVE_SSE4_2            %u\n",((cpu.basic_info.features[0]&F_SSE4_2)?1:0));
  printf("#define HAVE_AVX               %u\n",((cpu.basic_info.features[0]&F_AVX)?1:0));
  printf("#define HAVE_AVX2              %u\n",((cpu.more_feature[0].features[0]&F_AVX2)?1:0));
  printf("#define HAVE_AVX512F           %u\n",((cpu.more_feature[0].features[0]&F_AVX512F)?1:0));
  printf("#define HAVE_AVX512DQ          %u\n",((cpu.more_feature[0].features[0]&F_AVX512DQ)?1:0));
  printf("#define HAVE_AVX512PF          %u\n",((cpu.more_feature[0].features[0]&F_AVX512PF)?1:0));
  printf("#define HAVE_AVX512ER          %u\n",((cpu.more_feature[0].features[0]&F_AVX512ER)?1:0));
  printf("#define HAVE_AVX512CD          %u\n",((cpu.more_feature[0].features[0]&F_AVX512CD)?1:0));
  printf("#define HAVE_AVX512BW          %u\n",((cpu.more_feature[0].features[0]&F_AVX512BW)?1:0));
  printf("#define HAVE_AVX512VL          %u\n",((cpu.more_feature[0].features[0]&F_AVX512VL)?1:0));
  printf("#define HAVE_AVX512_IFMA       %u\n",((cpu.more_feature[0].features[0]&F_AVX512_IFMA)?1:0));
  printf("#define HAVE_AVX512_VBMI       %u\n",((cpu.more_feature[0].features[1]&F_AVX512_VBMI)?1:0));
  printf("#define HAVE_AVX512_VBMI2      %u\n",((cpu.more_feature[0].features[1]&F_AVX512_VBMI2)?1:0));
  printf("#define HAVE_AVX512_VNNI       %u\n",((cpu.more_feature[0].features[1]&F_AVX512_VNNI)?1:0));
  printf("#define HAVE_AVX512_BITALG     %u\n",((cpu.more_feature[0].features[1]&F_AVX512_BITALG)?1:0));
  printf("#define HAVE_AVX512_4VNNIW     %u\n",((cpu.more_feature[0].features[1]&F_AVX512_4VNNIW)?1:0));
  printf("#define HAVE_AVX512_4FMDPS     %u\n",((cpu.more_feature[0].features[1]&F_AVX512_4FMDPS)?1:0));
  printf("#define HAVE_AVX512_VPOPCNTDQ  %u\n",((cpu.more_feature[0].features[1]&F_AVX512_VPOPCNTDQ)?1:0));


  printf("/**********************************/\n");
  printf("/**         Instructions         **/\n");
  printf("/**********************************/\n");
  printf("#define HAVE_FMA               %u\n",((cpu.basic_info.features[0]&F_FMA)?1:0));
  printf("#define HAVE_MOVBE             %u\n",((cpu.basic_info.features[0]&F_MOVBE)?1:0));
  printf("#define HAVE_POPCNT            %u\n",((cpu.basic_info.features[0]&F_POPCNT)?1:0));
  printf("#define HAVE_RDRAND            %u\n",((cpu.basic_info.features[0]&F_RDRAND)?1:0));
  printf("#define HAVE_PCLMULQDQ         %u\n",((cpu.basic_info.features[0]&F_PCLMULQDQ)?1:0));
  printf("#define HAVE_CMPXCHG16B        %u\n",((cpu.basic_info.features[0]&F_CMPXCHG16B)?1:0));

  printf("#define HAVE_RDMSR             %u\n",((cpu.basic_info.features[1]&F_MSR)?1:0));
  printf("#define HAVE_WRMSR             %u\n",((cpu.basic_info.features[1]&F_MSR)?1:0));
  printf("#define HAVE_CMPXCHG8B         %u\n",((cpu.basic_info.features[1]&F_CX8)?1:0));
  printf("#define HAVE_SYSENTER          %u\n",((cpu.basic_info.features[1]&F_SEP)?1:0));
  printf("#define HAVE_SYSEXIT           %u\n",((cpu.basic_info.features[1]&F_SEP)?1:0));
  printf("#define HAVE_CMOV              %u\n",((cpu.basic_info.features[1]&F_CMOV)?1:0));
  printf("#define HAVE_FCOMI             %u\n",(((cpu.basic_info.features[1]&F_CMOV)&&(cpu.basic_info.features[1]&F_FPU))?1:0));
  printf("#define HAVE_FCMOV             %u\n",(((cpu.basic_info.features[1]&F_CMOV)&&(cpu.basic_info.features[1]&F_FPU))?1:0));
  printf("#define HAVE_CLFLUSH           %u\n",((cpu.basic_info.features[1]&F_CLFSH)?1:0));
  printf("#define HAVE_FXSAVE            %u\n",((cpu.basic_info.features[1]&F_FXSR)?1:0));
  printf("#define HAVE_FXRSTOR           %u\n",((cpu.basic_info.features[1]&F_FXSR)?1:0));

  printf("#define HAVE_RDSEED            %u\n",((cpu.more_feature[0].features[0]&F_RDSEED)?1:0));
  printf("#define HAVE_PREFETCHWT1       %u\n",((cpu.more_feature[0].features[1]&F_PREFETCHWT1)?1:0));

  printf("#define HAVE_LAHF              %u\n",((cpu.extend_info.features[0]&F_X_LAHF)?1:0));
  printf("#define HAVE_SAHF              %u\n",((cpu.extend_info.features[0]&F_X_LAHF)?1:0));
  printf("#define HAVE_LZCNT             %u\n",((cpu.extend_info.features[0]&F_X_LZCNT)?1:0));
  printf("#define HAVE_PREFETCHW         %u\n",((cpu.extend_info.features[0]&F_X_PREFETCHW)?1:0));

  printf("#define HAVE_SYSCALL           %u\n",((cpu.extend_info.features[1]&F_X_SYSCALL)?1:0));
  printf("#define HAVE_SYSRET            %u\n",((cpu.extend_info.features[1]&F_X_SYSCALL)?1:0));
  printf("#define HAVE_RDTSCP            %u\n",((cpu.extend_info.features[1]&F_X_RDTSCP)?1:0));

  printf("#define HAVE_VPCLMULQDQ        %u\n",((cpu.more_feature[0].features[1]&F_VPCLMULQDQ)?1:0));

  printf("/**********************************/\n");
  printf("/**      System Configuration    **/\n");
  printf("/**********************************/\n");
  printf("#define HAVE_HTT               %u\n",((cpu.basic_info.features[1]&F_HTT)?1:0));
  printf("#define HAVE_X86_64            %u\n",((cpu.extend_info.features[1]&F_X_INTEL64)?1:0));

  // Caches

  printf("/**********************************/\n");
  printf("/**      Cache Configuration     **/\n");
  printf("/**********************************/\n");
  for( i=0; i<cpu.num_caches; i++ ){
    sprintf(head,"L%1u%s\0",cpu.cache_info[i].cache_level,cache_type_str[cpu.cache_info[i].cache_type]);
    printf("#define %s_SIZE_B             %u\n",head,((cpu.cache_info[i].cache_size_b)));
    printf("#define %s_SIZE_KB            %u\n",head,((cpu.cache_info[i].cache_size_b)>>10));
    printf("#define %s_SIZE_MB            %u\n",head,((cpu.cache_info[i].cache_size_b)>>20));
    printf("#define %s_LINESIZE_B         %u\n",head,((cpu.cache_info[i].line_size)));
    printf("#define %s_PARTITION          %u\n",head,((cpu.cache_info[i].line_parts)));
    printf("#define %s_ASSOC_WAYS         %u\n",head,((cpu.cache_info[i].assoc_ways)));
    printf("#define %s_ASSOC_SETS         %u\n",head,((cpu.cache_info[i].assoc_sets)));
  }
  
  printf("/**********************************/\n");
  printf("#endif//CPU_H_HEADER_GUIRD\n");
  return (0);
}
