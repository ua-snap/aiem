#ifndef MODELDATA_H
#define MODELDATA_H

template<class T> class modelData {
        T **dataArray;
public:
        modelData() : dataArray( T() ){
        }
	void setValue( T x, T y, T val ){

	}
	T getValue( T x, T y ){
		return dataArray[x][y];
	}
};

#endif
