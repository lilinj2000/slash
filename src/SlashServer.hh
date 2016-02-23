#ifndef SLASH_SERVER_HH
#define SLASH_SERVER_HH

#include "smack/MDService.hh"
#include "air/MDataFile.hh"

namespace slash
{

class SlashOptions;

class SlashServer : public smack::MDServiceCallback
{
 public:
  SlashServer(SlashOptions* slash_options,
              soil::Options* options);

  virtual ~SlashServer();
  
 protected:
  
  virtual void onReceiveNormal(const smack::quote_head*, smack::quote_normal* data);

  virtual void onReceiveSummary(const smack::quote_head*, smack::quote_summary* data);

  air::SpeedMData* toSpeedMData(const std::string& instru,
                                const std::string& update_time,
                                int update_millisec);

 private:

  SlashOptions* slash_options_;
  
  std::unique_ptr<smack::MDService> md_service_;

  std::unique_ptr<air::MDataFile> speed_file_;

};

};

#endif
