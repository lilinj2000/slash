#ifndef SLASH_CONFIG_HH
#define SLASH_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace slash
{

namespace po = boost::program_options;

class SlashOptions : public soil::Options
{
 public:

  SlashOptions();
  
  virtual ~SlashOptions();

  virtual po::options_description* configOptions();

  int udp_port;
  
  std::string instrus_filter;

  std::string speed_file;
  
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class SlashConfig
{
 public:
  
  SlashConfig(int argc=0, char* argv[]=NULL);
  ~SlashConfig();

  SlashOptions* slashOptions()
  {
    return slash_options_.get();
  }

  soil::Options* smackOptions()
  {
    return smack_options_.get();
  }


 private:
  std::unique_ptr<SlashOptions> slash_options_;

  std::unique_ptr<soil::Options> smack_options_;
  
};

}  


#endif 
