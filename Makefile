CC=g++
INCLUDES=-I/home/apbennett/alfresco/include \
	-I/home/apbennett/gipl \
	-I/usr/include/gdal \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/assembler \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/atmosphere \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/data \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/disturb \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/ecodomain \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/inc \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/input \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/lookup \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/output \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/runmodule \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/snowsoil \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/util \
	-I/home/apbennett/DVMDOSTEM/DVMDOSTEM/model/src/vegetation
LDFLAGS=-L/home/apbennett/lib -L/home/apbennett/DVMDOSTEM/DVMDOSTEM/model -L/home/apbennett/gipl
LIBS=-lFrescoCustom -lFrescoFoundation -lGIPL -lPocoFoundation -lPocoXML -lPocoNet -lgdal -lTEM
EXEC=aiem
SRC=/home/apbennett/alfresco/src/StatArray.cpp /home/apbennett/alfresco/src/StatFile.cpp aiem.cpp
all:
	$(CC) $(INCLUDES) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
clean:
	rm aiem
