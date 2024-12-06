#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelListDeleteDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelListDeleteDelegate : public cocos2d::CCObject, public LevelListDeleteDelegate {
public:
    std::function<void(int)> m_levelListDeleteFinished;
    std::function<void(int)> m_levelListDeleteFailed;

    void levelListDeleteFinished(int p0) override {
        if (m_levelListDeleteFinished) return m_levelListDeleteFinished(p0);
    }
    void levelListDeleteFailed(int p0) override {
        if (m_levelListDeleteFailed) return m_levelListDeleteFailed(p0);
    }

    static LambdaLevelListDeleteDelegate* create(
        std::function<void(int)> const& levelListDeleteFinished = [](auto) {},
        std::function<void(int)> const& levelListDeleteFailed = [](auto) {}
    ) {
        auto delegate = new LambdaLevelListDeleteDelegate();
        delegate->m_levelListDeleteFinished = levelListDeleteFinished;
        delegate->m_levelListDeleteFailed = levelListDeleteFailed;
        delegate->autorelease();
        return delegate;
    }
};
