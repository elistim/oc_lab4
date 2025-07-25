#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Процесс 4 (PID %d) запущен\n", getpid());
    fflush(stdout);
    setsid(); // Создаем новый сеанс (процесс становится лидером сеанса)
    printf("Процесс 4: Создан новый сеанс (SID %d)\n", getsid(0));
    fflush(stdout);
    while (1) {
        pause(); // Ждем сигналы
    }
    return 0;
}
