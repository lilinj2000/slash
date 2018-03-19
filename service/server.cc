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

Server::Server(const rapidjson::Document& doc) {
  SOIL_TRACE("Server::Server()");

  options_.reset(new Options(doc));
  std::string speed_file = options_->speed_file;

  SOIL_DEBUG_PRINT(options_->instrus_filter);

  if (!speed_file.empty()) {
    speed_file_.reset(new MDataFile(speed_file, options_->instrus_filter));
  }

  s_service_.reset(SService::create(doc, this));
}

Server::~Server() { SOIL_TRACE("Server::~Server()"); }

void Server::onMData(const std::string& instru, const std::string& update_time,
                     int update_millisec, const struct timeval* t_pcap) {
  SOIL_TRACE("Server::onMData()");
  if (speed_file_.get()) {
    speed_file_->putData(
        toSpeedMData(instru, update_time, update_millisec, t_pcap));
  }
}

std::shared_ptr<MData> Server::toSpeedMData(const std::string& instru,
                                            const std::string& update_time,
                                            int update_millisec,
                                            const struct timeval* t_pcap) {
  SOIL_TRACE("Server::toSpeedMData()");

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(update_time);
  SOIL_DEBUG_PRINT(update_millisec);

  std::shared_ptr<SpeedMData> speed_data(new SpeedMData());

  speed_data->instru = instru;
  speed_data->update_time = update_time;
  speed_data->update_millisec = update_millisec;
  speed_data->t_pcap = t_pcap;

  return speed_data;
}

}  // namespace slash
