#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJDailyLevelDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJDailyLevelDelegate : public cocos2d::CCObject, public GJDailyLevelDelegate {
public:
    std::function<void(GJTimedLevelType)> m_dailyStatusFinished;
    std::function<void(GJTimedLevelType, GJErrorCode)> m_dailyStatusFailed;

    void dailyStatusFinished(GJTimedLevelType p0) override {
        if (m_dailyStatusFinished) return m_dailyStatusFinished(p0);
    }
    void dailyStatusFailed(GJTimedLevelType p0, GJErrorCode p1) override {
        if (m_dailyStatusFailed) return m_dailyStatusFailed(p0, p1);
    }

    static LambdaGJDailyLevelDelegate* create(
        std::function<void(GJTimedLevelType)> const& dailyStatusFinished = [](auto) {},
        std::function<void(GJTimedLevelType, GJErrorCode)> const& dailyStatusFailed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaGJDailyLevelDelegate();
        delegate->m_dailyStatusFinished = dailyStatusFinished;
        delegate->m_dailyStatusFailed = dailyStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
