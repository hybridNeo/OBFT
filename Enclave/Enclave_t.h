#ifndef ENCLAVE_T_H__
#define ENCLAVE_T_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include "sgx_edger8r.h" /* for sgx_ocall etc. */

#include "sgx_tseal.h"

#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif


char* ecall_api_handler(const char* request);
void ecall_start_raft_main(const char* ip_addr, const char* port, const char* intro_ip, const char* intro_port);
void ecall_s_node(const char* ip_addr, const char* port, const char* intro_ip, const char* intro_port);
char* ecall_heartbeat_handler(const char* request, const char* r_ep);
void ecall_straft();
void ecall_get_vote(const char* ip, int port);
void ecall_leader_fn();
int generate_random_number();
char* ecall_ah(const char* request, const char* ep);
void ecall_send_heartbeat(const char* message, const char* ip, int port);
sgx_status_t seal(uint8_t* plaintext, size_t plaintext_len, sgx_sealed_data_t* sealed_data, size_t sealed_size);
sgx_status_t unseal(sgx_sealed_data_t* sealed_data, size_t sealed_size, uint8_t* plaintext, uint32_t plaintext_len);

sgx_status_t SGX_CDECL ocall_print(const char* str);
sgx_status_t SGX_CDECL ocall_straft();
sgx_status_t SGX_CDECL ocall_set(int id, int state);
sgx_status_t SGX_CDECL ocall_get(int* retval, int id);
sgx_status_t SGX_CDECL ocall_sleep(int time);
sgx_status_t SGX_CDECL ocall_get_vote(const char* ip, int port);
sgx_status_t SGX_CDECL ocall_heartbeat_server(int port);
sgx_status_t SGX_CDECL ocall_leader_fn();
sgx_status_t SGX_CDECL ocall_api_server(int port);
sgx_status_t SGX_CDECL ocall_start_node(const char* ip_addr, const char* port, const char* intro_ip, const char* intro_port);
sgx_status_t SGX_CDECL ocall_send_heartbeat(const char* request, const char* host, int port_no);
sgx_status_t SGX_CDECL ocall_f_wrapper(const char* request, const char* host, int port_no);
sgx_status_t SGX_CDECL ocall_udp_sendmsg(char** response, const char* request, const char* host, int port_no);
sgx_status_t SGX_CDECL sgx_oc_cpuidex(int cpuinfo[4], int leaf, int subleaf);
sgx_status_t SGX_CDECL sgx_thread_wait_untrusted_event_ocall(int* retval, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_untrusted_event_ocall(int* retval, const void* waiter);
sgx_status_t SGX_CDECL sgx_thread_setwait_untrusted_events_ocall(int* retval, const void* waiter, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_multiple_untrusted_events_ocall(int* retval, const void** waiters, size_t total);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
