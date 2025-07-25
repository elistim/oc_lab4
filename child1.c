#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Функция для вывода текущего времени
void print_time() {
    time_t now = time(NULL);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf(" [%s]\n", buf);
    fflush(stdout);
}

// Обработчик SIGINT: выводит сообщение с датой
void sigint_handler1(int sig) {
    printf("Процесс 1 (PID %d): Получен SIGINT.", getpid());
    print_time();
}

int main() {
    printf("Процесс 1 (PID %d) запущен\n", getpid());
    fflush(stdout);
    // Устанавливаем обработчики сигналов
    signal(SIGINT, sigint_handler1);
    signal(SIGQUIT, SIG_IGN); // Игнорируем SIGQUIT
    while (1) {
        pause(); // Ждем сигналы
    }
    return 0;
}
