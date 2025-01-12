#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelListDeleteDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelListDeleteDelegate : public cocos2d::CCObject, public LevelListDeleteDelegate {
protected:
    std::function<void(LambdaLevelListDeleteDelegate*, int)> m_levelListDeleteFinished;
    std::function<void(LambdaLevelListDeleteDelegate*, int)> m_levelListDeleteFailed;
public:
    void levelListDeleteFinished(int p0) override {
        if (m_levelListDeleteFinished) return m_levelListDeleteFinished(this, p0);
    }
    void levelListDeleteFailed(int p0) override {
        if (m_levelListDeleteFailed) return m_levelListDeleteFailed(this, p0);
    }

    static LambdaLevelListDeleteDelegate* create(
        std::function<void(LambdaLevelListDeleteDelegate*, int)> const& levelListDeleteFinished = [](auto*, auto) {},
        std::function<void(LambdaLevelListDeleteDelegate*, int)> const& levelListDeleteFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaLevelListDeleteDelegate();
        delegate->m_levelListDeleteFinished = levelListDeleteFinished;
        delegate->m_levelListDeleteFailed = levelListDeleteFailed;
        delegate->autorelease();
        return delegate;
    }
};
