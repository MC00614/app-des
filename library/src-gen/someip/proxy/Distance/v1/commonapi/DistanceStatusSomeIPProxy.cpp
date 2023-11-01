/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/DistanceStatusSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createDistanceStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< DistanceStatusSomeIPProxy>(_address, _connection);
}

void initializeDistanceStatusSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.DistanceStatus:v1_0:DistanceStatus",
        0x1239, 0x567d, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.DistanceStatus:v1_0",
        &createDistanceStatusSomeIPProxy);
}

INITIALIZER(registerDistanceStatusSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeDistanceStatusSomeIPProxy);
}

DistanceStatusSomeIPProxy::DistanceStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          distance_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x814c), CommonAPI::SomeIP::event_id_t(0x814c), CommonAPI::SomeIP::method_id_t(0x2710), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x2711), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr))
{
}

DistanceStatusSomeIPProxy::~DistanceStatusSomeIPProxy() {
    completed_.set_value();
}

DistanceStatusSomeIPProxy::DistanceAttribute& DistanceStatusSomeIPProxy::getDistanceAttribute() {
    return distance_;
}


void DistanceStatusSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> DistanceStatusSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
