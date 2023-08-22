all: trab1

trab1: trab1.o leitura.o votacao.o validacao.o ordenacao.o relatorios.o layout.o impressao.o apuracao.o
	gcc trab1.o leitura.o votacao.o validacao.o ordenacao.o relatorios.o layout.o impressao.o apuracao.o -o trab1

generateos: trab1.c leitura.c  votacao.c validacao.c ordenacao.c relatorios.c layout.c impressao.c apuracao.c
	gcc -c trab1.c leitura.c votacao.c validacao.c ordenacao.c relatorios.c layout.c impressao.c apuracao.c

clean:
	rm -rf *.o trab1