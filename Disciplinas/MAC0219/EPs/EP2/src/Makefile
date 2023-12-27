CFLAGS = -Wall -pedantic -O2 -std=c11
MCC = mpicc
NAME = broadcast

CODEBRAID_FLAGS= --live-output $\
--overwrite --standalone --toc $\
--from=markdown $\
--number-sections --wrap=preserve $\
--mathjax=https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js

$(NAME): $(NAME).c
	$(MCC) $(DEBUG) $(CFLAGS) -o $(NAME) $<

debug: DEBUG = -DDEBUG

debug: $(NAME)

Relatorio.pdf: Relatorio.md
	codebraid pandoc $(CODEBRAID_FLAGS) --to=pdf --output=$@ Relatorio.md

.PHONY: clean
clean:
	rm $(NAME)
	