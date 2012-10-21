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

#ifndef _PLAVSEEKMSG_H
#define _PLAVSEEKMSG_H

#include "plAvTaskMsg.h"
#include "Math/hsGeometry3.h"

class PLASMA_DLL plAvSeekMsg : public plAvTaskMsg {
    CREATABLE(plAvSeekMsg, kAvSeekMsg, plAvTaskMsg)

public:
    enum Alignment {
        kAlignHandle, kAlignHandleAnimEnd, kAlignWorld, kAlignBone,
        kAlignBoneAnimEnd,
    };

    enum {
        kSeekFlagUnForce3rdPersonOnFinish = 0x1,
        kSeekFlagForce3rdPersonOnStart = 0x2,
        kSeekFlagNoWarpOnTimeout = 0x4,
        kSeekFlagRotationOnly = 0x8,
    };

private:
    plKey fSeekPoint;
    hsVector3 fTargetPos, fTargetLookAt;
    float fDuration;
    bool fSmartSeek, fNoSeek;
    unsigned short fAlignType;
    unsigned char fFlags;
    plString fAnimName;
    plKey fFinishKey;

public:
    plAvSeekMsg() : fDuration(0.0f), fSmartSeek(true), fNoSeek(false),
                    fAlignType(kAlignHandle), fFlags(kSeekFlagForce3rdPersonOnStart) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};


class PLASMA_DLL plAvOneShotMsg : public plAvSeekMsg {
    CREATABLE(plAvOneShotMsg, kAvOneShotMsg, plAvSeekMsg)

private:
    plString fAnimName;
    bool fDrivable, fReversible;

public:
    plAvOneShotMsg() : fDrivable(false), fReversible(false) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

#endif
