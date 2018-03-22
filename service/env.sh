
node=`uname -n`
home_3rd=~/3rd/${node}

home_boost=$home_3rd/boost
home_fmt=$home_3rd/fmt
home_pcap=$home_3rd/pcap

export LD_LIBRARY_PATH=$home_boost/lib:$home_fmt/lib:$home_pcap/lib

