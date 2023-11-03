#include <iostr

#define BUF_SIZE 1024

void ErrorHandling(const char* message) {
    printf("%s\n", message);
    system("pause");
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        system("pause");
        return 1;
    }
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR)
        ErrorHandling("WSAStartup() error!");
    SOCKET clnt_sock;
    SOCKADDR_IN serv_addr;
    clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (clnt_sock == SOCKET_ERROR)
        ErrorHandling("socket() error!");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(clnt_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
        ErrorHandling("connect() error!");
    int str_len;
    char message[BUF_SIZE];
    while (1) {
        scanf("%s", message);
        if (strcmp(message, "Q") == 0 || strcmp(message, "q") == 0)
            break;
        send(clnt_sock, message, strlen(message), 0);
        str_len = recv(clnt_sock, message, BUF_SIZE, 0);
        if (str_len == 0)
            break;
        else {
            message[str_len] = 0;
            printf("sdfs: %s\n", message);
        }
    }
    closesocket(clnt_sock);
    WSACleanup();
    system("pause");
    return 0;
}