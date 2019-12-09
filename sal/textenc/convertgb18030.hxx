/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SAL_TEXTENC_CONVERTGB18030_HXX
#define INCLUDED_SAL_TEXTENC_CONVERTGB18030_HXX

#include <sal/config.h>

#include <sal/types.h>

struct ImplGb180302000ToUnicodeRange
{
    sal_Int32 const m_nNonRangeDataIndex;
    sal_uInt32 const m_nFirstLinear;
    sal_uInt32 const m_nPastLinear;
    sal_Unicode const m_nFirstUnicode;
};

struct ImplUnicodeToGb180302000Range
{
    sal_Int32 const m_nNonRangeDataIndex;
    sal_Unicode const m_nFirstUnicode;
    sal_Unicode const m_nLastUnicode;
    sal_uInt32 const m_nFirstLinear;
};

struct ImplGb18030ConverterData
{
    sal_Unicode const * m_pGb18030ToUnicodeData;
    ImplGb180302000ToUnicodeRange const * m_pGb18030ToUnicodeRanges;
    sal_uInt32 const * m_pUnicodeToGb18030Data;
    ImplUnicodeToGb180302000Range const * m_pUnicodeToGb18030Ranges;
};

void * ImplCreateGb18030ToUnicodeContext();

void ImplResetGb18030ToUnicodeContext(void * pContext);

void ImplDestroyGb18030ToUnicodeContext(void * pContext);

sal_Size ImplConvertGb18030ToUnicode(void const * pData,
                                     void * pContext,
                                     char const * pSrcBuf,
                                     sal_Size nSrcBytes,
                                     sal_Unicode * pDestBuf,
                                     sal_Size nDestChars,
                                     sal_uInt32 nFlags,
                                     sal_uInt32 * pInfo,
                                     sal_Size * pSrcCvtBytes);

sal_Size ImplConvertUnicodeToGb18030(void const * pData,
                                     void * pContext,
                                     sal_Unicode const * pSrcBuf,
                                     sal_Size nSrcChars,
                                     char * pDestBuf,
                                     sal_Size nDestBytes,
                                     sal_uInt32 nFlags,
                                     sal_uInt32 * pInfo,
                                     sal_Size * pSrcCvtChars);

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */