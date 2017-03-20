﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using SECtype = SEC.GenericSupport.DataType;

namespace SEC.Nanoeye.NanoColumn
{
    public interface IAIOsem : ISEMController
    {
        SECtype.IControlInt VacuumState { get; }
        SECtype.IControlInt VacuumRuntime { get; }
        SECtype.IControlDouble PiraniGauge { get; }
        SECtype.IControlInt VacuumLastError { get; }
        SECtype.IControlInt VacuumResetCode { get; }

        SECtype.IControlBool HvEnable { get; }
        SECtype.IControlDouble HvElectronGun { get; }
        SECtype.IControlDouble HvGrid { get; }
        SECtype.IControlDouble HvFilament { get; }
        SECtype.IControlDouble HvCollector { get; }
        SECtype.IControlDouble HvPmt { get; }

        SECtype.IControlDouble GunAlignX { get; }
        SECtype.IControlDouble GunAlignY { get; }
        SECtype.IControlDouble GunAlignXRotate { get; }
        SECtype.IControlDouble GunAlignYRotate { get; }
        SECtype.IControlDouble GunAlignAngle { get; }
        SECtype.ITransform2DDouble GunAlignRotationTransfrom { get; }

        SECtype.IControlDouble BeamShiftX { get; }
        SECtype.IControlDouble BeamShiftY { get; }
        SECtype.IControlDouble BeamShiftXRotate { get; }
        SECtype.IControlDouble BeamShiftYRotate { get; }
        SECtype.IControlDouble BeamShiftAngle { get; }
        SECtype.ITransform2DDouble BeamShiftRotationTransfrom { get; }

        SECtype.IControlDouble StigX { get; }
        SECtype.IControlDouble StigXab { get; }
        SECtype.IControlDouble StigXcd { get; }
        SECtype.IControlBool StigXWobbleEnable { get; }
        SECtype.IControlDouble StigXWobbleAmplitude { get; }
        SECtype.IControlDouble StigXWobbleFrequence { get; }
        SECtype.IControlBool StigSyncX { get; }
        SECtype.IControlDouble StigY { get; }
        SECtype.IControlDouble StigYab { get; }
        SECtype.IControlDouble StigYcd { get; }
        SECtype.IControlBool StigYWobbleEnable { get; }
        SECtype.IControlDouble StigYWobbleAmplitude { get; }
        SECtype.IControlDouble StigYWobbleFrequence { get; }
        SECtype.IControlBool StigSyncY { get; }

        SECtype.IControlDouble LensCondenser1 { get; }
        SECtype.IControlInt LensCondenser1Direction { get; }
        SECtype.IControlBool LensCondenser1WobbleEnable { get; }
        SECtype.IControlDouble LensCondenser1WobbleAmplitude { get; }
        SECtype.IControlDouble LensCondenser1WobbleFrequence { get; }

        SECtype.IControlDouble LensCondenser2 { get; }
        SECtype.IControlInt LensCondenser2Direction { get; }
        SECtype.IControlBool LensCondenser2WobbleEnable { get; }
        SECtype.IControlDouble LensCondenser2WobbleAmplitude { get; }
        SECtype.IControlDouble LensCondenser2WobbleFrequence { get; }

        SECtype.IControlDouble LensObjectCoarse { get; }
        SECtype.IControlDouble LensObjectFine { get; }
        SECtype.IControlInt LensObjectDirection { get; }
        SECtype.IControlBool LensObjectWobbleEnable { get; }
        SECtype.IControlDouble LensObjectWobbleAmplitude { get; }
        SECtype.IControlDouble LensObjectWobbleFrequence { get; }

        SECtype.IControlDouble ScanAmplitudeX { get; }
        SECtype.IControlDouble ScanAmplitudeY { get; }
        SECtype.IControlInt ScanFeedbackMode { get; }
        SECtype.IControlDouble ScanMagnificationX { get; }
        SECtype.IControlDouble ScanMagnificationY { get; }
        SECtype.IControlDouble ScanRotation { get; }
        SECtype.ITable ScanMagnificationTable { get; }
        SECtype.IControlDouble ScanDynamicFocus { get; }

        // Mini-SEM에서 추가된 사항

        SECtype.IValue LensWDtable { get; }

        //BSEAmp 추가
        SECtype.IControlDouble BSE_AmpC { get; }
        SECtype.IControlDouble BSE_AmpD { get; }
        SECtype.IControlInt BSE_Amp { get; }

        //Camera 추가
        SECtype.IControlInt VacuumCamera { get; }


        //new Controller
        SECtype.IControlDouble ScanAmpX { get; }
        SECtype.IControlDouble ScanAmpY { get; }
        SECtype.IControlDouble ScanGeoXA { get; }
        SECtype.IControlDouble ScanGeoXB { get; }
        SECtype.IControlDouble ScanGeoYA { get; }
        SECtype.IControlDouble ScanGeoYB { get; }

        SECtype.IControlDouble Scan_AmpXA { get; }
        SECtype.IControlDouble Scan_AmpXB { get; }

        SECtype.IControlDouble Scan_AmpYA { get; }
        SECtype.IControlDouble Scan_AmpYB { get; }

        SECtype.IControlDouble VariableX { get; }
        SECtype.IControlDouble VariableY { get; }

    }
}
