/*
 * MIT License
 *
 * Copyright (c) 2020 Newracom, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef __NRC_ATCMD_SOCKET_H__
#define __NRC_ATCMD_SOCKET_H__
/**********************************************************************************************/

#define ATCMD_SOCKET_NUM_MAX			LWIP_SOCKET_NUM_MAX
#define ATCMD_SOCKET_RXBUF_SIZE			ATCMD_TXBUF_SIZE

enum ATCMD_SOCKET_PROTO
{
	ATCMD_SOCKET_PROTO_NONE = -1,
	ATCMD_SOCKET_PROTO_UDP = 0,
	ATCMD_SOCKET_PROTO_TCP,

	ATCMD_SOCKET_PROTO_NUM,

	ATCMD_SOCKET_PROTO_ALL = ~0
};

typedef struct
{
	int16_t id;
	int16_t protocol;
	uint16_t local_port;
	uint16_t remote_port;
	char remote_addr[ATCMD_IP4_ADDR_LEN_MAX + 1];
} atcmd_socket_t;

typedef struct
{
	atcmd_socket_t socket;

	struct
	{
		int msg;
		int data;
	} len;

	struct
	{
		char msg[ATCMD_LEN_MAX];
		char data[ATCMD_SOCKET_RXBUF_SIZE];
	} buf;
} atcmd_socket_rxd_t;

/**********************************************************************************************/

extern void atcmd_socket_reset (atcmd_socket_t *socket);
extern int atcmd_socket_enable (void);
extern void atcmd_socket_disable (void);
extern int atcmd_socket_send_data (atcmd_socket_t *socket, char *data, int len, int *err);

/**********************************************************************************************/
#endif /* #ifndef __NRC_ATCMD_SOCKET_H__ */

