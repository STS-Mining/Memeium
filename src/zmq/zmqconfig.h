// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024-2025 The Memeium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MEMEIUM_ZMQ_ZMQCONFIG_H
#define MEMEIUM_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/memeium-config.h"
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"
#include "primitives/transaction.h"

void zmqError(const char* str);

#endif // MEMEIUM_ZMQ_ZMQCONFIG_H
