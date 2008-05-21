#ifndef _PFGUICONTROLHANDLERS_H
#define _PFGUICONTROLHANDLERS_H

#include "FeatureLib/pfPRC/pfPrcHelper.h"
#include "FeatureLib/pfPRC/pfPrcParser.h"

DllClass pfGUICtrlProcObject {
public:
    pfGUICtrlProcObject();
    virtual ~pfGUICtrlProcObject();
};

DllClass pfGUIDialogProc : public pfGUICtrlProcObject {
public:
    enum ControlEvt { kExitMode };

protected:
    class pfGUIDialogMod* fDialog;

public:
    pfGUIDialogProc();
    virtual ~pfGUIDialogProc();
};

DllClass pfGUICtrlProcWriteableObject : public pfGUICtrlProcObject {
public:
    enum Types { kNull, kConsoleCmd, kPythonScript, kCloseDlg };

protected:
    unsigned int fType;

public:
    static pfGUICtrlProcWriteableObject* Read(hsStream* S);
    static void Write(hsStream* S, pfGUICtrlProcWriteableObject* proc);
    static void PrcWrite(pfPrcHelper* prc, pfGUICtrlProcWriteableObject* proc);
    static pfGUICtrlProcWriteableObject* PrcParse(const pfPrcTag* tag);

protected:
    virtual void IRead(hsStream* S)=0;
    virtual void IWrite(hsStream* S)=0;
    virtual void IPrcWrite(pfPrcHelper* prc)=0;
    virtual void IPrcParse(const pfPrcTag* tag)=0;
};

DllClass pfGUICloseDlgProc : public pfGUICtrlProcWriteableObject {
public:
    pfGUICloseDlgProc();

protected:
    virtual void IRead(hsStream* S);
    virtual void IWrite(hsStream* S);
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag);
};

DllClass pfGUIConsoleCmdProc : public pfGUICtrlProcWriteableObject {
protected:
    plString fCommand;

public:
    pfGUIConsoleCmdProc();

protected:
    virtual void IRead(hsStream* S);
    virtual void IWrite(hsStream* S);
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag);
};

DllClass pfGUIPythonScriptProc : public pfGUICtrlProcWriteableObject {
public:
     pfGUIPythonScriptProc();

protected:
    virtual void IRead(hsStream* S);
    virtual void IWrite(hsStream* S);
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag);
};

#endif