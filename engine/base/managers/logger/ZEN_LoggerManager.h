#pragma once

#include<base/ZEN_Types.h>
#include <spdlog/spdlog.h>

class ZEN_LoggerManager {
    public: 
        enum Level {
            LevelError = 0, LevelWarning, LevelInfo
        };

        void SetLevel(Level level) {
            m_LogLevel = level;
        }

        void Info(const char* message) {
            if (m_LogLevel >= LevelInfo)
                spdlog::info(message);
        }
        
        void Warn(const char* message) {
            if (m_LogLevel >= LevelWarning)
                spdlog::warn(message);
        }

        void Error(const char* message) {
            if (m_LogLevel >= LevelError)    
                spdlog::error(message);
        }
    private:
        Level m_LogLevel = LevelInfo;
};