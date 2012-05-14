CC=g++
INCLUDE=-I/home/apbennett/alfresco/include -I/home/apbennett/gipl -I/usr/include/gdal
LDFLAGS=-L/home/apbennett/alfinstalldir/lib -L/home/apbennett/gipl
LIBS=-lFrescoCustom -lFrescoFoundation -lGIPL -lPocoFoundation -lPocoXML -lPocoNet -lgdal
EXEC="aiem"
SRC=~/alfresco/src/StatArray.cpp ~/alfresco/src/StatFile.cpp aiem.cpp
all:
	$(CC) $(INCLUDE) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
