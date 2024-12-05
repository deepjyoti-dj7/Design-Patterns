#include <iostream>

class XMLData {
    std::string xmlData;

public:
    XMLData(std::string pXmlData) {
        xmlData = pXmlData;
    }
    std::string getXMLData() {
        return xmlData;
    }
};

class DataAnalyticsTool {
    std::string jsonData;
public:
    DataAnalyticsTool() {}
    DataAnalyticsTool(std::string pJsonData) {
        jsonData = pJsonData;
    }
    virtual void analyzeData() {
        std::cout << "Analyzing data: " << jsonData << std::endl;
    }
};

class Client {
public:
    void ProcessData(DataAnalyticsTool* pDataAnalyticsTool) {
        pDataAnalyticsTool->analyzeData();
    }
};

class Adapter : public DataAnalyticsTool {
    XMLData* xmlData;
public:
    Adapter(XMLData* pXmlData) {
        xmlData = pXmlData;
    }
    void analyzeData() override {
        std::cout << "Converting XML to JSON: " << xmlData->getXMLData() << " -> to Json Data" << std::endl;
        std::cout << "Analyzing the converted JSON Data" << std::endl;
    }
};

int main() {
    XMLData* xmlData = new XMLData("Sample XML Data");
    DataAnalyticsTool* dataAnalyticsTool = new Adapter(xmlData);

    Client* client = new Client();
    client->ProcessData(dataAnalyticsTool);

    return 0;
}