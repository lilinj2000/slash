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

#include "service/smack_service.h"
#include "soil/log.h"
#include "soil/date_time.h"

namespace slash {

SmackService::SmackService(const rapidjson::Document& doc, SCallback* callback)
    : callback_(callback) {
  SOIL_TRACE("SmackService::SmackService()");

  md_service_.reset(smack::MDService::create(doc, this));
}

SmackService::~SmackService() {
    SOIL_TRACE("SmackService::~SmackService()");
}

void SmackService::onReceiveNormal(const smack::guava_udp_normal* data) {
  SOIL_TRACE("SmackService::onReceiveNormal()");

  if (callback_) {
    callback_->onMData(data->m_symbol, data->m_update_time,
                       data->m_millisecond,
                       soil::DateTime::now());
  }
}

}  // namespace slash
