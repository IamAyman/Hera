#include <map>
#include <string>
 struct Info
 {
 	int InfoNumber;
 	std::map<string,string> InfoMap;
 	void initInfo();


 };

 void Info::initInfo()
 {
 	InfoMap["name"] = "Luna";
 	InfoMap["creator"] = "Abdeljalil";
 	InfoMap["country"] = "Algeria";
 	InfoNumber = 3;
 }

