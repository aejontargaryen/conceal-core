// Copyright (c) 2011-2017 The Cryptonote Developers
// Copyright (c) 2018 The Circle Foundation
//
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x7ad4; // addresses start with "ccx7"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10; // 20m unlock
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2; // 2 hours
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE           = 10; // 20m unlock

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

const uint64_t MONEY_SUPPLY                                  = UINT64_C(200000000000000); // max supply: 200M (Consensus II)

const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                   = 0;
const size_t   ZAWY_DIFFICULTY_FIX                           = 1;
const uint8_t  ZAWY_DIFFICULTY_BLOCK_VERSION                 = 0;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; // size of block (bytes): after which reward is calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 6;

// COIN - number of smallest units in one coin
const uint64_t POINT                                         = UINT64_C(1000);     // pow(10, 3)
const uint64_t COIN                                          = UINT64_C(1000000);  // pow(10, 6)
const uint64_t MINIMUM_FEE                                   = UINT64_C(10);       // pow(10, 1)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(10);       // pow(10, 1)

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds = 2m
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V1                          = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2                          = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_CUT                                = 60; // timestamps to cut after sorting
const size_t   DIFFICULTY_CUT_V1                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG                                = 15; // !!!
const size_t   DIFFICULTY_LAG_V1                             = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2                             = DIFFICULTY_LAG;

static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT                            = 1 * COIN; // minimun mmount for a valid deposit
const uint32_t DEPOSIT_MIN_TERM                              = 21900; // ~1 month
const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * 21900; // ~1 year
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0; // rate is constant
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 4; // percentage rate for DEPOSIT_MAX_TERM

static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR                             = 100;
const uint32_t END_MULTIPLIER_BLOCK                          = 12750;

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const size_t   CRYPTONOTE_MAX_TX_SIZE_LIMIT                  = (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;
const size_t   CRYPTONOTE_CONSOLIDATE_SIZE                   = 100; // proportional to CRYPTONOTE_MAX_TX_SIZE_LIMIT

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 12); // seconds, 12 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); // seconds, 1 day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_MAX_TX_SIZE_LIMIT * 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint64_t UPGRADE_HEIGHT                                = 1;
const uint64_t UPGRADE_HEIGHT_V2                             = 1;
const uint64_t UPGRADE_HEIGHT_V3                             = 12750; // Consensus III - block for CN Orion fork
const uint64_t UPGRADE_HEIGHT_V4                             = 45000; // block for minimum mixin fork
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";

} // parameters

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(5000) * parameters::POINT); // start reward (Consensus I)
const uint64_t FOUNDATION_TRUST	                             = (UINT64_C(12000000) * parameters::COIN); // locked funds to secure network  (Consensus II)
const uint64_t MAX_BLOCK_REWARD                              = (UINT64_C(20) * parameters::COIN); // max reward (Consensus I)
const uint64_t REWARD_INCREASE_INTERVAL                      = (UINT64_C(21900)); // aprox. 1 month (+ 0.25 CCX increment per month)

const char     CRYPTONOTE_NAME[]                             = "conceal";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001c096b102029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121017d6775185749e95ac2d70cae3f29e0e46f430ab648abbe9fdc61d8e7437c60f8";
const uint32_t GENESIS_NONCE                                 = 10000;
const uint64_t GENESIS_TIMESTAMP                             = 1527078920;

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1; // (Consensus I)
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2; // (Consensus II)
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3; // (Consensus III)
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        = 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            = 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         = 1000;

const int      P2P_DEFAULT_PORT                              = 15000;
const int      RPC_DEFAULT_PORT                              = 16000;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 = 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70; // percent
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60; // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000; // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000; // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "f7061e9a5f0d30549afde49c9bfbaa52ac60afdc46304642b460a9ea34bf7a4e";

// Seed Nodes
const std::initializer_list<const char*> SEED_NODES = {
		"212.237.59.97:15000",
		"94.177.171.102:15000",
		"93.186.254.77:15000"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// Blockchain Checkpoints:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
		{0, "b9dc432e56e37b52771970ce014dd23fda517cfd4fc5a9b296f1954b7d4505de"},
		{1000, "52ba463c6b6fbfd88765f50bb79761313091b585ed4a182a91fcf209c55ccb9f"},
		{2000, "b2f2d356cfc4acb3a5a9bb643a0d28059919d26101f46178262fc9c466321c4c"},
		{3000, "48013304f58d8b10882f7a1c265e5f307e453b44ab33ba5b9ea2a6565e993377"},
		{4000, "af92aac58e3ecf03ccd5118f920893fa4ff9207f650282d5fb439d18d53fe928"},
		{5000, "5fdf72e7c106d429231fb980bc336e736464403dee77c7c5ef5e87305644965d"},
		{6000, "acb8e16f4117763bccf966ad2a3af2f522246437c8be8956d1f145693a245b04"},
		{7000, "072a845b3113be159c2a79b8bb1206612b58a6e5395f2e449ddaf6941b660416"},
		{8000, "34cb847e7313e3a316d4eb4c017389f967da5d85573365ae0dec0e5bacddcfba"},
		{9000, "70f4fe7652d504b77bd459d76cc86ff78b15aab69f81567c70cafb5e25e43ffb"},
		{10000, "55cf271a5c97785fb35fea7ed177cb75f47c18688bd86fc01ae66508878029d6"},
		{11000, "eb4b3b4e3711ff132710392703d18eaffdfc044567447dae67ecd11a9799da68"},
		{12000, "b294a435ef3b39859a66ba90684c09c5c7ebf2bf647aaeabbd0be981b6d1f7a0"},
		{13000, "c3b566eb6e9f8e2a839d3f44b8351704a1f9a89b1b00b05155027217f094c787"},
		{14000, "72a7ba07f083af608cd19e20b5abd9dfc7d1fcc9a939efbd1586aa6ef51580d7"},
		{15000, "bbd63d8be2087567cefa44ff50a7d240a2b734be3efb26bfccc5391cbcb9e5ec"},
		{16000, "34d2aaecaa7ee8aae611df7e7fca44fd714cce91bd4b921eeccd8102ccb2f8ef"},
		{17000, "77c4f05c8f4269e3f0c631c3906751a96f33c9ed172929fdd7eba9446237a7ea"},
		{18000, "f752de14adeaaf230908582ab16657390c712902ba8436c8b8d2975695f03f99"},
		{19000, "9b61c4678ed84f4116bd0213efb6c84e24e67ae9c69c66430a8dd4f1fedc41ec"},
		{20000, "52533de7f1596154c6954530ae8331fe4f92e92d476f097c6d7d20ebab1c2748"},
		{21000, "8d3b8b2bce9a9d835fc4fa8c3502ddfaaca7ce0db90670eda49598b221ece835"},
		{22000, "f9fe323b236900c3917dd9b90e5df0aa36d43aa498a9d3f2558607f5cd7bf6b8"},
		{23000, "af81476fee85d2c608f78de6f8090be8d0438000492ed45df019648305539afd"}
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
