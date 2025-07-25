#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Обработчик SIGINT: выводит сообщение и продолжает работу
void sigint_handler2(int sig) {
    printf("Процесс 2 (PID %d): Получен SIGINT, продолжаю работу.\n", getpid());
    fflush(stdout);
}

int main() {
    printf("Процесс 2 (PID %d) запущен\n", getpid());
    fflush(stdout);
    // Устанавливаем обработчик SIGINT
    signal(SIGINT, sigint_handler2);
    while (1) {
        pause(); // Ждем сигналы
    }
    return 0;
}
