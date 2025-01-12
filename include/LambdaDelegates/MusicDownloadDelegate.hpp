#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/MusicDownloadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaMusicDownloadDelegate : public cocos2d::CCObject, public MusicDownloadDelegate {
protected:
    std::function<void(LambdaMusicDownloadDelegate*, SongInfoObject*)> m_loadSongInfoFinished;
    std::function<void(LambdaMusicDownloadDelegate*, int, GJSongError)> m_loadSongInfoFailed;
    std::function<void(LambdaMusicDownloadDelegate*, int)> m_downloadSongFinished;
    std::function<void(LambdaMusicDownloadDelegate*, int, GJSongError)> m_downloadSongFailed;
    std::function<void(LambdaMusicDownloadDelegate*)> m_songStateChanged;
    std::function<void(LambdaMusicDownloadDelegate*, int)> m_downloadSFXFinished;
    std::function<void(LambdaMusicDownloadDelegate*, int, GJSongError)> m_downloadSFXFailed;
    std::function<void(LambdaMusicDownloadDelegate*, GJMusicAction)> m_musicActionFinished;
    std::function<void(LambdaMusicDownloadDelegate*, GJMusicAction)> m_musicActionFailed;
public:
    void loadSongInfoFinished(SongInfoObject* p0) override {
        if (m_loadSongInfoFinished) return m_loadSongInfoFinished(this, p0);
    }
    void loadSongInfoFailed(int p0, GJSongError p1) override {
        if (m_loadSongInfoFailed) return m_loadSongInfoFailed(this, p0, p1);
    }
    void downloadSongFinished(int p0) override {
        if (m_downloadSongFinished) return m_downloadSongFinished(this, p0);
    }
    void downloadSongFailed(int p0, GJSongError p1) override {
        if (m_downloadSongFailed) return m_downloadSongFailed(this, p0, p1);
    }
    void songStateChanged() override {
        if (m_songStateChanged) return m_songStateChanged(this);
    }
    void downloadSFXFinished(int p0) override {
        if (m_downloadSFXFinished) return m_downloadSFXFinished(this, p0);
    }
    void downloadSFXFailed(int p0, GJSongError p1) override {
        if (m_downloadSFXFailed) return m_downloadSFXFailed(this, p0, p1);
    }
    void musicActionFinished(GJMusicAction p0) override {
        if (m_musicActionFinished) return m_musicActionFinished(this, p0);
    }
    void musicActionFailed(GJMusicAction p0) override {
        if (m_musicActionFailed) return m_musicActionFailed(this, p0);
    }

    static LambdaMusicDownloadDelegate* create(
        std::function<void(LambdaMusicDownloadDelegate*, SongInfoObject*)> const& loadSongInfoFinished = [](auto*, auto*) {},
        std::function<void(LambdaMusicDownloadDelegate*, int, GJSongError)> const& loadSongInfoFailed = [](auto*, auto, auto) {},
        std::function<void(LambdaMusicDownloadDelegate*, int)> const& downloadSongFinished = [](auto*, auto) {},
        std::function<void(LambdaMusicDownloadDelegate*, int, GJSongError)> const& downloadSongFailed = [](auto*, auto, auto) {},
        std::function<void(LambdaMusicDownloadDelegate*)> const& songStateChanged = [](auto*) {},
        std::function<void(LambdaMusicDownloadDelegate*, int)> const& downloadSFXFinished = [](auto*, auto) {},
        std::function<void(LambdaMusicDownloadDelegate*, int, GJSongError)> const& downloadSFXFailed = [](auto*, auto, auto) {},
        std::function<void(LambdaMusicDownloadDelegate*, GJMusicAction)> const& musicActionFinished = [](auto*, auto) {},
        std::function<void(LambdaMusicDownloadDelegate*, GJMusicAction)> const& musicActionFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaMusicDownloadDelegate();
        delegate->m_loadSongInfoFinished = loadSongInfoFinished;
        delegate->m_loadSongInfoFailed = loadSongInfoFailed;
        delegate->m_downloadSongFinished = downloadSongFinished;
        delegate->m_downloadSongFailed = downloadSongFailed;
        delegate->m_songStateChanged = songStateChanged;
        delegate->m_downloadSFXFinished = downloadSFXFinished;
        delegate->m_downloadSFXFailed = downloadSFXFailed;
        delegate->m_musicActionFinished = musicActionFinished;
        delegate->m_musicActionFailed = musicActionFailed;
        delegate->autorelease();
        return delegate;
    }
};
