#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CustomSongDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaCustomSongDelegate : public cocos2d::CCObject, public CustomSongDelegate {
protected:
    std::function<void(LambdaCustomSongDelegate*, int)> m_songIDChanged;
    std::function<int(LambdaCustomSongDelegate*)> m_getActiveSongID;
    std::function<gd::string(LambdaCustomSongDelegate*)> m_getSongFileName;
    std::function<LevelSettingsObject*(LambdaCustomSongDelegate*)> m_getLevelSettings;
public:
    void songIDChanged(int p0) override {
        if (m_songIDChanged) return m_songIDChanged(this, p0);
    }
    int getActiveSongID() override {
        if (m_getActiveSongID) return m_getActiveSongID(this);
        return 0;
    }
    gd::string getSongFileName() override {
        if (m_getSongFileName) return m_getSongFileName(this);
        throw std::runtime_error("Lambda Delegates: CustomSongDelegate::getSongFileName not implemented");
    }
    LevelSettingsObject* getLevelSettings() override {
        if (m_getLevelSettings) return m_getLevelSettings(this);
        throw std::runtime_error("Lambda Delegates: CustomSongDelegate::getLevelSettings not implemented");
    }

    static LambdaCustomSongDelegate* create(
        std::function<void(LambdaCustomSongDelegate*, int)> const& songIDChanged = [](auto*, auto) {},
        std::function<int(LambdaCustomSongDelegate*)> const& getActiveSongID = [](auto*) { return 0; },
        std::function<gd::string(LambdaCustomSongDelegate*)> const& getSongFileName = nullptr,
        std::function<LevelSettingsObject*(LambdaCustomSongDelegate*)> const& getLevelSettings = nullptr
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
