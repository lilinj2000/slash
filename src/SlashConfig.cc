#include "SlashConfig.hh"
#include "SlashLog.hh"
#include "smack/MDService.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace slash
{

SlashOptions::SlashOptions():
    config_options_("SlashConfigOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("slash.instrus_filter", po::value<std::string>(&instrus_filter), 
       "instrument")
      ("slash.speed_file", po::value<std::string>(&speed_file), 
       "speed file")

      ("slash.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      ;

  return;
  
}

SlashOptions::~SlashOptions()
{
}

po::options_description* SlashOptions::configOptions()
{
  return &config_options_;
}

SlashConfig::SlashConfig(int argc, char* argv[])
{
  slash_options_.reset(new SlashOptions());

  smack_options_.reset( smack::MDService::createOptions() );
      
  std::auto_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( slash_options_.get() );
  config->registerOptions( smack_options_.get() );

  config->configFile() = "slash.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  SLASH_LOG_INIT( slash_options_->log_cfg );
  
  return;
}

SlashConfig::~SlashConfig()
{
}

};  
