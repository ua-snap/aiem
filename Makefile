CC=g++
#CC=mpicxx
ALFDIR=/home/UA/apbennett/alfresco
GIPLDIR=/home/UA/apbennett/gipl
TEMDIR=/home/UA/apbennett/dvm-dos-tem
BOOST_LIBS=/home/UA/tcarman2/boost_1_55_0/stage/lib
INCLUDES= \
	-I./include \
	-I./src \
	-I/home/UA/apbennett/include \
	-I$(ALFDIR)/include \
	-I$(GIPLDIR) \
	-I/usr/include/gdal \
	-I/home/UA/apbennett/include/jsoncpp \
	-I/home/UA/tcarman2/boost_1_55_0/ \
	-I$(TEMDIR)/src \
	-I$(TEMDIR)/include \
	-I$(TEMDIR)/src/assembler \
	-I$(TEMDIR)/src/atmosphere \
	-I$(TEMDIR)/src/data \
	-I$(TEMDIR)/src/disturb \
	-I$(TEMDIR)/src/ecodomain \
	-I$(TEMDIR)/src/inc \
	-I$(TEMDIR)/src/input \
	-I$(TEMDIR)/src/lookup \
	-I$(TEMDIR)/src/output \
	-I$(TEMDIR)/src/runmodule \
	-I$(TEMDIR)/src/snowsoil \
	-I$(TEMDIR)/src/util \
	-I$(TEMDIR)/src/vegetation
LDFLAGS=-L/home/UA/apbennett/par-alf/lib -L/home/UA/apbennett/lib -L$(BOOST_LIBS) -L$(TEMDIR) -L$(GIPLDIR)
LIBS=-lFrescoAIEM -lPocoFoundation -lPocoXML -lPocoNet -lgdal -lTEM -lgipl -lboost_system \
	-lboost_filesystem -lboost_program_options -lboost_thread -lboost_log -lreadline -lpthread -ljsoncpp
EXEC=aiem
SRC=$(ALFDIR)/src/StatArray.cpp $(ALFDIR)/src/StatFile.cpp src/aiem.cpp src/CoupledData.cpp src/ArgParse.cpp src/main.cpp
all:
	$(CC) $(INCLUDES) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
clean:
	rm aiem
