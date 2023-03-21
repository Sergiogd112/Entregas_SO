#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int sock_conn, sock_listen, ret;
    struct sockaddr_in server_addr;
    char request[512];
    char response[512];
    if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("socket error\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9050);

    if (bind(sock_listen, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        printf("Error al bind\n");

    if (listen(sock_listen, 3) < 0)
        printf("Error en el listen\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Escuchando\n");

        sock_conn = accept(sock_listen, NULL, NULL);
        printf("He recibido conexion\n");
        int code = 1;
        while (code != 0)
        {
            printf("Esperando peticion\n");
            ret = read(sock_conn, request, sizeof(request));

            printf("Recibido\n");

            request[ret] = '\0';

            printf("Peticion: %s\n", request);

            char *p = strtok(request, "/");

            int code = atoi(p);
            char name[20];

            if (code != 0)
            {
                p = strtok(NULL, "/");
                strcpy(name, p);
                printf("Codigo: %d, Nombre %s\n", code, name);

                if (code == 1)
                {
                    sprintf(response, "%ld", strlen(name));
                }
                else if (code == 2)
                {
                    if ((name[0] == 'M') || (name[0] == 'S'))
                        strcpy(response, "Si");
                    else
                        strcpy(response, "No");
                }
                else if (code == 3)
                {
                    p = strtok(NULL, "/");
                    float heigth = atof(p);
                    if (heigth > 1.70)
                        sprintf(response, "%s: eres alto", name);
                    else
                        sprintf(response, "%s: no eres alto", name);
                }
                printf("Respuesta: %s\n", response);
                write(sock_conn, response, strlen(response));
            }
        }
        close(sock_conn);
    }

    return 0;
}
