/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PLRESPONDERMODIFIER_H
#define _PLRESPONDERMODIFIER_H

#include "plModifier.h"
#include "PRP/Message/plMessage.h"

class PLASMA_DLL plResponderModifier : public virtual plSingleModifier {
    CREATABLE(plResponderModifier, kResponderModifier, plSingleModifier)

public:
    class PLASMA_DLL plResponderCmd {
    public:
        plMessage* fMsg;
        int8_t fWaitOn;

        plResponderCmd(plMessage* msg = NULL, int8_t waitOn = -1)
            : fMsg(msg), fWaitOn(waitOn) { }
        ~plResponderCmd() { delete fMsg; }
    };

    class PLASMA_DLL plResponderState {
    public:
        hsTArray<plResponderCmd*> fCmds;
        int8_t fNumCallbacks, fSwitchToState;
        std::map<int8_t, int8_t> fWaitToCmd;

        plResponderState() : fNumCallbacks(0), fSwitchToState(0) { }
        ~plResponderState();

        void addCommand(plMessage* msg, int8_t waitOn);
        void delCommand(size_t idx);
        void clearCommands();
    };

    enum {
        kDetectTrigger = 0x1,
        kDetectUnTrigger = 0x2,
        kSkipFFSound = 0x4
    };

protected:
    hsTArray<plResponderState*> fStates;
    signed char fCurState;
    bool fEnabled;
    unsigned char fFlags;

public:
    plResponderModifier() : fCurState(0), fEnabled(true), fFlags(0) { }
    virtual ~plResponderModifier();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    const hsTArray<plResponderState*>& getStates() const { return fStates; }
    hsTArray<plResponderState*>& getStates() { return fStates; }
    void addState(plResponderState* state) { fStates.append(state); }
    void delState(size_t idx);
    void clearStates();

    bool isEnabled() const { return fEnabled; }
    signed char getCurState() const { return fCurState; }
    unsigned char getFlags() const { return fFlags; }

    void setEnabled(bool enabled) { fEnabled = enabled; }
    void setCurState(signed char state) { fCurState = state; }
    void setFlags(unsigned char flags) { fFlags = flags; }
};


class PLASMA_DLL plResponderEnableMsg : public plMessage {
    CREATABLE(plResponderEnableMsg, kResponderEnableMsg, plMessage)

protected:
    bool fEnable;

public:
    plResponderEnableMsg() : fEnable(true) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    bool getEnable() const { return fEnable; }
    void setEnable(bool enable) { fEnable = enable; }
};

#endif
