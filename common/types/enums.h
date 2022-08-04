#ifndef TYPES_ENUMS_H
#define TYPES_ENUMS_H

#include <QString>
#include "utils/protobuf_includes.h"

const int MTU_OFFSET_OPENVPN = 40;
const int MTU_OFFSET_IKEV2 = 80;
const int MTU_OFFSET_WG = 80;


enum PROXY_OPTION {
    PROXY_OPTION_NONE = 0,
    PROXY_OPTION_AUTODETECT = 1,
    PROXY_OPTION_HTTP = 2,
    PROXY_OPTION_SOCKS = 3
};

enum INIT_HELPER_RET { INIT_HELPER_SUCCESS, INIT_HELPER_FAILED, INIT_HELPER_USER_CANCELED };

enum LOGIN_RET {
    LOGIN_RET_SUCCESS = 0,
    LOGIN_RET_NO_API_CONNECTIVITY = 1,
    LOGIN_RET_NO_CONNECTIVITY = 2,
    LOGIN_RET_INCORRECT_JSON = 3,
    LOGIN_RET_BAD_USERNAME = 4,
    LOGIN_RET_PROXY_AUTH_NEED = 5,
    LOGIN_RET_SSL_ERROR = 6,
    LOGIN_RET_BAD_CODE2FA = 7,
    LOGIN_RET_MISSING_CODE2FA = 8,
    LOGIN_RET_ACCOUNT_DISABLED = 9,
    LOGIN_RET_SESSION_INVALID = 10
};

enum LOGIN_MESSAGE {
    LOGIN_MESSAGE_NONE = 0,
    LOGIN_MESSAGE_TRYING_BACKUP1 = 1,
    LOGIN_MESSAGE_TRYING_BACKUP2 = 2
};

enum SERVER_API_RET_CODE { SERVER_RETURN_SUCCESS, SERVER_RETURN_NETWORK_ERROR, SERVER_RETURN_INCORRECT_JSON, SERVER_RETURN_BAD_USERNAME,
                           SERVER_RETURN_PROXY_AUTH_FAILED, SERVER_RETURN_SSL_ERROR, SERVER_RETURN_API_NOT_READY,
                           SERVER_RETURN_MISSING_CODE2FA, SERVER_RETURN_BAD_CODE2FA, SERVER_RETURN_WIREGUARD_KEY_LIMIT,
                           SERVER_RETURN_ACCOUNT_DISABLED, SERVER_RETURN_SESSION_INVALID };

enum ENGINE_INIT_RET_CODE { ENGINE_INIT_SUCCESS, ENGINE_INIT_HELPER_FAILED, ENGINE_INIT_BFE_SERVICE_FAILED, ENGINE_INIT_HELPER_USER_CANCELED };

enum CONNECT_STATE {
    CONNECT_STATE_DISCONNECTED = 0,
    CONNECT_STATE_CONNECTED = 1,
    CONNECT_STATE_CONNECTING = 2,
    CONNECT_STATE_DISCONNECTING = 3
};

enum DISCONNECT_REASON {
    DISCONNECTED_ITSELF = 0,
    DISCONNECTED_BY_USER = 1,
    DISCONNECTED_BY_RECONNECTION_TIMEOUT_EXCEEDED = 2,
    DISCONNECTED_WITH_ERROR = 3
};

enum CONNECT_ERROR  {
  NO_CONNECT_ERROR = 0,
  AUTH_ERROR = 1,
  COULD_NOT_FETCH_CREDENTAILS = 2,
  LOCATION_NOT_EXIST = 3,
  LOCATION_NO_ACTIVE_NODES = 4,
  CANT_RESOLVE_HOSTNAME = 5,
  CONNECTION_BLOCKED = 6,
  NO_OPENVPN_SOCKET = 7,
  CANT_RUN_OPENVPN = 8,
  CANNOT_ALLOCATE_TUN_TAP = 9,
  NO_INSTALLED_TUN_TAP = 10,
  ALL_TAP_IN_USE = 11,
  CANNOT_CONNECT_TO_SERVICE_PIPE = 12,
  CANNOT_WRITE_TO_SERVICE_PIPE = 13,
  NO_AVAILABLE_PORT = 14,
  PROXY_AUTH_ERROR = 15,
  UDP_CANT_ASSIGN = 16,
  CONNECTED_ERROR = 17,
  INITIALIZATION_SEQUENCE_COMPLETED_WITH_ERRORS = 18,
  UDP_NO_BUFFER_SPACE = 19,
  UDP_NETWORK_DOWN = 20,
  TCP_ERROR = 21,
  CANNOT_OPEN_CUSTOM_CONFIG = 22,
  IKEV_FAILED_TO_CONNECT = 23,
  IKEV_NOT_FOUND_WIN = 24,
  IKEV_FAILED_SET_ENTRY_WIN = 25,
  IKEV_FAILED_MODIFY_HOSTS_WIN = 26,
  IKEV_NETWORK_EXTENSION_NOT_FOUND_MAC = 27,
  IKEV_FAILED_SET_KEYCHAIN_MAC = 28,
  IKEV_FAILED_START_MAC = 29,
  IKEV_FAILED_LOAD_PREFERENCES_MAC = 30,
  IKEV_FAILED_SAVE_PREFERENCES_MAC = 31,
  WIREGUARD_CONNECTION_ERROR = 32,
  EMERGENCY_FAILED_CONNECT = 33,
  WINTUN_OVER_CAPACITY = 34,
  WINTUN_DRIVER_REINSTALLATION_ERROR = 35,
  TAP_DRIVER_REINSTALLATION_ERROR = 36,
  WINTUN_FATAL_ERROR = 37,
  EXE_VERIFY_WSTUNNEL_ERROR = 38,
  EXE_VERIFY_STUNNEL_ERROR = 39,
  EXE_VERIFY_OPENVPN_ERROR = 40,
  EXE_VERIFY_WIREGUARD_ERROR = 41
};

enum PROXY_SHARING_TYPE {
    PROXY_SHARING_HTTP = 0,
    PROXY_SHARING_SOCKS = 1
};

enum ORDER_LOCATIONS_TYPE {
    ORDER_LOCATIONS_BY_GEOGRAPHY = 0,
    ORDER_LOCATIONS_BY_ALPHABETICALLY = 1,
    ORDER_LOCATIONS_BY_LATENCY = 2
};

enum DNS_POLICY_TYPE {
    DNS_TYPE_OS_DEFAULT = 0,
    DNS_TYPE_OPEN_DNS = 1,
    DNS_TYPE_CLOUDFLARE = 2,
    DNS_TYPE_GOOGLE = 3,
    DNS_TYPE_CONTROLD = 4
};

enum UPDATE_CHANNEL {
    UPDATE_CHANNEL_RELEASE = 0,
    UPDATE_CHANNEL_BETA = 1,
    UPDATE_CHANNEL_GUINEA_PIG = 2,
    UPDATE_CHANNEL_INTERNAL = 3
};

enum FIREWALL_MODE {
    FIREWALL_MODE_MANUAL = 0,
    FIREWALL_MODE_AUTOMATIC = 1,
    FIREWALL_MODE_ALWAYS_ON =2
};

enum FIREWALL_WHEN {
    FIREWALL_WHEN_BEFORE_CONNECTION = 0,
    FIREWALL_WHEN_AFTER_CONNECTION = 1
};

enum NETWORK_INTERACE_TYPE {
    NETWORK_INTERFACE_NONE = 0,
    NETWORK_INTERFACE_ETH = 1,
    NETWORK_INTERFACE_WIFI = 2,
    NETWORK_INTERFACE_PPP = 3
};

enum NETWORK_TRUST_TYPE {
    NETWORK_TRUST_SECURED = 0,
    NETWORK_TRUST_UNSECURED = 1,
    NETWORK_TRUST_FORGET = 2
};

enum TAP_ADAPTER_TYPE {
    TAP_ADAPTER = 1,
    WINTUN_ADAPTER = 2
};

enum DNS_WHILE_CONNECTED_TYPE {
    DNS_WHILE_CONNECTED_TYPE_ROBERT = 0,
    DNS_WHILE_CONNECTED_TYPE_CUSTOM = 1
};
enum DNS_MANAGER_TYPE {
    DNS_MANAGER_AUTOMATIC = 0,
    DNS_MANAGER_RESOLV_CONF = 1,
    DNS_MANAGER_SYSTEMD_RESOLVED = 2,
    DNS_MANAGER_NETWORK_MANAGER = 3
};

enum USER_WARNING_TYPE {
    USER_WARNING_MAC_SPOOFING_FAILURE_HARD = 0,
    USER_WARNING_MAC_SPOOFING_FAILURE_SOFT = 1,
    USER_WARNING_SEND_LOG_FILE_TOO_BIG = 2,
    USER_WARNING_VIEW_LOG_FILE_TOO_BIG = 3,
    USER_WARNING_CHECK_UPDATE_INVALID_PLATFORM = 4
};

enum INIT_STATE {
    INIT_STATE_CLEAN = 0,
    INIT_STATE_SUCCESS = 1,
    INIT_STATE_HELPER_FAILED = 2,
    INIT_STATE_HELPER_USER_CANCELED = 3,
    INIT_STATE_BFE_SERVICE_NOT_STARTED = 4,
    INIT_STATE_BFE_SERVICE_FAILED_TO_START = 5
};

enum WEB_SESSION_PURPOSE {
    WEB_SESSION_PURPOSE_EDIT_ACCOUNT_DETAILS = 0,
    WEB_SESSION_PURPOSE_ADD_EMAIL = 1
};

enum CUSTOM_CONFIG_TYPE {
    CUSTOM_CONFIG_OPENVPN = 0,
    CUSTOM_CONFIG_WIREGUARD = 1
};

enum SPLIT_TUNNELING_MODE {
    SPLIT_TUNNELING_MODE_EXCLUDE = 0,
    SPLIT_TUNNELING_MODE_INCLUDE = 1
};

enum SPLIT_TUNNELING_APP_TYPE {
    SPLIT_TUNNELING_APP_TYPE_USER = 0,
    SPLIT_TUNNELING_APP_TYPE_SYSTEM = 1
};

enum SPLIT_TUNNELING_NETWORK_ROUTE_TYPE {
    SPLIT_TUNNELING_NETWORK_ROUTE_TYPE_IP = 0,
    SPLIT_TUNNELING_NETWORK_ROUTE_TYPE_HOSTNAME = 1
};




QString LOGIN_RET_toString(LOGIN_RET ret);
QString dnsPolicyTypeToString(DNS_POLICY_TYPE d);
QString PROXY_SHARING_TYPE_toString(PROXY_SHARING_TYPE t);


#endif // TYPES_ENUMS_H


