#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Процесс 3 (PID %d) запущен\n", getpid());
    fflush(stdout);
    // Игнорируем сигнал SIGINT
    signal(SIGINT, SIG_IGN);
    while (1) {
        pause(); // Ждем сигналы
    }
    return 0;
}
