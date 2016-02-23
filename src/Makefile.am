AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = slash
slash_SOURCES = \
	SlashConfig.cc \
	SlashServer.cc \
	Main.cc

slash_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(SMACK_CPPFLAGS) \
		$(AIR_CPPFLAGS)


slash_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(SMACK_LIBADD) \
	$(AIR_LIBADD)


slash_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = SlashConfig.hh \
	SlashServer.hh \
	SlashLog.hh

EXTRA_DIST = env.sh slash.cfg log.cfg

slashdir = $(bindir)
slash_DATA = $(EXTRA_DIST)

