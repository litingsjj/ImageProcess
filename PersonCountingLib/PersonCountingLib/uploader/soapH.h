/* soapH.h
   Generated by gSOAP 2.8.23 from doupload.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifndef WITH_NOIDREF

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 const char ** SOAP_FMAC4 soap_faultcode(struct soap *soap);

SOAP_FMAC3 void * SOAP_FMAC4 soap_instantiate(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 int SOAP_FMAC4 soap_fdelete(struct soap_clist*);
SOAP_FMAC3 void* SOAP_FMAC4 soap_class_id_enter(struct soap*, const char*, void*, int, size_t, const char*, const char*);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_byte(soap, data), 0) || soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_int(soap, data), 0) || soap_put_int(soap, data, "int", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_time
#define SOAP_TYPE_time (9)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_time(struct soap*, time_t *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_time(struct soap*, const char*, int, const time_t *, const char*);
SOAP_FMAC3 time_t * SOAP_FMAC4 soap_in_time(struct soap*, const char*, time_t *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_time(struct soap*, const time_t *, const char*, const char*);

#ifndef soap_write_time
#define soap_write_time(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_time(soap, data), 0) || soap_put_time(soap, data, "dateTime", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 time_t * SOAP_FMAC4 soap_get_time(struct soap*, time_t *, const char*, const char*);

#ifndef soap_read_time
#define soap_read_time(soap, data) ( soap_begin_recv(soap) || !soap_get_time(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE__ns1__UpdateClassRoomPersonStatusResponse
#define SOAP_TYPE__ns1__UpdateClassRoomPersonStatusResponse (8)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out__ns1__UpdateClassRoomPersonStatusResponse(struct soap*, const char*, int, const _ns1__UpdateClassRoomPersonStatusResponse *, const char*);
SOAP_FMAC3 _ns1__UpdateClassRoomPersonStatusResponse * SOAP_FMAC4 soap_in__ns1__UpdateClassRoomPersonStatusResponse(struct soap*, const char*, _ns1__UpdateClassRoomPersonStatusResponse *, const char*);

#ifndef soap_write__ns1__UpdateClassRoomPersonStatusResponse
#define soap_write__ns1__UpdateClassRoomPersonStatusResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "ns1:UpdateClassRoomPersonStatusResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 _ns1__UpdateClassRoomPersonStatusResponse * SOAP_FMAC4 soap_get__ns1__UpdateClassRoomPersonStatusResponse(struct soap*, _ns1__UpdateClassRoomPersonStatusResponse *, const char*, const char*);

#ifndef soap_read__ns1__UpdateClassRoomPersonStatusResponse
#define soap_read__ns1__UpdateClassRoomPersonStatusResponse(soap, data) ( soap_begin_recv(soap) || !soap_get__ns1__UpdateClassRoomPersonStatusResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 _ns1__UpdateClassRoomPersonStatusResponse * SOAP_FMAC2 soap_instantiate__ns1__UpdateClassRoomPersonStatusResponse(struct soap*, int, const char*, const char*, size_t*);

inline _ns1__UpdateClassRoomPersonStatusResponse * soap_new__ns1__UpdateClassRoomPersonStatusResponse(struct soap *soap, int n = -1) { return soap_instantiate__ns1__UpdateClassRoomPersonStatusResponse(soap, n, NULL, NULL, NULL); }

inline _ns1__UpdateClassRoomPersonStatusResponse * soap_new_req__ns1__UpdateClassRoomPersonStatusResponse(struct soap *soap, int UpdateClassRoomPersonStatusResult) { _ns1__UpdateClassRoomPersonStatusResponse *_p = soap_instantiate__ns1__UpdateClassRoomPersonStatusResponse(soap, -1, NULL, NULL, NULL); if (_p) { _p->soap_default(soap); _p->_ns1__UpdateClassRoomPersonStatusResponse::UpdateClassRoomPersonStatusResult = UpdateClassRoomPersonStatusResult; } return _p; }

inline _ns1__UpdateClassRoomPersonStatusResponse * soap_new_set__ns1__UpdateClassRoomPersonStatusResponse(struct soap *soap, int UpdateClassRoomPersonStatusResult) { _ns1__UpdateClassRoomPersonStatusResponse *_p = soap_instantiate__ns1__UpdateClassRoomPersonStatusResponse(soap, -1, NULL, NULL, NULL); if (_p) { _p->soap_default(soap); _p->_ns1__UpdateClassRoomPersonStatusResponse::UpdateClassRoomPersonStatusResult = UpdateClassRoomPersonStatusResult; } return _p; }

inline void soap_delete__ns1__UpdateClassRoomPersonStatusResponse(struct soap *soap, _ns1__UpdateClassRoomPersonStatusResponse *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy__ns1__UpdateClassRoomPersonStatusResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE__ns1__UpdateClassRoomPersonStatus
#define SOAP_TYPE__ns1__UpdateClassRoomPersonStatus (7)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out__ns1__UpdateClassRoomPersonStatus(struct soap*, const char*, int, const _ns1__UpdateClassRoomPersonStatus *, const char*);
SOAP_FMAC3 _ns1__UpdateClassRoomPersonStatus * SOAP_FMAC4 soap_in__ns1__UpdateClassRoomPersonStatus(struct soap*, const char*, _ns1__UpdateClassRoomPersonStatus *, const char*);

#ifndef soap_write__ns1__UpdateClassRoomPersonStatus
#define soap_write__ns1__UpdateClassRoomPersonStatus(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "ns1:UpdateClassRoomPersonStatus", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 _ns1__UpdateClassRoomPersonStatus * SOAP_FMAC4 soap_get__ns1__UpdateClassRoomPersonStatus(struct soap*, _ns1__UpdateClassRoomPersonStatus *, const char*, const char*);

#ifndef soap_read__ns1__UpdateClassRoomPersonStatus
#define soap_read__ns1__UpdateClassRoomPersonStatus(soap, data) ( soap_begin_recv(soap) || !soap_get__ns1__UpdateClassRoomPersonStatus(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 _ns1__UpdateClassRoomPersonStatus * SOAP_FMAC2 soap_instantiate__ns1__UpdateClassRoomPersonStatus(struct soap*, int, const char*, const char*, size_t*);

inline _ns1__UpdateClassRoomPersonStatus * soap_new__ns1__UpdateClassRoomPersonStatus(struct soap *soap, int n = -1) { return soap_instantiate__ns1__UpdateClassRoomPersonStatus(soap, n, NULL, NULL, NULL); }

inline _ns1__UpdateClassRoomPersonStatus * soap_new_req__ns1__UpdateClassRoomPersonStatus(struct soap *soap, int studentCount, time_t updateTime) { _ns1__UpdateClassRoomPersonStatus *_p = soap_instantiate__ns1__UpdateClassRoomPersonStatus(soap, -1, NULL, NULL, NULL); if (_p) { _p->soap_default(soap); _p->_ns1__UpdateClassRoomPersonStatus::studentCount = studentCount; _p->_ns1__UpdateClassRoomPersonStatus::updateTime = updateTime; } return _p; }

inline _ns1__UpdateClassRoomPersonStatus * soap_new_set__ns1__UpdateClassRoomPersonStatus(struct soap *soap, char *account, char *password, char *roomNo, int studentCount, time_t updateTime) { _ns1__UpdateClassRoomPersonStatus *_p = soap_instantiate__ns1__UpdateClassRoomPersonStatus(soap, -1, NULL, NULL, NULL); if (_p) { _p->soap_default(soap); _p->_ns1__UpdateClassRoomPersonStatus::account = account; _p->_ns1__UpdateClassRoomPersonStatus::password = password; _p->_ns1__UpdateClassRoomPersonStatus::roomNo = roomNo; _p->_ns1__UpdateClassRoomPersonStatus::studentCount = studentCount; _p->_ns1__UpdateClassRoomPersonStatus::updateTime = updateTime; } return _p; }

inline void soap_delete__ns1__UpdateClassRoomPersonStatus(struct soap *soap, _ns1__UpdateClassRoomPersonStatus *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy__ns1__UpdateClassRoomPersonStatus(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Fault(soap, data), 0) || soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Fault * soap_new_SOAP_ENV__Fault(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Fault(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Fault * soap_new_req_SOAP_ENV__Fault(struct soap *soap) { struct SOAP_ENV__Fault *_p = soap_instantiate_SOAP_ENV__Fault(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Fault(soap, _p); } return _p; }

inline struct SOAP_ENV__Fault * soap_new_set_SOAP_ENV__Fault(struct soap *soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail) { struct SOAP_ENV__Fault *_p = soap_instantiate_SOAP_ENV__Fault(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Fault(soap, _p); _p->faultcode = faultcode; _p->faultstring = faultstring; _p->faultactor = faultactor; _p->detail = detail; _p->SOAP_ENV__Code = SOAP_ENV__Code; _p->SOAP_ENV__Reason = SOAP_ENV__Reason; _p->SOAP_ENV__Node = SOAP_ENV__Node; _p->SOAP_ENV__Role = SOAP_ENV__Role; _p->SOAP_ENV__Detail = SOAP_ENV__Detail; } return _p; }

inline void soap_delete_SOAP_ENV__Fault(struct soap *soap, struct SOAP_ENV__Fault *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Fault(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (23)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Reason(soap, data), 0) || soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Reason * soap_new_SOAP_ENV__Reason(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Reason(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Reason * soap_new_req_SOAP_ENV__Reason(struct soap *soap) { struct SOAP_ENV__Reason *_p = soap_instantiate_SOAP_ENV__Reason(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Reason(soap, _p); } return _p; }

inline struct SOAP_ENV__Reason * soap_new_set_SOAP_ENV__Reason(struct soap *soap, char *SOAP_ENV__Text) { struct SOAP_ENV__Reason *_p = soap_instantiate_SOAP_ENV__Reason(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Reason(soap, _p); _p->SOAP_ENV__Text = SOAP_ENV__Text; } return _p; }

inline void soap_delete_SOAP_ENV__Reason(struct soap *soap, struct SOAP_ENV__Reason *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Reason(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Detail(soap, data), 0) || soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Detail * soap_new_SOAP_ENV__Detail(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Detail(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Detail * soap_new_req_SOAP_ENV__Detail(struct soap *soap, int __type, void *fault) { struct SOAP_ENV__Detail *_p = soap_instantiate_SOAP_ENV__Detail(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Detail(soap, _p); _p->__type = __type; _p->fault = fault; } return _p; }

inline struct SOAP_ENV__Detail * soap_new_set_SOAP_ENV__Detail(struct soap *soap, char *__any, int __type, void *fault) { struct SOAP_ENV__Detail *_p = soap_instantiate_SOAP_ENV__Detail(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Detail(soap, _p); _p->__any = __any; _p->__type = __type; _p->fault = fault; } return _p; }

inline void soap_delete_SOAP_ENV__Detail(struct soap *soap, struct SOAP_ENV__Detail *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Detail(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Code(soap, data), 0) || soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Code * soap_new_SOAP_ENV__Code(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Code(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Code * soap_new_req_SOAP_ENV__Code(struct soap *soap) { struct SOAP_ENV__Code *_p = soap_instantiate_SOAP_ENV__Code(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Code(soap, _p); } return _p; }

inline struct SOAP_ENV__Code * soap_new_set_SOAP_ENV__Code(struct soap *soap, char *SOAP_ENV__Value, struct SOAP_ENV__Code *SOAP_ENV__Subcode) { struct SOAP_ENV__Code *_p = soap_instantiate_SOAP_ENV__Code(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Code(soap, _p); _p->SOAP_ENV__Value = SOAP_ENV__Value; _p->SOAP_ENV__Subcode = SOAP_ENV__Subcode; } return _p; }

inline void soap_delete_SOAP_ENV__Code(struct soap *soap, struct SOAP_ENV__Code *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Code(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Header(soap, data), 0) || soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Header * soap_new_SOAP_ENV__Header(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Header(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Header * soap_new_req_SOAP_ENV__Header(struct soap *soap) { struct SOAP_ENV__Header *_p = soap_instantiate_SOAP_ENV__Header(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Header(soap, _p); } return _p; }

inline struct SOAP_ENV__Header * soap_new_set_SOAP_ENV__Header(struct soap *soap) { struct SOAP_ENV__Header *_p = soap_instantiate_SOAP_ENV__Header(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Header(soap, _p); } return _p; }

inline void soap_delete_SOAP_ENV__Header(struct soap *soap, struct SOAP_ENV__Header *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Header(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef SOAP_TYPE___ns1__UpdateClassRoomPersonStatus_
#define SOAP_TYPE___ns1__UpdateClassRoomPersonStatus_ (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default___ns1__UpdateClassRoomPersonStatus_(struct soap*, struct __ns1__UpdateClassRoomPersonStatus_ *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize___ns1__UpdateClassRoomPersonStatus_(struct soap*, const struct __ns1__UpdateClassRoomPersonStatus_ *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out___ns1__UpdateClassRoomPersonStatus_(struct soap*, const char*, int, const struct __ns1__UpdateClassRoomPersonStatus_ *, const char*);
SOAP_FMAC3 struct __ns1__UpdateClassRoomPersonStatus_ * SOAP_FMAC4 soap_in___ns1__UpdateClassRoomPersonStatus_(struct soap*, const char*, struct __ns1__UpdateClassRoomPersonStatus_ *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put___ns1__UpdateClassRoomPersonStatus_(struct soap*, const struct __ns1__UpdateClassRoomPersonStatus_ *, const char*, const char*);

#ifndef soap_write___ns1__UpdateClassRoomPersonStatus_
#define soap_write___ns1__UpdateClassRoomPersonStatus_(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize___ns1__UpdateClassRoomPersonStatus_(soap, data), 0) || soap_put___ns1__UpdateClassRoomPersonStatus_(soap, data, "-ns1:UpdateClassRoomPersonStatus", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct __ns1__UpdateClassRoomPersonStatus_ * SOAP_FMAC4 soap_get___ns1__UpdateClassRoomPersonStatus_(struct soap*, struct __ns1__UpdateClassRoomPersonStatus_ *, const char*, const char*);

#ifndef soap_read___ns1__UpdateClassRoomPersonStatus_
#define soap_read___ns1__UpdateClassRoomPersonStatus_(soap, data) ( soap_begin_recv(soap) || !soap_get___ns1__UpdateClassRoomPersonStatus_(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct __ns1__UpdateClassRoomPersonStatus_ * SOAP_FMAC2 soap_instantiate___ns1__UpdateClassRoomPersonStatus_(struct soap*, int, const char*, const char*, size_t*);

inline struct __ns1__UpdateClassRoomPersonStatus_ * soap_new___ns1__UpdateClassRoomPersonStatus_(struct soap *soap, int n = -1) { return soap_instantiate___ns1__UpdateClassRoomPersonStatus_(soap, n, NULL, NULL, NULL); }

inline struct __ns1__UpdateClassRoomPersonStatus_ * soap_new_req___ns1__UpdateClassRoomPersonStatus_(struct soap *soap) { struct __ns1__UpdateClassRoomPersonStatus_ *_p = soap_instantiate___ns1__UpdateClassRoomPersonStatus_(soap, -1, NULL, NULL, NULL); if (_p) { soap_default___ns1__UpdateClassRoomPersonStatus_(soap, _p); } return _p; }

inline struct __ns1__UpdateClassRoomPersonStatus_ * soap_new_set___ns1__UpdateClassRoomPersonStatus_(struct soap *soap, _ns1__UpdateClassRoomPersonStatus *ns1__UpdateClassRoomPersonStatus) { struct __ns1__UpdateClassRoomPersonStatus_ *_p = soap_instantiate___ns1__UpdateClassRoomPersonStatus_(soap, -1, NULL, NULL, NULL); if (_p) { soap_default___ns1__UpdateClassRoomPersonStatus_(soap, _p); _p->ns1__UpdateClassRoomPersonStatus = ns1__UpdateClassRoomPersonStatus; } return _p; }

inline void soap_delete___ns1__UpdateClassRoomPersonStatus_(struct soap *soap, struct __ns1__UpdateClassRoomPersonStatus_ *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy___ns1__UpdateClassRoomPersonStatus_(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE___ns1__UpdateClassRoomPersonStatus
#define SOAP_TYPE___ns1__UpdateClassRoomPersonStatus (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default___ns1__UpdateClassRoomPersonStatus(struct soap*, struct __ns1__UpdateClassRoomPersonStatus *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize___ns1__UpdateClassRoomPersonStatus(struct soap*, const struct __ns1__UpdateClassRoomPersonStatus *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out___ns1__UpdateClassRoomPersonStatus(struct soap*, const char*, int, const struct __ns1__UpdateClassRoomPersonStatus *, const char*);
SOAP_FMAC3 struct __ns1__UpdateClassRoomPersonStatus * SOAP_FMAC4 soap_in___ns1__UpdateClassRoomPersonStatus(struct soap*, const char*, struct __ns1__UpdateClassRoomPersonStatus *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put___ns1__UpdateClassRoomPersonStatus(struct soap*, const struct __ns1__UpdateClassRoomPersonStatus *, const char*, const char*);

#ifndef soap_write___ns1__UpdateClassRoomPersonStatus
#define soap_write___ns1__UpdateClassRoomPersonStatus(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize___ns1__UpdateClassRoomPersonStatus(soap, data), 0) || soap_put___ns1__UpdateClassRoomPersonStatus(soap, data, "-ns1:UpdateClassRoomPersonStatus", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct __ns1__UpdateClassRoomPersonStatus * SOAP_FMAC4 soap_get___ns1__UpdateClassRoomPersonStatus(struct soap*, struct __ns1__UpdateClassRoomPersonStatus *, const char*, const char*);

#ifndef soap_read___ns1__UpdateClassRoomPersonStatus
#define soap_read___ns1__UpdateClassRoomPersonStatus(soap, data) ( soap_begin_recv(soap) || !soap_get___ns1__UpdateClassRoomPersonStatus(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct __ns1__UpdateClassRoomPersonStatus * SOAP_FMAC2 soap_instantiate___ns1__UpdateClassRoomPersonStatus(struct soap*, int, const char*, const char*, size_t*);

inline struct __ns1__UpdateClassRoomPersonStatus * soap_new___ns1__UpdateClassRoomPersonStatus(struct soap *soap, int n = -1) { return soap_instantiate___ns1__UpdateClassRoomPersonStatus(soap, n, NULL, NULL, NULL); }

inline struct __ns1__UpdateClassRoomPersonStatus * soap_new_req___ns1__UpdateClassRoomPersonStatus(struct soap *soap) { struct __ns1__UpdateClassRoomPersonStatus *_p = soap_instantiate___ns1__UpdateClassRoomPersonStatus(soap, -1, NULL, NULL, NULL); if (_p) { soap_default___ns1__UpdateClassRoomPersonStatus(soap, _p); } return _p; }

inline struct __ns1__UpdateClassRoomPersonStatus * soap_new_set___ns1__UpdateClassRoomPersonStatus(struct soap *soap, _ns1__UpdateClassRoomPersonStatus *ns1__UpdateClassRoomPersonStatus) { struct __ns1__UpdateClassRoomPersonStatus *_p = soap_instantiate___ns1__UpdateClassRoomPersonStatus(soap, -1, NULL, NULL, NULL); if (_p) { soap_default___ns1__UpdateClassRoomPersonStatus(soap, _p); _p->ns1__UpdateClassRoomPersonStatus = ns1__UpdateClassRoomPersonStatus; } return _p; }

inline void soap_delete___ns1__UpdateClassRoomPersonStatus(struct soap *soap, struct __ns1__UpdateClassRoomPersonStatus *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy___ns1__UpdateClassRoomPersonStatus(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Reason(soap, data), 0) || soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Detail(soap, data), 0) || soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Code(soap, data), 0) || soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef SOAP_TYPE_PointerTo_ns1__UpdateClassRoomPersonStatus
#define SOAP_TYPE_PointerTo_ns1__UpdateClassRoomPersonStatus (11)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTo_ns1__UpdateClassRoomPersonStatus(struct soap*, _ns1__UpdateClassRoomPersonStatus *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTo_ns1__UpdateClassRoomPersonStatus(struct soap*, const char *, int, _ns1__UpdateClassRoomPersonStatus *const*, const char *);
SOAP_FMAC3 _ns1__UpdateClassRoomPersonStatus ** SOAP_FMAC4 soap_in_PointerTo_ns1__UpdateClassRoomPersonStatus(struct soap*, const char*, _ns1__UpdateClassRoomPersonStatus **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTo_ns1__UpdateClassRoomPersonStatus(struct soap*, _ns1__UpdateClassRoomPersonStatus *const*, const char*, const char*);

#ifndef soap_write_PointerTo_ns1__UpdateClassRoomPersonStatus
#define soap_write_PointerTo_ns1__UpdateClassRoomPersonStatus(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerTo_ns1__UpdateClassRoomPersonStatus(soap, data), 0) || soap_put_PointerTo_ns1__UpdateClassRoomPersonStatus(soap, data, "ns1:UpdateClassRoomPersonStatus", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 _ns1__UpdateClassRoomPersonStatus ** SOAP_FMAC4 soap_get_PointerTo_ns1__UpdateClassRoomPersonStatus(struct soap*, _ns1__UpdateClassRoomPersonStatus **, const char*, const char*);

#ifndef soap_read_PointerTo_ns1__UpdateClassRoomPersonStatus
#define soap_read_PointerTo_ns1__UpdateClassRoomPersonStatus(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTo_ns1__UpdateClassRoomPersonStatus(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif

#define soap_default__QName(soap, a) soap_default_string(soap, a)

SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize__QName(soap, data), 0) || soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_string(soap, data), 0) || soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

/* End of soapH.h */
