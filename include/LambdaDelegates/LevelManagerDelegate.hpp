#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelManagerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaLevelManagerDelegate : public cocos2d::CCObject, public LevelManagerDelegate {
public:
    std::function<void(cocos2d::CCArray*, char const*)> m_loadLevelsFinished1;
    std::function<void(char const*)> m_loadLevelsFailed1;
    std::function<void(cocos2d::CCArray*, char const*, int)> m_loadLevelsFinished2;
    std::function<void(char const*, int)> m_loadLevelsFailed2;
    std::function<void(gd::string, char const*)> m_setupPageInfo;

    void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1) override {
        return m_loadLevelsFinished1(p0, p1);
    }
    void loadLevelsFailed(char const* p0) override {
        return m_loadLevelsFailed1(p0);
    }
    void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1, int p2) override {
        return m_loadLevelsFinished2(p0, p1, p2);
    }
    void loadLevelsFailed(char const* p0, int p1) override {
        return m_loadLevelsFailed2(p0, p1);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        return m_setupPageInfo(p0, p1);
    }

    static LambdaLevelManagerDelegate* create(
        std::function<void(cocos2d::CCArray*, char const*)> const& loadLevelsFinished1 = [](auto, auto) {},
        std::function<void(char const*)> const& loadLevelsFailed1 = [](auto) {},
        std::function<void(cocos2d::CCArray*, char const*, int)> const& loadLevelsFinished2 = [](auto, auto, auto) {},
        std::function<void(char const*, int)> const& loadLevelsFailed2 = [](auto, auto) {},
        std::function<void(gd::string, char const*)> const& setupPageInfo = [](auto, auto) {}
    ) {
        auto delegate = new LambdaLevelManagerDelegate();
        delegate->m_loadLevelsFinished1 = loadLevelsFinished1;
        delegate->m_loadLevelsFailed1 = loadLevelsFailed1;
        delegate->m_loadLevelsFinished2 = loadLevelsFinished2;
        delegate->m_loadLevelsFailed2 = loadLevelsFailed2;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->autorelease();
        return delegate;
    }
};
