#ifndef ENCLAVE_U_H__
#define ENCLAVE_U_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <string.h>
#include "sgx_edger8r.h" /* for sgx_satus_t etc. */

#include "sgx_tseal.h"

#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_print, (const char* str));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_straft, ());
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_set, (int id, int state));
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get, (int id));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_sleep, (int time));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get_vote, (const char* ip, int port));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_heartbeat_server, (int port));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_leader_fn, ());
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_api_server, (int port));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_start_node, (const char* ip_addr, const char* port, const char* intro_ip, const char* intro_port));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_send_heartbeat, (const char* request, const char* host, int port_no));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_f_wrapper, (const char* request, const char* host, int port_no));
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_udp_sendmsg, (char** response, const char* request, const char* host, int port_no));
void SGX_UBRIDGE(SGX_CDECL, sgx_oc_cpuidex, (int cpuinfo[4], int leaf, int subleaf));
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_wait_untrusted_event_ocall, (const void* self));
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_set_untrusted_event_ocall, (const void* waiter));
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_setwait_untrusted_events_ocall, (const void* waiter, const void* self));
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_set_multiple_untrusted_events_ocall, (const void** waiters, size_t total));

sgx_status_t ecall_api_handler(sgx_enclave_id_t eid, char** retval, const char* request);
sgx_status_t ecall_start_raft_main(sgx_enclave_id_t eid, const char* ip_addr, const char* port, const char* intro_ip, const char* intro_port);
sgx_status_t ecall_s_node(sgx_enclave_id_t eid, const char* ip_addr, const char* port, const char* intro_ip, const char* intro_port);
sgx_status_t ecall_heartbeat_handler(sgx_enclave_id_t eid, char** retval, const char* request, const char* r_ep);
sgx_status_t ecall_straft(sgx_enclave_id_t eid);
sgx_status_t ecall_get_vote(sgx_enclave_id_t eid, const char* ip, int port);
sgx_status_t ecall_leader_fn(sgx_enclave_id_t eid);
sgx_status_t generate_random_number(sgx_enclave_id_t eid, int* retval);
sgx_status_t ecall_ah(sgx_enclave_id_t eid, char** retval, const char* request, const char* ep);
sgx_status_t ecall_send_heartbeat(sgx_enclave_id_t eid, const char* message, const char* ip, int port);
sgx_status_t seal(sgx_enclave_id_t eid, sgx_status_t* retval, uint8_t* plaintext, size_t plaintext_len, sgx_sealed_data_t* sealed_data, size_t sealed_size);
sgx_status_t unseal(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_sealed_data_t* sealed_data, size_t sealed_size, uint8_t* plaintext, uint32_t plaintext_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
