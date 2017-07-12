#include "SlashServer.hh"
#include "SlashLog.hh"
#include "SlashConfig.hh"

namespace slash
{

SlashServer::SlashServer(SlashOptions* slash_options,
                         soil::Options* options):
    slash_options_(slash_options)
{
  SLASH_TRACE <<"SlashServer::SlashServer()";

  std::string speed_file = slash_options_->speed_file;
  
  if( !speed_file.empty() )
    speed_file_.reset( new air::MDataFile(speed_file,
                                          slash_options_->instrus_filter) );
  
  md_service_.reset( smack::MDService::createService(options, this) );
}

SlashServer::~SlashServer()
{
  SLASH_TRACE <<"SlashServer::~SlashServer()";
}

void SlashServer::onReceiveNormal(const smack::guava_udp_normal* data)
{
  SLASH_TRACE <<"SlashServer::onReceiveNormal()";

  speed_file_->putData( toSpeedMData(data->m_symbol,
                                     data->m_update_time,
                                     data->m_millisecond) );
}


air::SpeedMData* SlashServer::toSpeedMData(const std::string& instru,
                                           const std::string& update_time,
                                           int update_millisec)
{
  std::auto_ptr<air::SpeedMData> speed_data(new air::SpeedMData());
  
  speed_data->instru = instru;
  speed_data->update_time = update_time;
  speed_data->update_millisec = update_millisec;

  return speed_data.release();
}

};
