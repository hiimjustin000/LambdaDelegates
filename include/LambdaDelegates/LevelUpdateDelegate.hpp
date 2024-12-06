#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelUpdateDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelUpdateDelegate : public cocos2d::CCObject, public LevelUpdateDelegate {
public:
    std::function<void(GJGameLevel*, UpdateResponse)> m_levelUpdateFinished;
    std::function<void(int)> m_levelUpdateFailed;

    void levelUpdateFinished(GJGameLevel* p0, UpdateResponse p1) override {
        if (m_levelUpdateFinished) return m_levelUpdateFinished(p0, p1);
    }
    void levelUpdateFailed(int p0) override {
        if (m_levelUpdateFailed) return m_levelUpdateFailed(p0);
    }

    static LambdaLevelUpdateDelegate* create(
        std::function<void(GJGameLevel*, UpdateResponse)> const& levelUpdateFinished = [](auto, auto) {},
        std::function<void(int)> const& levelUpdateFailed = [](auto) {}
    ) {
        auto delegate = new LambdaLevelUpdateDelegate();
        delegate->m_levelUpdateFinished = levelUpdateFinished;
        delegate->m_levelUpdateFailed = levelUpdateFailed;
        delegate->autorelease();
        return delegate;
    }
};
