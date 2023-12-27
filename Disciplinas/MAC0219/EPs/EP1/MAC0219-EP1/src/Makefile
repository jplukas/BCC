UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    CC     = gcc
    CC_OMP = -fopenmp
    CC_PTH = -pthread
endif
ifeq ($(UNAME_S),Darwin)    # Darwin is for MacOS
    CC = /opt/homebrew/opt/llvm/bin/clang
    CC_OMP = -fopenmp=libomp
    CC_PTH = -pthread
    LDFLAGS = -L/opt/homebrew/opt/llvm/lib -Wl,-rpath,/opt/homebrew/opt/llvm/lib
    CPPFLAGS = -I/opt/homebrew/opt/llvm/include
endif

CFLAGS = -Wall -pedantic -O2 -std=c11

ifeq ($(DEBUG),yes)
CFLAGS += -DDEBUG
endif

INFILES = $(shell ls *.in)

CODEBRAID_FLAGS= --live-output $\
--overwrite --standalone --toc $\
--from=markdown $\
--number-sections --wrap=preserve $\
--mathjax=https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js

INPUT_FILE= Relatorio.md

all: check time_test grid_gen testes.csv Relatorio.pdf

Relatorio.pdf: $(INPUT_FILE)
	codebraid pandoc $(CODEBRAID_FLAGS) --to=pdf --output=$@ $(INPUT_FILE)

check: check.o lga_base.o lga_seq.o lga_omp.o lga_pth.o
	$(CC) $(CFLAGS) $(CC_OMP) $(CC_PTH) -o $@ $^ $(LDFLAGS)

check.o: check.c lga_base.o
	$(CC) $(CFLAGS) -c $<

time_test: time_test.o lga_base.o lga_seq.o lga_omp.o lga_pth.o time_extra.o
	$(CC) $(CFLAGS) $(CC_OMP) $(CC_PTH) -o $@ $^ $(LDFLAGS)

time_test.o: time_test.c lga_base.o
	$(CC) $(CFLAGS) -c $<

lga_seq.o: lga_seq.c lga_seq.h lga_base.o
	$(CC) $(CFLAGS) -c $<

lga_omp.o: lga_omp.c lga_omp.h lga_base.o
	$(CC) $(CFLAGS) $(CC_OMP) -c $<

lga_pth.o: lga_pth.c pthread_barrier.h lga_pth.h lga_base.o
	$(CC) $(CFLAGS) $(CC_PTH) -c $<

grid_gen: grid_gen.o lga_base.o
	$(CC) $(CFLAGS) -o $@ $^

grid_gen.o: grid_gen.c lga_base.o
	$(CC) $(CFLAGS) -c $<

lga_base.o: lga_base.c lga_base.h
	$(CC) $(CFLAGS) -c $<

time_extra.o: time_extra.c time_extra.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean purge

clean:
	rm -f *.pdf
	rm -rf _codebraid/

purge: clean
	rm -f *.csv
	rm -f check time_test grid_gen
	rm -f *.o

.ONESHELL: testes.csv

testes.csv: $(INFILES) time_test

	@echo "impl,num_threads,i,grid_size,time" > $@;

	for impl in omp pth; do \
		nthreads=1;
		for j in `seq 1 6`; do \
			for i in `seq 1 30`; do \
				for arq in $(INFILES); do \
					echo -n $$impl,$$nthreads,$$i,$${arq%.in}, >> $@;
					set -x;
					./time_test --grid_size $${arq%.in} --impl $$impl --num_threads $$nthreads >> $@; 
					set +x;
				done;
			done;
			nthreads=`expr $$nthreads \* 2`;
		done;
	done;

	for i in `seq 1 30`; do \
		for arq in $(INFILES); do \
			echo -n seq,1,$$i,$${arq%.in}, >> $@;
			set -x;
			./time_test --grid_size $${arq%.in} --impl seq >> $@; 
			set +x;
		done;
	done;
