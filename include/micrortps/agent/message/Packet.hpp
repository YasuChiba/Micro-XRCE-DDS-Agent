// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MICRORTPS_AGENT_MESSAGE_PACKET_HPP_
#define _MICRORTPS_AGENT_MESSAGE_PACKET_HPP_

#include <micrortps/agent/message/InputMessage.hpp>
#include <micrortps/agent/message/OutputMessage.hpp>
#include <memory>

namespace eprosima {
namespace micrortps {

class Server;
class EndPoint;

typedef std::unique_ptr<InputMessage> InputMessagePtr;
struct InputPacket
{
//    Server* server;
    std::shared_ptr<EndPoint> source;
    InputMessagePtr message;
};

typedef std::shared_ptr<OutputMessage> OutputMessagePtr;
struct OutputPacket
{
//    Server* server;
    std::shared_ptr<EndPoint> destination;
    OutputMessagePtr message;
};

} // namespace micrortps
} // namespace eprosima

#endif //_MICRORTPS_AGENT_MESSAGE_PACKET_HPP_