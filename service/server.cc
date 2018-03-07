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

#include "service/server.h"
#include "service/options.h"
#include "soil/log.h"

namespace slash {

Server::Server(
    const rapidjson::Document& doc) {
  SOIL_TRACE("Server::Server()");

  options_.reset(new Options(doc));
  std::string speed_file = options_->speed_file;

  if (!speed_file.empty()) {
    speed_file_.reset(new MDataFile(
        speed_file,
        options_->instrus_filter));
  }

  md_service_.reset(
      smack::MDService::create(doc, this));
}

Server::~Server() {
  SOIL_TRACE("Server::~Server()");
}

void Server::onReceiveNormal(
    const smack::guava_udp_normal* data) {
  SOIL_TRACE("Server::onReceiveNormal()");

  if (speed_file_.get()) {
    speed_file_->putData(
        toSpeedMData(data->m_symbol,
                     data->m_update_time,
                     data->m_millisecond));
  }
}

std::shared_ptr<MData> Server::toSpeedMData(
    const std::string& instru,
    const std::string& update_time,
    int update_millisec) {
  SOIL_TRACE("Server::toSpeedMData()");

  std::shared_ptr<SpeedMData> speed_data(
      new SpeedMData());

  speed_data->instru = instru;
  speed_data->update_time = update_time;
  speed_data->update_millisec = update_millisec;

  return speed_data;
}

}  // namespace slash
