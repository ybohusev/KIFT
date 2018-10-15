set browserList to {"Safari", "Google Chrome"}

repeat with browser in browserList
	tell application browser to quit
end repeat