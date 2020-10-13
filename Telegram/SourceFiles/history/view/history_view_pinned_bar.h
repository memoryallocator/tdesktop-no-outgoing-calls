/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/chat/message_bar.h"

#include <tuple>

namespace Main {
class Session;
} // namespace Main

namespace Ui {
class IconButton;
class PlainShadow;
struct MessageBarContent;
} // namespace Ui

namespace HistoryView {

[[nodiscard]] rpl::producer<Ui::MessageBarContent> MessageBarContentByItemId(
	not_null<Main::Session*> session,
	FullMsgId id);

enum class PinnedIdType;
struct PinnedBarId {
	FullMsgId message;
	PinnedIdType type = PinnedIdType();

	bool operator<(const PinnedBarId &other) const {
		return std::tie(message, type) < std::tie(other.message, other.type);
	}
	bool operator==(const PinnedBarId &other) const {
		return std::tie(message, type) == std::tie(other.message, other.type);
	}
};
[[nodiscard]] rpl::producer<Ui::MessageBarContent> PinnedBarContent(
	not_null<Main::Session*> session,
	rpl::producer<PinnedBarId> id);

} // namespace HistoryView