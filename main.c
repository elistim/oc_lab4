// Главный файл: создает 4 дочерних процесса и запускает отдельные исполняемые файлы
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    // Массив с именами исполняемых файлов дочерних процессов
    const char *children[] = {"./child1", "./child2", "./child3", "./child4"};

    // Цикл создания 4 дочерних процессов
    for (int i = 0; i < 4; ++i) {
        pid = fork(); // Создаем новый процесс
        if (pid == 0) {
            // В дочернем процессе: заменяем образ процесса на соответствующий исполняемый файл
            execl(children[i], children[i], NULL); // Запускаем child1, child2, child3 или child4
            // Если execl завершился с ошибкой:
            perror("execl failed");
            exit(1);
        } else if (pid < 0) {
            // Ошибка при fork()
            perror("fork failed");
            exit(1);
        } else {
            // Родительский процесс: выводит информацию о создании дочернего процесса
            printf("Родительский процесс (PID %d) создал дочерний процесс (PID %d)\n", getpid(), pid);
            fflush(stdout);
        }
    }

    // Даем время дочерним процессам и только потом завершаемся
    sleep(1);
    printf("Родительский процесс (PID %d) завершается\n", getpid());
    exit(0);
}