/**
 * Author:    Andrea Casalino
 * Created:   01.28.2020
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#ifndef _CROSS_SOCKET_MESSANGERCONCRETE_H_
#define _CROSS_SOCKET_MESSANGERCONCRETE_H_

#include <Messanger.h>
#include <utility>
#include <memory>

namespace sck {   
   /**
    * @brief interface to the socket APIs
    */
   class Handler;

    typedef Messanger<
        std::pair<const char*, std::size_t>, 
        std::pair<char*, std::size_t>
        > MessangerConcrete_t;

   class MessangerConcrete
    : public MessangerConcrete_t {
   private:      
       bool send(const std::pair<const char*, std::size_t>& message) final;

      std::size_t receive(std::pair<char*, std::size_t>& message, const std::chrono::milliseconds& timeout) final;
    
        std::chrono::milliseconds actualTimeOut = std::chrono::milliseconds(0);

        std::shared_ptr<Handler> messageChannel;

    protected:
        MessangerConcrete(std::shared_ptr<Handler> messageChannel);
   };
}

#endif