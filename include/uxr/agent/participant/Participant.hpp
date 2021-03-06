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

#ifndef UXR_AGENT_PARTICIPANT_HPP_
#define UXR_AGENT_PARTICIPANT_HPP_

#include <uxr/agent/object/XRCEObject.hpp>
#include <unordered_map>
#include <string>
#include <set>

namespace eprosima {
namespace uxr {

class Middleware;

class Participant : public XRCEObject
{
public:
    static std::unique_ptr<Participant> create(const dds::xrce::ObjectId& object_id,
        const dds::xrce::OBJK_PARTICIPANT_Representation& representation,
        Middleware& middleware);

    virtual ~Participant() override;

    Participant(Participant&&) = delete;
    Participant(const Participant&) = delete;
    Participant& operator=(Participant&&) = delete;
    Participant& operator=(const Participant&) = delete;

    void release(ObjectContainer& root_objects) override;
    void tie_object(const dds::xrce::ObjectId& object_id) { tied_objects_.insert(object_id); }
    void untie_object(const dds::xrce::ObjectId& object_id) { tied_objects_.erase(object_id); }
    bool matched(const dds::xrce::ObjectVariant& new_object_rep) const override;
    Middleware& get_middleware() const override { return middleware_; }

private:
    Participant(
        const dds::xrce::ObjectId& id,
        Middleware& middleware);

private:
    std::set<dds::xrce::ObjectId> tied_objects_;
    Middleware& middleware_;
};

} // namespace uxr
} // namespace eprosima

#endif // UXR_AGENT_PARTICIPANT_HPP_
