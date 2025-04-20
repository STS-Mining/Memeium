// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024-2025 The Memeium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MEMEIUM_ASSETFILTERPROXY_H
#define MEMEIUM_ASSETFILTERPROXY_H

#include <QSortFilterProxyModel>

class AssetFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit AssetFilterProxy(QObject* parent = 0);

    void setAssetNamePrefix(const QString& assetNamePrefix);
    void setAssetNameContains(const QString& assetNameContains);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const;

private:
    QString assetNamePrefix;
    QString assetNameContains;
};


#endif // MEMEIUM_ASSETFILTERPROXY_H
