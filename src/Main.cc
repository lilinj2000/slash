#include <memory>

#include "SlashConfig.hh"
#include "SlashServer.hh"
#include "soil/STimer.hh"

int main(int argc, char* argv[])
{

  std::unique_ptr<slash::SlashConfig> config;
  config.reset(new slash::SlashConfig(argc, argv));

  std::unique_ptr<slash::SlashServer> server;
  server.reset(new slash::SlashServer(config->slashOptions(),
                                      config->smackOptions()) );
  
  std::unique_ptr<soil::STimer> cond;
  cond.reset( soil::STimer::create() );

  do
  {
    cond->wait(2000);
  }while(true);
  
  return 0;
}
