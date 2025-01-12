#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelManagerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaLevelManagerDelegate : public cocos2d::CCObject, public LevelManagerDelegate {
protected:
    std::function<void(LambdaLevelManagerDelegate*, cocos2d::CCArray*, char const*)> m_loadLevelsFinished1;
    std::function<void(LambdaLevelManagerDelegate*, char const*)> m_loadLevelsFailed1;
    std::function<void(LambdaLevelManagerDelegate*, cocos2d::CCArray*, char const*, int)> m_loadLevelsFinished2;
    std::function<void(LambdaLevelManagerDelegate*, char const*, int)> m_loadLevelsFailed2;
    std::function<void(LambdaLevelManagerDelegate*, gd::string, char const*)> m_setupPageInfo;
public:
    void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadLevelsFinished1) return m_loadLevelsFinished1(this, p0, p1);
    }
    void loadLevelsFailed(char const* p0) override {
        if (m_loadLevelsFailed1) return m_loadLevelsFailed1(this, p0);
    }
    void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1, int p2) override {
        if (m_loadLevelsFinished2) return m_loadLevelsFinished2(this, p0, p1, p2);
    }
    void loadLevelsFailed(char const* p0, int p1) override {
        if (m_loadLevelsFailed2) return m_loadLevelsFailed2(this, p0, p1);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        if (m_setupPageInfo) return m_setupPageInfo(this, p0, p1);
    }

    static LambdaLevelManagerDelegate* create(
        std::function<void(LambdaLevelManagerDelegate*, cocos2d::CCArray*, char const*)> const& loadLevelsFinished1 = [](auto*, auto*, auto const*) {},
        std::function<void(LambdaLevelManagerDelegate*, char const*)> const& loadLevelsFailed1 = [](auto*, auto const*) {},
        std::function<void(LambdaLevelManagerDelegate*, cocos2d::CCArray*, char const*, int)> const& loadLevelsFinished2 = [](auto*, auto*, auto const*, auto) {},
        std::function<void(LambdaLevelManagerDelegate*, char const*, int)> const& loadLevelsFailed2 = [](auto*, auto const*, auto) {},
        std::function<void(LambdaLevelManagerDelegate*, gd::string, char const*)> const& setupPageInfo = [](auto*, auto, auto const*) {}
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
