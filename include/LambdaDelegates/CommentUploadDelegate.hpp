#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CommentUploadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCommentUploadDelegate : public cocos2d::CCObject, public CommentUploadDelegate {
public:
    std::function<void(int)> m_commentUploadFinished;
    std::function<void(int, CommentError)> m_commentUploadFailed;
    std::function<void(int, int)> m_commentDeleteFailed;

    void commentUploadFinished(int p0) override {
        if (m_commentUploadFinished) return m_commentUploadFinished(p0);
    }
    void commentUploadFailed(int p0, CommentError p1) override {
        if (m_commentUploadFailed) return m_commentUploadFailed(p0, p1);
    }
    void commentDeleteFailed(int p0, int p1) override {
        if (m_commentDeleteFailed) return m_commentDeleteFailed(p0, p1);
    }

    static LambdaCommentUploadDelegate* create(
        std::function<void(int)> const& commentUploadFinished = [](auto) {},
        std::function<void(int, CommentError)> const& commentUploadFailed = [](auto, auto) {},
        std::function<void(int, int)> const& commentDeleteFailed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaCommentUploadDelegate();
        delegate->m_commentUploadFinished = commentUploadFinished;
        delegate->m_commentUploadFailed = commentUploadFailed;
        delegate->m_commentDeleteFailed = commentDeleteFailed;
        delegate->autorelease();
        return delegate;
    }
};
