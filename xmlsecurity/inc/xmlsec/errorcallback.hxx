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

#ifndef INCLUDED_XMLSECURITY_SOURCE_XMLSEC_ERRORCALLBACK_HXX
#define INCLUDED_XMLSECURITY_SOURCE_XMLSEC_ERRORCALLBACK_HXX

#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/xml/crypto/XXMLSignatureTemplate.hpp>
#include <com/sun/star/xml/crypto/XXMLEncryptionTemplate.hpp>

#include <xsecxmlsecdllapi.h>

// Only used for logging
XSECXMLSEC_DLLPUBLIC void setErrorRecorder();
//ToDo
//void setErrorRecorder(const css::uno::Reference< css::xml::crypto::XXMLEncryptionTemplate >& xTemplate);
XSECXMLSEC_DLLPUBLIC void clearErrorRecorder();

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */