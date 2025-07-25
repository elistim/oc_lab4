CC=gcc                 # Компилятор C
CFLAGS=-Wall -O2       # Флаги компилятора: показывать все предупреждения и оптимизация

# Цель по умолчанию: собрать все исполняемые файлы
all: main child1 child2 child3 child4

# Сборка основного файла main
main: main.c
	$(CC) $(CFLAGS) -o main main.c

# Сборка дочернего процесса 1
child1: child1.c
	$(CC) $(CFLAGS) -o child1 child1.c

# Сборка дочернего процесса 2
child2: child2.c
	$(CC) $(CFLAGS) -o child2 child2.c

# Сборка дочернего процесса 3
child3: child3.c
	$(CC) $(CFLAGS) -o child3 child3.c

# Сборка дочернего процесса 4
child4: child4.c
	$(CC) $(CFLAGS) -o child4 child4.c

# Очистка: удаление всех исполняемых файлов
clean:
	rm -f main child1 child2 child3 child4
