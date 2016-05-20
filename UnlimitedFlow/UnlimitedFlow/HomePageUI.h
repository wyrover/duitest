#pragma once

class CHomePageUI : public CContainerUI
{
public:
    CHomePageUI();
    ~CHomePageUI();

    virtual LPCTSTR GetClass() const override { return _T("HomePageUI"); };
    virtual LPVOID GetInterface(LPCTSTR pstrName) override;

    virtual void DoInit() override;

    virtual void DoEvent(TEventUI& event) override;

};

