// Copyright 2017 The Slash Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -----------------------------------------------------------------------------
// File: [file_name]
// -----------------------------------------------------------------------------
//
// [file_descrition]
//
// Example:
//
//   ... ...
//
//

#include "service/zebra_service.h"
#include "soil/log.h"

namespace slash {

ZebraService::ZebraService(const rapidjson::Document& doc, SCallback* callback)
    : callback_(callback) {
  SOIL_TRACE("ZebraService::ZebraService()");

  service_.reset(zebra::Service::create(doc, this));
}

ZebraService::~ZebraService() { SOIL_TRACE("ZebraService::~ZebraService()"); }

void ZebraService::onReceiveMarketData(const ftdc::MarketDataField* md,
                                       const struct timeval& ts,
                                       const u_char* sp, uint32_t len) {
  SOIL_TRACE("ZebraService::onReceiveMarketData()");

  if (callback_) {
    soil::DateTime tk(std::chrono::system_clock::from_time_t(ts.tv_sec));
    tk += std::chrono::microseconds(ts.tv_usec);
    callback_->onMData(md->updatetime_field.InstrumentID,
                       md->updatetime_field.UpdateTime,
                       md->updatetime_field.UpdateMillisec,
                       tk);
  }
}

}  // namespace slash
