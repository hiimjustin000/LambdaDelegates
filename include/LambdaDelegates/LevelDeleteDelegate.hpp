#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelDeleteDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelDeleteDelegate : public cocos2d::CCObject, public LevelDeleteDelegate {
protected:
    std::function<void(LambdaLevelDeleteDelegate*, int)> m_levelDeleteFinished;
    std::function<void(LambdaLevelDeleteDelegate*, int)> m_levelDeleteFailed;
public:
    void levelDeleteFinished(int p0) override {
        if (m_levelDeleteFinished) return m_levelDeleteFinished(this, p0);
    }
    void levelDeleteFailed(int p0) override {
        if (m_levelDeleteFailed) return m_levelDeleteFailed(this, p0);
    }

    static LambdaLevelDeleteDelegate* create(
        std::function<void(LambdaLevelDeleteDelegate*, int)> const& levelDeleteFinished = [](auto*, auto) {},
        std::function<void(LambdaLevelDeleteDelegate*, int)> const& levelDeleteFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaLevelDeleteDelegate();
        delegate->m_levelDeleteFinished = levelDeleteFinished;
        delegate->m_levelDeleteFailed = levelDeleteFailed;
        delegate->autorelease();
        return delegate;
    }
};
