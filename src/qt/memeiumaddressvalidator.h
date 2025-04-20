// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024-2025 The Memeium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MEMEIUM_QT_MEMEIUMADDRESSVALIDATOR_H
#define MEMEIUM_QT_MEMEIUMADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class MemeiumAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MemeiumAddressEntryValidator(QObject* parent);

    State validate(QString& input, int& pos) const;
};

/** Memeium address widget validator, checks for a valid Memeium address.
 */
class MemeiumAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MemeiumAddressCheckValidator(QObject* parent);

    State validate(QString& input, int& pos) const;
};

#endif // MEMEIUM_QT_MEMEIUMADDRESSVALIDATOR_H
