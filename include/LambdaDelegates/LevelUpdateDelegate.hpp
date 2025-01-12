#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelUpdateDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelUpdateDelegate : public cocos2d::CCObject, public LevelUpdateDelegate {
protected:
    std::function<void(LambdaLevelUpdateDelegate*, GJGameLevel*, UpdateResponse)> m_levelUpdateFinished;
    std::function<void(LambdaLevelUpdateDelegate*, int)> m_levelUpdateFailed;
public:
    void levelUpdateFinished(GJGameLevel* p0, UpdateResponse p1) override {
        if (m_levelUpdateFinished) return m_levelUpdateFinished(this, p0, p1);
    }
    void levelUpdateFailed(int p0) override {
        if (m_levelUpdateFailed) return m_levelUpdateFailed(this, p0);
    }

    static LambdaLevelUpdateDelegate* create(
        std::function<void(LambdaLevelUpdateDelegate*, GJGameLevel*, UpdateResponse)> const& levelUpdateFinished = [](auto*, auto*, auto) {},
        std::function<void(LambdaLevelUpdateDelegate*, int)> const& levelUpdateFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaLevelUpdateDelegate();
        delegate->m_levelUpdateFinished = levelUpdateFinished;
        delegate->m_levelUpdateFailed = levelUpdateFailed;
        delegate->autorelease();
        return delegate;
    }
};
