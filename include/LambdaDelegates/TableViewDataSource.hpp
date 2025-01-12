#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TableViewDataSource.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTableViewDataSource : public cocos2d::CCObject, public TableViewDataSource {
protected:
    std::function<int(LambdaTableViewDataSource*, unsigned int, TableView*)> m_numberOfRowsInSection;
    std::function<unsigned int(LambdaTableViewDataSource*, TableView*)> m_numberOfSectionsInTableView;
    std::function<void(LambdaTableViewDataSource*, TableView*, TableViewCellEditingStyle, CCIndexPath&)> m_TableViewCommitCellEditingStyleForRowAtIndexPath;
    std::function<TableViewCell*(LambdaTableViewDataSource*, CCIndexPath&, TableView*)> m_cellForRowAtIndexPath;
public:
    int numberOfRowsInSection(unsigned int p0, TableView* p1) override {
        if (m_numberOfRowsInSection) return m_numberOfRowsInSection(this, p0, p1);
        throw std::runtime_error("Lambda Delegates: TableViewDataSource::numberOfRowsInSection not implemented");
    }
    unsigned int numberOfSectionsInTableView(TableView* p0) override {
        if (m_numberOfSectionsInTableView) return m_numberOfSectionsInTableView(this, p0);
        return 1;
    }
    void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* p0, TableViewCellEditingStyle p1, CCIndexPath& p2) override {
        if (m_TableViewCommitCellEditingStyleForRowAtIndexPath) return m_TableViewCommitCellEditingStyleForRowAtIndexPath(this, p0, p1, p2);
    }
    TableViewCell* cellForRowAtIndexPath(CCIndexPath& p0, TableView* p1) override {
        if (m_cellForRowAtIndexPath) return m_cellForRowAtIndexPath(this, p0, p1);
        throw std::runtime_error("Lambda Delegates: TableViewDataSource::cellForRowAtIndexPath not implemented");
    }

    static LambdaTableViewDataSource* create(
        std::function<int(LambdaTableViewDataSource*, unsigned int, TableView*)> const& numberOfRowsInSection = nullptr,
        std::function<unsigned int(LambdaTableViewDataSource*, TableView*)> const& numberOfSectionsInTableView = [](auto*, auto*) { return 1; },
        std::function<void(LambdaTableViewDataSource*, TableView*, TableViewCellEditingStyle, CCIndexPath&)> const& TableViewCommitCellEditingStyleForRowAtIndexPath = [](auto*, auto*, auto, auto&) {},
        std::function<TableViewCell*(LambdaTableViewDataSource*, CCIndexPath&, TableView*)> const& cellForRowAtIndexPath = nullptr
    ) {
        auto delegate = new LambdaTableViewDataSource();
        delegate->m_numberOfRowsInSection = numberOfRowsInSection;
        delegate->m_numberOfSectionsInTableView = numberOfSectionsInTableView;
        delegate->m_TableViewCommitCellEditingStyleForRowAtIndexPath = TableViewCommitCellEditingStyleForRowAtIndexPath;
        delegate->m_cellForRowAtIndexPath = cellForRowAtIndexPath;
        delegate->autorelease();
        return delegate;
    }
};
