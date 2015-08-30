#include "qh_string.h"

#include <string.h>

namespace qh
{

    string::string() : len_(0){
		data_ = new char[1];
		*data_ = '\0';
	}

    string::string( const char* s ){
    	if(s == NULL) {
    		data_ = new char[1];
    		*data_ = '\0';
    		len_ = 0;
		} else {
			len_ = strlen(s);
			data_ = new char[len_ + 1];
			strcpy(data_, s);
		}
    }

    string::string( const char* s, size_t len ){
    	len_ = len;
    	data_ = new char[len_+1];
    	strncpy(data_, s, len);
    	data_[len_] = '\0';    	
    }

    string::string( const string& rhs ){
    	len_ = strlen(rhs.data());
    	data_ = new char[len_ + 1];
    	strcpy(data_, rhs.data());
    }

    string& string::operator=( const string& rhs ){
    	if(this != &rhs){
    		delete []data_;
    		len_ = rhs.size();
    		data_ = new char[len_ + 1];
    		strcpy(data_, rhs.data());
    	}
       	return *this;
    }

    string::~string(){
    	delete []data_;
    	len_ = 0;
    }

    size_t string::size() const{
        return len_;
    }

    const char* string::data() const{
        return data_;
    }

    const char* string::c_str() const{
        return data_;
    }

    char& string::operator[]( size_t index ){
        return data_[index];
    }
}
