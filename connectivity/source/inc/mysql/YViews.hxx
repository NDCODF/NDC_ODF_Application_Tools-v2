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
#ifndef INCLUDED_CONNECTIVITY_SOURCE_INC_MYSQL_YVIEWS_HXX
#define INCLUDED_CONNECTIVITY_SOURCE_INC_MYSQL_YVIEWS_HXX

#include <connectivity/sdbcx/VCollection.hxx>
#include <com/sun/star/sdbc/XDatabaseMetaData.hpp>
namespace connectivity
{
    namespace mysql
    {
        class OViews final : public sdbcx::OCollection
        {
            css::uno::Reference< css::sdbc::XDatabaseMetaData >       m_xMetaData;
            bool m_bInDrop;
            virtual sdbcx::ObjectType createObject(const OUString& _rName) override;
            virtual void impl_refresh() override;
            virtual css::uno::Reference< css::beans::XPropertySet > createDescriptor() override;
            virtual sdbcx::ObjectType appendObject( const OUString& _rForName, const css::uno::Reference< css::beans::XPropertySet >& descriptor ) override;
            virtual void dropObject(sal_Int32 _nPos, const OUString& _sElementName) override;

            void createView( const css::uno::Reference< css::beans::XPropertySet >& descriptor );
        public:
            OViews(const css::uno::Reference< css::sdbc::XDatabaseMetaData >& _rMetaData,::cppu::OWeakObject& _rParent, ::osl::Mutex& _rMutex,
                const ::std::vector< OUString> &_rVector) : sdbcx::OCollection(_rParent, true, _rMutex, _rVector)
                ,m_xMetaData(_rMetaData)
                ,m_bInDrop(false)
            {}

            // only the name is identical to ::cppu::OComponentHelper
            virtual void disposing() override;

            void dropByNameImpl(const OUString& elementName);
        };
    }
}
#endif // INCLUDED_CONNECTIVITY_SOURCE_INC_MYSQL_YVIEWS_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */