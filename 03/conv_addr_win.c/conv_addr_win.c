// conv_addr_win.c.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#undef UNICODE
#undef _UNICODE
#include <stdio.h>
#include <winsock2.h>

int main(int argc, char* argv[])
{
    char* strAddr = "203.211.218.102:9190";

    char strAddrBuf[50];
    SOCKADDR_IN servAddr;
    int size;

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    size = sizeof(servAddr);
    WSAStringToAddress(strAddr, AF_INET, NULL, (SOCKADDR*)&servAddr, &size);

    size = sizeof(strAddrBuf);
    WSAAddressToString((SOCKADDR*)&servAddr, sizeof(servAddr), NULL, strAddrBuf, &size);

    printf("Second conv result : %s", strAddrBuf);
    WSACleanup();
    return 0;
}

