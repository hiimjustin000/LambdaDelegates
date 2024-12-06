#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CustomSongDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaCustomSongDelegate : public cocos2d::CCObject, public CustomSongDelegate {
public:
    std::function<void(int)> m_songIDChanged;
    std::function<int()> m_getActiveSongID;
    std::function<gd::string()> m_getSongFileName;
    std::function<LevelSettingsObject*()> m_getLevelSettings;

    void songIDChanged(int p0) override {
        if (m_songIDChanged) return m_songIDChanged(p0);
    }
    int getActiveSongID() override {
        if (m_getActiveSongID) return m_getActiveSongID();
        return 0;
    }
    gd::string getSongFileName() override {
        if (m_getSongFileName) return m_getSongFileName();
        throw std::runtime_error("Lambda Delegates: CustomSongDelegate::getSongFileName not implemented");
    }
    LevelSettingsObject* getLevelSettings() override {
        if (m_getLevelSettings) return m_getLevelSettings();
        throw std::runtime_error("Lambda Delegates: CustomSongDelegate::getLevelSettings not implemented");
    }

    static LambdaCustomSongDelegate* create(
        std::function<void(int)> const& songIDChanged/* = [](auto) {}*/,
        std::function<int()> const& getActiveSongID/* = []() { return 0; }*/,
        std::function<gd::string()> const& getSongFileName,
        std::function<LevelSettingsObject*()> const& getLevelSettings
    ) {
        auto delegate = new LambdaCustomSongDelegate();
        delegate->m_songIDChanged = songIDChanged;
        delegate->m_getActiveSongID = getActiveSongID;
        delegate->m_getSongFileName = getSongFileName;
        delegate->m_getLevelSettings = getLevelSettings;
        delegate->autorelease();
        return delegate;
    }
};
