#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJDailyLevelDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJDailyLevelDelegate : public cocos2d::CCObject, public GJDailyLevelDelegate {
protected:
    std::function<void(LambdaGJDailyLevelDelegate*, GJTimedLevelType)> m_dailyStatusFinished;
    std::function<void(LambdaGJDailyLevelDelegate*, GJTimedLevelType, GJErrorCode)> m_dailyStatusFailed;
public:
    void dailyStatusFinished(GJTimedLevelType p0) override {
        if (m_dailyStatusFinished) return m_dailyStatusFinished(this, p0);
    }
    void dailyStatusFailed(GJTimedLevelType p0, GJErrorCode p1) override {
        if (m_dailyStatusFailed) return m_dailyStatusFailed(this, p0, p1);
    }

    static LambdaGJDailyLevelDelegate* create(
        std::function<void(LambdaGJDailyLevelDelegate*, GJTimedLevelType)> const& dailyStatusFinished = [](auto*, auto) {},
        std::function<void(LambdaGJDailyLevelDelegate*, GJTimedLevelType, GJErrorCode)> const& dailyStatusFailed = [](auto*, auto, auto) {}
    ) {
        auto delegate = new LambdaGJDailyLevelDelegate();
        delegate->m_dailyStatusFinished = dailyStatusFinished;
        delegate->m_dailyStatusFailed = dailyStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
