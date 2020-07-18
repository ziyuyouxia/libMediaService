#ifndef __MK_RTSP_RTP_UDP_HANDLE_H__
#define __MK_RTSP_RTP_UDP_HANDLE_H__

#include <list>
#include "as.h"

class mk_rtsp_rtp_udp_observer
{
public:
    mk_rtsp_rtp_udp_observer();
    virtual ~mk_rtsp_rtp_udp_observer();
    virtual int32_t handle_rtp_packet(char* pData,uint32_t len) = 0;
}

class mk_rtsp_rtp_udp_handle: public as_udp_sock_handle
{
public:
    mk_rtsp_rtp_udp_handle(uint32_t idx);
    virtual ~mk_rtsp_rtp_udp_handle();
public:
    uint32_t get_index();
    int32_t set_observer(mk_rtsp_rtp_udp_observer* pObserver);
public:
    /* override as_udp_sock_handle */
    virtual void handle_recv(void);
    virtual void handle_send(void);
private:
    mk_rtsp_rtp_udp_observer* m_RtpObserver;
    uint32_t                  m_ulIdx;
};

class mk_rtsp_rtcp_udp_handle: public as_udp_sock_handle
{
public:
    mk_rtsp_rtcp_udp_handle(uint32_t idx);
    virtual ~mk_rtsp_rtcp_udp_handle();
public:
    uint32_t get_index();
public:
    /* override as_udp_sock_handle */
    virtual void handle_recv(void);
    virtual void handle_send(void);
private:
    uint32_t                  m_ulIdx;
};
#endif /* __MK_RTSP_RTP_UDP_HANDLE_H__ */

