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

#ifndef SERVICE_ZEBRA_SERVICE_H_
#define SERVICE_ZEBRA_SERVICE_H_

#include <string>
#include "service/s_service.h"
#include "zebra/service.h"

namespace slash {

class ZebraService : public SService, public zebra::ServiceCallback {
 public:
  explicit ZebraService(const rapidjson::Document& doc, SCallback* callback);

  virtual ~ZebraService();

  virtual void onReceiveMarketData(const ftdc::MarketDataField* md,
                                   const struct timeval& ts, const u_char* sp,
                                   uint32_t len);

 private:
  std::unique_ptr<zebra::Service> service_;

  SCallback* callback_;
};

}  // namespace slash

#endif  // SERVICE_ZEBRA_SERVICE_H_
