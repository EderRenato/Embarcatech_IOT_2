#ifndef LWIPOPTS_H
#define LWIPOPTS_H

// Configurações básicas
#define NO_SYS                      1
#define LWIP_SOCKET                 0
#define LWIP_NETCONN                0

// Protocolos habilitados
#define LWIP_TCP                    1
#define LWIP_UDP                    1  // Necessário para DHCP e DNS
#define LWIP_IPV4                   1
#define LWIP_ICMP                   1
#define LWIP_DHCP                   1
#define LWIP_DNS                    1
#define LWIP_AUTOIP                 0

// Configurações de memória
#define MEM_ALIGNMENT               4
#define MEM_SIZE                    (16 * 1024)
#define MEMP_NUM_PBUF               16
#define PBUF_POOL_SIZE              16
#define PBUF_POOL_BUFSIZE           TCP_MSS
#define MEMP_NUM_TCP_PCB            5
#define MEMP_NUM_TCP_SEG            32

// Configurações TCP
#define TCP_MSS                     1460
#define TCP_SND_BUF                 (4 * TCP_MSS)
#define TCP_WND                     (4 * TCP_MSS)
#define TCP_LISTEN_BACKLOG          1

// Configurações de desempenho
#define LWIP_CHECKSUM_ON_COPY       0
#define LWIP_TCP_TIMESTAMPS         0
#define LWIP_WND_SCALE              0
#define LWIP_TCP_SACK_OUT           0

// Configurações de depuração
#define LWIP_DEBUG                  0
#define TCP_DEBUG                   LWIP_DBG_OFF

// Outras configurações
#define LWIP_NETIF_STATUS_CALLBACK  1
#define LWIP_NETIF_LINK_CALLBACK    1
#define LWIP_NETIF_HOSTNAME         1

#endif /* LWIPOPTS_H */