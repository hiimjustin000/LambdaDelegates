#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelCommentDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaLevelCommentDelegate : public cocos2d::CCObject, public LevelCommentDelegate {
protected:
    std::function<void(LambdaLevelCommentDelegate*, cocos2d::CCArray*, char const*)> m_loadCommentsFinished;
    std::function<void(LambdaLevelCommentDelegate*, char const*)> m_loadCommentsFailed;
    std::function<void(LambdaLevelCommentDelegate*)> m_updateUserScoreFinished;
    std::function<void(LambdaLevelCommentDelegate*, gd::string, char const*)> m_setupPageInfo;
public:
    void loadCommentsFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadCommentsFinished) return m_loadCommentsFinished(this, p0, p1);
    }
    void loadCommentsFailed(char const* p0) override {
        if (m_loadCommentsFailed) return m_loadCommentsFailed(this, p0);
    }
    void updateUserScoreFinished() override {
        if (m_updateUserScoreFinished) return m_updateUserScoreFinished(this);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        if (m_setupPageInfo) return m_setupPageInfo(this, p0, p1);
    }

    static LambdaLevelCommentDelegate* create(
        std::function<void(LambdaLevelCommentDelegate*, cocos2d::CCArray*, char const*)> const& loadCommentsFinished = [](auto*, auto*, auto const*) {},
        std::function<void(LambdaLevelCommentDelegate*, char const*)> const& loadCommentsFailed = [](auto*, auto const*) {},
        std::function<void(LambdaLevelCommentDelegate*)> const& updateUserScoreFinished = [](auto*) {},
        std::function<void(LambdaLevelCommentDelegate*, gd::string, char const*)> const& setupPageInfo = [](auto*, auto, auto const*) {}
    ) {
        auto delegate = new LambdaLevelCommentDelegate();
        delegate->m_loadCommentsFinished = loadCommentsFinished;
        delegate->m_loadCommentsFailed = loadCommentsFailed;
        delegate->m_updateUserScoreFinished = updateUserScoreFinished;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->autorelease();
        return delegate;
    }
};
