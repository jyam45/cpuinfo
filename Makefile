CC=gcc

all   : build run
build : cpuinfo make_cpu_header 
run   : cpuinfo.txt cpu.h

cpuinfo : cpuinfo.o cpuid.o
	$(CC) $(LDFLAGS) -o $@ $?

make_cpu_header : make_cpu_header.o cpuid.o
	$(CC) $(LDFLAGS) -o $@ $?

cpuinfo.txt :
	./cpuinfo > $@

cpu.h :
	./make_cpu_header > $@

cpuid.o : cpuid.c cpuid.h cache.h
cpuinfo.o : cpuinfo.c cpuid.h
make_cpu_header.o : make_cpu_header.c cpuid.h

.PHONY: clean distclean

clean:
	rm -f cpuinfo make_cpu_header cpu.h cpuinfo.txt

distclean: clean
	rm -f *.o

.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
