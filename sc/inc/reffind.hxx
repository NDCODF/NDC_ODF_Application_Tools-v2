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

#ifndef INCLUDED_SC_INC_REFFIND_HXX
#define INCLUDED_SC_INC_REFFIND_HXX

#include "address.hxx"

class ScDocument;

class ScRefFinder
{
    OUString maFormula;
    formula::FormulaGrammar::AddressConvention const meConv;
    ScDocument* const mpDoc;
    ScAddress const maPos;
    sal_Int32 mnFound;
    sal_Int32 mnSelStart;
    sal_Int32 mnSelEnd;

public:
    ScRefFinder(
        const OUString& rFormula, const ScAddress& rPos, ScDocument* pDoc,
        formula::FormulaGrammar::AddressConvention eConvP = formula::FormulaGrammar::CONV_OOO );
    ~ScRefFinder();

    const OUString& GetText() const { return maFormula; }
    sal_Int32 GetFound() const { return mnFound; }
    sal_Int32 GetSelStart() const { return mnSelStart; }
    sal_Int32 GetSelEnd() const { return mnSelEnd; }

    void ToggleRel( sal_Int32 nStartPos, sal_Int32 nEndPos );
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */