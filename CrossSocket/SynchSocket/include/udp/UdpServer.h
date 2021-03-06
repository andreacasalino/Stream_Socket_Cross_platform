/**
 * Author:    Andrea Casalino
 * Created:   01.28.2020
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#ifndef _CROSS_SOCKET_UDPSERVER_H_
#define _CROSS_SOCKET_UDPSERVER_H_

#include <udp/UdpConnection.h>

namespace sck::udp {
   /**
    * @brief A UdpServer extends the UdpConnection class, since it has the possibility to deduce the remoteAddress when calling open,
    * by setting as target the first UdpConnection that hits this socket, sending 
    * at least a 1 byte (or more) message.
    * IMPORTANT!!! The first message sent to the server will be lost.
    */
   class UdpServer
      : public UdpConnection {
   public:
      /**
       * @param[in] the port to reserve
       * @param[in] the expected protocol family of the client to accept
       */
      explicit UdpServer(const std::uint16_t& localPort, const sck::Family& protocol = sck::Family::IP_V4);

   private:
      void openSteps() final;
   };
}

#endif