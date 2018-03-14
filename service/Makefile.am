AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = slash
slash_SOURCES = \
	md_data.cc \
	options.cc \
	smack_service.cc \
	zebra_service.cc \
	s_service.cc \
	server.cc \
	main.cc

slash_CPPFLAGS =  \
	-I$(top_srcdir) \
	$(BOOST_CPPFLAGS) \
	$(RAPIDJSON_CPPFLAGS) \
	$(FMT_CPPFLAGS) \
	$(SPDLOG_CPPFLAGS) \
	$(READERWRITERQUEUE_CPPFLAGS) \
	$(SOIL_CPPFLAGS) \
	$(SMACK_CPPFLAGS) \
	$(ZEBRA_CPPFLAGS) \
	$(ARGS_CPPFLAGS)

slash_LDADD = \
	$(BOOST_LIBADD) \
	$(FMT_LIBADD) \
	$(SOIL_LIBADD) \
	$(SMACK_LIBADD) \
	$(ZEBRA_LIBADD)


slash_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = \
	md_data.h \
	smack_service.h \
	zebra_service.h \
	s_service.h \
	options.h \
	server.h

EXTRA_DIST = env.sh smack.json zebra.json

slashdir = $(bindir)
slash_DATA = $(EXTRA_DIST)

