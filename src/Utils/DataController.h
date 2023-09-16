#pragma once

#include "../Constants/adjustmentType.h"
#include "../Interfaces/AdjustmentData.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

class DataController
{

public:
    static std::vector<AdjustmentType> GetAdjustmentTypes()
    {
        std::vector<AdjustmentType> types;

        types.push_back(AdjustmentType::isGrayScale);
        types.push_back(AdjustmentType::brightness);
        types.push_back(AdjustmentType::contrast);
        types.push_back(AdjustmentType::saturation);
        types.push_back(AdjustmentType::emboos);
        types.push_back(AdjustmentType::hue);
        types.push_back(AdjustmentType::vibarance);
        types.push_back(AdjustmentType::sharpness);
        types.push_back(AdjustmentType::blur);
        types.push_back(AdjustmentType::noise);
        types.push_back(AdjustmentType::pixelate);
        types.push_back(AdjustmentType::gamma);

        return types;
    }
    static std::pair<std::string, std::map<AdjustmentType, AdjustmentData>> Read(std::string path)
    {
        std::map<AdjustmentType, AdjustmentData> data;
        std::ifstream file(path);
        std::string curImage;
        if (file.is_open())
        {
            file >> curImage;
            int type, value, isApplied;
            while (file >> type >> value >> isApplied)
            {
                AdjustmentData adjustmentData;
                adjustmentData.value = value;
                adjustmentData.isApplied = isApplied;
                data[AdjustmentType(type)] = (adjustmentData);
            }
            file.close();
        }
        return std::make_pair(curImage, data);
    };
    static void Write(std::string path, std::map<AdjustmentType, AdjustmentData> data, std::string curImage)
    {
        auto vectorData = GetAdjustmentTypes();
        std::ofstream file(path);
        if (file.is_open())
        {
            file << curImage << std::endl;
            for (int i = 0; i < data.size(); i++)
            {
                file << (int)vectorData[i] << " " << data[vectorData[i]].value << " " << data[vectorData[i]].isApplied << std::endl;
            }
        };
    }
};