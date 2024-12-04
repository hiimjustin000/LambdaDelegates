#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelDeleteDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelDeleteDelegate : public cocos2d::CCObject, public LevelDeleteDelegate {
public:
    std::function<void(int)> m_levelDeleteFinished;
    std::function<void(int)> m_levelDeleteFailed;

    void levelDeleteFinished(int p0) override {
        return m_levelDeleteFinished(p0);
    }
    void levelDeleteFailed(int p0) override {
        return m_levelDeleteFailed(p0);
    }

    static LambdaLevelDeleteDelegate* create(
        std::function<void(int)> const& levelDeleteFinished = [](auto) {},
        std::function<void(int)> const& levelDeleteFailed = [](auto) {}
    ) {
        auto delegate = new LambdaLevelDeleteDelegate();
        delegate->m_levelDeleteFinished = levelDeleteFinished;
        delegate->m_levelDeleteFailed = levelDeleteFailed;
        delegate->autorelease();
        return delegate;
    }
};
