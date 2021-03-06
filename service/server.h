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

#ifndef SERVICE_SERVER_H_
#define SERVICE_SERVER_H_

#include <string>

#include "service/options.h"
#include "service/md_data.h"
#include "service/s_service.h"

namespace slash {

class Server : public SCallback {
 public:
  explicit Server(const rapidjson::Document& doc);

  virtual ~Server();

  virtual void onMData(const std::string& instru,
                       const std::string& update_time, int update_millisec,
                       const soil::DateTime& time_stamp);

 protected:
  std::shared_ptr<MData> toSpeedMData(const std::string& instru,
                                      const std::string& update_time,
                                      int update_millisec,
                                      const soil::DateTime& time_stamp);

 private:
  std::unique_ptr<Options> options_;
  std::unique_ptr<MDataFile> speed_file_;
  std::unique_ptr<SService> s_service_;
};

}  // namespace slash

#endif  // SERVICE_SERVER_H_
