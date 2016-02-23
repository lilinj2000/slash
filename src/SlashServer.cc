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
    speed_file_.reset( new air::MDataFile(speed_file) );
  
  md_service_.reset( smack::MDService::createService(options, this) );
}

SlashServer::~SlashServer()
{
  SLASH_TRACE <<"SlashServer::~SlashServer()";
}

void SlashServer::onReceiveNormal(const smack::quote_head* head, smack::quote_normal* data)
{
  SLASH_TRACE <<"SlashServer::onReceiveNormal()";

  speed_file_->putData( toSpeedMData(head->m_symbol,
                                     head->m_update_time,
                                     head->m_millisecond) );
}

void SlashServer::onReceiveSummary(const smack::quote_head* head, smack::quote_summary* data)
{
  SLASH_TRACE <<"SlashServer::onReceiveNormal()";
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
